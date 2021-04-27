#include <iostream>

#include "naval_invasions.hpp"
#include "../assembler-hooker-injector/ahi.hpp"

// Set prefers_naval_invasion to on by default.
void __declspec(naked) naval_invasions::fix_naval_invasions() {
    asm {
#ifndef STEAM
        lea ecx, [esp + 0x16c + 0x4]
        mov dword ptr [esp + 0x158 + 0x4], 1
#else
        movzx eax, al
        test eax, eax
        mov dword ptr [ebp - 0x24], 1
#endif
        ret
    }
}

void naval_invasions::patch() {
    std::cout << "Fixing AI not using naval invasions..." << std::endl;
    AHI::init();
    AHI::inject_func(
        AHI::get_offset(IMAGE_BASE, naval_invasions_patch_start_vaddr),
        AHI::get_offset(IMAGE_BASE, naval_invasions_patch_end_vaddr),
        (LPVOID)naval_invasions::fix_naval_invasions);
}
