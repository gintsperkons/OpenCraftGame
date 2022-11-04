#pragma once

#include "Application.h"
#include "Window/Window.h"
#include "Render/Render.h"
class Application;
class Window;
class Render;
class Config
{
public:
	Application* getApp() { return mainApp; };
	void setApp(Application* tempApp) { mainApp = tempApp; }; 
	Window* getWindow() { return mainWindow; };
	void setWindow(Window* tempWindow) { mainWindow = tempWindow; };
	Render* getRender() { return mainRender; };
	void setRender(Render* tempRender) { mainRender = tempRender; };
private:
	Application* mainApp;
	Window* mainWindow;
	Render* mainRender;
};

