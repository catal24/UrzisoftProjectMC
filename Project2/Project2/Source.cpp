#include <conio.h>
#include "crow.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <filesystem>

std::mutex json_mutex;
std::string current_command = "-1"; // Default command value
const std::string player_file = "player_count.txt"; // File to track the number of players

// Monitor keyboard input in a separate thread
void monitorKeyboard() {
    auto last_time = std::chrono::steady_clock::now();
    while (true) {
        if (_kbhit()) { // Check if a key is pressed
            char ch = _getch(); // Use _getch() to get the key press immediately (without Enter)
            std::lock_guard<std::mutex> lock(json_mutex); // Lock mutex to protect shared resource
            current_command = std::string(1, ch); // Update current command
            last_time = std::chrono::steady_clock::now(); // Reset the timer on key press
        }

        // Check if 1 second has passed since the last key press
        auto current_time = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count() >= 1000) {
            std::lock_guard<std::mutex> lock(json_mutex); // Lock mutex to protect shared resource
            current_command = "0"; // Reset command to "0" after 1 second of inactivity
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Sleep for a short time to avoid high CPU usage
    }
}

// Function to get the next available player number
int getPlayerNumber() {
    std::lock_guard<std::mutex> lock(json_mutex); // Lock the shared resource
    int player_number = 0;


        std::ifstream infile(player_file);
        infile >> player_number; // Read the current player count
        infile.close();
    

    // Increment the player number
    player_number++;

    // Limit to 4 players
    if (player_number > 4) {
        std::cerr << "Maximum number of players (4) reached!" << std::endl;
        return -1;
    }

    // Write the updated player count back to the file
    std::ofstream outfile(player_file, std::ios::trunc);
    outfile << player_number;
    outfile.close();

    return player_number;
}

int main() {
    int player_number = getPlayerNumber();
    if (player_number == -1) {
        return 1; // Exit if no more players can join
    }

    std::cout << "You are Player " << player_number << std::endl;

    crow::SimpleApp app;

    app.loglevel(crow::LogLevel::Warning);

    // Start the keyboard monitoring thread
    std::thread keyboard_thread(monitorKeyboard);

    // Define a single route for all players
    CROW_ROUTE(app, "/player").methods(crow::HTTPMethod::GET)(
        [player_number]() {
            std::lock_guard<std::mutex> lock(json_mutex); // Protect shared resource with lock
            crow::json::wvalue response;
            //response["player"] = player_number;
            response["command"] = current_command; // Add current command to JSON response
            return response;
        });

    // Launch the web server on a port based on the player number
    int port = 8080 + player_number;
    std::cout << "Server running on http://localhost:" << port << "/player" << std::endl;
    app.port(port).multithreaded().run();

    keyboard_thread.join(); // Wait for the keyboard monitoring thread to finish
    return 0;
}
