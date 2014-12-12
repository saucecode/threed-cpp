#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "resourcemanager.h"
#include <GL/gl.h>
#include <string>

class ResourceManager {
private:
	GLuint textures[32];
	GLuint png_texture_load(const char* file_name, int* width, int* height);
public:
	bool loadTexturePNG(std::string file, int id);
	void useTexture(int id);
};

#endif
