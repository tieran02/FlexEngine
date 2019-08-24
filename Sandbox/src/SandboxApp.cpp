#include "Flex.h"

class ExampleLayer : public Flex::ILayer
{
public:
	ExampleLayer() : ILayer("Example")
	{

	}

    ~ExampleLayer() override
    {

    }

	void OnUpdate() override
	{

	}

	void OnEvent(Flex::Event& event) override
	{
		FL_LOG_TRACE("{0}", event);
	}

    void OnAttach() override
    {

    }

    void OnDetach() override
    {

    }
};


class Sandbox : public Flex::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() override = default;
};

Flex::Application* Flex::CreateApplication()
{
	FL_LOG_INFO("Client initilised");
	return new Sandbox();
}