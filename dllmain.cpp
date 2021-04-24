#include <iostream>
#include <windows.h>

#include "patches/naval_invasions.hpp"
#include "patches/bi_features.hpp"

bool WINAPI DllMain(HINSTANCE hinst, DWORD call_reason, LPVOID reserved) {
    switch (call_reason) {
    case DLL_PROCESS_ATTACH:

#ifdef DEBUG
        // Allocate a console if we're in debug mode.
        AllocConsole();
        bool  result = true;
        FILE *fp;
        // Redirect STDIN if the console has an input handle.
        if (GetStdHandle(STD_INPUT_HANDLE) != INVALID_HANDLE_VALUE) {
            if (freopen_s(&fp, "CONIN$", "r", stdin) != 0) {
                result = false;
            } else {
                setvbuf(stdin, NULL, _IONBF, 0);
            }
        }

        // Redirect STDOUT if the console has an output handle.
        if (GetStdHandle(STD_OUTPUT_HANDLE) != INVALID_HANDLE_VALUE) {
            if (freopen_s(&fp, "CONOUT$", "w", stdout) != 0) {
                result = false;
            } else {
                setvbuf(stdout, NULL, _IONBF, 0);
            }
        }

        // Redirect STDERR if the console has an error handle.
        if (GetStdHandle(STD_ERROR_HANDLE) != INVALID_HANDLE_VALUE) {
            if (freopen_s(&fp, "CONOUT$", "w", stderr) != 0) {
                result = false;
            } else {
                setvbuf(stderr, NULL, _IONBF, 0);
            }
        }

        // Make C++ standard streams point to console as well.
        std::ios::sync_with_stdio(true);

        // Clear the error state for each of the C++ standard streams.
        std::wcout.clear();
        std::cout.clear();
        std::wcerr.clear();
        std::cerr.clear();
        std::wcin.clear();
        std::cin.clear();
#endif

        // Apply patches
        std::cout << "Applying ";
#ifdef STEAM
        std::cout << "Steam ";
#else
        std::cout << "CD ";
#endif
        std::cout << "patches..." << std::endl;
        naval_invasions::patch();
        bi_features::patch();
        std::cout << "Patching complete." << std::endl;
#ifdef DEBUG
        system("pause");
#endif
        break;
    }
    return true;
}
