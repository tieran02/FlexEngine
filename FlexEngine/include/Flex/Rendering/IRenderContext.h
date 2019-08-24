#pragma once

namespace Flex
{
    class IRenderContext
    {
    public:
        IRenderContext() = default;
        virtual ~IRenderContext() = default;

    private:
        virtual void create() = 0;
        virtual void cleanup() = 0;
    };
}