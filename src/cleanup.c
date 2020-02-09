#include "definitions.h"


void freeArrays()
{
	int i;
	for (i = 0; i < NUM_OF_PIECES; i++)
		free(rotationMatrix[i]);

	free(rotationMatrix);
	free(indices);
}
