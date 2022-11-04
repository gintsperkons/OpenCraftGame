#include "Render.h"



float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

Render::Render()
{
	shaderProgram = 0;
	VBO = 0;
	VAO = 0;
	vertexShader = 0;
	fragmentShader = 0;
	vertSourceDefLocation = "Shaders/Vertex/default.vert";
	fragSourceDefLocation = "Shaders/Fragment/default.frag";

}
Render::~Render()
{
}

void Render::RenderCycle()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Render::mainRender()
{
	LoadVertSourceFile();
	LoadFragSourceFile();
	CompileVertexShader();
	CompileFragmentShader();
	CreateProgram();
	CreateVBO();
	CreateVAO();



}

void Render::CreateVBO()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
void Render::CreateVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void Render::CreateProgram()
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void Render::CompileVertexShader()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}
void Render::CompileFragmentShader()
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void Render::LoadVertSourceFile(std::string fname)
{
	vertexString = LoadSourceFile(fname);
	vertexShaderSource = vertexString.c_str();
}

void Render::LoadFragSourceFile(std::string fname)
{

	fragmentString = LoadSourceFile(fname);
	fragmentShaderSource = fragmentString.c_str();
}

void Render::LoadVertSourceFile()
{
	

	LoadVertSourceFile(vertSourceDefLocation);
}

void Render::LoadFragSourceFile()
{
	fragmentShaderSource = "";
	LoadFragSourceFile(fragSourceDefLocation);
}
std::string Render::LoadSourceFile(std::string fname)
{
	std::string content;
	std::ifstream fileStream(fname, std::ios::in);

	if (!fileStream.is_open()) {
		printf("Failed to read %s! File doesn't exist.", fname.c_str());
		return "";
	}

	std::string line = "";
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
	
}
