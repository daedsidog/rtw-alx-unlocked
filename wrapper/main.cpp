#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <windows.h>

#define BUFSIZE 1024
#define EXE_NAME "alx.exe"
#define DLL_NAME "rtw-alx-unlocked.dll"

int main(int argc, char **argv) {
    STARTUPINFO start_info = {sizeof(start_info)};
    PROCESS_INFORMATION process_info;

    // Format passed down to loader to pass to process.
    std::stringstream args;
    args << EXE_NAME << " " << DLL_NAME << " -args";
    for (int i = 1; i < argc; ++i) {
        args << " " << argv[i];
    }

    // Launch the target process.
    // &std::string[0] is equivalent to char*.
    std::cout << args.str() << std::endl;
    if (CreateProcess(nullptr, &(args.str())[0], nullptr, nullptr, FALSE,
                      CREATE_SUSPENDED, nullptr, nullptr, &start_info,
                      &process_info)) {
        LPVOID page =
            VirtualAllocEx(process_info.hProcess, nullptr, BUFSIZE,
                           MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (page == nullptr) {
            std::cerr << "VirtualAllocEx error: " << GetLastError()
                      << std::endl;
            return -1;
        }
        if (WriteProcessMemory(process_info.hProcess, page,
                               DLL_NAME, sizeof(DLL_NAME),
                               nullptr) == 0) {
            std::cerr << "WriteProcessMemory error: " << GetLastError()
                      << std::endl;
            return -1;
        }
        HANDLE thread = CreateRemoteThread(
            process_info.hProcess, nullptr, 0,
            (LPTHREAD_START_ROUTINE)LoadLibraryA, page, 0, nullptr);
        if (thread == nullptr) {
            std::cerr << "CreateRemoteThread error: " << GetLastError()
                      << std::endl;
            return -1;
        }
        if (WaitForSingleObject(thread, INFINITE) == WAIT_FAILED) {
            std::cerr << "WaitForSingleObject error: " << GetLastError()
                      << std::endl;
            return -1;
        }
        CloseHandle(thread);
        std::cout << "Loaded " << DLL_NAME << std::endl;
        if (ResumeThread(process_info.hThread) == -1) {
            std::cerr << "ResumeThread error: " << GetLastError() << std::endl;
            return -1;
        }
        CloseHandle(process_info.hProcess);
        if (!VirtualFreeEx(process_info.hProcess, page, BUFSIZE,
                           MEM_RELEASE)) {
            std::cerr << "VirtualFreeEx error: " << GetLastError()
                      << std::endl;
            return -1;
        }
        return 0;
    }
    std::cerr << "CreateProcess error: " << GetLastError() << std::endl;
    return -1;
}