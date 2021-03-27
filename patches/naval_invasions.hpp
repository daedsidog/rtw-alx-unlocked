#define IMAGE_BASE 0x400000

#ifdef STEAM
#define naval_invasions_patch_start 0x8faaf9 - IMAGE_BASE
#define naval_invasions_patch_end   0x8faafe - IMAGE_BASE
#else
#define naval_invasions_patch_start 0x8ac81e - IMAGE_BASE
#define naval_invasions_patch_end   0x8ac825 - IMAGE_BASE
#endif

class naval_invasions {
    naval_invasions() = delete;
    static void __declspec(naked) fix_naval_invasions();

  public:
    static void patch();
};
