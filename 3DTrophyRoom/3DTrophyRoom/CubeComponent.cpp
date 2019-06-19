#include "CubeComponent.h"
#include <GL/freeglut.h>
#include <GL\GL.h>
#include <GL\freeglut_ext.h>
#include <iostream>

int textureID, middelpuntx, middelpunty,middelpuntz;
int startPos = 0.0f;
int endPos = 1.0f;
CubeComponent::CubeComponent(GLuint textureID, int middelpuntx, int middelpunty, int middelpuntz)
{
	this->textureID = textureID;
	this->middelpuntx = middelpuntx;
	this->middelpunty = middelpunty;
	this->middelpuntz = middelpuntz;
}

CubeComponent::~CubeComponent()
{

}


void CubeComponent::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBlendFunc(GL_ONE, GL_ZERO);
	
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 1);
	glTexCoord2f((float)startPos, (float)startPos);
	glVertex3f(-0.5 + middelpuntx,middelpunty - 0.5, middelpuntz-0.5);
	glTexCoord2f((float)startPos, (float)endPos);
	glVertex3f(middelpuntx -0.5,middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos, (float)endPos);
	glVertex3f(middelpuntx + 0.5,  middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos, (float)startPos);
	glVertex3f(middelpuntx + 0.5,  middelpunty - 0.5, middelpuntz - 0.5);

	glTexCoord2f((float)startPos, (float)startPos);
	glVertex3f(-0.5 + middelpuntx, middelpunty - 0.5, middelpuntz +0.5);
	glTexCoord2f((float)startPos, (float)endPos);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos, (float)endPos);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos, (float)startPos);
	glVertex3f(middelpuntx + 0.5, middelpunty - 0.5, middelpuntz + 0.5);

	glTexCoord2f((float)startPos, (float)startPos);
	glVertex3f( middelpuntx + 0.5, middelpunty - 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)startPos, (float)endPos);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos, (float)endPos);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos, (float)startPos);
	glVertex3f(middelpuntx + 0.5, middelpunty - 0.5, middelpuntz + 0.5);

	glTexCoord2f((float)startPos, (float)startPos);
	glVertex3f(middelpuntx - 0.5, middelpunty - 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)startPos, (float)endPos);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos, (float)endPos);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos, (float)startPos);
	glVertex3f(middelpuntx - 0.5, middelpunty - 0.5, middelpuntz + 0.5);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}