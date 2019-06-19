#pragma once


#include <GL\freeglut.h>
#include "DrawComponent.h"

class CubeComponent: public DrawComponent
{
private:

	GLuint textureID;
	int size;

public:
	CubeComponent(GLuint textureID, int size);
	~CubeComponent();
	virtual void draw() override;
#
	
};

