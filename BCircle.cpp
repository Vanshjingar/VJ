#include <GL/freeglut.h>
#include <iostream>
int r, xc, yc, x, y;
float p;
void putPixel(int px, int py)
{
glBegin(GL_POINTS);
glVertex2f((float)px, (float)py);
glEnd();
}
void plotPoints(int px, int py)
{
putPixel(xc + px, yc + py);
putPixel(xc + py, yc + px);
putPixel(xc + py, yc - px);
putPixel(xc + px, yc - py);
putPixel(xc - px, yc - py);
putPixel(xc - py, yc - px);
putPixel(xc - px, yc + py);
putPixel(xc + py, yc - px);
putPixel(xc - py, yc + px);
}
void drawCircle()
{
glBegin(GL_LINES);
glVertex2f(-640.0F, 0);
glVertex2f(640.0F, 0);
glVertex2f(0, -480.0F);
glVertex2f(0, 480.0F);
glEnd();
p = 1.25F - (float)r;
x = 0, y = r;
while (x < y) {
plotPoints(x, y);
if (p < 0) {p += 2.0F * (float)x + 1.0F;
}
else if (p >= 0) {
--y;
p += 2.0F * (float)(x - y) + 1.0F;
}
++x;
}
glFlush();
}
void init()
{
glOrtho(-640.0, 640.0, -480.0, 480.0, -1.0, 1.0);
glClearColor(1.0F, 0.0F, 0.0F, 0.0F);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0F, 1.0F, 1.0F);
}
int main(int argc, char **argv)
{
std::cout << "Enter radius: ";
std::cin >> r;
std::cout << "Enter X coordinate of center: ";
std::cin >> xc;
std::cout << "Enter Y coordinate of center: ";
std::cin >> yc;
r = r * 16;
xc = xc * 16;
yc = yc * 16;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(640, 480);
glutInitWindowPosition(400, 150);
glutCreateWindow("Bresenham's Circle Drawing Algorithm");
init();
glutDisplayFunc(drawCircle);
glutMainLoop();
return 0;
}





AIM: Implement Bresenham circle drawing algorithm to draw any object. The object
should be displayed in all the quadrants with respect to center and radius

PROBLEM STATEMENT : Draw inscribed and Circumscribed circles in the triangle as shown as an example below (Use any Circle drawing and Line drawing algorithms).

OBJECTIVE:
1. Understand bresenham circle drawing algorithm.
2. Further using these algorithms to draw real time pictures
3. To Learn openGL functions

OUTCOME:
Apply and implement line drawing and circle drawing algorithms to draw specific shape given in
the problem.

THEORY:
Bresenham’s Circle Drawing:
A circle is a symmetrical figure. It has eight - way symmetry. If we know any single point of circle we can plot all remaining seven pixels using 8- way symmetry. This algorithm considers 8 –way symmetry of circle and generates the whole circle. 1/8th part of circle i.e. from 90° to 45° is drawn, during this x increments in positive direction and y increments in negative direction. In this algorithm we have to select proper pixel which is either on the circle or closed to the circle port.

Decision Variable is given as d = 3 -2r
Both of these algorithms uses the key feature of circle that it is highly symmetric. So, for whole 360 degree of circle we will divide it in 8-parts each octant of 45 degree. In order to do that we will use Bresenham’s Circle Algorithm for calculation of the locations of the pixels in the first octant of 45 degrees. It assumes that the circle is centered on the origin. So for every pixel (x, y) it calculates, we draw a pixel in each of the 8 octants of the circle as shown below :

Now, we will see how to calculate the next pixel location from a previously known pixel location (x, y). In Bresenham’s algorithm at any point (x, y) we have two option either to choose the next pixel in the east i.e. (x+1, y) or in the south east i.e. (x+1, y-1).

And this can be decided by using the decision parameter d as:
• If d > 0, then (x+1, y-1) is to be chosen as the next pixel as it will be closer to the arc.
• else (x+1, y) is to be chosen as next pixel.
Now to draw the circle for a given radius ‘r’ and centre (xc, yc) We will start from (0, r) and move in first quadrant till x=y (i.e. 45 degree). We should start from listed initial condition:
d = 3 - (2 * r)
x = 0
y = r

Now for each pixel, we will do the following operations:
1. Set initial values of (xc, yc) and (x, y)
2. Set decision parameter d to d = 3 – (2 * r).
3. call drawCircle(int xc, int yc, int x, int y) function.
4. Repeat steps 5 to 8 until x < = y
5. Increment value of x.
6. If d < 0, set d = d + (4*x) + 6
7. Else, set d = d + 4 * (x – y) + 10 and decrement y by 1.
8. call drawCircle(int xc, int yc, int x, int y) function

CONCLUSION: Hence we are able to implement algorithm for circle drawing.



