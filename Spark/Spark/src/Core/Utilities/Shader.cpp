#include<Shader.h>

std::string Shader::GetFileContents(const char* fileName) {
    std::ifstream in(fileName, std::ios::binary);
    if(in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;  
    }
    throw(errno);
}


Shader::Shader(const char* vertexFile, const char* fragmentFile) {
    std::string vertexCode = GetFileContents(vertexFile);
    std::string fragmentCode = GetFileContents(fragmentFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    glShaderSource(vertexShader, 1, &vertexSource, NULL); 
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL); 
    glCompileShader(fragmentShader);

    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID); 

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void Shader::Activate() {
    glUseProgram(ID);
}


void Shader::Delete() {
    glDeleteProgram(ID);
}