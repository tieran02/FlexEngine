#pragma once


#include <Flex/Rendering/IRenderContext.h>
#include <memory>
#include <vulkan/vulkan.hpp>

namespace Flex
{
    class VulkanRenderContext : public IRenderContext {
    public:
        static std::unique_ptr<VulkanRenderContext> Create();
        VulkanRenderContext();
        ~VulkanRenderContext() override;

    private:
        vk::Instance m_vkInstance;

        void create() override;
        void cleanup() override;

        void createInstance();
    };
}