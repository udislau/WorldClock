#pragma once

#ifdef WORLDCLOCK_PLATFORM_WINDOWS

extern WorldClock::Application* WorldClock::CreateApplication();

int main(int argc, char** argv)
{
	auto app = WorldClock::CreateApplication();
	app->Run();
	delete app;
}
#endif