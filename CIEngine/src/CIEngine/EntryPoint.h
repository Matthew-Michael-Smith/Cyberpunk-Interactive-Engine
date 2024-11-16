#pragma once

#ifdef CIE_PLATFORM_WINDOWS

extern CIEngine::Application* CreateApplcation();

int main(int argc, char** argv)
{
	auto app = CIEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif