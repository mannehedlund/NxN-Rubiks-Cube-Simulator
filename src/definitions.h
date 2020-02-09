#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define FPS			60
#define TILE_SIZE		30.0f
#define TILE_GAP		0.0f
#define TILE_BORDER_WIDTH 	2.0f
#define ITERATIONS_PER_ROT	9
#define SIN_P 			0.17364817766f	// sin(10°)
#define SIN_N 			-SIN_P			// sin(-10°)
#define COS_P 			0.98480775301f	// cos(10°)
#define COS_N 			-COS_P			// cos(-10°)


typedef enum
{
	X,
	Y,
	Z
} Axis;

typedef enum
{
	CW = 1,
	ACW = -1,
} Direction;


// initialise.c
extern GLint DIM_SIZE, NUM_OF_PIECES, PIECES_PER_SLIVER;
extern GLfloat DRAW_OFFSET;

// display.c
extern GLint xViewRotation, yViewRotation, zoomCoef;

// rotation.c
extern int *indices;
extern GLfloat **rotationMatrix;
extern int isInRotation;

// matrices.c
extern GLfloat ID_MATRIX[16];
extern GLfloat X_CW_MATRIX[16];
extern GLfloat X_ACW_MATRIX[16];
extern GLfloat Y_CW_MATRIX[16];
extern GLfloat Y_ACW_MATRIX[16];
extern GLfloat Z_CW_MATRIX[16];
extern GLfloat Z_ACW_MATRIX[16];


// initialise.c
void initialiseDimSize(int dimSize);
void initialiseArrays();
void initialiseGL();
void initialiseGLUT(int argc, char **argv);
void initialiseMatrix(GLfloat *matrix);

// cleanup.c
void freeArrays();

// display.c
void display(void);
void reshape(int width, int height);

// matrices.c
void multiplyMatrices(GLfloat *result, GLfloat *matrix1, GLfloat *matrix2);

// cube.c
void drawCube();

// rotation.c
void performRotation(Axis rotationAxis, int layer, Direction rotationDirection);

// input.c
void specialKeyDownHandler(int key, int x, int y);
void keyDownHandler(unsigned char key, int x, int y);
void keyUpHandler(unsigned char key, int x, int y);
