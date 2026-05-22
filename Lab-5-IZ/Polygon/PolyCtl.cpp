// PolyCtl.cpp: реализация CPolyCtl
#include "pch.h"
#include "PolyCtl.h"


// CPolyCtl

STDMETHODIMP CPolyCtl::get_Sides(SHORT* pVal)
{
	*pVal = m_nSides;
	return S_OK;
}


STDMETHODIMP CPolyCtl::put_Sides(SHORT newVal)
{
	if (newVal < 3) {
		return Error("Колличество сторон не может быть меньше 3.");
	}
	if (newVal > 10) {
		return Error("Колличество сторон не должно быть больше 10.");
	}
	m_nSides = newVal;
	FireViewChange();
	return S_OK;
}

// GraphColor
STDMETHODIMP CPolyCtl::get_GraphColor(OLE_COLOR* pVal)
{
	*pVal = m_clrGraphColor;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_GraphColor(OLE_COLOR newVal)
{
	m_clrGraphColor = newVal;
	FireViewChange();
	return S_OK;
}

// BackgroundColor
STDMETHODIMP CPolyCtl::get_BackgroundColor(OLE_COLOR* pVal)
{
	*pVal = m_clrBackColor;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_BackgroundColor(OLE_COLOR newVal)
{
	m_clrBackColor = newVal;
	FireViewChange();
	return S_OK;
}

// XMin
STDMETHODIMP CPolyCtl::get_XMin(DOUBLE* pVal)
{
	*pVal = m_dXMin;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_XMin(DOUBLE newVal)
{
	if (newVal >= m_dXMax)
		return Error("XMin должен быть меньше XMax.");
	m_dXMin = newVal;
	FireViewChange();
	return S_OK;
}

// XMax
STDMETHODIMP CPolyCtl::get_XMax(DOUBLE* pVal)
{
	*pVal = m_dXMax;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_XMax(DOUBLE newVal)
{
	if (newVal <= m_dXMin)
		return Error("XMax должен быть больше XMin.");
	m_dXMax = newVal;
	FireViewChange();
	return S_OK;
}

// YMin
STDMETHODIMP CPolyCtl::get_YMin(DOUBLE* pVal)
{
	*pVal = m_dYMin;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_YMin(DOUBLE newVal)
{
	if (newVal >= m_dYMax)
		return Error("YMin должен быть меньше YMax.");
	m_dYMin = newVal;
	FireViewChange();
	return S_OK;
}

// YMax
STDMETHODIMP CPolyCtl::get_YMax(DOUBLE* pVal)
{
	*pVal = m_dYMax;
	return S_OK;
}

STDMETHODIMP CPolyCtl::put_YMax(DOUBLE newVal)
{
	if (newVal <= m_dYMin)
		return Error("YMax должен быть больше YMin.");
	m_dYMax = newVal;
	FireViewChange();
	return S_OK;
}

void CPolyCtl::CalcPoints(const RECT& rc)
{
	const double pi = 3.14159265358979;
	POINT ptCenter;
	double dblRadiusx = (rc.right - rc.left) / 2;
	double dblRadiusy = (rc.bottom - rc.top) / 2;
	double dblAngle = 3 * pi / 2; // Start at the top
	double dblDiff = 2 * pi / m_nSides; // Angle each side will make
	ptCenter.x = (rc.left + rc.right) / 2;
	ptCenter.y = (rc.top + rc.bottom) / 2;
	// Calculate the points for each side
	for (int i = 0; i < m_nSides; i++)
	{
		m_arrPoint[i].x = (long)(dblRadiusx * cos(dblAngle
		) + ptCenter.x + 0.5);
		m_arrPoint[i].y = (long)(dblRadiusy * sin(dblAngle
		) + ptCenter.y + 0.5);
		dblAngle += dblDiff;
	}
}

LRESULT CPolyCtl::OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	WORD xPos = LOWORD(lParam);
	WORD yPos = HIWORD(lParam);

	if (m_bGraphVisible)
	{
		MessageBox(_T("Ошибка: график уже отображён!"),
			_T("PolyCtl"), MB_OK | MB_ICONWARNING);
	}
	else
	{
		m_bGraphVisible = TRUE;
		FireViewChange();
	}

	Fire_LButton(xPos, yPos);
	return 0;
}

LRESULT CPolyCtl::OnRButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	WORD xPos = LOWORD(lParam);
	WORD yPos = HIWORD(lParam);

	if (!m_bGraphVisible)
	{
		MessageBox(_T("Ошибка: график уже скрыт!"),
			_T("PolyCtl"), MB_OK | MB_ICONWARNING);
	}
	else
	{
		m_bGraphVisible = FALSE;
		FireViewChange();
	}

	Fire_RButton(xPos, yPos);
	return 0;
}