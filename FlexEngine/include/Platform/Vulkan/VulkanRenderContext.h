#pragma once
#include <Flex/Rendering/IRenderContext.h>
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
        VkDebugUtilsMessengerEXT debugMessenger;

        void create() override;
        void cleanup() override;

        void createInstance();
        bool checkValidationLayerSupport();
        void setupDebugMessenger();

        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
        VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                     const VkAllocationCallbacks *pAllocator,
                                     VkDebugUtilsMessengerEXT *pDebugMessenger);

        void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
                                           const VkAllocationCallbacks *pAllocator);

    };
}