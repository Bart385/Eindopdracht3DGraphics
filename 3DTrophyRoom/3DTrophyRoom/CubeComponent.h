#pragma once


#include <GL\freeglut.h>
#include "DrawComponent.h"

class CubeComponent: public DrawComponent
{
private:

	GLuint textureID;
	int middelpuntx, middelpunty, middelpuntz;

public:
	CubeComponent(GLuint textureID, int middelpuntx, int middelpunty, int middelpuntz);
	~CubeComponent();
	virtual void draw() override;
#
	
};

