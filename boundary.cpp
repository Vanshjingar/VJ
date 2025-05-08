#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
void init(){
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,640,0,480);
}
void bound_it(int x, int y, float* fillColor, float* bc){
 float color[3];
 glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
 if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
 color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
 glColor3f(fillColor[0],fillColor[1],fillColor[2]);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
 glFlush();
 bound_it(x+1,y,fillColor,bc);
 bound_it(x-2,y,fillColor,bc);
 bound_it(x,y+2,fillColor,bc);
 bound_it(x,y-2,fillColor,bc);
 bound_it(x-1,y-1,fillColor,bc);
 bound_it(x-1,y+1,fillColor,bc);
 bound_it(x+1,y-1,fillColor,bc);
 bound_it(x+1,y+1,fillColor,bc);
 }
}
void mouse(int btn, int state, int x, int y){
 y = 480-y;
 if(btn==GLUT_LEFT_BUTTON)
 {
 if(state==GLUT_DOWN)
 {
 float bCol[] = {1,0,0};
 float color[] = {0,0,1};
 bound_it(x,y,color,bCol);
 }
 }
}
void world(){
 glLineWidth(3);
 glPointSize(2);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(150,100);
 glVertex2i(300,300);
 glVertex2i(450,100);
 glEnd();
 glFlush();
}
int main(int argc, char** argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(640,480);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Boundary Fill Algorithm");
 glutDisplayFunc(world);
 glutMouseFunc(mouse);
 init();
 glutMainLoop();
 return 0;
}









AIM : IMPLEMENT THE FOLLOWING POLYGON FILLING METHODS 
i) Boundary fill

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


3) For boundary fill:
Some people also call this as block fill algorithm (pixels scatter like seeds of grass) The ideology is different than seed fill. Regardless of old pixel value, one fills the whole polygon based until boundary not reached Condition: check if the color not new color and check if color is not boundary color condition true: put new color, go for surrounding pixels condition false: return This is a recursive function The surrounding pixels are 4 pixels in direction north, south, east, west to the current pixel.

CONCLUSION: Implement the following polygon filling methods
i) Boundary fill