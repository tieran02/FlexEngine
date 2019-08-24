#pragma once

#include <memory>
#include "IRenderContext.h"

namespace Flex
{
    class IRenderer
    {
    public:
        IRenderer() = default;
        virtual ~IRenderer() = default;

    protected:
        std::unique_ptr<IRenderContext> m_renderContext;
    private:
        virtual void setup() = 0;
        virtual void cleanup() = 0;
    };
}