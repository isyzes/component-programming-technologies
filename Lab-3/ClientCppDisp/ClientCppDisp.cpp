#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <initguid.h>
#include "..\AutoSvr\AutoSvr_i.h"


int task1() 
{
	printf("Initializing COM \n");
	if (FAILED(OleInitialize(NULL)))
	{
		printf("Unable to initialize Ole \n");
		return -1;
	}
	const wchar_t* szProgID = L"Lb3AutoSvr.MyMath.1";

	CLSID clsid;

	HRESULT hr = ::CLSIDFromProgID(szProgID, &clsid);
	if (FAILED(hr))
	{
		printf("Unable to get CLSID from ProgID. HR = %X \n", hr);
		return -1;
	}

	IDispatch* pIDisp;
	// Создать компонент и получить pIDisp
	hr = CoCreateInstance(clsid, nullptr, CLSCTX_INPROC, IID_IDispatch, (void**)&pIDisp);
	// проверка hr - пропущена
	if (FAILED(hr))
	{
		printf("Unable to call CoCreateInstance. HR = %X \n", hr);
		return -1;
	}

	printf("CoCreateInstance succeeded.\n");

	//========================================
	// First we need to get the IDs for the function names.
	printf("Get DispID for function \"Add\".\n");
	DISPID dispid;
	OLECHAR* name = (OLECHAR*)L"Add";//*
	hr = pIDisp->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

	if (FAILED(hr)) {
		printf("Query GetIDsOfNames failed.Code %X \n", hr);
		pIDisp->Release();
		return 1;
	}

	//========================================
	// Build up the parameters for the invoke call.
	// Allocate and initialize a VARIANT argument.
	VARIANTARG vargs[2];//*

	::VariantInit(&vargs[0]); // Initialize the VARIANT.//*
	vargs[0].vt = VT_I4; // Type of VARIANT data//*
	vargs[0].lVal = 20; //Op2 Data for the VARIANT//*

	::VariantInit(&vargs[1]); // Initialize the VARIANT.
	vargs[1].vt = VT_I4; // Type of VARIANT data
	vargs[1].lVal = 10; //Op1 Data for the VARIANT
	//Аргументы справа на лево!!! (vargs[1], vargs[0])

	// Fill in the DISPPARAMS structure.
	DISPPARAMS param;
	param.cArgs = 2; // Number of arguments//*
	param.rgvarg = vargs; // Arguments//*
	param.cNamedArgs = 0; // Number of named args
	param.rgdispidNamedArgs = NULL; // Named arguments

	VARIANTARG varres;//*
	::VariantInit(&varres); // Initialize the VARIANT.//*
	varres.vt = VT_I4; // Type of VARIANT data//*
	varres.lVal = 0; // Data for the VARIANT//*
	printf("Invoke the function \"Add\".\n");

	hr = pIDisp->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &param, &varres, NULL, NULL);
	if (FAILED(hr))
	{
		printf("Invoke call failed.Code 0x8%X \n", hr);
		pIDisp->Release();
		return 1;
	}

	// Display the returned Val.
	if (varres.vt == VT_I4)
	{
		printf("Returned from component: op1 %d + op2 %d = %d\n", vargs[1].lVal, vargs[0].lVal, varres.lVal);
	}


	//*************************************
	// Используем второй интефейс IVer
	IVer* pIVer = NULL;
	IID myIID_IVer = __uuidof(IVer);

	hr = pIDisp->QueryInterface(myIID_IVer, (void**)&pIVer);

	wchar_t* pName = (wchar_t*)L"Ignatovich, 40332!";
	BSTR bstrName;
	BSTR bstrMessage;
	bstrName = SysAllocString(pName);
	pIVer->GetAuthor(bstrName, &bstrMessage);
	wprintf(L"From GetAuthor -- %s", (wchar_t*)bstrMessage);
	SysFreeString(bstrName);
	SysFreeString(bstrMessage);

	pIVer->Release();
	pIDisp->Release();
	OleUninitialize();
	return 0;
}

int task2() 
{
	
	DWORD clsctx;
	clsctx = CLSCTX_INPROC_SERVER;
	HRESULT hr = OleInitialize(NULL);
	if (FAILED(hr))
	{
		printf("Failed to initialize. Code 0x8%X \n", hr); 
		return 1;
	}
	// Get the CLSID for the application.
	wchar_t progid[] = L"Lb3AutoSvr.MyMath.1";// Прог. ид. Prog ID
	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	if (FAILED(hr)) {
		printf("Failed to get CLSID.Code 0x8%X \n", hr); 
		return 1;
	}
	// Create the component.
	IDispatch* pIDispatch = NULL;
	hr = ::CoCreateInstance(clsid, NULL, clsctx, IID_IDispatch, (void**)&pIDispatch);
	if (FAILED(hr))
	{
		//trace("Create instance failed.", hr);
		printf("Create instance failed.Code 0x8%X \n", hr);//+
		OleUninitialize();
		return 1;
	}
	printf("CoCreateInstance succeeded.\n");

////////////////////////////////////////////////////
// Установка и чтение свойства

////===Установка значения свойства =========================
// Получение диспетчерского идентификатора =================
	printf("Get DispID for \"Param1\".\n");
	DISPID dispidProp;
	
	OLECHAR* nameProp = (OLECHAR*)L"Param1";//*
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &nameProp, 1, GetUserDefaultLCID(),
		&dispidProp);
	if (FAILED(hr))
	{
		printf("Query GetIDsOfNames Prop failed.Code %X \n", hr);
		pIDispatch->Release(); return 1;
	}
	// Build up the parameters for the invoke call.
	// Allocate and initialize a VARIANT argument.
	VARIANTARG vargsProp;
	::VariantInit(&vargsProp); // Initialize the VARIANT.//*
	vargsProp.vt = VT_I4; // Type of VARIANT data//*
	vargsProp.lVal = 6; // Data for the VARIANT//*
	// Fill in the DISPPARAMS structure.
	DISPID dispPropPut = DISPID_PROPERTYPUT; ///ВНИМАНИЕ !!!!!!
	DISPPARAMS paramProp;
	paramProp.cArgs = 1; // Number of arguments//*
	paramProp.rgvarg = &vargsProp; // Arguments//*
	paramProp.cNamedArgs = 1; // Number of named args //ВНИМАНИЕ!!!!!!
	paramProp.rgdispidNamedArgs = &dispPropPut; // Named arguments ///ВНИМАНИЕ!!!!!!
	
		printf("Invoke the Prop put\"Param1\".\n");
	hr = pIDispatch->Invoke(dispidProp, IID_NULL, GetUserDefaultLCID(),
		DISPATCH_PROPERTYPUT, &paramProp, NULL, NULL, NULL);
	if (FAILED(hr))
	{
		printf("Invoke call Prop Put failed.Code 0x8%X \n", hr);
		pIDispatch->Release(); return 1;
	}
	////=====Значение свойства установлено =========================

	////=== Чтение свойства ========================================
	// Build up the parameters for the invoke call.
	// Fill in the DISPPARAMS structure.
	paramProp.cArgs = 0; // Number of arguments//*
	paramProp.rgvarg = NULL; // Arguments//*
	paramProp.cNamedArgs = 0; // Number of named args
	paramProp.rgdispidNamedArgs = NULL; // Named arguments
	VARIANTARG varresProp;//*
	::VariantInit(&varresProp); // Initialize the VARIANT.//*
	printf("Invoke the Prop Get\"Param1\".\n");
	hr = pIDispatch->Invoke(dispidProp, IID_NULL, GetUserDefaultLCID(),
		DISPATCH_PROPERTYGET, &paramProp, &varresProp, NULL, NULL);
	if (FAILED(hr))
	{
		printf("Invoke call Prop Get failed.Code 0x8%X \n", hr);
		pIDispatch->Release(); return 1;
	}
	// Display the returned Value.
	if (varresProp.vt == VT_I4)
	{
		printf("Returned from component: Param1 %d \n", varresProp.lVal);
	}
	////====== Значение свойства получено и отображено =============
}

int main(int argc, char* argv[])
{
	return task2();
}