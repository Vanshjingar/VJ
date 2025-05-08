#include <GL/glut.h>
#include <math.h>

// 3 Control points (Quadratic Bézier)
float ctrlPoints[3][2] = {
    {-0.9, -0.9},
    { 0.0,  0.9},
    { 0.9, -0.9}
};

void drawBezierCurve() {
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.001) {
        float u = 1 - t;

        float x = u * u * ctrlPoints[0][0] +
                  2 * u * t * ctrlPoints[1][0] +
                  t * t * ctrlPoints[2][0];

        float y = u * u * ctrlPoints[0][1] +
                  2 * u * t * ctrlPoints[1][1] +
                  t * t * ctrlPoints[2][1];

        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0); // Yellow curve
    drawBezierCurve();

    glColor3f(1.0, 0.0, 0.0); // Red control points
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 3; i++)
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);           // Background black
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   // 2D view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Bézier Curve");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}












AIM: GENERATE FRACTAL PATTERNS USING I) BEZIER CURVE

OBJECTIVE:
Bezier Curves: Properties of Bezier Curves
Bezier curves have the following properties
They generally follow the shape of the control polygon, which consists of the segments joining the  control points.
They always pass through the first and last control points.
They are contained in the convex hull of their defining control points.
The degree of the polynomial defining the curve segment is one less that the number of defining polygon point. Therefore, for 4 control points, the degree of the polynomial is 3, i.e. cubic polynomial.
A Bezier curve generally follows the shape of the defining polygon.
The direction of the tangent vector at the end points is same as that of the vector determined by first and last segments.
The convex hull property for a Bezier curve ensures that the polynomial smoothly follows the control points.
No straight line intersects a Bezier curve more times than it intersects its control polygon.
They are invariant under an affine transformation.
Bezier curves exhibit global control means moving a control point alters the shape of the whole curve.
A given Beziercurve can be subdivided at a point t=t0 into two Bezier segments which join together at the point corresponding to the parameter value t=t0.

Algorithm:
1.Input: A set of control points P0, P1, ..., Pn
2.Choose a resolution (i.e., how many points you want to generate along the curve)
3.For each value of t from 0 to 1 (incremented by step size):
*Recursively interpolate points between control points:
*First level: Interpolate between P0 and P1,P1 and P2, ..., Pn-1 and Pn
*Continue interpolating between resulting points until only one point remains.
*This final point is a point on the Bezier curve.
4.Plot all the computed points to form the curve.

CONCLUSION: Thus we have to studied Different kind of curve and its implementation