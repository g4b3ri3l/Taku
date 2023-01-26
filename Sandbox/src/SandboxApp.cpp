#include <Taku.h>

class Sandbox : public Taku::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Taku::Application* Taku::CreateApplication()
{
	return new Sandbox();
}
