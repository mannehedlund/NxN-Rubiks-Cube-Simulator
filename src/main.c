#include "definitions.h"


int main(int argc, char **argv)
{
	int dimSize = atoi(argv[1]);
	initialiseDimSize(dimSize);
	initialiseArrays();
	initialiseGLUT(argc, argv);
	initialiseGL();

	glutMainLoop();

	return 0;
}
