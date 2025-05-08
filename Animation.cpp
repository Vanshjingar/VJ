#include <GL/glut.h>
#include <cmath>

// Ball position and velocity
float x = -0.5f, y = 0.0f;
float vx = 0.001f, vy = 0.02f;
float gravity = -0.0005f;
float radius = 0.05f;

void drawBall(float x, float y) {
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.2, 0.2); // Red color
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = i * 2.0f * 3.14159f / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBall(x, y);
    glutSwapBuffers();
}

void update(int value) {
    // Apply gravity and update position
    vy += gravity;
    y += vy;
    x += vx;

    // Bounce on bottom
    if (y - radius <= -1.0f) {
        y = -1.0f + radius;
        vy = -vy; // No energy loss for continuous bounce
    }

    // Reflect on side walls
    if (x + radius > 1.0f || x - radius < -1.0f) {
        vx = -vx;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // call update ~60 times per second
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Continuous Bouncing Ball");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}








AIM: IMPLEMENT ANIMATION PRINCIPLES FOR ANY OBJECT

OBJECTIVES:
Animation is defined as a series of images rapidly changing to create an illusion of movement. We replace the previous image with a new image which is a little bit shifted. Animation Industry is having a huge market nowadays. To make an efficacious animation there are some principles to be followed. Principle of Animation:

THEORY:
There are 12 major principles for an effective and easy to communicate animation.
Squash and Strech:
This principle works over the physical properties that are expected to change in any process. Ensuring proper squash and stretch makes our animation more convincing.

Anticipation:
Anticipation works on action.Animation has broadly divided into 3 phases:
1. Preparation phase
2. Movement phase
3. Finish

In Reality:- humans and animals move in arcs. Introducing the concept of arcs will increase the realism. This principle of animation helps us to implement the realism through projectile motion also. While performing animation, one should always keep in mind that in reality object takes time to accelerate and slow down. To make our animation look realistic, we should always focus on its slow in and slow out proportion.

Appeal:- Animation should be appealing to the audience and must be easy to understand. The syntax or font style used should be easily understood and appealing to the audience. Lack of symmetry and complicated design of character should be avoided.

Timing:- Velocity with which object is moving effects animation a lot. The speed should be handled with care in case of animation.

3D Effect:- By giving 3D effects we can make our animation more convincing and effective. In 3D Effect, we convert our object in a 3-dimensional plane i.e., X-Y-Z plane which improves the realism of the object.

Staging:- Staging is defined as the presentation of the primary idea, mood or action. It should always be in presentable and easy to manner. The purpose of defining principle is to avoid unnecessary details and
focus on important features only. The primary idea should always be clear and unambiguous.
Secondary Action:
Secondary actions are more important than primary action as they represent the animation as a whole. Secondary actions support the primary or main idea.

Follow Through:- It refers to the action which continues to move even after the completion of action. This type of action helps in the generation of more idealistic animations.

Overlap:- It deals with the nature in which before ending the first action, the second action starts.

CONCLUSION : Thus we have to studied the implement animation principles for any object