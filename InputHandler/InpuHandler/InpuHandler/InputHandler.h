#pragma once

#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif

#include <string>

extern "C" {
    DLL_EXPORT void StartKeyboardMonitoring();  // Pornește monitorizarea tastaturii
    DLL_EXPORT void StopKeyboardMonitoring();   // Oprește monitorizarea
    DLL_EXPORT const char* GetCurrentCommand(); // Obține comanda curentă
    DLL_EXPORT int getPlayerNumber();           // Obține numărul jucătorului
}
