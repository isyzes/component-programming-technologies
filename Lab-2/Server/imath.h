#pragma once
//
// imath.h
//

#include <Windows.h>

// {E06DF13A-55C5-460E-ABEE-C28E19562FBE}
DEFINE_GUID(CLSID_CMATH,
	0xe06df13a, 0x55c5, 0x460e, 0xab, 0xee, 0xc2, 0x8e, 0x19, 0x56, 0x2f, 0xbe);

// {D00DD4B5-5ABC-43FB-A8CE-BB5CBF50FAF2}
DEFINE_GUID(IDD_IMATH,
	0xd00dd4b5, 0x5abc, 0x43fb, 0xa8, 0xce, 0xbb, 0x5c, 0xbf, 0x50, 0xfa, 0xf2);


// {5009136B-A8D6-461D-BCD6-615BA918818C}
DEFINE_GUID(IDD_IFN_04,
	0x5009136b, 0xa8d6, 0x461d, 0xbc, 0xd6, 0x61, 0x5b, 0xa9, 0x18, 0x81, 0x8c);

// {925E82F0-41E5-4F09-B1D8-940B53071CF2}
DEFINE_GUID(IDD_IVer,
	0x925e82f0, 0x41e5, 0x4f09, 0xb1, 0xd8, 0x94, 0xb, 0x53, 0x7, 0x1c, 0xf2);



class IMath : public IUnknown
{
public:
	STDMETHOD(Add(long, long, long*)) PURE;
	STDMETHOD(Subtract(long, long, long*)) PURE;
	STDMETHOD(Multiply(long, long, long*)) PURE;
	STDMETHOD(Divide(long, long, long*)) PURE;
};


class IFN_04 : public IUnknown
{
public:
	STDMETHOD(Fun41(int, int, float*)) PURE;
	STDMETHOD(Fun42(int, double*)) PURE;
	STDMETHOD(Fun43(double, double*)) PURE;
};

class IVer : public IUnknown
{
public:
	STDMETHOD(GetAuthor(wchar_t* name, wchar_t** author)) PURE;
};