#include "Flex.h"

class Sandbox : public Flex::Application
{
public:
	Sandbox(){}
	~Sandbox() override{}
};

Flex::Application* Flex::CreateApplication()
{
	FL_LOG_INFO("Client initilised");
	return new Sandbox();
}