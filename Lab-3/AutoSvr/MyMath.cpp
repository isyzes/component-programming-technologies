// MyMath.cpp: реализация CMyMath

#include "pch.h"
#include "MyMath.h"


// CMyMath

STDMETHODIMP CMyMath::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IMyMath
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyMath::Add(LONG x, LONG y, LONG* z) {
	*z = x + y;
	return S_OK;
}

STDMETHODIMP CMyMath::Fun41(int a, int b, float* c)
{
	// Пример: (a + b) / 100.0f и результат через c
	*c = static_cast<float>(a + b) / 100.0f;
	return S_OK;
}

STDMETHODIMP CMyMath::Fun42(int a, double* b)
{
	// a - радиус, вычисляем площадь круга: π * r²
	double radius = static_cast<double>(a);
	*b = 3.14159265358979323846 * radius * radius;
	return S_OK;
}

STDMETHODIMP CMyMath::Fun43(double in, double* ou)
{
	*ou = in * in;  // b = a²
	return S_OK;
}

STDMETHODIMP CMyMath::Sub(LONG x, LONG y, LONG* z)
{
	*z = x - y;
	return S_OK;
}


STDMETHODIMP CMyMath::GetAuthor(BSTR name, BSTR* message)
{
	CComBSTR messageBSTR("Welcome, ");
	messageBSTR.Append(name);
	*message = messageBSTR;

	return S_OK;
}
STDMETHODIMP CMyMath::get_Param1(LONG* pVal)
{
	*pVal = m_lParam1;
	return S_OK;
}

STDMETHODIMP CMyMath::put_Param1(LONG newVal)
{
	if (newVal < 0) 
	{
		return Error("Значение свойства не может быть меньше 0");
	}
	m_lParam1 = newVal;
	return S_OK;
}