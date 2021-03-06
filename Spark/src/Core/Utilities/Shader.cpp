#include<Shader.h>
/*
    Parses the contents from the given file
 */
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
Shader::Shader() {}
Shader::Shader(const char* vertexFile, const char* fragmentFile) {
    std::string vertexCode = GetFileContents(vertexFile);
	std::string fragmentCode = GetFileContents(fragmentFile);

	// Convert the shader source strings into character arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Create Vertex Shader Object and get its reference
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
    // Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	
    // Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	
    // Create Fragment Shader Object and get its reference
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
    // Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	
    // Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	
    // Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	
    // Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

// Activates the Shader Program
void Shader::Activate() const {
	glUseProgram(ID);
}


void Shader::Delete() {
    glDeleteProgram(ID);
}