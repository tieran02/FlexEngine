#include "Flex.h"

class Sandbox : public Flex::Application
{
public:
	Sandbox(){}
	~Sandbox() override{}
};

Flex::Application* Flex::CreateApplication()
{
	return new Sandbox();

}