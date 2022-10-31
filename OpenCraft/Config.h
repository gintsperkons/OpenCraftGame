#pragma once

#include "Application.h"
#include "Window/Window.h"
class Application;
class Window;
class Config
{
public:
	Application* getApp() { return mainApp; };
	void setApp(Application* tempApp) { mainApp = tempApp; }; 
	Window* getWindow() { return mainWindow; };
	void setWindow(Window* tempWindow) { mainWindow = tempWindow; };
private:
	Application* mainApp = nullptr;
	Window* mainWindow = nullptr;
};

