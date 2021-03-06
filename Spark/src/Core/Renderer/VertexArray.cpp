#include<VertexArray.h>


VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &ID));
    Bind();
}

void VertexArray::Delete() {
    GLCall(glDeleteVertexArrays(1, &ID));
}

void VertexArray::LinkVertexBuffer(VertexBuffer& vertexBuffer, uint32_t layout) {
    vertexBuffer.Bind();
	GLCall(glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0));
	GLCall(glEnableVertexAttribArray(layout));
	vertexBuffer.Unbind();
}

void VertexArray::Bind() const {
    GLCall(glBindVertexArray(ID));
}

void VertexArray::Unbind() {
    GLCall(glBindVertexArray(0));
}