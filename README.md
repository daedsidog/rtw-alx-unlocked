# rtw-alx-unlocked
A memory patch for `RomeTW-ALX.exe` for Windows with the goal of porting over `RomeTW-BI.exe` features, fixing bugs, & removing hardcoded limits.

# Changes
* Fix AI not using naval invasions.
* Add shield wall & schiltrom formations.
* Add swimming ability.
* Add hording ability (Hording functionality does not yet work).

# Usage
The appropriate DLL has to be loaded into the `RomeTW-ALX.exe` process **right at the very beginning**. The best way to do this is to use a DLL loader such as [daedsidog/win-dll-loader](https://github.com/daedsidog/win-dll-loader).
Alternatively, you can compile [`wrapper/main.cpp`](https://github.com/daedsidog/rtw-alx-unlocked/blob/master/wrapper/main.cpp) which acts as a wrapper to `RomeTW-ALX.exe` & takes care of everything, but you will have to rename the original `RomeTW-ALX.exe` to `alx.exe`.

# Steam
While the patch is attempting to provide Steam compatibility, it is not guaranteed because thorough testing is done only on the CD version.
