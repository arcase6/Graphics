#pragma once

#include <glew.h>

class CustomRenderer
{
    public:
        virtual void Initialize();
        void InitializeShaders();
        virtual void RenderFrame();
    protected:
        void PassIndicesData();
        void PassVertexData();
        void GenerateAndBindBuffer(GLenum targetBuffer);
};

