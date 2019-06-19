#include <GL/freeglut.h>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include "CubeComponent.h"
#include "ObjectModel.h"
float lastFrameTime = 0;

int width, height;
GLuint texturePack;
const char* textureFilename = "mblock1.png";

struct Camera
{
	float posX = 0;
	float posY = -4;
	float rotX = 0;
	float rotY = 0;
} camera;

bool keys[255];

void move(float angle, float fac)
{
	camera.posX += (float)cos((camera.rotY + angle) / 180 * M_PI) * fac;
	camera.posY += (float)sin((camera.rotY + angle) / 180 * M_PI) * fac;
}

void drawCircle(float r, float x, float y) {
	float i = 0.0f;
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(x,0, y); // Center
	for (i = 0.0f; i <= 360; i++)
		glVertex3f(r*cos(M_PI * i / 180.0) + x,-1, r*sin(M_PI * i / 180.0) + y);
	glEnd();
}

void display()
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)width / height, 0.1, 60);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glTranslatef(camera.posX, 0, camera.posY);


	glColor3f(1.0f,1.0f,1.0f);
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


	for (int i = -13;  i < 12 ;  i += 3)
	{
		drawCircle(1.0f, (float) i, 13.0f);
	}
	

	Texture texture = Texture(textureFilename);
	texture.loadTextureFromFile(textureFilename);
	texturePack = texture.getTextureId();

	CubeComponent* component = new CubeComponent(1, 15);

	glutSwapBuffers();
}



bool justMovedMouse = false;
void mousePassiveMotion(int x, int y)
{
	int dx = x - width / 2;
	int dy = y - height / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400 && !justMovedMouse)
	{
		camera.rotY += dx / 10.0f;
		camera.rotX += dy / 10.0f;
	}
	if (!justMovedMouse)
	{
		glutWarpPointer(width / 2, height / 2);
		justMovedMouse = true;
	}
	else
		justMovedMouse = false;
}

void keyboard(unsigned char key, int, int)
{
	if (key == 27)
		exit(0);
	keys[key] = true;
}

void keyboardUp(unsigned char key, int, int)
{
	keys[key] = false;
}

void idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;

	const float speed = 3;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);

	glutPostRedisplay();
}



int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);
	glutInit(&argc, argv);
	glutCreateWindow("Hello World");

	memset(keys, 0, sizeof(keys));
	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc([](int w, int h) { width = w; height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutPassiveMotionFunc(mousePassiveMotion);

	glutWarpPointer(width / 2, height / 2);

	glutMainLoop();


	return 0;
}