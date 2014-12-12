#include "framework3D.h"
#include "resourcemanager.h"
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

Framework3D::Framework3D(std::string title, int width, int height){
	this->title = title;
	this->width = width;
	this->height = height;
	this->aspectRatio = ((float) width) / ((float) height);
	this->resourceManager = new ResourceManager();
}

void Framework3D::setFPS(int fps){
	this->fps = fps;
}

void Framework3D::setFOV(int fov){
	this->fov = fov;
}

void Framework3D::setScene(BaseScene* scene){
	this->scene = scene;
}

void Framework3D::setVsync(bool vsync){
	this->vsync = vsync;
}

void Framework3D::setDrawDistance(int drawDistance){
	this->drawDistance = drawDistance;
}

void Framework3D::clearGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void Framework3D::initGL3(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(getFOV(), getAspectRatio(), 0.001, getDrawDistance());
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	glEnable(GL_ALPHA);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Framework3D::initGL2(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, getWidth(), 0, getHeight(), -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Framework3D::start(){
	printf("Starting engine!\n");
	glfwInit();
	this->window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), NULL, NULL);
	if(!this->window){
		glfwTerminate();
		return;
    }
	
	glfwMakeContextCurrent(this->window);
	//glfwSetWindowPos(this->window, 1920,20);
	
	getScene()->init();
	getScene()->setResourceManager(resourceManager);
	getScene()->loadResources();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	double x,y,nx,ny,dx,dy;
	
	while(!glfwWindowShouldClose(this->window) && !getScene()->isCloseRequested()){
		clearGL();
		
		glfwGetCursorPos(window, &nx, &ny);
		
		dx=nx-x;dy=ny-y;x=nx;y=ny;
		if(getScene()->isMouseGrabbed()){
			if(nx < 1){
				glfwSetCursorPos(window, getWidth()-2, ny);
				dx = 0;
			}
			if(nx > getWidth()-1){
				glfwSetCursorPos(window, 2, ny);
				dx = 0;
			}
		}
		
		getScene()->mouseX = x;getScene()->mouseY = y;getScene()->mouseDX = dx;getScene()->mouseDY = dy;
		
		for(int i=0;i<512;i++){
			getScene()->keys[i] = glfwGetKey(window, i);
		}
		getScene()->update();
		
		initGL3();
		getScene()->render3D();
		//initGL2();
		//getScene()->render2D();
		
    	glfwSwapBuffers(this->window);
    	glfwPollEvents();
		usleep(1000000.0/60.0);
	}
	
	getScene()->destroy();
	glfwTerminate();
}
