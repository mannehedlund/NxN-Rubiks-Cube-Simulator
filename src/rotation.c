#include "header.h"


// Indices to reference each piece of the cube.
int *indices;
// A matrix to store all rotations for all pieces.
GLfloat **rotationMatrix;

// Whether or not a rotation is ongoing.
int isInRotation = 0;

// The detals of an ongoing rotation.
Axis currentRotationAxis;
int currentRotationLayer;
Direction currentRotationDirection;


int getNewPieceIndex(int index, int dim1, int dim2, Axis axis, Direction rotationDirection)
{
	int indexChange;

	// Rotate the dimension indices -90° if the rotation is anti-clockwise.
	if (rotationDirection == ACW)
	{
		int tempDim1 = dim1;
		switch (axis)
		{
			case X:
				dim1 = (DIM_SIZE - 1) - dim2;
				dim2 = tempDim1;
				break;
			case Y:
				dim1 = dim2;
				dim2 = (DIM_SIZE - 1) - tempDim1;
				break;
			case Z:
				dim1 = (DIM_SIZE - 1) - dim2;
				dim2 = tempDim1;
				break;
		}
	}

	// Calculate the required index difference after a rotation.
	switch (axis)
	{
		case X:
			indexChange = ((dim1 + 1) * (DIM_SIZE - 1))
					- (dim2 * (DIM_SIZE + 1));
			break;
		case Y:
			indexChange = (DIM_SIZE * DIM_SIZE * DIM_SIZE)
					- ((dim2 + dim1 + 1) * PIECES_PER_SLIVER + (dim1 - dim2));
			break;
		case Z:
			indexChange = (dim1 + 1) * (DIM_SIZE * (DIM_SIZE - 1))
					- dim2 * (DIM_SIZE * (DIM_SIZE + 1));
			break;
	}

	// Return the index of the piece after its rotation.
	return index + indexChange;
}


void updateIndices(Axis axisToRotate, int layer, Direction rotationDirection)
{
	// Save a copy of the indices array.
	int index, tempIndices[NUM_OF_PIECES];
	for (index = 0; index < NUM_OF_PIECES; index++)
		tempIndices[index] = indices[index];

	// Asssign each piece of the cube its new index.
	int dim1, dim2;
	switch (axisToRotate)
	{
		case X:
			for (dim1 = 0; dim1 < DIM_SIZE; dim1++)
				for (dim2 = 0; dim2 < DIM_SIZE; dim2++)
				{
					index = dim1 + dim2 * DIM_SIZE + layer * PIECES_PER_SLIVER;
					indices[index] = tempIndices[
						getNewPieceIndex(index, dim1, dim2, X, rotationDirection)
					];
				}
			break;
		case Y:
			for (dim1 = 0; dim1 < DIM_SIZE; dim1++)
				for (dim2 = 0; dim2 < DIM_SIZE; dim2++)
				{
					index = dim1 + PIECES_PER_SLIVER * dim2 + layer * DIM_SIZE;
					indices[index] = tempIndices[
						getNewPieceIndex(index, dim1, dim2, Y, rotationDirection)
					];
				}
			break;
		case Z:
			for (dim1 = 0; dim1 < DIM_SIZE; dim1++)
				for (dim2 = 0; dim2 < DIM_SIZE; dim2++)
				{
					index = dim1 * DIM_SIZE + dim2 * PIECES_PER_SLIVER + layer;
					indices[index] = tempIndices[
						getNewPieceIndex(index, dim1, dim2, Z, rotationDirection)
					];
				}
			break;
	}
}


void multiplyRotation(Axis rotationAxis, int layer, Direction rotationDirection)
{
	// Multiply each piece of the cube with the appropriate matrix.
	int i, j;
	switch (rotationAxis)
	{
		case X:
			if (rotationDirection == CW)
				for (i = layer * PIECES_PER_SLIVER; i < (layer + 1) * PIECES_PER_SLIVER; i++)
					multiplyMatrices(
						rotationMatrix[indices[i]],
						X_CW_MATRIX,
						rotationMatrix[indices[i]]
					);
			else
				for (i = layer * PIECES_PER_SLIVER; i < (layer + 1) * PIECES_PER_SLIVER; i++)
					multiplyMatrices(
						rotationMatrix[indices[i]],
						X_ACW_MATRIX,
						rotationMatrix[indices[i]]
					);
			break;
		case Y:
			if (rotationDirection == CW)
				for (i = layer * DIM_SIZE; i < (layer + 1) * DIM_SIZE; i++)
					for (j = 0; j < NUM_OF_PIECES; j += PIECES_PER_SLIVER)
						multiplyMatrices(
							rotationMatrix[indices[i+j]],
							Y_CW_MATRIX,
							rotationMatrix[indices[i+j]]
						);
			else
				for (i = layer * DIM_SIZE; i < (layer + 1) * DIM_SIZE; i++)
					for (j = 0; j < NUM_OF_PIECES; j += PIECES_PER_SLIVER)
						multiplyMatrices(
							rotationMatrix[indices[i+j]],
							Y_ACW_MATRIX,
							rotationMatrix[indices[i+j]]
						);
			break;
		case Z:
			if (rotationDirection == CW)
				for (i = layer; i < NUM_OF_PIECES; i += PIECES_PER_SLIVER)
					for (j = 0; j < PIECES_PER_SLIVER; j += DIM_SIZE)
						multiplyMatrices(
							rotationMatrix[indices[i+j]],
							Z_CW_MATRIX,
							rotationMatrix[indices[i+j]]
						);
			else
				for (i = layer; i < NUM_OF_PIECES; i += PIECES_PER_SLIVER)
					for (j = 0; j < PIECES_PER_SLIVER; j += DIM_SIZE)
						multiplyMatrices(
							rotationMatrix[indices[i+j]],
							Z_ACW_MATRIX,
							rotationMatrix[indices[i+j]]
						);
			break;
	}
}


void rotateSlightly(int iteration)
{
	// Rotate the cube accordingly.
	multiplyRotation(
		currentRotationAxis,
		currentRotationLayer,
		currentRotationDirection
	);
	
	glutPostRedisplay();

	// Call this functions recursively (on a timer) until rotation is complete.
	iteration++;
	if (iteration == ITERATIONS_PER_ROT)
		isInRotation = 0;
	if (isInRotation)
		glutTimerFunc(1000.0 / FPS, &rotateSlightly, iteration);
}


void performRotation(Axis rotationAxis, int layer, Direction rotationDirection)
{
	// Prevent other rotations from starting until this one finishes.
	isInRotation = 1;

	// Save the details of this rotation.
	currentRotationAxis = rotationAxis;
	currentRotationLayer = layer;
	currentRotationDirection = rotationDirection;

	// Start the first recursive iteration of the rotation.
	glutTimerFunc(1000.0 / FPS, &rotateSlightly, 0);

	// Ensure each piece is assigned its new index post-rotation.
	updateIndices(rotationAxis, layer, rotationDirection);
}
