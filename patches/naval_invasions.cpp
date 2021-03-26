#include <iostream>

#include "naval_invasions.hpp"
#include "../assembler-hooker-injector/ahi.hpp"

void __declspec(naked) naval_invasions::fix_naval_invasions() {
    asm {
        lea ecx, [esp + 0x16c + 0x4]

        // Set prefers_naval_invasion to on by default.
        mov dword ptr [esp + 0x158 + 0x4], 1
        ret
    }
}

void naval_invasions::patch() {
    AHI::init();
    std::cout << "Fixing AI not using naval invasions..." << std::endl;
    AHI::inject_func(naval_invasions_patch_start, naval_invasions_patch_end,
                     (LPVOID)naval_invasions::fix_naval_invasions);
}
