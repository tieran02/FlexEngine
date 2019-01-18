#include "Flex.h"

class ExampleLayer : public Flex::Layer
{
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override
	{
		FL_LOG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Flex::Event& event) override
	{
		FL_LOG_TRACE("{0}", event);
	}
};


class Sandbox : public Flex::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() override{}
};

Flex::Application* Flex::CreateApplication()
{
	FL_LOG_INFO("Client initilised");
	return new Sandbox();
}