# rtw-alx-unlocked
A memory patch for the lastest (1.9) `RomeTW-ALX.exe` for Windows with the goal of porting over `RomeTW-BI.exe` features, fixing bugs, & removing hardcoded limits for `RomeTW-ALX.exe`.

# Changes
* Add shield wall & schiltrom formations.
* Add swimming ability.
* Add hording ability & functionality for factions.
* Fix AI not using naval invasions.
* Fix camera not jumping to unit when interrupted.

# Usage
The appropriate DLL has to be loaded into the `RomeTW-ALX.exe` (`testappa.exe` if using Steam) process **right at the very beginning**. The best way to do this is to use a DLL loader such as [daedsidog/win-dll-loader](https://github.com/daedsidog/win-dll-loader).
Alternatively, you can compile [`wrapper/main.cpp`](https://github.com/daedsidog/rtw-alx-unlocked/blob/master/wrapper/main.cpp) which acts as a wrapper to `RomeTW-ALX.exe` & takes care of everything, but you will have to rename the original `RomeTW-ALX.exe` (`testappa.exe` if using Steam) to `alx.exe`.

# Steam
While the patch is attempting to provide Steam compatibility, it is not guaranteed because thorough testing is done only on the CD version.

# Malware concerns
Due to the nature of memory patching & code injection, some antivirus software may label the DLLs as a false positive. There is no immediate solution other than excluding these files in your AV program. Anyone pedantic enough is free to compile the DLLs himself using the included makefile.
