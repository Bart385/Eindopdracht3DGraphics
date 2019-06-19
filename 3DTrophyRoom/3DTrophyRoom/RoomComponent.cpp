#include "RoomComponent.h"
#include <GL/freeglut.h>
#include <GL\GL.h>
#include <GL\freeglut_ext.h>
#include <iostream>


RoomComponent::RoomComponent()
{

}


RoomComponent::~RoomComponent()
{
}

void RoomComponent::draw()
{

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, -15);
	glVertex3f(15, -1, -15);
	glVertex3f(15, -1, 15);
	glVertex3f(-15, -1, 15);
	glEnd();

	for (int x = -10; x <= 10; x += 5)
	{
		for (int y = -10; y <= 10; y += 5)
		{

			glPushMatrix();
			glTranslatef((float)x, 0.0f, (float)y);
			glPopMatrix();
		}
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, -15);
	glVertex3f(-15, 15, -15);
	glVertex3f(15, 15, -15);
	glVertex3f(15, -1, -15);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, 15);
	glVertex3f(-15, 15, 15);
	glVertex3f(15, 15, 15);
	glVertex3f(15, -1, 15);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, 15);
	glVertex3f(-15, 15, 15);
	glVertex3f(-15, 15, -15);
	glVertex3f(-15, -1, -15);
	glEnd();



	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(15, -0.99, -3);
	glVertex3f(15, -0.99, 3);
	glVertex3f(-15, -0.99, 3);
	glVertex3f(-15, -0.99, -3);
	glEnd();
}

