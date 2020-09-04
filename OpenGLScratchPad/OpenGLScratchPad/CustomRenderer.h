#pragma once

#include <glew.h>
#include <string>
class CustomRenderer
{
    public:
        virtual void Initialize();
        void InitializeShaders();
        virtual void RenderFrame() = 0;
    protected:
        virtual void PassIndicesData() = 0;
        virtual void PassVertexData() = 0;
        virtual std::string GetVertexShaderPath();
        virtual std::string GetFragmentShaderPath();
        
        GLuint GenerateAndBindBuffer(GLenum targetBuffer);
};