#pragma once


#include <GL\freeglut.h>
#include "DrawComponent.h"

class CubeComponent: public DrawComponent
{
private:

	GLuint textureID;
	int middelpuntx, middelpunty, middelpuntz, startPos, endPos;

public:
	CubeComponent(GLuint textureID, int middelpuntx, int middelpunty, int middelpuntz, int startPos, int endPos);
	~CubeComponent();
	virtual void draw() override;
#
	
};

