#pragma once

#include <Drengr.h>

// window class
// the window needs to 
// register its class
//		* needs a message pump
//		* needs wndProc override
// 
// create a window 
//	* needs to know:
//		* client rect - width height, x & y position
//			* used to resume WINDOWED mode from FULLSCREEN mode
//		* window rect - width height, x & y position 
//		

namespace Drengr {

	enum class DisplayMode {
		WINDOWED = 0,
		WINDOWED_BORDERLESS = 1,
		FULLSCREEN = 2
	};

	class Window
	{
	public:
		Window() = default;
		~Window();
		HRESULT Create();
		void Show();
		bool ProcessMessages();
	private:
		const wchar_t* ClassName();
		static LRESULT CALLBACK proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		HWND hWnd;
		DisplayMode displayMode;

	};

}
