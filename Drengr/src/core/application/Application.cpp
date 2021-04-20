#include "Application.h"

namespace Drengr {

	Application::Application()
	{
		if (instance != nullptr)
			THROW("INSTANCE ALREADY EXISTS");

		instance = this;
		
		window = new Window();
		THROW_IF_FAILED(window->Create());
		
		window->Show();

	}

	Application::~Application()
	{
	}

	std::optional<int> Application::Run()
	{
		// hmm... will this approach block?
		while (window->ProcessMessages()) {
			// render

			// update

		}
		return {};
	}

}