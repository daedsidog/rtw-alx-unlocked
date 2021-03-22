#include <windows.h>

#include "assembler-hooker-injector/ahi.hpp"

bool WINAPI DllMain(HINSTANCE hinst, DWORD call_reason, LPVOID reserved) {
    switch (call_reason) {
    case DLL_PROCESS_ATTACH:
        AHI::init();
        break;
    }
    return true;
}
