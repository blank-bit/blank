#include <iostream>
#include <Windows.h>

int main()
{
    // int i = ((9) << 16) | ((0) << 14) | ((0x804) << 2) | (0); // 1001 0010 0000 0001 0000
    // int t = ((9) << 16) | ((0) << 14) | ((8) << 2) | (0);     // 1001 0000 0000 0010 0000
    // std::cout << "i:" << i << std::endl;
    // std::cout << "t:" << t << std::endl;
    DWORD dw;
    TCHAR TC1[50], TC2[50];

    dw = GetLogicalDrives();
    std::cout << dw << std::endl;
    wsprintf(TC1, "%ld", dw);
    std::cout << TC1 << std::endl;

    _itoa(dw, TC2, 2);
    std::cout << TC2 << std::endl;
}