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
uintptr_t abilities_ifchain_end;
uintptr_t swimming_ifchain_end;
void __declspec(naked) special_abilities::enable_swimming_ability() {

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
        push abilities_ifchain_end
#else

        // The unit attribute offsets may be wrong. Requires testing.
        movzx eax, al
        test eax, eax
        jnz can_swim
        add esp, 0x4
        push swimming_ifchain_end
        ret
        can_swim:
        mov al, byte ptr[ecx + 0x200]
        or al, 0x40
        mov [ecx + 0x199], al
        add esp, 0x4
        push abilities_ifchain_end
#endif
        cannot_swim:
        ret
    }
}
uintptr_t hording_ifchain_end;
void __declspec(naked) special_abilities::enable_hording_ability() {
    asm {
#ifndef STEAM
        test eax, eax
        jz cannot_horde
        mov al, byte ptr[edi + 0x201]
        or al, 0x80
        mov [edi + 0x200], al
        add esp, 0x4
        push abilities_ifchain_end
#else

        // The unit attribute offsets may be wrong. Requires testing.
        movzx eax, al
        test eax, eax
        jnz can_horde
        add esp, 0x4
        push hording_ifchain_end
        ret
        can_horde:
        mov al, byte ptr[ecx + 0x200]
        or al, 0x80
        mov[ecx + 0x199], al
        add esp, 0x4
        push abilities_ifchain_end
#endif
        cannot_horde:
        ret
    }
}

void special_abilities::patch() {
    AHI::init();
    std::cout << "Enabling shield_wall and schiltrom formations..."
              << std::endl;
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, formations_fix_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, formations_fix_end_vaddr),
                     (LPVOID)enable_bi_formations);
    std::cout << "Enabling swimming ability..." << std::endl;
#ifndef STEAM
    abilities_ifchain_end =
        AHI::get_abs_addr(IMAGE_BASE, abilities_ifchain_end_vaddr);
#else
    abilities_ifchain_end =
        AHI::get_abs_addr(IMAGE_BASE, abilities_ifchain_end_vaddr);
    swimming_ifchain_end =
        AHI::get_abs_addr(IMAGE_BASE, swimming_ifchain_end_vaddr);
    hording_ifchain_end =
        AHI::get_abs_addr(IMAGE_BASE, hording_ifchain_end_vaddr);
#endif
    AHI::inject_func(
        AHI::get_offset(IMAGE_BASE, swimming_ability_enable_fix_start_vaddr),
        AHI::get_offset(IMAGE_BASE, swimming_ability_enable_fix_end_vaddr),
        (LPVOID)enable_swimming_ability);
    std::cout << "Enabling hording ability..." << std::endl;
    AHI::inject_func(
        AHI::get_offset(IMAGE_BASE, hording_ability_enable_fix_start_vaddr),
        AHI::get_offset(IMAGE_BASE, hording_ability_enable_fix_end_vaddr),
        (LPVOID)enable_hording_ability);
}
