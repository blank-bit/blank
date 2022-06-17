#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // SECURITY_ATTRIBUTES sa;
    // SECURITY_DESCRIPTOR sd;
    // HANDLE hEvent = NULL;

    // InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    // SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
    // sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    // sa.bInheritHandle = FALSE;
    // sa.lpSecurityDescriptor = &sd;

    // hEvent = CreateEventW(&sa, TRUE, FALSE, (LPCWSTR)L"gUseEvent");
    // if (hEvent && GetLastError() != ERROR_ALREADY_EXISTS)
    // {
    //     cout << "create success" << endl;
    // }
    // else if (GetLastError() == ERROR_ALREADY_EXISTS)
    // {
    //     cout << "create ERROR_ALREADY_EXISTS" << endl;
    // }
    // else
    // {
    //     cout << "create fail" << endl;
    // }

    while (1)
    {
        Sleep(1000);
        HANDLE hEvent2 = OpenEventW(EVENT_ALL_ACCESS, true, L"gTestEvent");

        if (hEvent2)
        {
            cout << "open success  gTestEvent" << endl;
            // if (hEvent)
            // {
            //     SetEvent(hEvent);
            //     cout << "hevent" << endl;
            // }
            DWORD dReturn = WaitForSingleObject(hEvent2, INFINITE);
            ResetEvent(hEvent2);
            CloseHandle(hEvent2);
        }
        else
        {
            cout << "open error" << endl;
        }
    }
    return 0;
}