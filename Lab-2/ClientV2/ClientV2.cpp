//
// ClientV2.cpp
//
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <initguid.h>
#include "..\Server\imath.h"

int main(int argc, char* argv[])
{
	printf("Initializing COM \n");

	if (FAILED(CoInitialize(NULL)))
	{
		printf("Unable to initialize COM \n");
		return -1;
	}

	IMath* pMath = NULL;

	HRESULT hr = CoCreateInstance(CLSID_CMATH, NULL, CLSCTX_INPROC, IDD_IMATH, (void**)&pMath);
	
	if (FAILED(hr))
	{
		printf("Failed to CoCreateInstance server instance. HR =%X \n", hr);
		return -1;
	}
	
	long result;
	printf("######## IMath ########\n");
	pMath->Multiply(20, 7, &result);
	printf("20 * 7 is %d \n", result);

	pMath->Subtract(200, 123, &result);
	printf("200 - 123 is %d \n", result);

	//######## IFN_04 ########
	IFN_04* ifn = nullptr;
	hr = pMath->QueryInterface(IDD_IFN_04, (void**)&ifn);

	float fResult;
	printf("\n######## IFN_04 ########\n");
	ifn->Fun41(200, 123, &fResult);
	printf("Fun41: 200 / 123 is %f \n", fResult);

	double dResult;
	ifn->Fun42(2, &dResult);
	printf("Fun42: 2 * 2 is %f \n", dResult);

	ifn->Fun43(200.876, &dResult);
	printf("Fun43: 200.876 is %f \n", dResult);


	//######## IVer ########
	IVer* pVer = nullptr;
	hr = pMath->QueryInterface(IDD_IVer, (void**)&pVer);
	if (FAILED(hr))
	{
		printf("Failed to CoCreateInstance server instance. HR =%X \n", hr);
		return -1;
	}

	printf("\n######## IVer ########\n");
	printf("Get IVer Sucseded\n");
	wchar_t* name;
	name = (wchar_t*)L"AUTHOR:Igatovich, 40332";
	wchar_t* message;
	pVer->GetAuthor(name, &message);
	wprintf(L"FROM IVer: %s\n", message);
	CoTaskMemFree(message);

	printf("\nReleasing instance \n");
	pMath->Release();
	printf("Shuting down COM\n");

	CoUninitialize();
	return 0;
}