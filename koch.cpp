#include <GL/glut.h>
#include <math.h>

void drawKoch(float x1, float y1, float x2, float y2, int depth) {
    if (depth == 0) {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        return;
    }

    float dx = (x2 - x1) / 3.0;
    float dy = (y2 - y1) / 3.0;

    // Points dividing the line into 3 segments
    float xA = x1 + dx;
    float yA = y1 + dy;

    float xB = x1 + 2 * dx;
    float yB = y1 + 2 * dy;

    // Coordinates of the peak of the equilateral triangle
    float xM = (x1 + x2) / 2.0;
    float yM = (y1 + y2) / 2.0;

    float px = xA + (dx * cos(M_PI / 3)) - (dy * sin(M_PI / 3));
    float py = yA + (dx * sin(M_PI / 3)) + (dy * cos(M_PI / 3));

    // Recursive calls for each new segment
    drawKoch(x1, y1, xA, yA, depth - 1);
    drawKoch(xA, yA, px, py, depth - 1);
    drawKoch(px, py, xB, yB, depth - 1);
    drawKoch(xB, yB, x2, y2, depth - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2, 0.7, 1.0);
    glBegin(GL_LINES);

    drawKoch(-0.8f, 0.0f, 0.8f, 0.0f, 4);  // Increase depth for more detail

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1); // Background: black
    glColor3f(1, 1, 1);       // Draw color: white
    gluOrtho2D(-1, 1, -1, 1); // 2D projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Koch Curve - 4 Control Points");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}













AIM: GENERATE FRACTAL PATTERNS USING I) KOCH CURVE

OBJECTIVE:
Koch Curve :
Fractals are geometric objects. Many real-world objects like ferns are shaped like fractals. Fractals are formed by iterations. Fractals are self-similar.

In computer graphics, we use fractal functions to create complex object
The object representations uses Euclidean-geometry methods; that is, object shapes were described with equations. These methods are adequate for describing manufactured objects: those that have smooth surfaces and regular shapes. But natural objects, such as mountains and clouds, have irregular or fragmented features, and Euclidean methods do not realistically model these objects. Natural objects can be realistically described with fractal-geometry methods, where procedures rather than equations are used to model objects.

In computer graphics, fractal methods are used to generate displays of natural objects and visualizations The self-similarity properties of an object can take different forms, depending on the choice of fractal representation.

In computer graphics, we use fractal functions to create complex objects
A mountain outlined against the sky continues to have the same jagged shape as we view it from a closer and closer. We can describe the amount of variation in the object detail with a number called the fractal dimension.

ALGORITHM:
Algorithm Steps: Koch Curve
Input:
* Starting point A(x1, y1)
* Ending point B(x2, y2)
* Recursion depth n

Algorithm (Recursive):
Function KochCurve(A, B, n):
    If n == 0:
        Draw line from A to B
    Else:
        1. Compute point C = 1/3 point between A and B
        2. Compute point D = 2/3 point between A and B
        3. Compute point E (peak of the triangle) using:
           - E forms an equilateral triangle with C and D
           - Rotate vector CD by 60° counterclockwise
        4. Recursively call:
            KochCurve(A, C, n - 1)
            KochCurve(C, E, n - 1)
            KochCurve(E, D, n - 1)
            KochCurve(D, B, n - 1)

CONCLUSION: Thus we have to studied Different kind of curve and its implementation.
