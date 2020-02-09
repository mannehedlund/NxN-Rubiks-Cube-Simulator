# NxN-Rubiks-Cube-Simulator
OpenGL implementation of a Rubik's cube of any size with simulated rotations.

See demo below:

![Demo](demo.gif)

### Usage

Run `make` in the command line to compile. In the same directory, run `./rubiks N` to start the program, where N is the dimension size of the Rubik's cube. There are not enough hotkeys to rotate all slivers of a cube greater than 9x9. However, the program will create a cube of ANY size (although 100x100 will not be processor-friendly).

The hotkeys are as follows.

| Key  | Effect |
| ------------- | ------------- |
| ARROW_UP  | Camera Up  |
| ARROW_DOWN  | Camera Down  |
| ARROW_LEFT  | Camera Left  |
| ARROW_RIGHT  | Camera Right  |
| +  | Zoom In  |
| -  | Zoom Out |
| R  | Reset Cube  |
| X (pressed)  | Make Cube Rotate about X-Axis |
| Y (pressed)  | Make Cube Rotate about Y-Axis |
| Z (pressed)  | Make Cube Rotate about Z-Axis |
| A (pressed)  | Enable -90° rotation |
| 1  | Rotate 1st Layer of Cube |
| 2  | Rotate 2nd Layer of Cube |
| 3  | Rotate 3rd Layer of Cube |
| 4  | Rotate 4th Layer of Cube |
| 5  | Rotate 5th Layer of Cube |
| 6  | Rotate 6th Layer of Cube |
| 7  | Rotate 7th Layer of Cube |
| 8  | Rotate 8th Layer of Cube |
| 9  | Rotate 9th Layer of Cube |
