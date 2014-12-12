#ifndef BASESCENE_H
#define BASESCENE_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "camera.h"
#include "basescene.h"
#include "resourcemanager.h"

class Framework3D;

class BaseScene {
private:
	bool closeRequested, wireframe, mouseGrabbed;
	Framework3D* framework;
	Camera* camera;
	ResourceManager* resourceManager;
public:
	double mouseX, mouseY, mouseDX, mouseDY;
	bool keys[512];
	//BaseScene(Framework3D* framework);
	BaseScene();
	
	void translateCamera();
	
	virtual void init();
	virtual void loadResources();
	virtual void update();
	virtual void render3D();
	virtual void render2D();
	virtual void destroy();
	
	Camera* getCamera();
	bool isMouseGrabbed() { return mouseGrabbed; }
	bool isCloseRequested(){ return closeRequested; }
	Framework3D* getFramework(){ return framework; }
	
	void setCamera(Camera* camera);
	void setMouseGrabbed(bool mouseGrabbed);
	void setResourceManager(ResourceManager* resourceManager);
	void setCloseRequested(bool closeRequested);
	ResourceManager* getResourceManager(){ return resourceManager; }
};

float degrees(float x);
float radians(float x);
void unbindTexture();
void drawPlane(float x1, float z1, float x2, float z2, float y);
void drawWall(float x1, float z1, float x2, float z2, float y, float height);
void drawBox(float x1, float y1, float z1, float x2, float y2, float z2);

#endif
