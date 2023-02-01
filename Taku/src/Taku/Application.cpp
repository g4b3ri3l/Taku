#include "tkpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Taku {

	Taku::Application::Application()
	{
	}

	Taku::Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TK_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TK_TRACE(e);
		}
		while (true);
	}
}

