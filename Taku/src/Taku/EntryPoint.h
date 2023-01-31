#pragma once

#ifdef TK_PLATFORM_WINDOWS

extern Taku::Application* Taku::CreateApplication();

int main(int argc, char** argv)
{
	Taku::Log::Init();
	TK_CORE_WARN("Initialized Log!");
	int a = 5;
	TK_INFO("Hello! Var={0}", a);


	auto app = Taku::CreateApplication();
	app->Run();
	delete app;
}

#endif
