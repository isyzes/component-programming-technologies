// PolyCtl.h: объявление CPolyCtl
#pragma once
#include <math.h>
#include "resource.h"       // основные символы
#include <atlctl.h>
#include "Polygon_i.h"
#include "_IPolyCtlEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;



// CPolyCtl
class ATL_NO_VTABLE CPolyCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CPolyCtl, IPolyCtl>,
	public IPersistStreamInitImpl<CPolyCtl>,
	public IOleControlImpl<CPolyCtl>,
	public IOleObjectImpl<CPolyCtl>,
	public IOleInPlaceActiveObjectImpl<CPolyCtl>,
	public IViewObjectExImpl<CPolyCtl>,
	public IOleInPlaceObjectWindowlessImpl<CPolyCtl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CPolyCtl>,
	public CProxy_IPolyCtlEvents<CPolyCtl>,
	public IObjectWithSiteImpl<CPolyCtl>,
	public IServiceProviderImpl<CPolyCtl>,
	public IPersistStorageImpl<CPolyCtl>,
	public ISpecifyPropertyPagesImpl<CPolyCtl>,
	public IQuickActivateImpl<CPolyCtl>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CPolyCtl>,
#endif
	public IProvideClassInfo2Impl<&CLSID_PolyCtl, &__uuidof(_IPolyCtlEvents), &LIBID_PolygonLib>,
	public IPropertyNotifySinkCP<CPolyCtl>,
	public IObjectSafetyImpl<CPolyCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CPolyCtl, &CLSID_PolyCtl>,
	public CComControl<CPolyCtl>
{
public:


	CPolyCtl()
	{
		m_nSides = 5;
		m_clrFillColor = RGB(0, 255, 0);
		m_clrBorderColor = RGB(255, 255, 0);
		m_clrGraphColor = RGB(0, 128, 0);
		m_clrBackColor = RGB(255, 255, 255);
		m_dXMin = 4.0;
		m_dXMax = 7.0;
		m_dYMin = 0.0;
		m_dYMax = 4.0;
		m_bGraphVisible = FALSE;
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_POLYCTL)


BEGIN_COM_MAP(CPolyCtl)
	COM_INTERFACE_ENTRY(IPolyCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IServiceProvider)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CPolyCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("BorderColor", DISPID_BORDERCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	// Записи примеров
	// PROP_ENTRY_TYPE("Имя свойства", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CPolyCtl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(__uuidof(_IPolyCtlEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CPolyCtl)
	CHAIN_MSG_MAP(CComControl<CPolyCtl>)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()

LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
LRESULT OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IPolyCtl,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPolyCtl
	POINT m_arrPoint[10];



public:
	void CPolyCtl::CalcPoints(const RECT& rc);

	static double Func(double x)
	{
		return exp(x) / (x * x * x) - pow(sin(x), 3.0);
	}

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		HDC hdc = di.hdcDraw;

		HRGN hRgnOld = nullptr;
		if (GetClipRgn(hdc, hRgnOld) != 1)
			hRgnOld = nullptr;
		bool bSelectOldRgn = false;

		HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
		if (hRgnNew != nullptr)
			bSelectOldRgn = (SelectClipRgn(hdc, hRgnNew) != ERROR);

		COLORREF colBack;
		OleTranslateColor(m_clrBackColor, NULL, &colBack);
		HBRUSH hBgBrush = CreateSolidBrush(colBack);
		FillRect(hdc, &rc, hBgBrush);
		DeleteObject(hBgBrush);

		if (!m_bGraphVisible)
		{
			int savedHide = SaveDC(hdc);
			SetBkMode(hdc, TRANSPARENT);
			int hfPx = MulDiv(11, GetDeviceCaps(hdc, LOGPIXELSY), 72);
			if (hfPx < 14) hfPx = 14;
			HFONT hHideFont = CreateFont(-hfPx, 0, 0, 0, FW_NORMAL,
				FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
			SelectObject(hdc, hHideFont);
			SetTextColor(hdc, RGB(120, 120, 140));
			SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
			LPCTSTR pszHidden = _T("График скрыт. Нажмите левую кнопку мыши для отображения.");
			TextOut(hdc, (rc.left + rc.right) / 2, (rc.top + rc.bottom) / 2,
				pszHidden, lstrlen(pszHidden));
			RestoreDC(hdc, savedHide);
			DeleteObject(hHideFont);

			if (bSelectOldRgn)
				SelectClipRgn(hdc, hRgnOld);
			DeleteObject(hRgnNew);
			return S_OK;
		}

		int ctlW = rc.right - rc.left;
		int ctlH = rc.bottom - rc.top;

		int mL = ctlW / 7;  if (mL < 40) mL = 40;
		int mR = ctlW / 12; if (mR < 15) mR = 15;
		int mT = ctlH / 7;  if (mT < 28) mT = 28;
		int mB = ctlH / 6;  if (mB < 30) mB = 30;

		RECT gr;
		gr.left   = rc.left + mL;
		gr.right  = rc.right - mR;
		gr.top    = rc.top + mT;
		gr.bottom = rc.bottom - mB;
		int gw = gr.right - gr.left;
		int gh = gr.bottom - gr.top;

		if (gw < 10 || gh < 10)
		{
			if (bSelectOldRgn) SelectClipRgn(hdc, hRgnOld);
			DeleteObject(hRgnNew);
			return S_OK;
		}

		const double xMin = m_dXMin, xMax = m_dXMax;
		const double yMin = m_dYMin, yMax = m_dYMax;
		double xRange = xMax - xMin;
		double yRange = yMax - yMin;
		if (xRange < 1e-9) xRange = 1.0;
		if (yRange < 1e-9) yRange = 1.0;

		const int N = 500;
		double fv[501];
		for (int i = 0; i <= N; i++)
		{
			double x = xMin + xRange * i / N;
			fv[i] = Func(x);
		}

		BYTE rB = GetRValue(colBack), gB = GetGValue(colBack), bB = GetBValue(colBack);
		COLORREF colGraphBg = RGB(
			rB > 10 ? rB - 10 : 0,
			gB > 10 ? gB - 10 : 0,
			bB > 7  ? bB - 3  : bB);
		HBRUSH hGrBg = CreateSolidBrush(colGraphBg);
		FillRect(hdc, &gr, hGrBg);
		DeleteObject(hGrBg);

		int savedDC = SaveDC(hdc);
		SetBkMode(hdc, TRANSPARENT);

		int fontPx = MulDiv(8, GetDeviceCaps(hdc, LOGPIXELSY), 72);
		if (fontPx < 10) fontPx = 10;
		HFONT hSmallFont = CreateFont(-fontPx, 0, 0, 0, FW_NORMAL,
			FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
		SelectObject(hdc, hSmallFont);
		SetTextColor(hdc, RGB(80, 80, 100));

		HPEN hGridPen = CreatePen(PS_DOT, 1, RGB(200, 200, 218));
		SelectObject(hdc, hGridPen);

		const int nYTicks = 5;
		SetTextAlign(hdc, TA_RIGHT | TA_BASELINE);
		for (int i = 0; i <= nYTicks; i++)
		{
			double yVal = yMin + yRange * i / nYTicks;
			int py = gr.bottom - (int)(((yVal - yMin) / yRange) * gh);
			MoveToEx(hdc, gr.left, py, NULL);
			LineTo(hdc, gr.right, py);
			TCHAR buf[32];
			_stprintf_s(buf, 32, _T("%.2f"), yVal);
			TextOut(hdc, gr.left - 5, py + fontPx / 3, buf, lstrlen(buf));
		}

		const int nXTicks = 6;
		SetTextAlign(hdc, TA_CENTER | TA_TOP);
		for (int i = 0; i <= nXTicks; i++)
		{
			double xVal = xMin + xRange * i / nXTicks;
			int px = gr.left + (int)(((xVal - xMin) / xRange) * gw);
			MoveToEx(hdc, px, gr.top, NULL);
			LineTo(hdc, px, gr.bottom);
			TCHAR buf[32];
			_stprintf_s(buf, 32, _T("%.1f"), xVal);
			TextOut(hdc, px, gr.bottom + 3, buf, lstrlen(buf));
		}

		HPEN hBorderPen = CreatePen(PS_SOLID, 1, RGB(100, 100, 130));
		SelectObject(hdc, hBorderPen);
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		::Rectangle(hdc, gr.left, gr.top, gr.right, gr.bottom);

		POINT pts[501];
		for (int i = 0; i <= N; i++)
		{
			double x = xMin + xRange * i / N;
			pts[i].x = gr.left + (long)(((x - xMin) / xRange) * gw);
			pts[i].y = gr.bottom - (long)(((fv[i] - yMin) / yRange) * gh);
		}

		COLORREF colCurve;
		OleTranslateColor(m_clrGraphColor, NULL, &colCurve);
		HPEN hCurvePen = CreatePen(PS_SOLID, 3, colCurve);
		SelectObject(hdc, hCurvePen);
		Polyline(hdc, pts, N + 1);

		int titlePx = MulDiv(10, GetDeviceCaps(hdc, LOGPIXELSY), 72);
		if (titlePx < 13) titlePx = 13;
		HFONT hTitleFont = CreateFont(-titlePx, 0, 0, 0, FW_BOLD,
			FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
		SelectObject(hdc, hTitleFont);
		SetTextColor(hdc, RGB(30, 30, 80));
		SetTextAlign(hdc, TA_CENTER | TA_BOTTOM);
		TCHAR szTitle[128];
		_stprintf_s(szTitle, 128,
			_T("f(x) = e^x / x^3 - sin^3(x),  x [%.1f, %.1f]   PolyCtl 40332"),
			m_dXMin, m_dXMax);
		TextOut(hdc, (rc.left + rc.right) / 2, gr.top - 5, szTitle, lstrlen(szTitle));

		RestoreDC(hdc, savedDC);

		DeleteObject(hGridPen);
		DeleteObject(hBorderPen);
		DeleteObject(hCurvePen);
		DeleteObject(hSmallFont);
		DeleteObject(hTitleFont);

		if (bSelectOldRgn)
			SelectClipRgn(hdc, hRgnOld);
		DeleteObject(hRgnNew);

		return S_OK;
	}

	OLE_COLOR m_clrBorderColor;
	void OnBorderColorChanged()
	{
		ATLTRACE(_T("OnBorderColorChanged\n"));
	}
	OLE_COLOR m_clrFillColor;
	void OnFillColorChanged()
	{
		ATLTRACE(_T("OnFillColorChanged\n"));
	}
	STDMETHOD(_InternalQueryService)(REFGUID /*guidService*/, REFIID /*riid*/, void** /*ppvObject*/)
	{
		return E_NOTIMPL;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
	public:
		OLE_COLOR m_clrGraphColor;
		OLE_COLOR m_clrBackColor;
	private:
		SHORT m_nSides;
		BOOL m_bGraphVisible;
		double m_dXMin;
		double m_dXMax;
		double m_dYMin;
		double m_dYMax;

	public:
		STDMETHOD(get_Sides)(SHORT* pVal);
		STDMETHOD(put_Sides)(SHORT newVal);

		STDMETHOD(get_GraphColor)(OLE_COLOR* pVal);
		STDMETHOD(put_GraphColor)(OLE_COLOR newVal);
		STDMETHOD(get_BackgroundColor)(OLE_COLOR* pVal);
		STDMETHOD(put_BackgroundColor)(OLE_COLOR newVal);

		STDMETHOD(get_XMin)(DOUBLE* pVal);
		STDMETHOD(put_XMin)(DOUBLE newVal);
		STDMETHOD(get_XMax)(DOUBLE* pVal);
		STDMETHOD(put_XMax)(DOUBLE newVal);
		STDMETHOD(get_YMin)(DOUBLE* pVal);
		STDMETHOD(put_YMin)(DOUBLE newVal);
		STDMETHOD(get_YMax)(DOUBLE* pVal);
		STDMETHOD(put_YMax)(DOUBLE newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(PolyCtl), CPolyCtl)
