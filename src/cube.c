#include "header.h"


void drawPiece(float x, float y, float z)
{
	// Translate piece to correct coordinates.
	glTranslatef(
		x * (TILE_SIZE + TILE_GAP),
		y * (TILE_SIZE + TILE_GAP),
		z * (TILE_SIZE + TILE_GAP)
	);

	GLfloat TILE_OFFSET = TILE_SIZE / 2;

	/* ------------ Right side of piece ------------ */

	// Determine if face is outward.
	if (x == DRAW_OFFSET)
		glColor3f(0.051, 0.165, 0.675); // blue
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw right face.
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	// Draw right side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);

		glVertex3f(TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);

		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);

		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	/* ------------ Left side of piece ------------ */

	// Determine if face is outward.
	if (x == -DRAW_OFFSET)
		glColor3f(0.098, 0.608, 0.298); // green
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw left face.
	glBegin(GL_QUADS);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	// Draw left side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	/* ------------ Top side of piece ------------ */

	// Determine if face is outward.
	if (y == DRAW_OFFSET)
		glColor3f(1.000, 1.000, 1.000); // white
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw top face.
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	// Draw top side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	/* ------------ Bottom side of piece ------------ */

	// Determine if face is outward.
	if (y == -DRAW_OFFSET)
		glColor3f(0.996, 0.835, 0.184); // yellow
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw bottom face.
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	// Draw bottom side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET + TILE_BORDER_WIDTH);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET - TILE_BORDER_WIDTH);
	glEnd();

	/* ------------ Front side of piece ------------ */

	// Determine if face is outward.
	if (z == DRAW_OFFSET)
		glColor3f(0.537, 0.071, 0.078); // red
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw front face.
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
	glEnd();

	// Draw front side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET);
	glEnd();

	/* ------------ Back side of piece ------------ */

	// Determine if face is outward.
	if (z == -DRAW_OFFSET)
		glColor3f(1.000, 0.333, 0.145); // orange
	else
		glColor3f(0.05, 0.05, 0.05); // black

	// Draw back face.
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);
	glEnd();

	// Draw back side border.
	glColor3f(0.05, 0.05, 0.05); // black
	glBegin(GL_QUADS);
		glVertex3f(TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET + TILE_BORDER_WIDTH, -TILE_OFFSET);

		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET, -TILE_OFFSET);
		glVertex3f(TILE_OFFSET - TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
		glVertex3f(-TILE_OFFSET + TILE_BORDER_WIDTH, TILE_OFFSET - TILE_BORDER_WIDTH, -TILE_OFFSET);
	glEnd();
}


void drawCube()
{
	int currentPieceIndex = 0;

	// Center cube at the origin and draw pieces outward.
	float x, y, z;
	for (x = -DRAW_OFFSET; x <= DRAW_OFFSET; x++)
		for (y = -DRAW_OFFSET; y <= DRAW_OFFSET; y++)
			for (z = -DRAW_OFFSET; z <= DRAW_OFFSET; z++)
			{
				glPushMatrix();
				// Apply rotation to the current piece.
				glMultMatrixf(rotationMatrix[currentPieceIndex]);
				// Draw the current piece.
				drawPiece(x, y, z);
				glPopMatrix();
				currentPieceIndex++;
			}
}
