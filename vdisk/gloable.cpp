#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SECURITY_ATTRIBUTES sa;
    SECURITY_DESCRIPTOR sd;
    HANDLE hEvent = NULL;
    cout << "11" << endl;

    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = FALSE;
    sa.lpSecurityDescriptor = &sd;

    cout << "11" << endl;
    TCHAR *name = (TCHAR *)L"gTestEvent";
    hEvent = CreateEventW(&sa, TRUE, TRUE, (LPCWSTR)name);
    if (hEvent && GetLastError() != ERROR_ALREADY_EXISTS)
    {
        cout << "create success" << endl;
    }
    else if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        cout << "create ERROR_ALREADY_EXISTS" << endl;
    }
    else
    {
        cout << "create fail" << endl;
    }
    while (1)
    {
        /* code */
    }

    // while (1)
    // {
    //     Sleep(1000);
    //     HANDLE hEvent2 = OpenEventW(EVENT_ALL_ACCESS, true, L"gUseEvent");

    //     if (hEvent2)
    //     {
    //         cout << "open success gUseEvent" << endl;
    //         if (hEvent)
    //         {
    //             SetEvent(hEvent);
    //             cout << "hevent" << endl;
    //         }
    //         DWORD dReturn = WaitForSingleObject(hEvent2, INFINITE);
    //         ResetEvent(hEvent2);
    //         if (CloseHandle(hEvent2))
    //         {
    //             cout << "closed hEvent2" << endl;
    //         }
    //     }
    //     else
    //     {
    //         cout << "open error" << endl;
    //     }
    // }
    return 0;
}