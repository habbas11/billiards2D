#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

const GLfloat PI = acos(-1);

void drawTable() {
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glBegin(GL_POLYGON);                        // Middle circle
//    double radius = 22;
//    double ori_x = 70.0;                         // the origin or center of circle
//    double ori_y = 716.0;
//    for (int i = 0; i <= 300; i++) {
//        double angle = 2 * PI * i / 300;
//        double x = cos(angle) * radius;
//        double y = sin(angle) * radius;
//        glVertex2d(ori_x + x, ori_y + y);
//    }
//    glEnd();

    // ==== CORNERS
    // top left corner
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 716.0f);
    glVertex2f(0.0f, 800.0f);
    glVertex2f(70.0f, 800.0f);
    glVertex2f(70.0f, 716.0f);
    glEnd();

    // down left corner
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 84.0f);
    glVertex2f(70.0f, 84.0f);
    glVertex2f(70.0f, 0.0f);
    glEnd();

    // mid up corner (maybe)
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(470.0f, 716.0f);
    glVertex2f(470.0f, 800.0f);
    glVertex2f(530.0f, 800.0f);
    glVertex2f(530.0f, 716.0f);
    glEnd();

    // mid down corner (maybe)
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(470.0f, 0.0f);
    glVertex2f(470.0f, 84.0f);
    glVertex2f(530.0f, 84.0f);
    glVertex2f(530.0f, 0.0f);
    glEnd();

    // down right corner
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(930.0f, 0.0f);
    glVertex2f(930.0f, 84.0f);
    glVertex2f(1000.0f, 84.0f);
    glVertex2f(1000.0f, 0.0f);
    glEnd();

    // up right corner
    glColor3ub(159, 104, 40);
    glBegin(GL_POLYGON);
    glVertex2f(930.0f, 716.0f);
    glVertex2f(930.0f, 800.0f);
    glVertex2f(1000.0f, 800.0f);
    glVertex2f(1000.0f, 716.0f);
    glEnd();


    // === BORDERS
    // left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(40.0f, 84.0f);
    glVertex2f(40.0f, 716.0f);
    glVertex2f(70.0f, 716.0f);
    glVertex2f(70.0f, 84.0f);
    glEnd();

    // right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(960.0f, 84.0f);
    glVertex2f(960.0f, 716.0f);
    glVertex2f(930.0f, 716.0f);
    glVertex2f(930.0f, 84.0f);
    glEnd();

    // mid up left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 756.0f);
    glVertex2f(470.0f, 756.0f);
    glVertex2f(470.0f, 716.0f);
    glVertex2f(70.0f, 716.0f);
    glEnd();

    // mid up right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(530.0f, 756.0f);
    glVertex2f(930.0f, 756.0f);
    glVertex2f(930.0f, 716.0f);
    glVertex2f(530.0f, 716.0f);
    glEnd();

    // mid up left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 44.0f);
    glVertex2f(70.0f, 84.0f);
    glVertex2f(470.0f, 84.0f);
    glVertex2f(470.0f, 44.0f);
    glEnd();

    // mid down right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(530.0f, 44.0f);
    glVertex2f(530.0f, 84.0f);
    glVertex2f(930.0f, 84.0f);
    glVertex2f(930.0f, 44.0f);
    glEnd();


    // === BORDERS STROKES
    // left green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 84.0f);
    glVertex2f(70.0f, 716.0f);
    glVertex2f(75.0f, 716.0f);
    glVertex2f(75.0f, 84.0f);
    glEnd();

    // right green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(930.0f, 84.0f);
    glVertex2f(930.0f, 716.0f);
    glVertex2f(925.0f, 716.0f);
    glVertex2f(925.0f, 84.0f);
    glEnd();

    // mid up green stoke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 711.0f);
    glVertex2f(930.0f, 711.0f);
    glVertex2f(930.0f, 716.0f);
    glVertex2f(70.0f, 716.0f);
    glEnd();

    // mid down green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 84.0f);
    glVertex2f(70.0f, 89.0f);
    glVertex2f(930.0f, 89.0f);
    glVertex2f(930.0f, 84.0f);
    glEnd();


    // table mid
    glColor3ub(32, 91, 47);
    glBegin(GL_POLYGON);
    glVertex2f(40.0f, 44.0f);
    glVertex2f(40.0f, 756.0f);
    glVertex2f(960.0f, 756.0f);
    glVertex2f(960.0f, 44.0f);
    glEnd();


};


void init() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Billiard_2D");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, 1000, 800);
    glOrtho(0.0, 1000, 0.0, 800, -100.0, 100.0);
}

void drawMidCircle() {
    GLfloat radius = 100;
    GLfloat twoPI = 2 * PI;
    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2;) {
        glVertex2f(400 + (sin(-i) * radius), 400 + (cos(-i) * radius));
        i += 0.00001;
    }
    glEnd();
    glFlush();
}

void drawMidLine() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2d(400.0f, 89.0f);
    glVertex2d(400.0f, 711.0f);
    glEnd();
}

void drawTableBorders() {
    glColor3f(0.6f, 0.45f, 0.06f);
    glBegin(GL_LINE_STRIP);
    glVertex2d(0.0f, 0.0f);
    glVertex2d(1000.0f, 0.0f);

    glVertex2d(0.0f, 0.0f);
    glVertex2d(0.0f, 800.0f);

    glVertex2d(0.0f, 800.0f);
    glVertex2d(1000.0f, 800.0f);

    glVertex2d(1000.0f, 800.0f);
    glVertex2d(1000.0f, 0.0f);
    glEnd();

    glColor3f(0.7f, 0.45f, 0.06f);
    glBegin(GL_LINE_STRIP);
    glVertex2d(40.0f, 44.0f);
    glVertex2d(960.0f, 44.0f);

    glVertex2d(40.0f, 44.0f);
    glVertex2d(40.0f, 756.0f);

    glVertex2d(40.0f, 756.0f);
    glVertex2d(960.0f, 756.0f);

    glVertex2d(960.0f, 756.0f);
    glVertex2d(960.0f, 44.0f);
    glEnd();
}

void drawCircle(double x, double y, double z, double radius, double lightPos) {
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    GLfloat mat_specular[] = {0.0f, 0.5f, 0.0f, 1.0f};
    GLfloat mat_shininess[] = {1.0};
    GLfloat light_position[] = {(GLfloat) lightPos, 1.0f, -0.8f, 0.0f};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);





//    glColor3ub(red, green, blue);
    glPushMatrix();
    glTranslated(x, y, z);
    glutSolidSphere(radius, 50, 50);
    glPopMatrix();


}

void draw() {

    // 1000 * 800

    glClearColor(0.4f, 0.2f, 0.1f, 0.12);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);


    glDisable(GL_LIGHTING);

    // ====
//    drawTableBorders();
    // ====

    // ====
    drawMidLine();
    // ====

    drawMidCircle();

    // ====
    drawTable();
    // ====

    // drawing holes
    // x += 15, y += 15

    // down leftmost hole
    drawCircle(68, 79, 0, 26, -0.4);
    // down rightmost hole
    drawCircle(930, 79, 0, 26, 0.4);
    // down mid-hole
    drawCircle(500, 79, 0, 26, 0.0);
    // up leftmost hole
    drawCircle(70, 721, 0, 26, -0.4);
    // up rightmost hole
    drawCircle(930, 721, 0, 26, 0.4);
    // up mid-hole
    drawCircle(500, 721, 0, 26, 0.0);

    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}
