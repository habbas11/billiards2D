#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "Hole.h"
#include "Ball.h"

using namespace std;

bool mouseClick = false;
GLfloat lineX1, lineY1, lineX2, lineY2;

void drawTable() {
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glBegin(GL_POLYGON);                        // Middle circle
//    double ballRect = 22;
//    double ori_x = 70.0;                         // the origin or center of circle
//    double ori_y = 716.0;
//    for (int i = 0; i <= 300; i++) {
//        double angle = 2 * PI * i / 300;
//        double x = cos(angle) * ballRect;
//        double y = sin(angle) * ballRect;
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

    // LEFT
    // ====
    // left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(40.0f, 74.0f);
    glVertex2f(40.0f, 726.0f);
    glVertex2f(70.0f, 696.0f);
    glVertex2f(70.0f, 104.0f);
    glEnd();

    // left green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 104.0f);
    glVertex2f(70.0f, 696.0f);
    glVertex2f(75.0f, 696.0f);
    glVertex2f(75.0f, 104.0f);
    glEnd();
    // ====

    // RIGHT
    // ====
    // right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(960.0f, 74.0f);
    glVertex2f(960.0f, 726.0f);
    glVertex2f(930.0f, 696.0f);
    glVertex2f(930.0f, 104.0f);
    glEnd();

    // right green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(930.0f, 104.0f);
    glVertex2f(930.0f, 696.0f);
    glVertex2f(925.0f, 696.0f);
    glVertex2f(925.0f, 104.0f);
    glEnd();
    // ====

    // UP LEFT
    // ====
    // mid up left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 756.0f);
    glVertex2f(470.0f, 756.0f);
    glVertex2f(440.0f, 716.0f);
    glVertex2f(100.0f, 716.0f);
    glEnd();
    // mid up left green stoke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(100.0f, 711.0f);
    glVertex2f(440.0f, 711.0f);
    glVertex2f(440.0f, 716.0f);
    glVertex2f(100.0f, 716.0f);
    glEnd();
    // ====

    // UP RIGHT
    // ====
    // up right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(530.0f, 756.0f);
    glVertex2f(930.0f, 756.0f);
    glVertex2f(900.0f, 716.0f);
    glVertex2f(560.0f, 716.0f);
    glEnd();
    // up right green stoke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(560.0f, 711.0f);
    glVertex2f(900.0f, 711.0f);
    glVertex2f(900.0f, 716.0f);
    glVertex2f(560.0f, 716.0f);
    glEnd();
    // ====

    // DOWN LEFT
    // ====
    // down left green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(70.0f, 44.0f);
    glVertex2f(100.0f, 84.0f);
    glVertex2f(440.0f, 84.0f);
    glVertex2f(470.0f, 44.0f);
    glEnd();

    // down left green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(100.0f, 84.0f);
    glVertex2f(100.0f, 89.0f);
    glVertex2f(440.0f, 89.0f);
    glVertex2f(440.0f, 84.0f);
    glEnd();
    // ====

    // DOWN RIGHT
    // ====
    // mid down right green border
    glColor3ub(13, 137, 67);
    glBegin(GL_POLYGON);
    glVertex2f(530.0f, 44.0f);
    glVertex2f(560.0f, 84.0f);
    glVertex2f(900.0f, 84.0f);
    glVertex2f(930.0f, 44.0f);
    glEnd();
    // mid down right green stroke
    glColor3ub(23, 60, 26);
    glBegin(GL_POLYGON);
    glVertex2f(560.0f, 84.0f);
    glVertex2f(560.0f, 89.0f);
    glVertex2f(900.0f, 89.0f);
    glVertex2f(900.0f, 84.0f);
    glEnd();
    // ====













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
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("BCG601 - Billiards 2D");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);

    // down leftmost hole
    holes[0] = new Hole(78, 89, -0.6);
    // down rightmost hole
    holes[1] = new Hole(920, 89, 0.6);
    // down mid-hole
    holes[2] = new Hole(500, 79, 0.0);
    // up leftmost hole
    holes[3] = new Hole(78, 711, -0.4);
    // up rightmost hole
    holes[4] = new Hole(920, 711, 0.4);
    // up mid-hole
    holes[5] = new Hole(500, 711, 0.0);

    // 15
    balls[15] = new Ball(802, 484, 18, 135, 57, 0, 15);
    // 14
    balls[14] = new Ball(802, 442, 155, 97, 77, 0, 14);
    // 13
    balls[13] = new Ball(802, 400, 244, 122, 66, 0, 13);
    // 12
    balls[12] = new Ball(802, 358, 128, 68, 133, 0, 12);
    // 11
    balls[11] = new Ball(802, 316, 223, 39, 40, 0, 11);


    // 10
    balls[10] = new Ball(765, 464, 42, 57, 132, 0, 10);
    // 09
    balls[9] = new Ball(765, 422, 255, 196, 55, 0, 9);
    // 08
    balls[8] = new Ball(765, 378, 4, 159, 72, 0, 8);
    // 07
    balls[7] = new Ball(765, 336, 144, 96, 66, 0, 7);

    // 06
    balls[6] = new Ball(728, 442, 241, 121, 38, 0, 6);
    // 05
    balls[5] = new Ball(728, 400, 52, 60, 54, 0, 5);
    // 04
    balls[4] = new Ball(728, 358, 139, 73, 133, 0, 4);

    // 03
    balls[3] = new Ball(691, 422, 241, 32, 53, 0, 3);
    // 02
    balls[2] = new Ball(691, 378, 37, 57, 114, 0, 2);

    // 01
    balls[1] = new Ball(654, 400, 251, 199, 54, 0, 1);
    // White ball
    balls[0] = new Ball(300, 400, 255, 255, 255, 0, 0);

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


void draw() {

    // 1000 * 800

    glClearColor(0.4f, 0.2f, 0.1f, 0.12);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);


    glDisable(GL_LIGHTING);

    if (mouseClick && lineX2 != 0) {
        PlaySound(TEXT("C:\\Users\\User\\CLionProjects\\billiards2D\\hit.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        glDisable(GL_LIGHTING);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(lineX1, lineY1);
        glVertex2f(lineX2, lineY2);
        glEnd();
    }

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
    holes[0]->drawHoleCircle();
    // down rightmost hole
    holes[1]->drawHoleCircle();
    // down mid-hole
    holes[2]->drawHoleCircle();
    // up leftmost hole
    holes[3]->drawHoleCircle();
    // up rightmost hole
    holes[4]->drawHoleCircle();
    // up mid-hole
    holes[5]->drawHoleCircle();
    // balls colors
    /*
        15: 18, 135, 57
        14: 155, 97, 77
        13: 244, 122, 66
        12: 128, 68, 133
        11: 223, 39, 40
        10: 42, 57, 132
        9: 255, 196, 55
        8: 52, 60, 54
        7: 4, 159, 72
        6: 144, 96, 66
        5: 241, 121, 38
        4: 139, 73, 133
        3: 241, 32, 53
        2: 37, 57, 114
        1: 251, 199, 54
        0: 255, 255, 255
     */

    // 15
    balls[15]->drawBall();
    // 14
    balls[14]->drawBall();
    // 13
    balls[13]->drawBall();
    // 12
    balls[12]->drawBall();
    // 11
    balls[11]->drawBall();
    // 10
    balls[10]->drawBall();
    // 09
    balls[9]->drawBall();
    // 08
    balls[8]->drawBall();
    // 07
    balls[7]->drawBall();
    // 06
    balls[6]->drawBall();
    // 05
    balls[5]->drawBall();
    // 04
    balls[4]->drawBall();
    // 03
    balls[3]->drawBall();
    // 02
    balls[2]->drawBall();
    // 01
    balls[1]->drawBall();
    // White ball
    balls[0]->drawBall();

    glFlush();
    glutSwapBuffers();
}

void mouseEvent(int button, int state, int mouseX, int mouseY) {
    mouseY = HEIGHT - mouseY;
    double ballX = balls[0]->x;
    double ballY = balls[0]->y;
    cerr << "Pressing at: mouseX = " << mouseX << ", mouseY = " << mouseY << '\n';
    if (button == GLUT_LEFT_BUTTON)
        if (!balls[0]->speed) {
            if (state == GLUT_DOWN) {
                double d = ((mouseX - ballX) * (mouseX - ballX)) + ((mouseY - ballY) * (mouseY - ballY));
                cerr << "Press" << '\n';
                cout << "HERE: " << ballRadius * ballRadius << " === " << d << '\n';
                if ((ballRadius * ballRadius) >= d) {
                    mouseClick = true;
                    lineX1 = balls[0]->x;
                    lineY1 = balls[0]->y;
                }
            }
            if (state == GLUT_UP) {

                balls[0]->vX = 5 * balls[0]->x - mouseX;
                balls[0]->vY = 5 * balls[0]->y - mouseY;

                cerr << "Un-press" << '\n';
                mouseClick = false;
                printf("%f %f\n", lineX1 - lineX2, lineY1 - lineY2);
                printf("%lf\n", atan2(double(lineY1 - lineY2), double(lineX1 - lineX2)) * 180 / PI);
                balls[0]->ballRect = atan2(double(lineY1 - lineY2), double(lineX1 - lineX2)) * 180 / PI;
                //atan2를 이용하여 공이 날아갈 각도를 계산해준다.

                balls[0]->speed = sqrt(pow(lineX1 - lineX2, 2.0) + pow(lineY1 - lineY2, 2.0)) / 20;
                //흰공의 속도는 나누기 20을 해줌으로써 적당히 할당해준다.

                lineX1 = lineY1 = lineX2 = lineY2 = 0;

            }
        }

}

void mousemove(int x, int y) {

    //마우스 왼쪽이 눌려져있다면
    if (mouseClick) {
        cout << "Hello World" << '\n';
        y = HEIGHT - y;
        lineX2 = x;
        lineY2 = y;
    }
}

void timer(int value) {
    for (auto &ball: balls)
        ball->move(), ball->checkHole(), ball->checkTableBorder();

    for (auto &ball : balls) {
        for (auto &targetBall: balls) {
            if (ball->id == targetBall->id)
                continue;
            ball->collision(*targetBall);
        }
    }


    // Refresh display
    glutPostRedisplay();
    glutTimerFunc(1, timer, 1);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    init();
    glutMouseFunc(mouseEvent);
    glutMotionFunc(mousemove);
    glutDisplayFunc(draw);
    glutTimerFunc(1, timer, 1);
    glutMainLoop();
}
