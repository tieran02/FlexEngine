//
// Created by tieran on 24/08/2019.
//
#include "pchheader.h"
#include "Platform/Vulkan/VulkanRenderContext.h"
#include <Flex/Application.h>

namespace Flex
{
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData) {

        std::string msg = "validation layer: ";
        msg.append(pCallbackData->pMessage);
        FL_LOG_CORE_INFO(msg);

        return VK_FALSE;
    }

    const std::vector<const char*> validationLayers
    {
            "VK_LAYER_KHRONOS_validation"
    };

    #ifdef DEBUG
        const bool enableValidationLayers = true;
    #else
        const bool enableValidationLayers = false;
    #endif

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
        setupDebugMessenger();
        FL_LOG_CORE_INFO("Created Vulkan Render Context");

    }

    void VulkanRenderContext::cleanup()
    {
        FL_LOG_CORE_INFO("Cleaning up Vulkan Render Context ");
        if (enableValidationLayers)
            destroyDebugUtilsMessengerEXT(VkInstance(m_vkInstance), debugMessenger, nullptr);

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
        auto extensions = Application::Instance().GetWindow().VulkanExtensions();
        //add validation layers to extensions
        if (enableValidationLayers)
        {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        createInfo.enabledExtensionCount = extensions.size();
        createInfo.ppEnabledExtensionNames = extensions.data();

        //create debug messanger for the instance only
        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;
        if (enableValidationLayers && checkValidationLayerSupport())
        {
            createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();

            populateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
        }
        else
        {
            createInfo.enabledLayerCount = 0;

            createInfo.pNext = nullptr;
        }

        m_vkInstance = vk::createInstance(createInfo);
        FL_CORE_ASSERT(m_vkInstance, "Failed to create vulkan instance");

    }

    bool VulkanRenderContext::checkValidationLayerSupport()
    {
        //check validation layer support
        std::vector<vk::LayerProperties> availableLayers = vk::enumerateInstanceLayerProperties();

        for (const char* layerName : validationLayers)
        {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound)
            {
                FL_LOG_CORE_FATAL("Vulkan validation layers not supported but were called upon");
                return false;
            }
        }

        return true;
    }

    void VulkanRenderContext::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
    {
        createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = debugCallback;
    }

    void VulkanRenderContext::setupDebugMessenger()
    {
        if (!enableValidationLayers) return;

        VkDebugUtilsMessengerCreateInfoEXT createInfo;
        populateDebugMessengerCreateInfo(createInfo);


        if (createDebugUtilsMessengerEXT(VkInstance(m_vkInstance), &createInfo, nullptr, &debugMessenger) != VK_SUCCESS){
            FL_LOG_CORE_FATAL("failed to set up vulkan debug messenger!");
        }
    }

    VkResult VulkanRenderContext::createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger)
    {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        } else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }

    void VulkanRenderContext::destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }
}