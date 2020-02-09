#include "definitions.h"


void freeArrays()
{
	int index;
	for (index = 0; index < NUM_OF_PIECES; index++)
		free(rotationMatrix[index]);

	free(rotationMatrix);
	free(indices);
}
