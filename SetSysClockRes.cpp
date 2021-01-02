#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "winmm.lib")

#ifndef _UNICODE
#define _UNICODE
#endif
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <wchar.h>
#include <shlwapi.h>
#include <mmsystem.h>

INT
wmain(INT argc, WCHAR *argv[])
{
    if (argc < 2)
    {
        wprintf(L"%s <Period In Milliseconds>\n", argv[0]);
        return 0;
    }

    //

    UINT period;
    period = StrToInt(argv[1]);

    //

    MMRESULT result;
    result = timeBeginPeriod(period);
    if (result != TIMERR_NOERROR)
    {
        if (result == TIMERR_NOCANDO)
        {
            wprintf(L"timeBeginPeriod(): TIMERR_NOCANDO\n");
        }
        else
        {
            wprintf(L"timeBeginPeriod(): %d\n", result);
        }

        goto Cleanup;
    }

    wprintf(L"Called timeBeginPeriod(%d). Press any key to continue...", period);
    getwchar();

Cleanup:

    result = timeEndPeriod(period);
    if (result != TIMERR_NOERROR)
    {
        if (result == TIMERR_NOCANDO)
        {
            wprintf(L"timeEndPeriod(): TIMERR_NOCANDO\n");
        }
        else
        {
            wprintf(L"timeEndPeriod(): %d\n", result);
        }
    }

    return 0;
}
