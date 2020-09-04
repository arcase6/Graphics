#pragma once
#include <CustomRenderer.h>

class DoubleTriangleRenderer : public CustomRenderer
{
protected:
    void PassIndicesData() override, PassVertexData() override, RenderFrame() override;
};