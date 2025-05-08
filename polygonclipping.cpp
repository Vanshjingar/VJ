#include <GL/glut.h>
#include <iostream>
using namespace std;
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
const float x_min = -0.5, y_min = -0.5, x_max = 0.5, y_max = 0.5;
int computeCode(float x, float y) {
    int code = INSIDE;
    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;
    return code;
}
bool cohenSutherlandLineClip(float &x0, float &y0, float &x1, float &y1) {
    int code0 = computeCode(x0, y0);
    int code1 = computeCode(x1, y1);
    bool accept = false;
    while (true) {
        if ((code0 == 0) && (code1 == 0)) {
            accept = true;
            break;
        } else if ((code0 & code1) != 0) {
            break;
        } else {
            int code_out = code0 ? code0 : code1;
            float x, y;
            if (code_out & TOP) {
                x = x0 + (x1 - x0) * (y_max - y0) / (y1 - y0);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x0 + (x1 - x0) * (y_min - y0) / (y1 - y0);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y0 + (y1 - y0) * (x_max - x0) / (x1 - x0);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y0 + (y1 - y0) * (x_min - x0) / (x1 - x0);
                x = x_min;
            }
            if (code_out == code0) {
                x0 = x;
                y0 = y;
                code0 = computeCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
        }
    }

    return accept;
}

void drawLine(float x0, float y0, float x1, float y1) {
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
}

void drawClippingWindow() {
    glBegin(GL_LINE_LOOP);
        glVertex2f(x_min, y_min);
        glVertex2f(x_min, y_max);
        glVertex2f(x_max, y_max);
        glVertex2f(x_max, y_min);
    glEnd();
}

void displayOriginalLine() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawClippingWindow();

    float x0 = -0.8f, y0 = -0.7f, x1 = 0.9f, y1 = 0.8f;

    glColor3f(0.0f, 1.0f, 0.0f);
    drawLine(x0, y0, x1, y1);

    glFlush();
}

void displayClippedLine() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawClippingWindow();

    float x0 = -0.8f, y0 = -0.7f, x1 = 0.9f, y1 = 0.8f;

    if (cohenSutherlandLineClip(x0, y0, x1, y1)) {
        glColor3f(0.0f, 1.0f, 0.0f);
        drawLine(x0, y0, x1, y1);
    } else {
        glColor3f(1.0f, 0.0f, 0.0f);
        drawLine(x0, y0, x1, y1);
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(500, 500);
    glutCreateWindow("Original Line (Unclipped)");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(displayOriginalLine);
    
    glutInitWindowSize(500, 500);
    glutCreateWindow("Clipped Line");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(displayClippedLine);
    glutMainLoop();
    return 0;
}











AIM: Implement Cohen Sutherland polygon clipping method to clip the polygon with respect the view-port and window.

THEORY: Line Clipping – Cohen Sutherland
In computer graphics, 'line clipping' is the process of removing lines or portions of lines outside of an area of interest. Typically, any line or part thereof which is outside of the viewing area is removed.

The Cohen–Sutherland algorithm is a computer graphics algorithm used for line clipping. The algorithm divides a two-dimensional space into 9 regions (or a three-dimensional space into 27 regions), and then efficiently determines the lines and portions of lines that are visible in the center region of interest (the viewport).

The algorithm was developed in 1967 during flight simulator work by Danny Cohen and Ivan Sutherland The design stage includes, excludes or partially includes the line based on where:
Both endpoints are in the viewport region (bitwise OR of endpoints == 0): trivial accept.

Both endpoints share at least one non-visible region which implies that the line does not cross the visible region. (bitwise AND of endpoints != 0): trivial reject.

Both endpoints are in different regions: In case of this nontrivial situation the algorithm finds one of the two points that is outside the viewport region (there will be at least one point outside). The intersection of the outpoint and extended viewport border is then calculated (i.e. with the parametric equation for the line) and this new point replaces the outpoint. The algorithm repeats until a trivial accept or reject occurs.

The numbers in the figure below are called outcodes. The outcode is computed for each of the two points in the line. The outcode will have four bits for two-dimensional clipping, or six bits in the three-dimensional case. The first bit is set to 1 if the point is above the viewport. The bits in the 2D outcode  represent: Top, Bottom, Right, Left. For example the outcode 1010 represents a point that is top-right of the viewport. Note that the outcodes for endpoints must be recalculated on each iteration after the clipping occurs.
1001 1000 1010
0001 0000 0010
0101 0100 0110

Sutherland Hodgman Polygon Clipping:-
It is used for clipping polygons. It works by extending each line of the convex clip polygon in turn and selecting only vertices from the subject polygon those are on the visible side.

An algThe algorithm begins with an input list of all vertices in the subject polygon. Next, one side of the clip polygon is extended infinitely in both directions, and the path of the subject polygon is traversed. Vertices from the input list are inserted into an output list if they lie on the visible side of the extended clip polygon line, and new vertices are added to the output list where the subject polygon path crosses the extended clip polygon line.

This process is repeated iteratively for each clip polygon side, using the output list from one stage as the input list for the next. Once all sides of the clip polygon have been processed, the final generated list of vertices defines a new single polygon that is entirely visible. Note that if the subject polygon was concave at vertices outside the clipping polygon, the new polygon may have coincident (i.e. overlapping) edges – this is acceptable for rendering, but not for other applications such as computing shadows.

Clipping ping polygons would seem to be quite complex. A single polygon can actually be split into multiple polygons .The Sutherland-Hodgman algorithm clips a polygon against all edges of the clipping region in turn. The algorithm steps from vertex to vertex, adding 0, 1, or 2 vertices to the output list at each step. The Sutherland-Hodgeman Polygon-Clipping Algorithms clips a given polygon successively against the edges of the given clip-rectangle. These clip edges are denoted with e1, e2, e3, and e4, here. The closed polygon is represented by a list of its verteces (v1 to vn; Since we got 15 verteces in the example shown
above, vn = v15.).

Clipping is computed successively for each edge. The output list of the previous clipping run is used as the inputlist for the next clipping run. 1st run: Clip edge: e1; inputlist = {v1, v2, ..., v14, v15}, the given polygon

CONCLUSION : In this way we studied the Cohen Sutherland polygon clipping and Line Clipping algorithm.