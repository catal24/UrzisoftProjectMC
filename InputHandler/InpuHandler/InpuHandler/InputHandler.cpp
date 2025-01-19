#include "pch.h"
#include "InputHandler.h"
#include <conio.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <fstream>
#include <iostream>

std::mutex json_mutex;
std::string current_command = "-1"; // Default command value
std::atomic<bool> running = true;
std::thread keyboard_thread;
const std::string player_file = "player_count.txt"; // Fișier care reține numărul jucătorilor

void monitorKeyboard() {
    auto last_time = std::chrono::steady_clock::now();
    while (running) {
        if (_kbhit()) {
            char ch = _getch();
            std::lock_guard<std::mutex> lock(json_mutex);
            current_command = std::string(1, ch);
            last_time = std::chrono::steady_clock::now();
        }

        auto current_time = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count() >= 1000) {
            std::lock_guard<std::mutex> lock(json_mutex);
            current_command = "0";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

extern "C" DLL_EXPORT void StartKeyboardMonitoring() {
    running = true;
    keyboard_thread = std::thread(monitorKeyboard);
}

extern "C" DLL_EXPORT void StopKeyboardMonitoring() {
    running = false;
    if (keyboard_thread.joinable()) {
        keyboard_thread.join();
    }
}

extern "C" DLL_EXPORT const char* GetCurrentCommand() {
    std::lock_guard<std::mutex> lock(json_mutex);

    if (current_command.empty() || current_command[0] < 32 || current_command[0] > 126) {
        return "0";  // Dacă e invalid, returnăm "0"
    }

    static std::string safe_command;
    safe_command = current_command;  // Salvăm într-un buffer static
    current_command = "0";  // Resetăm după citire

    //std::cout << "Returning clean command: [" << safe_command << "]" << std::endl;
    return safe_command.c_str();
}


extern "C" DLL_EXPORT int getPlayerNumber() {
    std::lock_guard<std::mutex> lock(json_mutex);
    int player_number = 0;

    std::ifstream infile(player_file);
    if (!infile.is_open() || infile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Could not open file or file is empty!" << std::endl;
        return -1;
    }

    infile >> player_number;
    infile.close();

    // Incrementare
    player_number++;

    if (player_number > 4) {
        std::cerr << "Maximum number of players (4) reached!" << std::endl;
        return -1;
    }

    std::ofstream outfile(player_file, std::ios::trunc);
    if (outfile.is_open()) {
        outfile << player_number;
        outfile.close();
    }
    else {
        std::cerr << "Error: Could not write to file!" << std::endl;
    }

    return player_number;
}
