//
// Created by tieran on 24/08/2019.
//
#include "pchheader.h"
#include <Platform/Vulkan/VulkanRenderContext.h>
#include "Platform/Vulkan/VulkanRenderer.h"

namespace Flex
{
    std::unique_ptr<VulkanRenderer> VulkanRenderer::Create()
    {
        return std::make_unique<VulkanRenderer>();
    }

    VulkanRenderer::VulkanRenderer()
    {
        setup();
    }

    VulkanRenderer::~VulkanRenderer()
    {
        cleanup();
    }

    void VulkanRenderer::setup()
    {
        FL_LOG_CORE_INFO("Creating Vulkan Renderer");
        //Create context
        m_renderContext = VulkanRenderContext::Create();
        FL_LOG_CORE_INFO("Created Vulkan Renderer");
    }

    void VulkanRenderer::cleanup()
    {
        //clean up context first
        m_renderContext.reset();

        FL_LOG_CORE_INFO("Cleaning up Vulkan Renderer");
    }
}