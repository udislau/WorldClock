#include <WorldClock.h>

class Sandbox : public WorldClock::Application {
public:
	Sandbox(){
	}
	~Sandbox(){
	}
};

WorldClock::Application* WorldClock::CreateApplication()
{
	return new Sandbox();
}