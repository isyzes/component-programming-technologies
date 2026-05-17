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

STDMETHODIMP CMyMath::Fun42(int a, DOUBLE* b)
{
	// a - радиус, вычисляем площадь круга: π * r²
	double radius = static_cast<double>(a);
	*b = 3.14159265358979323846 * radius * radius;
	return S_OK;
}


STDMETHODIMP CMyMath::Fun43(DOUBLE a, DOUBLE* b)
{
	*b = a * a;  // b = a²
	return S_OK;
}
