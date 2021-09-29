#pragma once

#ifdef WORLDCLOCK_PLATFORM_WINDOWS

extern WorldClock::Application* WorldClock::CreateApplication();

int main(int argc, char** argv)
{
	WorldClock::Log::Init();
	WORLDCLOCK_CORE_WARN("Initialized Log!");
	WORLDCLOCK_CORE_INFO("Hi!");

	auto app = WorldClock::CreateApplication();
	app->Run();
	delete app;
}
#endif