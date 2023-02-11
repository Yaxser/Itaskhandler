// dllmain.cpp : Defines the entry point for the DLL application.

#include <initguid.h>
#include "config.h"
#include "stager/Common.h"
#include "ClassFactory.hpp"
#include "TaskHandler.hpp"



extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    return TRUE;
}

#pragma warning(push) //disable different annotation warnings
#pragma warning(disable: 28252)
#pragma warning(disable: 28251)
STDAPI DllGetClassObject(_In_ REFCLSID clsid, _In_ REFIID iid, _Outptr_ LPVOID FAR* ppv)
{
    if (IsEqualGUID(clsid, CLSID_TaskHandler)) //check if the guid passed by CoCreateInstance is a one that we support
    {
        ClassFactory* pAddFact = new ClassFactory(); //create the class factory
        if (pAddFact == NULL)
            return E_OUTOFMEMORY;
        else
        {
            return pAddFact->QueryInterface(iid, ppv); //return the class factory to the COM runtime. The runtime will call CreateInstance
        }
    }
    return CLASS_E_CLASSNOTAVAILABLE;
}


STDAPI DllCanUnloadNow(void)
{
    if (g_nComObjsInUse == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}
#pragma warning(pop)