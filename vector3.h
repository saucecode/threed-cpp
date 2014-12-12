#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
	public:
		float x;
		float y;
		float z;
		
		Vector3(float x, float y, float z);
		float getX();
		float getY();
		float getZ();
		void addX(float dx);
		void addY(float dy);
		void addZ(float dz);
};

#endif
