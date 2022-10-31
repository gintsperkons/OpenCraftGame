#include "Application.h"


int Application::startApplication(Application *mainApp)
{
	std::cout << "Starting Application" << std::endl;
	int code = 0;
	Config tempConfig = Config();
	mainConfig = &tempConfig;
	mainConfig->setApp(mainApp);
	Window tempWindow = Window();
	mainConfig->setWindow(&tempWindow);
	currentWindow = mainConfig->getWindow();
	currentWindow->initilizeGL();
	code = currentWindow->createWindow();
	currentGLFWWindow = currentWindow->getGLFWWindow();
	currentWindow->initilizeGLAD();
	std::cout << "Starting AppLoop" << std::endl;
	mainLoop();
	return code;
}

int Application::mainLoop()
{
	while (!glfwWindowShouldClose(currentGLFWWindow))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(currentGLFWWindow);
		glfwPollEvents();
	}
	return 0;
}
