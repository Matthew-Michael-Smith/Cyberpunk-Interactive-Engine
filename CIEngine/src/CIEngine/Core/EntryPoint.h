#pragma once

#ifdef CIE_PLATFORM_WINDOWS

extern CIEngine::Application* CreateApplcation();

int main(int argc, char** argv)
{
	CIEngine::Log::Init();
	CIE_CORE_WARN("Initialized Log!");
	int a = 5;
	CIE_INFO("Daredevil: Shadow of the Hand Var={0}", a);


	auto app = CIEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif