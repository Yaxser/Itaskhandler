#pragma once

#include <taskschd.h>
#include <comdef.h>

extern long g_nComObjsInUse;

class CTaskHandler :
    public ITaskHandler
{
public:
    CTaskHandler();
    virtual ~CTaskHandler();

    //IUnknown 
    STDMETHODIMP QueryInterface(_In_ REFIID riid, _COM_Outptr_ LPVOID* ppObj) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    //Task Handler interface
    STDMETHODIMP Start(IUnknown* handler, BSTR data) override;
    STDMETHODIMP Stop(HRESULT* retCode) override;
    STDMETHODIMP Pause() override;
    STDMETHODIMP Resume() override;
private:
    long m_nRefCount;
};