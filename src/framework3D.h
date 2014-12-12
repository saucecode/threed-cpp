#ifndef FRAMEWORK3D_H
#define FRAMEWORK3D_H

#include <string>
#include <GLFW/glfw3.h>
#include "basescene.h"
#include "framework3D.h"
#include "resourcemanager.h"

class Framework3D {
private:
	BaseScene* scene;
	int width, height, fps, fov, drawDistance;
	float aspectRatio;
	std::string title;
	bool vsync;
	GLFWwindow* window;
	ResourceManager* resourceManager;

public:
	Framework3D(std::string title, int width, int height);
	
	BaseScene* getScene() { return scene; }
	GLFWwindow* getWindow() { return window; }
	int getWidth() { return width; }
	float getAspectRatio() { return aspectRatio; }
	int getHeight() { return height; }
	int getDrawDistance() { return drawDistance; }
	int getFPS() { return fps; }
	int getFOV() { return fov; }
	bool getVsync() { return vsync; }
	std::string getTitle() { return title; }
	
	void setDrawDistance(int drawDistance);
	void setVsync(bool vsync);
	void setFPS(int fps);
	void setFOV(int fov);
	void setScene(BaseScene* scene);
	
	void start();
	void clearGL();
	void initGL3();
	void initGL2();
};

#endif
