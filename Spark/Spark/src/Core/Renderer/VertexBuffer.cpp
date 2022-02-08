#include<VertexBuffer.h>


VertexBuffer::VertexBuffer(float* vertices, unsigned int size) {
    glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &ID);
}


void VertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}