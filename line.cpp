#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
int ch = 0;
void display(int x, int y)
{
glColor3f(0,0,0);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void displaydotted(int x, int y)
{
glColor3f(0,0,0);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void displaydashed(int x, int y)
{
glColor3f(0,0,0);
glPointSize(3);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void displaysolid(int x, int y)
{
glColor3f(0,0,0);
glPointSize(6);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void SimpleLine(int x1, int y1, int x2, int y2){
float dx = x2 - x1;
float dy = y2 - y1;
int steps;
if(abs(dx) >= abs(dy))
{
steps = abs(dx);
}
else{
steps = abs(dy);
}
float Xin = dx / (float) steps;
float Yin = dy / (float) steps;
float x = x1;
float y = y1;
for(int i=0; i<=steps; i++)
{
display(x, y);
x = x + Xin;
y = y + Yin;
}
glFlush();
}
void DottedLine(int x1, int y1, int x2, int y2)
{
float dx = x2 - x1;
float dy = y2 - y1;
int steps;
if(abs(dx) >= abs(dy))
{
steps = abs(dx);
}
else
{
steps = abs(dy);
}
float Xin = dx / (float) steps;
float Yin = dy / (float) steps;
float x = x1;
float y = y1;
for(int i=0; i<=steps; i++)
{
if(i % 6 == 0)
{
displaydotted(x, y);
}
x = x + Xin;
y = y + Yin;
}
glFlush();
}
void DashLine(int x1, int y1, int x2, int y2)
{
float dx = x2 - x1;
float dy = y2 - y1;
int steps;
if(abs(dx) >= abs(dy))
{
steps = abs(dx);}
else
{
steps = abs(dy);
}
float Xin = dx / (float) steps;
float Yin = dy / (float) steps;
float x = x1;
float y = y1;
for(int i=0; i<=steps; i++)
{
if(i % 8 > 4)
{
displaydashed(x, y);
}
x = x + Xin;
y = y + Yin;
}
glFlush();
}
void SolidLine(int x1, int y1, int x2, int y2)
{
float dx = x2 - x1;
float dy = y2 - y1;
int steps;
if(abs(dx) >= abs(dy))
{
steps = abs(dx);
}
else
{
steps = abs(dy);
}
float Xin = dx / (float) steps;
float Yin = dy / (float) steps;
float x = x1;
float y = y1;
for(int i=0; i<=steps; i++)
{
displaydashed(x, y);
x = x + Xin;
y = y + Yin;
}
glFlush();
}
void mouse(int button, int state, int x, int y)
{
static int x1, y1, pt = 0;
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
if (pt == 0){
x1 = x;
y1 = y;
pt = pt + 1;
}
else
{
if (ch == 1)
{
SimpleLine(x1, y1, x, y);
}
else if (ch == 2)
{
DottedLine(x1, y1, x, y);
}
else if (ch == 3)
{
DashLine(x1, y1, x, y);
}
else if(ch == 4)
{
SolidLine(x1, y1, x, y);
}
x1 = x;
y1 = y;
}
}
else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
pt = 0;
}
glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 's':
{
ch = 1;
cout << "Simple Line" << endl;
glutMouseFunc(mouse);
break;
}
case 'd':
{
ch = 2;
cout << "Dotted Line" << endl;glutMouseFunc(mouse);
break;
}
case 'D':
{
ch = 3;
cout << "Dashed Line" << endl;
glutMouseFunc(mouse);
break;
}
case 'S':
{
ch = 4;
cout << "Solid Line" << endl;
glutMouseFunc(mouse);
break;
}
}
glutPostRedisplay();
}
void initialize()
{
glClearColor(0.5F,0.5F,0.5F,1.0F);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(0, 600, 600, 0);
}
void initialaxis(){
glColor3f(0,0,0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2i(300, 0);
glVertex2i(300, 600);
glVertex2i(0, 300);
glVertex2i(600, 300);
glEnd();
glFlush();
glutKeyboardFunc(keyboard);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(600, 600);glutInitWindowPosition(800, 100);
glutCreateWindow("algorith of dda");
initialize();
cout << "Choose which Line pattern you want: " << endl;
cout << " " << endl;
cout << "s: simple" << endl;
cout << "d: dotted" << endl;
cout << "D: Dashed" << endl;
cout << "S: Solid" << endl;
cout << " " << endl;
glutDisplayFunc(initialaxis);
glutMainLoop();
return 0;
}








AIM : Implement DDA and Bresenham line drawing algorithm to draw
I) Simple line
ii) Dotted line
iii) Dashed line
iv) Solid line
using mouse interface. Divide the screen in four quadrants with center as (0, 0). The line should work
for all the slopes +ve, -ve, >1,<1

OBJECTIVE:
1. Understand bresenham line drawing algorithm.
2. Understand 2 D transformations
3. Understand seed fill algorithm
4. Further using these algorithms to draw real time pictures
5. To Learn openGL functions

OUTCOME:
1. Apply and implement line drawing and circle drawing algorithms to draw specific shape
given in theproblem.
2. Apply and implement polygon filling algorithm for a given polygon

Problem Statement:
Implement DDA and Bresenham line drawing algorithm to draw:
i) Simple Line ii) Dotted Line iii) Dashed Line iv) Solid line
using mouse interface Divide the screen in four quadrants with center as (0, 0). The line should
work for all the slopes positive as well as negative.


The DDA (Digital Differential Analyzer) line drawing algorithm is a simple and efficient algorithm used in computer graphics to draw lines between two points. It works by calculating intermediate points along the line path between a start and end point using the line equation.


Steps of the DDA Line Drawing Algorithm:
1.Input the starting point(x0,y0) and the ending point (x1,y1).
2.Calculate the differences:
   dx=x1-x0, dy=y1-y0
3.Determine the number of steps required to generate pixels:
   steps=max(|dx|,|dy|)
4.Calculate the increment for each step:
   xinc=dx\steps, yinc=dy\steps
5.Initialize:
   x=x0, y=y0
6.Loop through each step and plot the pixel at the rounded coordinates:
   * Plot (round(x), round(y))
   * Update:
     x=x+xinc, y=y+yinc

Example:
Given:Start point (2, 3) and end point (10, 8)
1.dx=10-2=8
2.dy=8-3=5
3.steps=max(|8|,|5|)=8
4.xinc=8/8=1.0, yinc=5/8=0.625
5.Start at x=2.0, y=3.0

Now compute and plot:

| Step | x    | y     | Rounded (x, y) |
| ---- | ---- | ----- | -------------- |
| 0    | 2.0  | 3.0   | (2, 3)         |
| 1    | 3.0  | 3.625 | (3, 4)         |
| 2    | 4.0  | 4.25  | (4, 4)         |
| 3    | 5.0  | 4.875 | (5, 5)         |
| 4    | 6.0  | 5.5   | (6, 6)         |
| 5    | 7.0  | 6.125 | (7, 6)         |
| 6    | 8.0  | 6.75  | (8, 7)         |
| 7    | 9.0  | 7.375 | (9, 7)         |
| 8    | 10.0 | 8.0   | (10, 8)        |

