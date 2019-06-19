#include "LightComponent.h"


int x, y, z;
LightComponent::LightComponent(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


LightComponent::~LightComponent()
{
}

void LightComponent::draw()
{
	glEnable(GL_LIGHTING);
	

	GLUquadricObj* quadric;
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);


	glDisable(GL_LIGHTING);

	glPushMatrix();
	glColor3f(0.8, 0.498039, 0.196078);
	gluSphere(quadric, 1, 36, 18);
	glEnable(GL_BLEND);
	glBlendFunc(1, 1);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 15);
	gluSphere(quadric, 1.2, 36, 18);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	GLfloat light_position[] = { 0.0, 1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	GLfloat light_amb[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	GLfloat light_diff[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
	
	
}

void LightComponent::lightOn()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void LightComponent::lightOff()
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
}