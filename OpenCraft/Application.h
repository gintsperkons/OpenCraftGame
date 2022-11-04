#pragma once
//OpenGL includes
#include <glad/glad.h>
#include "GLFW/glfw3.h"
//Libery Includes
#include <iostream>
//Header Includes
#include "Window/Window.h"
#include "Config.h"
#include "Render/Render.h"
class Config;
class Window;
class Application
{
	public:

		Application();
		~Application();
		int startApplication(Application *mainApp);
		int mainLoop();
	private:
		Config *mainConfig;
		Window* currentWindow;
		GLFWwindow* currentGLFWWindow;
		int code;
};
