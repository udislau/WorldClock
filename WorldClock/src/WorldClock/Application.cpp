#include "PreCompiledHeaders.h"
#include "Application.h"

#include "WorldClock/Events/ApplicationEvent.h"
#include "WorldClock/Log.h"

namespace WorldClock {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			WORLDCLOCK_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			WORLDCLOCK_TRACE(e);
		}

		while (true);
	}
}
