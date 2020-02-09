#include "definitions.h"


// Initial view rotations.
GLint xViewRotation = 30;
GLint yViewRotation = 45;

// Initial zoom coefficient.
GLint zoomCoef = 80;


void display(void)
{
	// Buffer indications.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Camera position.
	gluLookAt(
		0, 0, zoomCoef * DIM_SIZE,
		0, 0, 0,
		0, 1, 0
	);

	// Rotate view.
	glRotatef(xViewRotation, 1.0, 0.0, 0.0);
	glRotatef(yViewRotation, 0.0, 1.0, 0.0);

	drawCube();

	// Swap the two buffers.
	glutSwapBuffers();
}


void reshape(int width, int height)
{
	// Make viewport entire window.
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Redefine the perspective for new window size.
	GLfloat angle = 60.0;
	GLfloat aspect = (GLfloat) width / (GLfloat) height;
	gluPerspective(angle, aspect, 1.0, DIM_SIZE * 500.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}
