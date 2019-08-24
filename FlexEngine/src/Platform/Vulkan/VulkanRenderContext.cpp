//
// Created by tieran on 24/08/2019.
//
#include <flpch.h>
#include "Platform/Vulkan/VulkanRenderContext.h"
#include <memory>
#include <Flex/Application.h>

namespace Flex
{
    std::unique_ptr<VulkanRenderContext> VulkanRenderContext::Create()
    {
        return std::make_unique<VulkanRenderContext>();
    }

    VulkanRenderContext::VulkanRenderContext()
    {
        create();
    }

    VulkanRenderContext::~VulkanRenderContext()
    {
        cleanup();
    }

    void VulkanRenderContext::create()
    {
        FL_LOG_CORE_INFO("Creating Vulkan Render Context");
        createInstance();
        FL_LOG_CORE_INFO("Created Vulkan Render Context");

    }

    void VulkanRenderContext::cleanup()
    {
        FL_LOG_CORE_INFO("Cleaning up Vulkan Render Context ");
        m_vkInstance.destroy();
    }

    void VulkanRenderContext::createInstance()
    {
        vk::ApplicationInfo appInfo;
        appInfo.pApplicationName = "Flex Engine";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Flex Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;


        vk::InstanceCreateInfo createInfo;
        createInfo.pApplicationInfo = &appInfo;

        //get GLFW extensions
        auto glfwExtensions = Application::Instance().GetWindow().VulkanExtensions();
        createInfo.enabledExtensionCount = glfwExtensions.size();
        createInfo.ppEnabledExtensionNames = glfwExtensions.data();
        createInfo.enabledLayerCount = 0;

        m_vkInstance = vk::createInstance(createInfo);
        FL_CORE_ASSERT(m_vkInstance, "Failed to create vulkan instance");

    }
}