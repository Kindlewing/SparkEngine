#pragma once
#include<vector>
#include<glad/gl.h>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch(type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
    public:
        VertexBufferLayout() {
            _stride = 0;
        };
        template<typename T>
        void Push(int count) {
            static_assert(false);
        }

        template<>
        void Push<float>(int count) {
            _elements.push_back({ GL_FLOAT, count, false });
            _stride += VertexBufferElement::GetSizeOfType(GL_FLOAT);;
        }

        template<>
        void Push<unsigned int>(int count) {
            _elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
            _stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
        }

        template<>
        void Push<unsigned char>(int count) {
            _elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
            _stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
        }

        inline std::vector<VertexBufferElement> GetElements() const { return _elements; }
        inline unsigned int GetStride() const { return _stride; }


    private:
        unsigned int _stride;
        std::vector<VertexBufferElement> _elements; 
};