#pragma once


#include <GL\freeglut.h>
#include "DrawComponent.h"

class LightComponent : public DrawComponent
{
private:

	GLuint textureID;
	int x,y,z;

public:
	LightComponent(int x, int y, int z);
	~LightComponent();
	void lightOn();
	void lightOff();
	virtual void draw() override;
#

};
