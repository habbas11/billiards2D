#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const GLfloat PI = acos(-1);
const int HEIGHT = 800;
const int WIDTH = 1000;
const double ballRadius = 20;
const double holeRadius = 20;
const double gravity = 9.8;

//double x, double y, double z, double radius, double lightPos

class Hole {
public:
    double x{};
    double y{};
    double radius = holeRadius;
    double lightPos{};
};

Hole holes[6];

class Ball {
public:
    double x;
    double y;
    double red;
    double green;
    double blue;
    double speed{};
    double radius;
    double frictionForce{};

    Ball(double x, double y, double red, double green, double blue) {
        this->x = x;
        this->y = y;
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->radius = ballRadius;
    }

    void move() {
        if (speed > frictionForce * gravity) {
            cout << speed << ' ' << frictionForce << '\n';
            speed -= frictionForce * gravity;
            x += cos((radius * PI) / 180.0) * speed;
            y += sin((radius * PI) / 180.0) * speed;
        } else
            speed = 0;
    }

//    // 구멍과 만나는지 아닌지 체크
//    void holechk() {
//        for (int i = 0; i < 6; i++) {
//            double x = holes[i]->holeCoord[0] - ballCoord[0];
//            double y = holes[i]->holeCoord[1] - ballCoord[1];
//            double z = holes[i]->holeCoord[2] - ballCoord[2];
//            if ((x * x + y * y + z * z) < ballRadius * ballRadius - 2) {
//                if (ballColor[0] == 1.0f && ballColor[1] == 1.0f && ballColor[2] == 1.0f)    // 흰공이라면
//                {
//                    // 구멍에 빠질경우 다시 시작위치로 빠져나옴
//                    ballCoord[0] = holes[i]->holeCoord[0];
//                    ballCoord[1] = holes[i]->holeCoord[1];
//                    ballCoord[2] = holes[i]->holeCoord[2];
//                    ballCoord[0] = 650.0f;
//                    ballCoord[1] = 300.0f;
//                    ballCoord[2] = 0.0f;
//                    ballSpd = 0;
//                } else {    // 다른공들이 구멍에 들어갈경우
//                    for (int j = 0; j < 3; j++) {
//                        ballColor[j] = 0.0f;    // 공색을 검은색으로
//                        ballSpd *= 0.1;    // 자연스럽게 들어가보이게
//                        ballCoord[j] = 1050.0f;    // 창 바깥 좌표로 뺌
//                    }
//                }
//            }
//        }
//    }

    [[nodiscard]] bool check(const Ball &b) const {

        //미리 다음 위치로 이동시켜본 다음에 충돌하는지 확인
        double move1 = (x + cos((radius * PI) / 180.0) * speed)
                       - (b.x + cos((b.radius * PI) / 180.0) * b.speed);
        double move2 = (y + sin((radius * PI) / 180.0) * speed)
                       - (b.y + sin((b.radius * PI) / 180.0) * b.speed);

        if (pow(move1, 2) + pow(move2, 2) <= pow(ballRadius * 2, 2) + 1)
            return true;
        else
            return false;
    }

};

Ball *balls[16];

//class HisBall {
//public:
//    float ballColor[3]{};        //공의 색깔을 위한 배열
//    double ballCoord[3]{};    //공의 위치를 위한 배열
//    double ballRect;        //공이 움직일 각도
//    double ballSpd;            //공의 속도 대략 0~5정도 됨
//    double ballFric;        //공의 마찰계수
//
//public:
//    //공 생성자.
//    HisBall(const float *color, const double *coord, double rect) {
//        for (int i = 0; i < 3; i++) {
//            ballColor[i] = color[i];
//            ballCoord[i] = coord[i];
//        }
//        ballRect = rect;
//        ballSpd = 0;
//        ballFric = 0.0001;
//    }
//
//    // 구멍과 만나는지 아닌지 체크
//    void holechk() {
//        for (int i = 0; i < 6; i++) {
//            double x = holes[i]->holeCoord[0] - ballCoord[0];
//            double y = holes[i]->holeCoord[1] - ballCoord[1];
//            double z = holes[i]->holeCoord[2] - ballCoord[2];
//            if ((x * x + y * y + z * z) < ballRadius * ballRadius - 2) {
//                if (ballColor[0] == 1.0f && ballColor[1] == 1.0f && ballColor[2] == 1.0f)    // 흰공이라면
//                {
//                    // 구멍에 빠질경우 다시 시작위치로 빠져나옴
//                    ballCoord[0] = holes[i]->holeCoord[0];
//                    ballCoord[1] = holes[i]->holeCoord[1];
//                    ballCoord[2] = holes[i]->holeCoord[2];
//                    ballCoord[0] = 650.0f;
//                    ballCoord[1] = 300.0f;
//                    ballCoord[2] = 0.0f;
//                    ballSpd = 0;
//                } else {    // 다른공들이 구멍에 들어갈경우
//                    for (int j = 0; j < 3; j++) {
//                        ballColor[j] = 0.0f;    // 공색을 검은색으로
//                        ballSpd *= 0.1;    // 자연스럽게 들어가보이게
//                        ballCoord[j] = 1050.0f;    // 창 바깥 좌표로 뺌
//                    }
//                }
//            }
//        }
//    }
//
//    //공이 어떠한 공과 서로 충돌했는지 체크
//    bool check(const HisBall &b) const {
//
//        //미리 다음 위치로 이동시켜본 다음에 충돌하는지 확인
//        double move1 = (ballCoord[0] + cos((ballRect * PI) / 180.0) * ballSpd)
//                       - (b.ballCoord[0] + cos((b.ballRect * PI) / 180.0) * b.ballSpd);
//        double move2 = (ballCoord[1] + sin((ballRect * PI) / 180.0) * ballSpd)
//                       - (b.ballCoord[1] + sin((b.ballRect * PI) / 180.0) * b.ballSpd);
//
//        if (pow(move1, 2) + pow(move2, 2) <= pow(ballRadius * 2, 2) + 1)
//            return true;
//        else
//            return false;
//    }
//
//    //현재 공의 각도에 따른 다음위치 계산
//    void move() {
//        if (ballSpd > ballFric * gravity) {
//            ballSpd -= ballFric * gravity;
//            ballCoord[0] += cos((ballRect * PI) / 180.0) * ballSpd;
//            ballCoord[1] += sin((ballRect * PI) / 180.0) * ballSpd;
//        } else
//            ballSpd = 0;
//    }
//
//    //벽에 충돌했는지 체크
//    void collisionWall() {
//        //미리 다음에 움직일 위치를 계산해본다.
//        double move1 = ballCoord[0] + cos((ballRect * PI) / 180.0) * ballSpd;
//        double move2 = ballCoord[1] + sin((ballRect * PI) / 180.0) * ballSpd;
//
//        if (move1 - 75 <= ballRadius + 1 || move1 >= WIDTH - 75 - ballRadius - 1) {        //왼쪽 or 오른쪽 충돌
//            ballRect = 180 - ballRect;
//            if (ballRect < 0)
//                ballRect += 360;
//            ballSpd *= 0.55;            //쿠션의 원리를 생각해서 속도를 20% 줄여봄
//        } else if (move2 - 75 <= ballRadius + 1 || move2 >= HEIGHT - 75 - ballRadius - 1) {        //위 or 아래 충돌
//            ballRect = 360 - ballRect;
//            if (ballRect < 0)
//                ballRect += 360;
//            ballSpd *= 0.55;
//        }
//    }
//
//    //충돌체크한 후 계산해주는 부분
//    void collision(HisBall &b) {
//
//        //벡터계산을 위해 공과 공사이의 각도를 찾아줌
//        double rect = atan2(this->ballCoord[1] - b.ballCoord[1], this->ballCoord[0] - b.ballCoord[0]);
//        rect *= 180;
//        rect /= PI;
//
//        //충돌로 인한 두개의 공의 속도를 각각 45%씩 줄여줌
//        ballSpd *= 0.55;
//        b.ballSpd *= 0.55;
//
//        double bx1, by1, bx2, by2;        //벡터용
//
//        bx1 = cos(((ballRect - rect) * PI) / 180.0) * ballSpd;
//        by1 = sin(((ballRect - rect) * PI) / 180.0) * ballSpd;
//        bx2 = cos(((b.ballRect - rect) * PI) / 180.0) * b.ballSpd;
//        by2 = sin(((b.ballRect - rect) * PI) / 180.0) * b.ballSpd;
//
//        printf("%lf\n", rect);
//        printf("SPD : ball1 %lf, ball2 %lf\n", ballSpd, b.ballSpd);
//        printf("Rect : ball1 %lf, ball2 %lf\n", ballRect, b.ballRect);
//        printf("ball1 x_vector : %lf, y_vector : %lf\n", bx1, by1);
//        printf("ball2 x_vector : %lf, y_vector : %lf\n", bx2, by2);
//
//        //탄성충돌이므로
//        //각 구의 x벡터를 서로 교환해준다음 다시 속도를 구해줌
//        ballSpd = sqrt(pow(bx2, 2) + pow(by1, 2));
//        b.ballSpd = sqrt(pow(bx1, 2) + pow(by2, 2));
//
//        //각도도 다시 구해줌
//        printf("ball1 SPD : %lf, ball2 SPD : %lf\n", ballSpd, b.ballSpd);
//        ballRect = rect + (atan2(by1, bx2) * 180 / PI);
//        b.ballRect = rect + (atan2(by2, bx1) * 180 / PI);
//
//        printf("newRect ball1 : %lf, ball2 : %lf\n", ballRect, b.ballRect);
//        printf("\n");
//
//    }
//};

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
    glutInitWindowSize(1100, 800);
    glutCreateWindow("BCG601 - Billiards 2D");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);

    // 15
    balls[15] = new Ball(800, 480, 18, 135, 57);
    // 14
    balls[14] = new Ball(800, 440, 155, 97, 77);
    // 13
    balls[13] = new Ball(800, 400, 244, 122, 66);
    // 12
    balls[12] = new Ball(800, 360, 128, 68, 133);
    // 11
    balls[11] = new Ball(800, 320, 223, 39, 40);
    // 10
    balls[10] = new Ball(765, 460, 42, 57, 132);
    // 09
    balls[9] = new Ball(765, 420, 255, 196, 55);
    // 08
    balls[8] = new Ball(730, 400, 52, 60, 54);
    // 07
    balls[7] = new Ball(765, 380, 4, 159, 72);
    // 06
    balls[6] = new Ball(765, 340, 144, 96, 66);
    // 05
    balls[5] = new Ball(730, 440, 241, 121, 38);
    // 04
    balls[4] = new Ball(730, 360, 139, 73, 133);
    // 03
    balls[3] = new Ball(695, 420, 241, 32, 53);
    // 02
    balls[2] = new Ball(695, 380, 37, 57, 114);
    // 01
    balls[1] = new Ball(660, 400, 251, 199, 54);
    // White ball
    balls[0] = new Ball(300, 400, 255, 255, 255);

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

void drawHoleCircle(Hole hole) {
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    GLfloat mat_specular[] = {0.0f, 0.5f, 0.0f, 1.0f};
    GLfloat mat_shininess[] = {1.0};
    GLfloat light_position[] = {(GLfloat) hole.lightPos, 1.0f, -0.8f, 0.0f};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);


    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslated(hole.x, hole.y, 0);
    glutSolidSphere(hole.radius, 50, 50);
    glPopMatrix();

}

const GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {2.0f, 5.0f, 5.0f, 0.0f};
const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

void drawBall(Ball &ball) {
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glColor3ub((GLubyte) ball.red, (GLubyte) ball.green, (GLubyte) ball.blue);

    glPushMatrix();
    glTranslated(ball.x, ball.y, 0);
    glutSolidSphere(20, 50, 50);
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
    holes[0].x = 68, holes[0].y = 79, holes[0].radius = 26, holes[0].lightPos = -0.6;
    drawHoleCircle(holes[0]);
    // down rightmost hole
    holes[1].x = 930, holes[1].y = 79, holes[1].lightPos = 0.6;
    drawHoleCircle(holes[1]);
    // down mid-hole
    holes[2].x = 500, holes[2].y = 79, holes[2].lightPos = 0.0;
    drawHoleCircle(holes[2]);
    // up leftmost hole
    holes[3].x = 70, holes[3].y = 721, holes[3].lightPos = -0.4;
    drawHoleCircle(holes[3]);
    // up rightmost hole
    holes[4].x = 930, holes[4].y = 721, holes[4].lightPos = 0.4;
    drawHoleCircle(holes[4]);
    // up mid-hole
    holes[5].x = 500, holes[5].y = 721, holes[5].lightPos = 0.0;
    drawHoleCircle(holes[5]);

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
    drawBall(*balls[15]);
    // 14
    drawBall(*balls[14]);
    // 13
    drawBall(*balls[13]);
    // 12
    drawBall(*balls[12]);
    // 11
    drawBall(*balls[11]);
    // 10
    drawBall(*balls[10]);
    // 09
    drawBall(*balls[9]);
    // 08
    drawBall(*balls[8]);
    // 07
    drawBall(*balls[7]);
    // 06
    drawBall(*balls[6]);
    // 05
    drawBall(*balls[5]);
    // 04
    drawBall(*balls[4]);
    // 03
    drawBall(*balls[3]);
    // 02
    drawBall(*balls[2]);
    // 01
    drawBall(*balls[1]);
    // White ball
    drawBall(*balls[0]);
    balls[0]->speed = 100;
    balls[0]->move();

    glutSwapBuffers();
}

void timer(int value) {
    for (auto &ball: balls)
        ball->move();
    // refresh display
    glutPostRedisplay();
    glutTimerFunc(1, timer, 1);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(draw);
    glutTimerFunc(1, timer, 1);
    glutMainLoop();
}
