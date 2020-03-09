#include "header.h"


// "Constants" used to reference the NxN cube.
GLint DIM_SIZE, NUM_OF_PIECES, PIECES_PER_SLIVER;
GLfloat DRAW_OFFSET;


void initialiseDimSize(int dimSize)
{
	// Set "constants".
	DIM_SIZE = dimSize;
	NUM_OF_PIECES = DIM_SIZE * DIM_SIZE * DIM_SIZE;
	PIECES_PER_SLIVER = DIM_SIZE * DIM_SIZE;
	DRAW_OFFSET = (DIM_SIZE - 1.0f) / 2;
}


void initialiseArrays()
{
	indices = malloc(NUM_OF_PIECES * sizeof(int));
	rotationMatrix = malloc(NUM_OF_PIECES * sizeof(GLfloat[16]));

	// Ensure malloc is sucessful.
	if (indices == NULL || rotationMatrix == NULL)
		return;

	int index;
	for (index = 0; index < NUM_OF_PIECES; index++)
	{
		rotationMatrix[index] = malloc(16 * sizeof(GLfloat));

		// Ensure malloc is sucessful.
		if (rotationMatrix[index] == NULL)
			return;

		// Assign identity matrix.
		initialiseMatrix(rotationMatrix[index]);
		// Assign index.
		indices[index] = index;
	}
}


void initialiseGL()
{
	// Background color.
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Clear depth buffer.
	glClearDepth(1.0f);

	// Render depth.
	glEnable(GL_DEPTH_TEST);

	// Smooth lines.
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void initialiseGLUT(int argc, char **argv)
{
	glutInit(&argc, argv);

	// Define window properties.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rubik's Cube");

	// Assign callback functions.
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDownHandler);
	glutKeyboardUpFunc(keyUpHandler);
	glutSpecialFunc(specialKeyDownHandler);
}


void initialiseMatrix(GLfloat *matrix)
{
	// Load the ID matrix into the given matrix.
	int i;
	for (i = 0; i < 16; i++)
		matrix[i] = ID_MATRIX[i];
}
