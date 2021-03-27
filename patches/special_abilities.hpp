#ifndef FORMATIONS_HPP_
#define FORMATIONS_HPP_

#define IMAGE_BASE 0x400000

#ifndef STEAM
#define sw_fix_start 0x8d4964 - IMAGE_BASE
#define sw_fix_end 0x8d4970 - IMAGE_BASE
#else
#define sw_fix_start 0x8d4964 - IMAGE_BASE
#define sw_fix_end 0x8d4970 - IMAGE_BASE
#endif

class special_abilities {
    special_abilities() = delete;

    static void __declspec(naked) enable_bi_formations();
  public:
    static void patch();
};

#endif
