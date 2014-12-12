#include "vector3.h"

Vector3::Vector3(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::addX(float dx){
	this->x += dx;
}
void Vector3::addY(float dy){
	this->y += dy;
}
void Vector3::addZ(float dz){
	this->z += dz;
}

float Vector3::getX(){
	return this->x;
}
float Vector3::getY(){
	return this->y;
}
float Vector3::getZ(){
	return this->z;
}

