#include <iostream>

#include "../assembler-hooker-injector/ahi.hpp"
#include "special_abilities.hpp"

void __declspec(naked) special_abilities::enable_bi_formations() {
    asm {
        ret // Taken from the old RTR launcher: apparently all you had to do was
            // just delete the two instructions occupying this injection range.
    }
}

void special_abilities::patch() {
    std::cout << "Adding shield_wall and schiltrom formations..." << std::endl;
    AHI::inject_func(sw_fix_start, sw_fix_end, (LPVOID)enable_bi_formations);
}
