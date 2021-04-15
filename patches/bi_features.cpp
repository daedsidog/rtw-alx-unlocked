#include <iostream>

#include "../assembler-hooker-injector/ahi.hpp"
#include "bi_features.hpp"

void __declspec(naked) bi_features::enable_bi_formations() {
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
void __declspec(naked) bi_features::enable_swimming_ability() {

    // Taken almost verbatim from the old RTR launcher, except for Steam
    // version.
    asm {
#ifndef STEAM
        test eax, eax
        jz cannot_swim
        mov al, byte ptr[edi + 0x200]
        or al, 0x40
        mov [edi + 0x200], al
        add esp, 0x4
        push abilities_ifchain_end
#else
        movzx eax, al
        test eax, eax
        jnz can_swim
        add esp, 0x4
        push swimming_ifchain_end
        ret
        can_swim:
        mov al, byte ptr[ecx + 0x200]
        or al, 0x40
        mov [ecx + 0x200], al
        add esp, 0x4
        push abilities_ifchain_end
#endif
        cannot_swim:
        ret
    }
}
uintptr_t hording_ifchain_end;
void __declspec(naked) bi_features::enable_hording_ability() {
    asm {
#ifndef STEAM
        test eax, eax
        jz cannot_horde
        mov al, byte ptr[edi + 0x200]
        or al, 0x80
        mov [edi + 0x200], al
        add esp, 0x4
        push abilities_ifchain_end
#else
        movzx eax, al
        test eax, eax
        jnz can_horde
        add esp, 0x4
        push hording_ifchain_end
        ret
        can_horde:
        mov al, byte ptr[ecx + 0x200]
        or al, 0x80
        mov[ecx + 0x200], al
        add esp, 0x4
        push abilities_ifchain_end
#endif
        cannot_horde:
        ret
    }
}
char *    horde_min_units;
char *    horde_max_units;
char *    horde_max_units_reduction_every_horde;
char *    horde_unit_per_settlement_population;
char *    horde_min_named_characters;
char *    horde_max_percent_army_stack;
char *    horde_disband_percent_on_settlement_cap;
char *    horde_unit;
uintptr_t hording_init_end;
uintptr_t hording_enable_flag;
uintptr_t some_parsing_func;
uintptr_t strparse_func;

void bi_features::enable_hording_functionality() {
    asm {
        add esp, 0x4
        case_horde_min_units:
		push horde_min_units
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_1
		push eax
		push strparse_func
		ret
		strparse_func_ret_1:
        movzx eax, al
        test eax, eax
        jz case_horde_max_units
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_1
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_1:
		case_horde_max_units:
		push horde_max_units
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_2
		push eax
		push strparse_func
		ret
		strparse_func_ret_2:
        movzx eax, al
        test eax, eax
        jz case_horde_max_units_reduction_every_horde
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_2
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_2:
		case_horde_max_units_reduction_every_horde:
		push horde_max_units_reduction_every_horde
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_3
		push eax
		push strparse_func
		ret
		strparse_func_ret_3:
        movzx eax, al
        test eax, eax
        jz case_horde_unit_per_settlement_population
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_3
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_3:
		case_horde_unit_per_settlement_population:
		push horde_unit_per_settlement_population
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_4
		push eax
		push strparse_func
		ret
		strparse_func_ret_4:
        movzx eax, al
        test eax, eax
        jz case_horde_min_named_characters
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_4
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_4:
		case_horde_min_named_characters:
		push horde_min_named_characters
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_5
		push eax
		push strparse_func
		ret
		strparse_func_ret_5:
        movzx eax, al
        test eax, eax
        jz case_horde_max_percent_army_stack
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_5
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_5:
		case_horde_max_percent_army_stack:
		push horde_max_percent_army_stack
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_6
		push eax
		push strparse_func
		ret
		strparse_func_ret_6:
        movzx eax, al
        test eax, eax
        jz case_horde_disband_percent_on_settlement_cap
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_6
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_6:
		case_horde_disband_percent_on_settlement_cap:
		push horde_disband_percent_on_settlement_cap
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_7
		push eax
		push strparse_func
		ret
		strparse_func_ret_7:
        movzx eax, al
        test eax, eax
        jz case_horde_unit
        case_special_horde_disband_percent_on_settlement_cap:
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_7
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_7:
        push horde_disband_percent_on_settlement_cap
        lea ecx, [esp + 0x170]
        lea eax, special_ret
        push eax
        push strparse_func
        ret
        special_ret:
        movzx eax, al
        test eax, eax
        jnz case_special_horde_disband_percent_on_settlement_cap
		case_horde_unit:
		push horde_unit
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_8
		push eax
		push strparse_func
		ret
		strparse_func_ret_8:
        movzx eax, al
        test eax, eax
        jz end
        case_special_horde_unit:
		lea ecx, [esp + 0x16c]
		lea eax, some_parsing_func_ret_8
		push eax
		push some_parsing_func
		ret
		some_parsing_func_ret_8:
        mov byte ptr [esp + 0x155], 0x1
        push horde_unit
        lea ecx, [esp + 0x170]
        lea eax, strparse_func_ret_9
        push eax
        push strparse_func
        ret
        strparse_func_ret_9:
        movzx eax, al
        test eax, eax
        jnz case_special_horde_unit
		end:
        push hording_init_end
        ret
    }
}
void bi_features::patch() {
    AHI::init();
    std::cout << "Enabling shield_wall & schiltrom formations..."
              << std::endl;
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, formations_fix_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, formations_fix_end_vaddr),
                     (LPVOID)enable_bi_formations);
    std::cout << "Enabling swimming ability..." << std::endl;
#ifndef STEAM
    abilities_ifchain_end =
        AHI::get_abs_addr(IMAGE_BASE, abilities_ifchain_end_vaddr);
    some_parsing_func = AHI::get_abs_addr(IMAGE_BASE, some_parsing_func_vaddr);
    strparse_func     = AHI::get_abs_addr(IMAGE_BASE, strparse_func_vaddr);
    hording_init_end  = AHI::get_abs_addr(
        IMAGE_BASE, hording_functionality_enable_fix_end_vaddr);
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
    std::cout << "Enabling hording ability & functionality..." << std::endl;
#define defstr(x, y) x = (char *)AHI::get_abs_addr(IMAGE_BASE, y);
    defstr(horde_min_units, horde_min_units_vaddr);
    defstr(horde_max_units, horde_max_units_vaddr);
    defstr(horde_max_units_reduction_every_horde,
           horde_max_units_reduction_every_horde_vaddr);
    defstr(horde_unit_per_settlement_population,
           horde_unit_per_settlement_population_vaddr);
    defstr(horde_min_named_characters, horde_min_named_characters_vaddr);
    defstr(horde_max_percent_army_stack, horde_max_percent_army_stack_vaddr);
    defstr(horde_disband_percent_on_settlement_cap,
           horde_disband_percent_on_settlement_cap_vaddr);
    defstr(horde_unit, horde_unit_vaddr);
    AHI::inject_func(
        AHI::get_offset(IMAGE_BASE, hording_ability_enable_fix_start_vaddr),
        AHI::get_offset(IMAGE_BASE, hording_ability_enable_fix_end_vaddr),
        (LPVOID)enable_hording_ability);
    AHI::inject_func(
        AHI::get_offset(IMAGE_BASE,
                        hording_functionality_enable_fix_start_vaddr),
        AHI::get_offset(IMAGE_BASE, hording_functionality_enable_fix_end_vaddr),
        (LPVOID)enable_hording_functionality);
}
