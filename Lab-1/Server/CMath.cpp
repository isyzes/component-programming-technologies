//
// СMath.cpp
//

#include <windows.h>
#include "cmath.h"

//
// Math class implementation
//

// Constructors
CMath::CMath()
{
	m_lRef = 0;
	// Увеличить значение внешнего счетчика объектов
	InterlockedIncrement(&g_lObjs);
}
// The destructor
CMath::~CMath()
{
	// Уменьшить значение внешнего счетчика объектов
	InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP CMath::QueryInterface(REFIID riid, void** ppv)
{
	*ppv = 0;

	if (riid == IID_IUnknown)
	{
		*ppv = (IMath*)this;
	}
	else if (riid == IDD_IMATH)
	{
		*ppv = (IMath*) this;
	}
	else if (riid == IDD_IVer)
	{
		*ppv = (IVer*)this;
	}
	else if (riid == IDD_IFN_04)
	{
		*ppv = (IFN_04*)this;
	}

	if (*ppv)
	{
		AddRef();
		return(S_OK);
	}
	return (E_NOINTERFACE);
}

STDMETHODIMP_(ULONG) CMath::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) CMath::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}



STDMETHODIMP CMath::Add(long lOp1, long lOp2, long* pResult)
{
	*pResult = lOp1 + lOp2;
	return S_OK;
}

STDMETHODIMP CMath::Subtract(long lOp1, long lOp2, long* pResult)
{
	*pResult = lOp1 - lOp2;
	return S_OK;
}

STDMETHODIMP CMath::Multiply(long lOp1, long lOp2, long* pResult)
{
	*pResult = lOp1 * lOp2;
	return S_OK;
}

STDMETHODIMP CMath::Divide(long lOp1, long lOp2, long* pResult)
{
	if (lOp2 == 0) {
		return S_FALSE;
	}

	*pResult = lOp1 / lOp2;
	return S_OK;
}

STDMETHODIMP CMath::Fun41(int iOp1, int iOp2, float* result)
{
	*result = (float)(iOp1 / iOp2);
	return S_OK;
}

STDMETHODIMP CMath::Fun42(int iOp, double* result)
{
	*result = (double)(iOp * iOp);
	return S_OK;
}

STDMETHODIMP CMath::Fun43(double in, double* out)
{
	*out = in;
	return S_OK;
}

STDMETHODIMP CMath::GetAuthor(wchar_t* name, wchar_t** author)
{
	wchar_t* buffer = nullptr;
	buffer = (wchar_t*)CoTaskMemAlloc(200);
	if (!buffer)
	{
		return E_OUTOFMEMORY;
	}
	lstrcpyW(buffer, name);
	*author = buffer;

	return S_OK;
}

MathClassFactory::MathClassFactory()
{
	m_lRef = 0;
}

MathClassFactory::~MathClassFactory()
{
}

STDMETHODIMP MathClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return S_OK;
	}
	return(E_NOINTERFACE);
}

STDMETHODIMP_(ULONG) MathClassFactory::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) MathClassFactory::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}

STDMETHODIMP MathClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj)
{
	CMath* pMath;
	HRESULT hr;
	*ppvObj = 0;
	pMath = new CMath;
	if (pMath == 0)
		return(E_OUTOFMEMORY);
	hr = pMath->QueryInterface(riid, ppvObj);
	if (FAILED(hr))
		delete pMath;
	return hr;
}

STDMETHODIMP MathClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		InterlockedIncrement(&g_lLocks);
	else
		InterlockedDecrement(&g_lLocks);
	return S_OK;
}