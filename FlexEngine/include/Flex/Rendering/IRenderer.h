#pragma once

#include <memory>

class IRenderContext;
class IRenderer
{
public:
    
private:
    std::unique_ptr<IRenderContext> m_renderContext;
    virtual void setup() = 0;

};