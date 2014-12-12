#include "camera.h"
#include "vector3.h"
#include "basescene.h"
#define _USE_MATH_DEFINES
#include <math.h>

Camera::Camera(float x, float y, float z) : Vector3(x,y,z) {
	this->yaw = 0;
	this->pitch = 0;
	this->headOffset = 0;
}

void Camera::setPitch(float pitch){
	this->pitch = pitch;
}

void Camera::setHeadOffset(float headOffset){
	this->headOffset = headOffset;
}

void Camera::setYaw(float yaw){
	this->yaw = yaw;
}

float Camera::getPitch() { return pitch; }
float Camera::getYaw() { return yaw; }
float Camera::getHeadOffset() { return headOffset; }

void Camera::repositionCamera(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Camera::pointCameraAt(float tx, float ty, float tz){
	float f1 = atan2( tz-getZ(), tx-getX() ) + 0.5*M_PI;
	this->yaw = f1;
	this->pitch = atan((getY() - ty) / hypot(tx-getX(), tz-getZ()));
}

void Camera::mouseLook(double dx, double dy){
	float mouseDX = dx * 0.8 * 0.16 * 0.1;
	float mouseDY = dy * 0.8 * 0.16 * 0.1;
	if (yaw + mouseDX >= 2.0*M_PI) {
		yaw = yaw + mouseDX - (2.0*M_PI);
	} else if (yaw + mouseDX < 0) {
		yaw = (2.0*M_PI) - yaw + mouseDX;
	} else {
		yaw += mouseDX;
	}
	if (pitch - mouseDY >= -1.5533430342749532 && pitch - mouseDY <= 1.5533430342749532) {
		pitch += -mouseDY;
	} else if (pitch - mouseDY < -1.5533430342749532) {
		pitch = -1.5533430342749532; // -89
	} else if (pitch - mouseDY > 1.5533430342749532) {
		pitch = 1.5533430342749532; // 89
	}
}
