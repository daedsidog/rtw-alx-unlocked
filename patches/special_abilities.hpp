#ifndef FORMATIONS_HPP_
#define FORMATIONS_HPP_

#define IMAGE_BASE 0x400000

#ifndef STEAM
#define formations_fix_start 0x8d4964 - IMAGE_BASE
#define formations_fix_end   0x8d4970 - IMAGE_BASE
#define swimming_fix_start   0x8d43c1 - IMAGE_BASE
#define swimming_fix_end     0x8d43c9 - IMAGE_BASE
#else
#define formations_fix_start 0x91a30f - IMAGE_BASE
#define formations_fix_end   0x91a32c - IMAGE_BASE
#define swimming_fix_start   0x91931 - IMAGE_BASE
#define swimming_fix_end     0x91938 - IMAGE_BASE
#endif

class special_abilities {
    special_abilities() = delete;

    static void __declspec(naked) enable_bi_formations();
    static void __declspec(naked) enable_swimming();

  public:
    static void patch();
};

#endif
