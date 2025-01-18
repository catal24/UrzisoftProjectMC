#include <conio.h>
#include "crow.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <filesystem>
#include <windows.h>

typedef void (*StartKeyboardFunc)();
typedef void (*StopKeyboardFunc)();
typedef const char* (*GetCommandFunc)();
typedef int (*GetPlayerNumberFunc)();

std::mutex server_mutex;

int main() {
    // Încărcare DLL
    HINSTANCE hDLL = LoadLibrary(L"InpuHandler.dll");  //L - converteste stringul intr-un wide string
    if (!hDLL) {
        std::cerr << "Nu s-a putut încărca DLL-ul!\n";
        return 1;
    }

    // Obținem funcțiile din DLL
    StartKeyboardFunc StartKeyboardMonitoring = (StartKeyboardFunc)GetProcAddress(hDLL, "StartKeyboardMonitoring");
    StopKeyboardFunc StopKeyboardMonitoring = (StopKeyboardFunc)GetProcAddress(hDLL, "StopKeyboardMonitoring");
    GetCommandFunc GetCurrentCommand = (GetCommandFunc)GetProcAddress(hDLL, "GetCurrentCommand");
    GetPlayerNumberFunc GetPlayerNumber = (GetPlayerNumberFunc)GetProcAddress(hDLL, "getPlayerNumber");

    if (!StartKeyboardMonitoring || !StopKeyboardMonitoring || !GetCurrentCommand) {
        std::cerr << "Nu s-au putut găsi funcțiile în DLL!\n";
        return 1;
    }

    // Obținem numărul jucătorului
    int player_number = GetPlayerNumber();
    if (player_number == -1) {
        return 1; // Ieșim dacă s-a atins limita de 4 jucători
    }

    std::cout << "You are Player " << player_number << std::endl;

    // Pornim monitorizarea tastaturii
    StartKeyboardMonitoring();

    // Inițializare server
    crow::SimpleApp app;
    app.loglevel(crow::LogLevel::Warning);

    // Definim endpoint-ul care returnează comanda curentă de la tastatură
    CROW_ROUTE(app, "/player").methods(crow::HTTPMethod::GET)(
    [&]() {
        std::lock_guard<std::mutex> lock(server_mutex);
        crow::json::wvalue response;
        std::string command = GetCurrentCommand();

        if (command.empty()) {
            command = "0"; // Default
        }

        response["command"] = command;
        response["player"] = player_number;
        return response;
    });


    // Lansăm serverul
    int port = 8080 + player_number;
    std::cout << "Server running on http://localhost:" << port << "/player" << std::endl;
    app.port(port).multithreaded().run();

    // Oprim monitorizarea tastaturii când serverul se închide
    StopKeyboardMonitoring();

    // Eliberăm DLL-ul
    FreeLibrary(hDLL);
    return 0;
}