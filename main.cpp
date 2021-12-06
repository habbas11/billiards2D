#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

const GLfloat PI = acos(-1);
const int HEIGHT = 800;
const int WIDTH = 1000;


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
    glutCreateWindow("BCG601 - Billiards 2D");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);
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

// just for demo
// TODO: Remove
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

void drawHoleCircle(double x, double y, double z, double radius, double lightPos) {
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



    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslated(x, y, z);
    glutSolidSphere(radius, 50, 50);
    glPopMatrix();

}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void drawBall(int red, int green, int blue, double x, double y) {
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glColor3ub(red,green,blue);

    glPushMatrix();
    glTranslated(x,y,0);
    glutSolidSphere(20,50,50);
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
    drawHoleCircle(68, 79, 0, 26, -0.6);
    // down rightmost hole
    drawHoleCircle(930, 79, 0, 26, 0.6);
    // down mid-hole
    drawHoleCircle(500, 79, 0, 26, 0.0);
    // up leftmost hole
    drawHoleCircle(70, 721, 0, 26, -0.4);
    // up rightmost hole
    drawHoleCircle(930, 721, 0, 26, 0.4);
    // up mid-hole
    drawHoleCircle(500, 721, 0, 26, 0.0);

    // 15
    drawBall(18, 135, 57, 800, 480);
    // 14
    drawBall(155, 97, 77, 800, 440);
    // 13
    drawBall(244, 122, 66, 800, 400);
    // 12
    drawBall(128, 68, 133, 800, 360);
    // 11
    drawBall(223, 39, 40, 800, 320);
    // 10
    drawBall(42, 57, 132, 765, 460);
    // 09
    drawBall(255, 196, 55, 765, 420);
    // 08
    drawBall(52, 60, 54, 730, 400);
    // 07
    drawBall(4, 159, 72, 765, 380);
    // 06
    drawBall(144, 96, 66, 765, 340);
    // 05
    drawBall(241, 121, 38, 730, 440);
    // 04
    drawBall(139, 73, 133, 730, 360);
    // 03
    drawBall(241, 32, 53, 695, 420);
    // 02
    drawBall(37, 57, 114, 695, 380);
    // 01
    drawBall(251, 199, 54, 660, 400);
    // White ball
    drawBall(255, 255, 255, 300, 400);


    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}
