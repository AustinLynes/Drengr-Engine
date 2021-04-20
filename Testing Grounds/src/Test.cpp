#include <Drengr.h>
#include <core/application/Application.h>

namespace Drengr {

	class EngineTest : public Application {
	public:
		EngineTest() {

		}
		
		~EngineTest() {

		}

	};

	Application* CreateApplication() { return new EngineTest(); }

}