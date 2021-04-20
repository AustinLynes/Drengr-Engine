
#include <Drengr.h>
#include <core/application/Application.h>

#include <d3d12.h>



#define DRAPI WINAPI

extern Drengr::Application* Drengr::CreateApplication();
#ifdef WIN32

	int WINAPI WinMain(
		_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPSTR nCmdLine,
		_In_ int nCmdShow
	) {
		// application is created on client side on the heap.
		// grab ptr to application
		auto application = Drengr::CreateApplication();
		
		// run the application. 
		// if an error code is returned.
		// exit with error code
		if (auto eCode = application->Run()) {
			return *eCode;
		}
		// there where no errors during runtime of application
		// return success 0
		return 0;
	
	}

	
#else
#error Windows is only supported at the moment. please check back later for future releases with MacOS implementations being next to come.
#endif