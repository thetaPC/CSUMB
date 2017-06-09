#define WIN32_LEAN_AND_MEAN  
#include <windows.h>
#include <windowsx.h>
#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <time.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <fstream>
using namespace std;
#include <direct.h>
#include <commdlg.h>
#include <malloc.h>
#include <cmath>
#include <string.h>
#include <tchar.h>

class double_buffer_
	{
	private:
		HWND failsavehwnd;
		HDC m_dc, m_DC;
		HBITMAP hbmMem, hbmOld;
		PAINTSTRUCT *ps;
		bool sub_dc;
		RECT drawrect;
	public:
		double_buffer_()
			{
			sub_dc = FALSE;
			failsavehwnd = NULL;
			ps = NULL;
			m_dc = m_DC = NULL;
			}
		~double_buffer_()
			{
			if (failsavehwnd)
				end();
			}
		HDC begin(HWND hwnd, HDC dc_parent, COLORREF bg, RECT rect)
			{
			failsavehwnd = hwnd;
			sub_dc = TRUE;
			m_DC = dc_parent;
			m_dc = CreateCompatibleDC(m_DC);
			RECT rc;
			GetClientRect(hwnd, &rc);
			hbmMem = CreateCompatibleBitmap(m_DC, rc.right - rc.left, 2000);
			hbmOld = (HBITMAP)SelectObject(m_dc, hbmMem);
			HBRUSH hbrBkGnd = CreateSolidBrush(bg);
			FillRect(m_dc, &rc, hbrBkGnd);
			DeleteObject(hbrBkGnd);
			drawrect = rect;
			ps = NULL;
			return m_dc;
			}
		HDC begin(HWND hwnd, PAINTSTRUCT *PaintStruct, COLORREF bg)
			{
			ps = PaintStruct;
			failsavehwnd = hwnd;
			m_DC = BeginPaint(hwnd, PaintStruct);
			m_dc = CreateCompatibleDC(m_DC);
			RECT rc;
			GetClientRect(hwnd, &rc);
			hbmMem = CreateCompatibleBitmap(m_DC, rc.right - rc.left, 2000);
			hbmOld = (HBITMAP)SelectObject(m_dc, hbmMem);
			HBRUSH hbrBkGnd = CreateSolidBrush(bg);
			FillRect(m_dc, &rc, hbrBkGnd);
			DeleteObject(hbrBkGnd);
			return m_dc;
			}

		void end()
			{
			RECT rc;
			if (!failsavehwnd)return;
			GetClientRect(failsavehwnd, &rc);
			if (m_DC && m_dc)
				{
				if (!sub_dc)	BitBlt(m_DC, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, m_dc, 0, 0, SRCCOPY);
				else			BitBlt(m_DC, drawrect.left, drawrect.top, drawrect.right, drawrect.bottom, m_dc, drawrect.left, drawrect.top, SRCCOPY);
				}
			SelectObject(m_dc, hbmOld);
			if (hbmMem)	DeleteObject(hbmMem);
			if (m_dc)	DeleteDC(m_dc);
			if (ps)		EndPaint(failsavehwnd, ps);
			failsavehwnd = NULL;
			}
	};
