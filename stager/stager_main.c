#include <windows.h>


DWORD WINAPI init() {
    MessageBoxA(NULL, "Hello", "From COM Handler", 0);
    return 0;
}
