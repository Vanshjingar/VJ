#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void init() {
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

// Utility to read the color of a pixel
void getPixelColor(int x, int y, float* color) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

// Flood fill implementation
void floodFill(int x, int y, float* fillColor, float* targetColor) {
    float color[3];
    getPixelColor(x, y, color);

    if (color[0] == targetColor[0] && color[1] == targetColor[1] && color[2] == targetColor[2]) {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        // Recursive calls in 4 directions
        floodFill(x+1, y, fillColor, targetColor);
        floodFill(x-1, y, fillColor, targetColor);
        floodFill(x, y+1, fillColor, targetColor);
        floodFill(x, y-1, fillColor, targetColor);
    }
}

void mouse(int btn, int state, int x, int y) {
    y = 480 - y;
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float targetColor[3];
        getPixelColor(x, y, targetColor);

        float fillColor[] = {0, 1, 0};  // Fill with green
        floodFill(x, y, fillColor, targetColor);
    }
}

void world() {
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing a red triangle
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 100);
    glVertex2i(300, 300);
    glVertex2i(450, 100);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(world);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}













AIM : IMPLEMENT THE FOLLOWING POLYGON FILLING METHODS (1 WEEK, 2 HRS)
i) Flood fill / Seed fill

OBJECTIVE :
1) The code contains algorithm to draw polygon using co-ordinate system and in-built line drawing function
2) Both seedfill and floodfill have similar process of color filling, only the difference is in function call and conditions provided

THEORY :
1) How recursive functions work
2) getpixel() and putpixel() in your own framework
3) Difference in boundary fill and seed fill.

1) For drawing polygon:
To fill a polygon, we should first draw a polygon.
Here we are taking (x,y) inputs in an array and drawing line for each consecutive pair of points
Finally, we complete the polygon using joining the first and last point of the polygon
Note: If you know the equivalent polygon drawing version using mouse events to draw polygon using mouse, you can use that instead.

2) For seed fill:
Some people also call this as seed fill algorithm (pixels scatter like seeds of grass)
The ideology is simple.
Condition: check if the color is similar to old color
condition true: put new color, go for surrounding pixels
condition false: return
This is a recursive function
This is the function to fill "bucket" in "paint" app
The surrounding pixels are 4 pixels in direction north, south, east, west to the current pixel

CONCLUSION: Implement the following polygon filling methods 
i) Flood fill / Seed fill 
