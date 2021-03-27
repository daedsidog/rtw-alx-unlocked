#include <iostream>

#include "../assembler-hooker-injector/ahi.hpp"
#include "special_abilities.hpp"

void __declspec(naked) special_abilities::enable_bi_formations() {
    asm {
#ifdef STEAM
        mov dword ptr [ebp - 0x574], 7
        mov eax, [ebp - 0x6e0]
        add eax, [ebp - 0x574]
#endif
        ret // Taken from the old RTR launcher: apparently all you had to do was
            // just delete the two instructions occupying this injection range.
    }
}
uintptr_t swimming_scope_exit;
void __declspec(naked) special_abilities::enable_swimming() {
    // Taken almost verbatim from the old RTR launcher, except for Steam
    // version.
    asm {
#ifndef STEAM
        test eax, eax
        jz cannot_swim
        mov al, byte ptr[edi + 0x201]
        or al, 0x40
        mov [edi + 0x200], al
        add esp, 0x4
        push swimming_scope_exit
#else
        movzx eax, al
        test eax, eax
        jnz can_swim
        push swimming_scope_exit
        jmp cannot_swim
        can_swim:
        mov al, byte ptr[ecx + 0x200]
        or al, 0x40
        mov [ecx + 0x199], al // Not sure about this.
        add esp, 0x4
#endif
        cannot_swim:
        ret
    }
}

void special_abilities::patch() {
    AHI::init();
    std::cout << "Adding shield_wall and schiltrom formations..." << std::endl;
    AHI::inject_func(formations_fix_start, formations_fix_end,
                     (LPVOID)enable_bi_formations);
    std::cout << "Adding swimming..." << std::endl;
#ifndef STEAM
    swimming_scope_exit = AHI::get_abs_addr(IMAGE_BASE, 0x008d479d);
#else
    swimming_scope_exit = AHI::get_abs_addr(IMAGE_BASE, 0x00919a3d);
#endif
    AHI::inject_func(swimming_fix_start, swimming_fix_end,
                     (LPVOID)enable_swimming);
}
