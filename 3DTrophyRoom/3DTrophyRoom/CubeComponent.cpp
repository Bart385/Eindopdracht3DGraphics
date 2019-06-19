#include "CubeComponent.h"
#include <GL/freeglut.h>
#include <GL\GL.h>
#include <GL\freeglut_ext.h>
#include <iostream>

int textureID, size;
int startPos = 0.0f;
int endPos = 1.0f;
CubeComponent::CubeComponent(GLuint textureID, int size)
{
	this->textureID = textureID;
	this->size = size;
}

CubeComponent::~CubeComponent()
{

}


void CubeComponent::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glDisable(GL_BLEND);
	
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 1);
	glTexCoord2f((float)startPos, (float)startPos);
	glVertex3f(-size, -size, -size);
	glTexCoord2f((float)startPos, (float)endPos);
	glVertex3f(size, -size, -size);
	glTexCoord2f((float)endPos, (float)endPos);
	glVertex3f(size, size, -size);
	glTexCoord2f((float)endPos, (float)startPos);
	glVertex3f(-size, size, -size);
	glDisable(GL_TEXTURE_2D);
	glEnd();

	
}