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

static CIEngine::Application* CIEngine::CreateApplication()
{
	return new DaredevilSOTH();
}
