#include "CubeComponent.h"
#include <GL/freeglut.h>
#include <GL\GL.h>
#include <GL\freeglut_ext.h>
#include <iostream>

int textureID, middelpuntx, middelpunty,middelpuntz, startPos, endPos;
int packAantal = 2;
CubeComponent::CubeComponent(GLuint textureID, int middelpuntx, int middelpunty, int middelpuntz, int startPos, int endPos)
{
	this->textureID = textureID;
	this->middelpuntx = middelpuntx;
	this->middelpunty = middelpunty;
	this->middelpuntz = middelpuntz;
	this->startPos = startPos;
	this->endPos = endPos;
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
	glTexCoord2f((float)startPos /packAantal, (float)startPos/ packAantal);
	glVertex3f(-0.5 + middelpuntx,middelpunty - 0.5, middelpuntz-0.5);
	glTexCoord2f((float)startPos/ packAantal, (float)endPos/ packAantal);
	glVertex3f(middelpuntx -0.5,middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos/ packAantal, (float)endPos/ packAantal);
	glVertex3f(middelpuntx + 0.5,  middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos/ packAantal, (float)startPos/ packAantal);
	glVertex3f(middelpuntx + 0.5,  middelpunty - 0.5, middelpuntz - 0.5);

	glTexCoord2f((float)startPos/packAantal, (float)startPos / packAantal);
	glVertex3f(-0.5 + middelpuntx, middelpunty - 0.5, middelpuntz +0.5);
	glTexCoord2f((float)startPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)startPos / packAantal);
	glVertex3f(middelpuntx + 0.5, middelpunty - 0.5, middelpuntz + 0.5);

	glTexCoord2f((float)startPos / packAantal, (float)startPos / packAantal);
	glVertex3f( middelpuntx + 0.5, middelpunty - 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)startPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx + 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)startPos / packAantal);
	glVertex3f(middelpuntx + 0.5, middelpunty - 0.5, middelpuntz + 0.5);

	glTexCoord2f((float)startPos / packAantal, (float)startPos / packAantal);
	glVertex3f(middelpuntx - 0.5, middelpunty - 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)startPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz - 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)endPos / packAantal);
	glVertex3f(middelpuntx - 0.5, middelpunty + 0.5, middelpuntz + 0.5);
	glTexCoord2f((float)endPos / packAantal, (float)startPos / packAantal);
	glVertex3f(middelpuntx - 0.5, middelpunty - 0.5, middelpuntz + 0.5);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}