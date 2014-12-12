#include <GLFW/glfw3.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "framework3D.h"
#include "camera.h"
#include "basescene.h"
#include "resourcemanager.h"


class MyScene : public BaseScene {
public:
	virtual void init(){
		setCamera(new Camera(0.0,0.0,0.0));
		setMouseGrabbed(true);
		printf("Hello, world!\n");
		getCamera()->pointCameraAt(3,0,3);
	}
	
	virtual void loadResources(){
		getResourceManager()->loadTexturePNG("res/spray.png", 0);
	}
	
	virtual void update(){
		if(keys[GLFW_KEY_ESCAPE]){
			printf("Escape!\n");
			setCloseRequested(true);
		}
	}
	
	virtual void render3D(){
		translateCamera();
		if(isMouseGrabbed())
			getCamera()->mouseLook(mouseDX, -mouseDY);
		
		glColor3f(1.0,1.0,1.0);
		//getResourceManager()->useTexture(0);
		getResourceManager()->useTexture(0);
		drawBox(3,-1,3, 6,1,6);
		unbindTexture();
		drawBox(3,1.5,3, 6,2.5,6);
	}
	
	virtual void render2D(){
		
	}
	
};

int main(int argc, char** argv){
	Framework3D framework("threed", 1280, 720);
	BaseScene* baseScene = new MyScene();
	
	framework.setFPS(60);
	framework.setFOV(90);
	framework.setVsync(false);
	framework.setScene(baseScene);
	framework.start();
}

