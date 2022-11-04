#pragma once
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "../Config.h"
class Render
{
public:
	Render();
	~Render();
	void RenderCycle();
	void mainRender();
	void CreateVBO();
	void CreateVAO();
	void CreateProgram();
	void CompileVertexShader();
	void CompileFragmentShader();
	void LoadVertSourceFile(std::string fname);
	void LoadFragSourceFile(std::string fname);
	void LoadVertSourceFile();
	void LoadFragSourceFile();
private:
	std::string LoadSourceFile(std::string fname);
	unsigned int shaderProgram;
	unsigned int VBO, VAO;
	unsigned int vertexShader, fragmentShader;
	const char* vertexShaderSource = "";
	const char* fragmentShaderSource = "";
	std::string vertexString;
	std::string fragmentString;
	std::string vertSourceDefLocation = "";
	std::string fragSourceDefLocation = "";
};

