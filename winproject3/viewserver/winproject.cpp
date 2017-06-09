/*
Maria Loza
CST 320 SECTION 01
Dr. Eckhardt
Date Created: 24 August 2016
Due Date: 2 September 2016


*/

/*
Problem:
The assignment wants a simple version of Arkanoid.
The ball will be a rectangle, which bounces from the walls and ceiling. The rectangle will
also bounce from the shuffle (paddle). The shuffle will be located close to the bottom of
the program. It will also be control by the player's mouse.
The program will end upon the rectangle hitting the bottom line.

Solution:
The rectangle will be created using four draw_line functions. But I will also test it out with 
the SetPixel function since it can create a rectangle based of the homework example. 
The rectangle will move by switching between positive and negative numbers (+-1) for the ix and iy.
The start x direction will be a +1.
The start y direction will be a -1.
If the rectangle's x position is >= 500 then change the ix to -1 or <= 0 then change the ix to +1.
If the rectangle's y position is <= 0 then change the iy to +1 or >= 500 then end the game.


*/

#include "ground.h"



#define MAX_LOADSTRING 1000
// Globale Variablen:
HINSTANCE hInst;								// Aktuelle Instanz
TCHAR szTitle[MAX_LOADSTRING];					// Titelleistentext
TCHAR szWindowClass[MAX_LOADSTRING];			// Klassenname des Hauptfensters
HFONT editfont;
HWND hMain = NULL;
//-----------------------
static char MainWin[] = "MainWin";

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void draw_line(HDC DC, int x, int y, int a, int b, int red, int green, int blue, int width);

HBRUSH  hWinCol = CreateSolidBrush(RGB(180, 180, 180));

HWND g_hwnd=NULL;

//int dx = 0, dy = 0;
int px = 230; //x position of the paddle



//timer:
#define TIMER1 111

// Vorwärtsdeklarationen der in diesem Codemodul enthaltenen Funktionen:
/*ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

*/

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{

	
	hInst = hInstance;												//						save in global variable for further use
	// TODO: Hier Code einfügen.
	MSG msg;
	
	// Globale Zeichenfolgen initialisieren
	LoadString(hInstance, 103, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, 104, szWindowClass, MAX_LOADSTRING);
	//register Window													<<<<<<<<<<			STEP ONE: REGISTER WINDOW						!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	WNDCLASSEX wcex;												//						=> Filling out struct WNDCLASSEX
	BOOL Result = TRUE;
	wcex.cbSize = sizeof(WNDCLASSEX);								//						size of this struct (don't know why
	wcex.style = CS_HREDRAW | CS_VREDRAW;							//						?
	wcex.lpfnWndProc = (WNDPROC)WndProc;							//						The corresponding Proc File -> Message loop switch-case file
	wcex.cbClsExtra = 0;											//
	wcex.cbWndExtra = 0;											//
	wcex.hInstance = hInstance;										//						The number of the program
	wcex.hIcon = LoadIcon(hInstance, NULL);							//
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);						//
	wcex.hbrBackground = hWinCol;									//						Background color
	wcex.lpszMenuName = NULL;										//
	wcex.lpszClassName = MainWin;									//						Name of the window (must the the same as later when opening the window)
	wcex.hIconSm = LoadIcon(wcex.hInstance, NULL);					//
	Result = (RegisterClassEx(&wcex) != 0);							//						Register this struct in the OS

				//													STEP TWO: OPENING THE WINDOW with x,y position and xlen, ylen !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	hMain = CreateWindow(MainWin, "TestWin CST 320", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, hInst, NULL);
	if (!hMain)return 0;
	ShowWindow(hMain, nCmdShow);
	UpdateWindow(hMain);

	//													STEP THRE: Going into the infinity message loop							  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Hauptmeldungsschleife:
	bool quit = FALSE;
	while (!quit)
	{
		//if (GetMessage(&msg, NULL, 0, 0) > 0)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) == TRUE)
		{
			if (msg.message == WM_QUIT){ quit = TRUE; break; }

			
				TranslateMessage(&msg);								//						IF a meessage occurs, the WinProc will be called!!!!
				DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}
///////////////////////////////////////////////////
void redr_win_full(HWND hwnd, bool erase)
	{
	RECT rt;
	GetClientRect(hwnd, &rt);
	InvalidateRect(hwnd, &rt, erase);
	}
void draw_text(HDC DC,char text[], int x, int y, int r, int g, int b)
	{
	COLORREF rgb = RGB(r, g, b);
	SetTextColor(DC, rgb);
	SetBkMode(DC, TRANSPARENT);
	TextOut(DC, x, y, text, strlen(text));
	}
///////////////////////////////////
//		This Function is called every time the Left Mouse Button is down
///////////////////////////////////
void OnLBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}
///////////////////////////////////
//		This Function is called every time the Right Mouse Button is down
///////////////////////////////////
void OnRBD(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
	{
	
	}
///////////////////////////////////
//		This Function is called every time a character key is pressed
///////////////////////////////////
void OnChar(HWND hwnd, UINT ch, int cRepeat)
{

}
///////////////////////////////////
//		This Function is called every time the Left Mouse Button is up
///////////////////////////////////
void OnLBU(HWND hwnd, int x, int y, UINT keyFlags)
{

	
}
///////////////////////////////////
//		This Function is called every time the Right Mouse Button is up
///////////////////////////////////
void OnRBU(HWND hwnd, int x, int y, UINT keyFlags)
	{
	

	}
///////////////////////////////////
//		This Function is called every time the Mouse Moves
///////////////////////////////////
void OnMM(HWND hwnd, int x, int y, UINT keyFlags)
{

	px = x;
	//dy = y;

if ((keyFlags & MK_LBUTTON) == MK_LBUTTON)
	{
	}

if ((keyFlags & MK_RBUTTON) == MK_RBUTTON)
	{
	}
}
///////////////////////////////////
//		This Function is called once at the begin of a program
///////////////////////////////////
#define TIMER1 1

BOOL OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct)
{
g_hwnd = hwnd;
	editfont = CreateFont(-10, 0, 0, 0, 0, FALSE, 0, 0, 0, 0, 0, 0, 0, "Arial");	
	if (!SetTimer(hwnd, TIMER1, 5, NULL))
		{
		MessageBox(hwnd, "No Timers Available", "Info", MB_OK);
		return FALSE;
		}
	
	return TRUE;
}

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	HWND hwin;
	
	switch (id)
	{
	default:
		break;
	}

}
//************************************************************************
int rx = 200, ry = 200; //position of the rectangle-ball
int ix = 1, iy = -1;
void OnTimer(HWND hwnd, UINT id)
	{
		rx = rx + ix;
		ry = ry + iy;

		if (rx >= 450) {
			ix = -1;
		}
		if (rx <= 0){
			ix = 1;
		}
		if (ry <= 0) {
			iy = 1;
		}
		if (ry >= 430) {
			PostQuitMessage(0);
		}
		if (ry >= 370 && (px - 64 <= rx && rx <= px + 64)) {
			iy = -1;
		}
	redr_win_full(hwnd, FALSE);
	}
//************************************************************************
///////////////////////////////////
//		This Function is called every time the window has to be painted again
///////////////////////////////////


void OnPaint(HWND hwnd)
	{
	PAINTSTRUCT PaintStruct;
	double_buffer_ doublebuffer;
	HDC dc = doublebuffer.begin(hwnd, &PaintStruct, RGB(255, 255, 255));
	
	draw_text(dc, "ARKANOID", 50, 50, 0, 0, 0);
	/*for (int yy = ry; yy < 230; yy++)
		for (int xx = rx; xx < 240; xx++)
			SetPixel(dc, xx, yy, RGB(0, 200, 0));
	*/

	draw_line(dc, rx, ry, rx+35, ry, 0, 0, 255, 5); //top horizontal line for rect.
	draw_line(dc, rx, ry+25, rx+35, ry+25, 0, 0, 255, 5); //bottom horizontal line for rect.

	draw_line(dc, rx, ry, rx, ry+25, 0, 0, 255, 5); //left vertical line for rect.
	draw_line(dc, rx+35, ry, rx+35, ry+25, 0, 0, 255, 5); //right vertical line for rect.

	draw_line(dc, px - 30, 400, px + 30, 400, 255, 0, 0, 5); //paddle



	doublebuffer.end();
	}
//****************************************************************************

void draw_line(HDC DC,int x, int y, int a, int b, int red, int green, int blue, int width)
	{
	HPEN Stift = CreatePen(PS_SOLID, width, RGB(red, green, blue));
	SelectObject(DC, Stift);
	MoveToEx(DC, x, y, NULL);
	LineTo(DC, a, b);
	DeleteObject(Stift);
	}
//*************************************************************************
void OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
	{

	switch (vk)
		{
			default:break;
			
		}
	}

//*************************************************************************
void OnKeyUp(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
	{
	switch (vk)
		{
			default:break;
			
		}

	}


//**************************************************************************
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	SCROLLINFO si;


	
	switch (message)
	{
	/*
	#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_##message((hwnd), (wParam), (lParam), (fn))
	*/
		
		HANDLE_MSG(hwnd, WM_CHAR, OnChar);
		HANDLE_MSG(hwnd, WM_LBUTTONDOWN, OnLBD);
		HANDLE_MSG(hwnd, WM_LBUTTONUP, OnLBU);
		HANDLE_MSG(hwnd, WM_MOUSEMOVE, OnMM);	
		HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
		HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
		HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
		HANDLE_MSG(hwnd, WM_TIMER, OnTimer);
		HANDLE_MSG(hwnd, WM_KEYDOWN, OnKeyDown);
		HANDLE_MSG(hwnd, WM_KEYUP, OnKeyUp);

	case WM_ERASEBKGND:
		return (LRESULT)1;
	case WM_DESTROY:
		
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
