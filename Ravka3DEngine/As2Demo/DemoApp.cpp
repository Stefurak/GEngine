#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include <JADEngine\GameEngine.h>

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>



long windowWidth = 1024;
long windowHeight = 768;
long windowBits = 32;
bool fullscreen = false;

HDC hDC;
GameEngine engine;
bool windowIsOpen = true;

void SetupPixelFormat(HDC hDC)
{
	int pixelFormat;

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),	// size
		1,							// version
		PFD_SUPPORT_OPENGL |		// OpenGL window
		PFD_DRAW_TO_WINDOW |		// render to window
		PFD_DOUBLEBUFFER,			// support double-buffering
		PFD_TYPE_RGBA,				// color type
		32,							// prefered color depth
		0, 0, 0, 0, 0, 0,			// color bits (ignored)
		0,							// no alpha buffer
		0,							// alpha bits (ignored)
		0,							// no accumulation buffer
		0, 0, 0, 0,					// accum bits (ignored)
		16,							// depth buffer
		0,							// no stencil buffer
		0,							// no auxiliary buffers
		PFD_MAIN_PLANE,				// main layer
		0,							// reserved
		0, 0, 0,					// no layer, visible, damage masks
	};

	pixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, pixelFormat, &pfd);
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HDC hDC;
	static HGLRC hRC;
	int height, width;

	// dispatch messages
	switch (uMsg)
	{
	case WM_CREATE:			// window creation
		hDC = GetDC(hWnd);
		SetupPixelFormat(hDC);
		//SetupPalette();
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		//HDApplication::getRunningApp()->onCreate();
		break;

	case WM_DESTROY:			// window destroy
	case WM_QUIT:
	case WM_CLOSE:					// windows is closing

		// deselect rendering context and delete it
		//HDApplication::getRunningApp()->stopRunning();
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		// send WM_QUIT to message queue
		PostQuitMessage(0);
		break;

	case WM_SIZE:
		height = HIWORD(lParam);		// retrieve width and height
		width = LOWORD(lParam);

		//HDApplication::getRunningApp()->setWindowSize(width, height);

		break;

	case WM_ACTIVATEAPP:		// activate app
		break;

	case WM_PAINT:				// paint
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:		// left mouse button
		break;

	case WM_RBUTTONDOWN:		// right mouse button
		break;

	case WM_MOUSEMOVE:			// mouse movement
		break;

	case WM_LBUTTONUP:			// left button release
		break;

	case WM_RBUTTONUP:			// right button release
		break;

	case WM_KEYUP:
		/*if(HDApplication::getRunningApp()->deliverKeyUpEvents())
		{
		HDApplication::getRunningApp()->handleKeyUpEvent((int)wParam, (short)lParam & 0x000000000000FFFF);
		}*/
		break;

	case WM_KEYDOWN:
		int fwKeys;
		LPARAM keyData;
		fwKeys = (int)wParam;    // virtual-key code 
		keyData = lParam;          // key data 

		switch (fwKeys)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		default:
			/*if(HDApplication::getRunningApp()->deliverKeyDownEvents())
			{
			HDApplication::getRunningApp()->handleKeyDownEvent((int)wParam, (short)lParam & 0x000000000000FFFF);
			}*/
			break;
		}

		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX windowClass;		// window class
	HWND	   hwnd;			// window handle
	MSG		   msg;				// message
	DWORD	   dwExStyle;		// Window Extended Style
	DWORD	   dwStyle;			// Window Style
	RECT	   windowRect;

	//////////////////////////////////////////////////////////////
	// User should create the desired type of HDApplication here
	//////////////////////////////////////////////////////////////
	//hdApp = new TrialApp();

	windowRect.left = (long)0;						// Set Left Value To 0
	windowRect.right = (long)1024;// HDApplication::getRunningApp()->getProperties().getPreferredWindowWidth();	// Set Right Value To Requested Width
	windowRect.top = (long)0;							// Set Top Value To 0
	windowRect.bottom = (long)1024;// HDApplication::getRunningApp()->getProperties().getPreferredWindowHeight();	// Set Bottom Value To Requested Height

	// fill out the window class structure
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = MainWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// default icon
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// default arrow
	windowClass.hbrBackground = NULL;								// don't need background
	windowClass.lpszMenuName = NULL;								// no menu
	windowClass.lpszClassName = "GLClass";
	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);		// windows logo small icon

	// register the windows class
	if (!RegisterClassEx(&windowClass))
		return 0;

	//fullscreen = HDApplication::getRunningApp()->getProperties().getStartFullscreen();

	if (fullscreen)								// fullscreen?
	{
		DEVMODE dmScreenSettings;					// device mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = 512;// HDApplication::getRunningApp()->getProperties().getPreferredWindowWidth();			// screen width
		dmScreenSettings.dmPelsHeight = 512;// HDApplication::getRunningApp()->getProperties().getPreferredWindowHeight();			// screen height
		dmScreenSettings.dmBitsPerPel = windowBits;				// bits per pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// 
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// setting display mode failed, switch to windowed
			MessageBox(NULL, "Display mode failed", NULL, MB_OK);
			fullscreen = FALSE;
		}
	}

	if (fullscreen)								// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;					// Window Extended Style
		dwStyle = WS_POPUP;						// Windows Style
		ShowCursor(FALSE);						// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;					// Windows Style
	}

	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// class registered, so now create our window
	hwnd = CreateWindowEx(NULL,									// extended style
		"GLClass",							// class name
		"DemoApp_Assignment1_Derochie_Jesse",
		dwStyle | WS_CLIPCHILDREN |
		WS_CLIPSIBLINGS,
		0, 0,								// x,y coordinate
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top, // width, height
		NULL,								// handle to parent
		NULL,								// handle to menu
		hInstance,							// application instance
		NULL);								// no extra params

	hDC = GetDC(hwnd);

	// check if window creation failed (hwnd would equal NULL)
	if (!hwnd)
		return 0;

	ShowWindow(hwnd, SW_SHOW);			// display the window
	UpdateWindow(hwnd);					// update the window

	engine.onStart();

	while (windowIsOpen)
	{
		engine.clearScreen();
		engine.render(PrimitiveTypeDef::QUAD);
		//engine.render(PrimitiveTypeDef::CUBE);
		//engine.render(ModelType::CUBE);
		//engine.render(PrimitiveTypeDef::TRIANGLE);
		//engine.render(PrimitiveTypeDef::LINE);
		//engine.render(PrimitiveTypeDef::POINT);


		SwapBuffers(hDC);
		

		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0))
			{
				windowIsOpen = false;
				break;
			}


			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	if (fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);						// Show Mouse Pointer
	}

	return (int)msg.wParam;
}