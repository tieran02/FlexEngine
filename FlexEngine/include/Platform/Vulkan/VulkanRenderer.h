#pragma once
#include <Flex/Rendering/IRenderer.h>

namespace Flex
{
    class VulkanRenderer : public IRenderer
    {
    public:
        static std::unique_ptr<VulkanRenderer> Create();
        VulkanRenderer();
        ~VulkanRenderer();

    private:

        void setup() override;
        void cleanup() override;
    };
}