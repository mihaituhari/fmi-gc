#include <gl/freeglut.h>

void init(void)
{
    glClearColor(0.282f, 0.545f, 0.639f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void desen(void) // procedura desenare
{
    glColor3f(0.0, 0.0, 1.0); // culoarea punctelor: albastru
    glBegin(GL_POINTS); // reprezinta puncte
    glVertex2i(20, 20);
    glVertex2i(21, 21);
    glVertex2i(22, 22);
    glVertex2i(23, 23);
    glVertex2i(24, 24);
    glVertex2i(100, 100);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // culoarea liniei frante: rosu
    glBegin(GL_LINE_STRIP);
    glVertex2i(0, 0);
    glVertex2i(200, 100);
    glVertex2i(300, 120);
    glEnd();

    glFlush(); // proceseaza procedurile OpenGL cat mai rapid
}


void drawTextMIHAI() {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(6.0);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Litera M
    glBegin(GL_LINES);
    glVertex2i(10, 10);
    glVertex2i(10, 50);
    glVertex2i(10, 50);
    glVertex2i(20, 30);
    glVertex2i(20, 30);
    glVertex2i(30, 50);
    glVertex2i(30, 50);
    glVertex2i(30, 10);
    glEnd();

    // Litera I
    glBegin(GL_LINES);
    glVertex2i(40, 10);
    glVertex2i(40, 50);
    glEnd();

    // Litera H
    glBegin(GL_LINES);
    glVertex2i(50, 10);
    glVertex2i(50, 50);
    glVertex2i(50, 30);
    glVertex2i(60, 30);
    glVertex2i(60, 10);
    glVertex2i(60, 50);
    glEnd();

    // Litera A
    glBegin(GL_LINES);
    glVertex2i(70, 10);
    glVertex2i(80, 50);
    glVertex2i(80, 50);
    glVertex2i(90, 10);
    glVertex2i(75, 30);
    glVertex2i(85, 30);
    glEnd();

    // Litera I
    glBegin(GL_LINES);
    glVertex2i(100, 10);
    glVertex2i(100, 50);
    glEnd();

    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 300); // 1. Pozitionare schimbata
    glutInitWindowSize(900, 700); // 2. Dimensiuni schimbate
    glutCreateWindow("Puncte & Segmente - Mihai Tuhari");

    init();

    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(drawTextMIHAI);
    glutMainLoop();

    return 0;
}
