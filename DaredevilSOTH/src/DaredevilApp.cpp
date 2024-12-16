#include <CIEngine.h>

class DaredevilSOTH : public CIEngine::Application
{
public:
	DaredevilSOTH()
	{

	}

	~DaredevilSOTH()
	{

	}

};

CIEngine::Application* CIEngine::CreateApplication()
{
	return new DaredevilSOTH();
}
