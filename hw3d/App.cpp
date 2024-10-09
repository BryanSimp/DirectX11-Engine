#include "App.h"

App::App()
	:
	wnd(800, 600, "Bryan Simpson DirectX 11")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	const float c2 = cos(timer.Peek()) / 2.0f + 0.5f;
	const float c3 = tan(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c2, c3);
	wnd.Gfx().EndFrame();
}