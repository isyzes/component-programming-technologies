//
// server.cpp : Defines the initialization routines for the DLL.
//

#include <windows.h>
#include <initguid.h>
#include <stdio.h>
#include "cmath.h"
#include "Registry.h"

long g_lObjs = 0;
long g_lLocks = 0;

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	HRESULT hr;
	MathClassFactory* pCF;
	pCF = 0;

	// Make sure the CLSID is for our Expression component
	if (rclsid != CLSID_CMATH)
		return(E_FAIL);
	pCF = new MathClassFactory;
	if (pCF == 0)
		return(E_OUTOFMEMORY);
	hr = pCF->QueryInterface(riid, ppv);

	// Check for failure of QueryInterface
	if (FAILED(hr))
	{
		delete pCF;
		pCF = 0;
	}
	return hr;
}

STDAPI DllCanUnloadNow(void)
{
	if (g_lObjs || g_lLocks)
		return(S_FALSE);
	else
		return(S_OK);
}
//######################## LAB 2 ########################
static HMODULE g_hModule = NULL; // DLL module handle
// Friendly name of component
const wchar_t g_szFriendlyName[] = L"40332_CMath Class";
// Version-independent ProgID
const wchar_t g_szVerIndProgID[] = L"Server40332.MathComponent";
// ProgID
const wchar_t g_szProgID[] = L"Server40332.MathComponent.1";


STDAPI DllRegisterServer()
{
	return RegisterServer(
		g_hModule,
		CLSID_CMATH,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID
	);
}

STDAPI DllUnregisterServer(void)
{
	return UnregisterServer(
		CLSID_CMATH,
		g_szVerIndProgID,
		g_szProgID
	);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) 
	{
		g_hModule = (HMODULE)hModule;
	}
    
    return TRUE;
}