#pragma once

#ifdef TK_PLATFORM_WINDOWS

extern Taku::Application* Taku::CreateApplication();

int main(int argc, char** argv)
{
	printf("Taku Engine\n");
	auto app = Taku::CreateApplication();
	app->Run();
	delete app;
}

#endif
