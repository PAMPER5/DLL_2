// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <Shellapi.h>

// Экспортная функция для запуска калькулятора
extern "C" __declspec(dllexport) void LaunchCalculator()
{
    try
    {
        ShellExecuteA(NULL, "open", "calc.exe", NULL, NULL, SW_SHOW);
    }
    catch (...)
    {
        return;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

