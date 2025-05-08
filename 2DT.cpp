#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;
float trianglePoints[3][2] = {
    {0.0f, 0.5f},
    {-0.5f, -0.5f},
    {0.5f, -0.5f}
};
float scaleX = 1.0f, scaleY = 1.0f;
float angle = 0.0f;
bool reflectX = false;
float translationX = 0.0f;
void drawTriangle(float points[3][2]) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}
void applyTransformations() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f);
    drawTriangle(trianglePoints);
    glPopMatrix();
    float transformedTriangle[3][2];
    for (int i = 0; i < 3; i++) {
        transformedTriangle[i][0] = trianglePoints[i][0] * scaleX;
        transformedTriangle[i][1] = trianglePoints[i][1] * scaleY;
    }
    float tempX, tempY;
    float rad = angle * M_PI / 180.0f;
    for (int i = 0; i < 3; i++) {
        tempX = transformedTriangle[i][0] * cos(rad) - transformedTriangle[i][1] * sin(rad);
        tempY = transformedTriangle[i][0] * sin(rad) + transformedTriangle[i][1] * cos(rad);
        transformedTriangle[i][0] = tempX;
        transformedTriangle[i][1] = tempY;
    }
    if (reflectX) {
        for (int i = 0; i < 3; i++) {
            transformedTriangle[i][1] = -transformedTriangle[i][1];
        }
    }
    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(translationX, 0.0f, 0.0f);
    drawTriangle(transformedTriangle);
    glPopMatrix();
    glutSwapBuffers();
}
void updateTransformations(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            scaleX += 0.1f;
            scaleY += 0.1f;
            break;
        case 'r':
            angle += 5.0f;
            break;
        case 't':
            translationX += 0.2f;
            if (translationX > 2.0f) {
                translationX = -2.0f;
            }
            break;
        case 'f':
            reflectX = !reflectX;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0f, 2.0f, -2.0f, 2.0f);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle Transformations");
    init();
    glutDisplayFunc(applyTransformations);
    glutKeyboardFunc(updateTransformations);
    glutMainLoop();
    return 0;
}










AIM : IMPLEMENT FOLLOWING 2D TRANSFORMATIONS ON THE OBJECT WITH RESPECT TO AXIS
a. Scaling b. Rotation about arbitrary point c. Reflection

OBJECTIVE :
It is a process of changing the angle of the object. Rotation can be clockwise or anticlockwise. For rotation, we have to specify the angle of rotation and rotation point. Rotation point is also called a pivot point. It is print about which object is rotated.
TYPES OF ROTATION:
1. Anticlockwise
2. Counterclockwise

The positive value of the pivot point (rotation angle) rotates an object in a counter-clockwise (anticlockwise) direction. 
The negative value of the pivot point (rotation angle) rotates an object in a clockwise direction.
When the object is rotated, then every point of the object is rotated by the same angle. 
Straight Line: Straight Line is rotated by the endpoints with the same angle and redrawing the line between new endpoints. 
Polygon: Polygon is rotated by shifting every vertex using the same rotational angle. 
Curved Lines: Curved Lines are rotated by repositioning of all points and drawing of the curve at new positions.
Circle: It can be obtained by center position by the specified angle.
Ellipse: Its rotation can be obtained by rotating major and minor axis of an ellipse by the desired angle.
Matrix for rotation is a clockwise direction.
Matrix for rotation is an anticlockwise direction.
Matrix for homogeneous co-ordinate rotation (clockwise)
Matrix for homogeneous co-ordinate rotation (anticlockwise)

Rotation about an arbitrary point: If we want to rotate an object or point about an arbitrary point, first of all, we translate the point about which we want to rotate to the origin. Then rotate point or object about the origin, and at the end, we again translate it to the original place. We get rotation about an
arbitrary point.

Composite Transformation:
A number of transformations or sequence of transformations can be combined into single one called as composition. The resulting matrix is called as composite matrix. The process of combining is called as concatenation.
Suppose we want to perform rotation about an arbitrary point, then we can perform it by the sequence of three transformations
1. Translation
2. Rotation
3. Reverse Translation

The ordering sequence of these numbers of transformations must not be changed. If a matrix is represented in column form, then the composite transformation is performed by multiplying matrix in order from right to left side. The output obtained from the previous matrix is multiplied with the new coming matrix.

CONCLUSION : I studied 2d Composite transformation having 2D Translation Scaling, Rotation.

