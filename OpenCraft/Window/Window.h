#pragma once
#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include <iostream>

class Window
{
	public:
		void initilizeGL();
		int createWindow();
		int initilizeGLAD();
		GLFWwindow* getGLFWWindow() { return mainWindow; };
	private:
		GLFWwindow *mainWindow = nullptr;
};

