#pragma once

#include <glew.h>
#include <string>
class CustomRenderer
{
    public:
        virtual void Initialize();
        void InitializeShaders();
        virtual void RenderFrame();
    protected:
        virtual void PassIndicesData();
        virtual void PassVertexData();
        virtual std::string GetVertexShaderPath();
        virtual std::string GetFragmentShaderPath();
        
        GLuint GenerateAndBindBuffer(GLenum targetBuffer);
};

class DoubleTriangleRenderer : public CustomRenderer
{

};