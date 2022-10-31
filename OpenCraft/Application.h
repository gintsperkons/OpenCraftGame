#pragma once
#include <iostream>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "Window/Window.h"
#include "Config.h"
class Config;
class Window;
class Application
{
	public:
		int startApplication(Application *mainApp);
		int mainLoop();
	private:
		Config *mainConfig = nullptr;
		Window* currentWindow = nullptr;
		GLFWwindow* currentGLFWWindow = nullptr;
};

