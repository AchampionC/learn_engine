#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hIntance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow)
{
	HWND hWnd;

	WNDCLASSEX  wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hIntance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = _T("WindowClass1");

	// register the window class
	RegisterClassEx(&wc);

	// create the window
	hWnd = CreateWindowEx(0, _T("WindowClass1"), _T("Hello, Engine"), WS_OVERLAPPEDWINDOW, 300, 300, 500, 400, NULL, NULL, hIntance, NULL);

	ShowWindow(hWnd, nCmdShow);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			RECT rec = {20, 20, 60, 80};
			HBRUSH brush = (HBRUSH) GetStockObject(BLACK_BRUSH);

			FillRect(hdc, &rec, brush);

			EndPaint(hWnd, &ps);
		}
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}