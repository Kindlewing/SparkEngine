#pragma once
#include<VertexBuffer.h>
#include<VertexBufferLayout.h>
#include<Renderer.h>

class VertexArray {
    public:
        VertexArray();
        ~VertexArray();
        
        void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
        void Bind() const;
        void Unbind() const;
 
    private:
        unsigned int _rendererID;
};