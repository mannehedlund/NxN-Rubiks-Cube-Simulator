rubik_cube: src/main.c
	gcc src/initialise.c src/cleanup.c src/display.c src/matrices.c src/cube.c src/rotation.c src/input.c src/main.c -o rubiks -lGL -lGLU -lglut