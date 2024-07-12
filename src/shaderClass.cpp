#include "../Headers/shaderClass.h"


std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile){
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    //compile our vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // set source of shader to one string and setr the reference to the string above
    glShaderSource(vertexShader, 1, &vertexSource, NULL);

    // compile our shader
    glCompileShader(vertexShader);

    //compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // set source of shader to one string and setr the reference to the string above
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

    // compile Shader
    glCompileShader(fragmentShader);

    // link everything together by creating a shader program
    ID = glCreateProgram();

    // attach our vertexShader and FragmentShader to our shaderprogram
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    // linke shader program
    glLinkProgram(ID);

    // shaders have been attached delete and clear the memory
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // send stuff between cpu and gpu in big batches because its slow
    // use a buffer

}

void Shader::Activate()
{
     glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}