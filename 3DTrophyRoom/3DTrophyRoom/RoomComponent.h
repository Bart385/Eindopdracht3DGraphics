#pragma once


#include <GL\freeglut.h>
#include "DrawComponent.h"

class RoomComponent : public DrawComponent
{
private:

	GLuint textureID;
	int middelpuntx, middelpunty, middelpuntz, startPos, endPos;

public:
	RoomComponent();
	~RoomComponent();
	virtual void draw() override;
#

};