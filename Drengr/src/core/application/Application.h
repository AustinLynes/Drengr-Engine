#pragma once

#include <Drengr.h>
#include <core/window/Window.h>
// window
#include <optional>

/// <summary>
/// SINGLETON APPLICATION BASE-BACK-END CLASS
/// ---------------------> CLIENT WILL HAVE TO CREATE THEIR OWN INSTANCE OF A
/// ---------------------> HEAP ALLOCATED APPLICATION PTR FOR DRENGR TO RUN.
/// </summary>

namespace Drengr {

	class Application
	{
	public:
		Application();
		virtual ~Application();
	
		std::optional<int> Run();
	private:
		// allocate a window ptr on the heap
		Window* window = nullptr;
		Application* instance = nullptr; 
	};

	Application* CreateApplication();
}

