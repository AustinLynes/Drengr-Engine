#include "Window.h"

Drengr::Window::~Window()
{
	hWnd = NULL;
}

HRESULT Drengr::Window::Create()
{
	WNDCLASSEXW wc = {0};
	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = proc;
	wc.lpszClassName = ClassName();

	THROW_IF_FAILED(RegisterClassExW(&wc));
	
	
	DWORD style = WS_OVERLAPPEDWINDOW;

	DWORD exStyle = WS_EX_OVERLAPPEDWINDOW; // WS_EX_WINDOWEDGE WS_EX_CLIENTEDGE

	RECT desired_size = { 50, 50, 1280, 720};
	
	AdjustWindowRectEx(&desired_size, style, NULL, exStyle);

	hWnd = CreateWindowExW(
		exStyle,
		ClassName(),
		L"Drengr Engine", // move to config 
		style,
		desired_size.left,
		desired_size.top,
		desired_size.right - desired_size.left,
		desired_size.bottom - desired_size.top,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		this
	);

	return hWnd != NULL ? S_OK : E_HANDLE;

}

void Drengr::Window::Show() {
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

bool Drengr::Window::ProcessMessages()
{
	MSG msg = {};
	// just process messages as they come up dont block...
	if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {

		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return true;
}

const wchar_t* Drengr::Window::ClassName()
{
	return L"MAIN WINDOW";
}

LRESULT Drengr::Window::proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_KEYDOWN:
			OutputDebugStringW(L"Hey!\n");
			break;
		default:
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}
}
