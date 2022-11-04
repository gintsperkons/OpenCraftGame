#include "Application.h"

Application::Application() 
{
	code = 0;
	mainConfig = nullptr;
	currentWindow = nullptr;
	currentGLFWWindow = nullptr;
}
Application::~Application() 
{

}


int Application::startApplication(Application *mainApp)
{
	std::cout << "Starting Application" << std::endl;
	Config tempConfig = Config();
	Window tempWindow = Window();
	Render tempRender = Render();

	mainConfig = &tempConfig;

	mainConfig->setApp(mainApp);
	mainConfig->setWindow(&tempWindow);
	mainConfig->setRender(&tempRender);

	currentWindow = mainConfig->getWindow();
	currentWindow->initilizeGL();
	code = currentWindow->createWindow();
	currentGLFWWindow = currentWindow->getGLFWWindow();
	currentWindow->initilizeGLAD();

	mainConfig->getRender()->mainRender();
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

		mainConfig->getRender()->RenderCycle();

		glfwSwapBuffers(currentGLFWWindow);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
