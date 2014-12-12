#include "basescene.h"
#include "camera.h"
#include "resourcemanager.h"
#include "framework3D.h"
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <GLFW/glfw3.h>

BaseScene::BaseScene(Framework3D* framework){
	this->framework = framework;
}

void BaseScene::init(){

}

void BaseScene::loadResources(){

}

void BaseScene::update(){

}

void BaseScene::render3D(){

}

void BaseScene::render2D(){

}

void BaseScene::destroy(){

}

Camera* BaseScene::getCamera() { return camera; }

void BaseScene::setMouseGrabbed(bool mouseGrabbed){
	this->mouseGrabbed = mouseGrabbed;
	glfwSetInputMode(getFramework()->getWindow(), GLFW_CURSOR, mouseGrabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void BaseScene::translateCamera(){
	glRotatef(degrees(getCamera()->getPitch()), 1, 0, 0);
	glRotatef(degrees(getCamera()->getYaw()), 0, 1, 0);
	glTranslatef(-getCamera()->getX(), -getCamera()->getY()-getCamera()->getHeadOffset(), -getCamera()->getZ());
}

float degrees(float x){
	return x*180.0/M_PI;
}

float radians(float x){
	return x*M_PI/180.0;
}

void BaseScene::setCamera(Camera* camera){
	this->camera = camera;
}

void BaseScene::setCloseRequested(bool closeRequested){
	this->closeRequested = closeRequested;
}

void BaseScene::setResourceManager(ResourceManager* resourceManager){
	this->resourceManager = resourceManager;
}

void unbindTexture(){
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawPlane(float x1, float z1, float x2, float z2, float y){
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex3f(x1, y, z1);
	
	glTexCoord2f(1, 0);
	glVertex3f(x2, y, z1);
	
	glTexCoord2f(1, 1);
	glVertex3f(x2, y, z2);
	
	glTexCoord2f(0, 1);
	glVertex3f(x1, y, z2);

	glEnd();
}

void drawWall(float x1, float z1, float x2, float z2, float y, float height){
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(x1, y, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x2, y, z2);
	glTexCoord2f(1, 1);
	glVertex3f(x2, y+height, z2);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y+height, z1);
	glEnd();
}

void drawBox(float x1, float y1, float z1, float x2, float y2, float z2) {
	float width = abs(x1-x2);
	float length = abs(z1-z2);
	float height = abs(y1-y2);
	glBegin(GL_QUADS);
	//Top
	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x1+width, y1, z1);
	glTexCoord2f(1, 1);
	glVertex3f(x1+width, y1, z1+length);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y1, z1+length);
	//Bottom
	glTexCoord2f(0, 0);
	glVertex3f(x1, y1+height, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x1+width, y1+height, z1);
	glTexCoord2f(1, 1);
	glVertex3f(x1+width, y1+height, z1+length);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y1+height, z1+length);
	//Front
	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x1+width, y1, z1);
	glTexCoord2f(1, 1);
	glVertex3f(x1+width, y1+height, z1);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y1+height, z1);
	//Back
	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1+length);
	glTexCoord2f(1, 0);
	glVertex3f(x1+width, y1, z1+length);
	glTexCoord2f(1, 1);
	glVertex3f(x1+width, y1+height, z1+length);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y1+height, z1+length);
	//Left side
	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x1, y1, z1+length);
	glTexCoord2f(1, 1);
	glVertex3f(x1, y1+height, z1+length);
	glTexCoord2f(0, 1);
	glVertex3f(x1, y1+height, z1);
	//Right side
	glTexCoord2f(0, 0);
	glVertex3f(x1+width, y1, z1);
	glTexCoord2f(1, 0);
	glVertex3f(x1+width, y1, z1+length);
	glTexCoord2f(1, 1);
	glVertex3f(x1+width, y1+height, z1+length);
	glTexCoord2f(0, 1);
	glVertex3f(x1+width, y1+height, z1);
	glEnd();
}
