#include "definitions.h"


// To record which keys are being held down.
int aIsPressed = 0;
int xIsPressed = 0;
int yIsPressed = 0;
int zIsPressed = 0;


void specialKeyDownHandler(int key, int x, int y)
{
	switch (key)
	{
		// Rotate about Y-axis.
		case GLUT_KEY_LEFT:
			yViewRotation += 15;
			break;
		case GLUT_KEY_RIGHT:
			yViewRotation -= 15;
			break;

		// Rotate about X-axis.
		case GLUT_KEY_UP:
			xViewRotation += 15;
			break;
		case GLUT_KEY_DOWN:
			xViewRotation -= 15;
			break;
	}

	glutPostRedisplay();
}


void keyDownHandler(unsigned char key, int x, int y)
{
	// Let ongoing rotations finish.
	if (isInRotation)
		return;

	// Prevent rotation of non-existent layers.
	if (isdigit(key) && DIM_SIZE < (key - '0'))
		return;

	// Holding down 'a' will make rotations anti-clockwise.
	Direction rotationDirection;
	if (aIsPressed)
		rotationDirection = ACW;
	else
		rotationDirection = CW;
	
	switch (key)
	{
		// Zoom in.
		case '+':
			zoomCoef -= 10;
			glutPostRedisplay();
			break;
		// Zoom out.
		case '-':
			zoomCoef += 10;
			glutPostRedisplay();
			break;

		// Reset cube.
		case 'R':
		case 'r':
			freeArrays();
			initialiseArrays();
			glutPostRedisplay();
			break;

		// X-axis rotation enabled.
		case 'X':
		case 'x':
			xIsPressed = 1;
			yIsPressed = 0;
			zIsPressed = 0;
			break;
		// Y-axis rotation enabled.
		case 'Y':
		case 'y':
			yIsPressed = 1;
			xIsPressed = 0;
			zIsPressed = 0;
			break;
		// Z-axis rotation enabled.
		case 'Z':
		case 'z':
			zIsPressed = 1;
			xIsPressed = 0;
			yIsPressed = 0;
			break;

		// Anti-clockwise rotation enabled.
		case 'A':
		case 'a':
			aIsPressed = 1;
			break;

		// Perform a rotation at i-th cube layer about the X, Y or Z axis.
		case '1':
			if (xIsPressed)
				performRotation(X, 0, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 0, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 0, rotationDirection);
			break;
		case '2':
			if (xIsPressed)
				performRotation(X, 1, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 1, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 1, rotationDirection);
			break;
		case '3':
			if (xIsPressed)
				performRotation(X, 2, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 2, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 2, rotationDirection);
			break;
		case '4':
			if (xIsPressed)
				performRotation(X, 3, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 3, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 3, rotationDirection);
			break;
		case '5':
			if (xIsPressed)
				performRotation(X, 4, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 4, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 4, rotationDirection);
			break;
		case '6':
			if (xIsPressed)
				performRotation(X, 5, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 5, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 5, rotationDirection);
			break;
		case '7':
			if (xIsPressed)
				performRotation(X, 6, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 6, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 6, rotationDirection);
			break;
		case '8':
			if (xIsPressed)
				performRotation(X, 7, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 7, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 7, rotationDirection);
			break;
		case '9':
			if (xIsPressed)
				performRotation(X, 8, rotationDirection);
			else if (yIsPressed)
				performRotation(Y, 8, rotationDirection);
			else if (zIsPressed)
				performRotation(Z, 8, rotationDirection);
			break;
	}
}


void keyUpHandler(unsigned char key, int x, int y)
{
	// Let ongoing rotations finish.
	if (isInRotation)
		return;
	
	switch (key)
	{
		// X-axis rotation disabled.
		case 'X':
		case 'x':
			xIsPressed = 0;
			break;
		// Y-axis rotation disabled.
		case 'Y':
		case 'y':
			yIsPressed = 0;
			break;
		// Z-axis rotation disabled.
		case 'Z':
		case 'z':
			zIsPressed = 0;
			break;

		// Anti-clockwise rotation disabled.
		case 'A':
		case 'a':
			aIsPressed = 0;
			break;
	}
}
