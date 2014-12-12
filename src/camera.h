#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include "camera.h"

class Camera : public Vector3 {
private:
	float pitch, yaw;
	float headOffset;
public:
	Camera(float x, float y, float z);
	
	float getPitch();
	float getYaw();
	float getHeadOffset();
	
	void setPitch(float pitch);
	void setYaw(float yaw);
	void setHeadOffset(float headOffset);
	
	void repositionCamera(float x, float y, float z);
	void pointCameraAt(float tx, float ty, float tz);
	void mouseLook(double mouseDX, double mouseDY);
};

#endif
