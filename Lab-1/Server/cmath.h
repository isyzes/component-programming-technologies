#pragma once

//
// сmath.h
//

#include "imath.h"

extern long g_lObjs;
extern long g_lLocks;

class CMath : public IMath, public IFN_04, public IVer
{
protected:
	// Reference count
	long m_lRef;

public:
	CMath();//конструктор
	~CMath();//деструктор

public:
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());
	// IMath
	STDMETHOD(Add(long, long, long*));
	STDMETHOD(Subtract(long, long, long*));
	STDMETHOD(Multiply(long, long, long*));
	STDMETHOD(Divide(long, long, long*));
	//IFN_04
	STDMETHOD(Fun41(int, int, float*));
	STDMETHOD(Fun42(int, double*));
	STDMETHOD(Fun43(double, double*));
	//IVer
	STDMETHOD(GetAuthor(wchar_t* name, wchar_t** author));

};

class MathClassFactory : public IClassFactory
{
protected:
	long m_lRef;

public:
	MathClassFactory();
	~MathClassFactory();
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());
	// IClassFactory
	STDMETHOD(CreateInstance(LPUNKNOWN, REFIID, void**));
	STDMETHOD(LockServer(BOOL));
};