#include "definitions.h"


// The identity matrix.
GLfloat ID_MATRIX[16] = {
	1,		0,		0,		0,
 	0,		1,		0,		0,
	0,		0,		1,		0,
	0,		0,		0,		1
};

// Matrices for clockwise and anti-clockwise rotations about every axis.
GLfloat X_CW_MATRIX[16] = {
	1,		0,		0,		0,
	0,		COS_P,	SIN_P,	0,
	0,		SIN_N,	COS_P,	0,
	0,		0,		0,		1
};

GLfloat X_ACW_MATRIX[16] = {
	1,		0,		0,		0,
	0,		COS_P,	SIN_N,	0,
	0,		SIN_P,	COS_P,	0,
	0,		0,		0,		1
};

GLfloat Y_CW_MATRIX[16] = {
	COS_P,	0,		SIN_N,	0,
	0,		1,		0,		0,
	SIN_P,	0,		COS_P,	0,
	0,		0,		0,		1
};

GLfloat Y_ACW_MATRIX[16] = {
	COS_P,	0,		SIN_P,	0,
	0,		1,		0,		0,
	SIN_N,	0,		COS_P,	0,
	0,		0,		0,		1
};

GLfloat Z_CW_MATRIX[16] = {
	COS_P,	SIN_P,	0,		0,
	SIN_N,	COS_P,	0,		0,
	0,		0,		1,		0,
	0,		0,		0,		1
};

GLfloat Z_ACW_MATRIX[16] = {
	COS_P,	SIN_N,	0,		0,
	SIN_P,	COS_P,	0,		0,
	0,		0,		1,		0,
	0,		0,		0,		1
};


// Multiply two matrices into a resulting matrix.
void multiplyMatrices(GLfloat *result, GLfloat *matrix1, GLfloat *matrix2)
{
	GLfloat tempMatrix[16] = { 0 };

	int i, j, k;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				tempMatrix[4 * i + j] += matrix2[4 * i + k] * matrix1[4 * k + j];

	for (i = 0; i < 16; i++)
		result[i] = tempMatrix[i];
}
