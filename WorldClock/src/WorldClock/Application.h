#pragma once

#include "Core.h"

namespace WorldClock {

	class WORLDCLOCK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// TO BE defined by CLIENT
	Application* CreateApplication();

}



