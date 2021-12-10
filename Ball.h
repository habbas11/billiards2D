//
// Created by User on 08/12/2021.
//

#ifndef BILLIARDS2D_BALL_H
#define BILLIARDS2D_BALL_H


#include <valarray>
#include <cstdio>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <Gl/glut.h>
#include "Hole.h"

using namespace std;

const GLfloat PI = acos(-1);
const int HEIGHT = 800;
const int WIDTH = 1000;
const double EPS = 1e-18;
const double ballRadius = 20;
const double gravity = 9.81;
const GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {2.0f, 1.0f, 5.0f, 0.0f};
const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

class Ball {

public:
    // position vector
    double x, y;
    // velocity vector
    double vX, vY;
    // acceleration vector
    double aX, aY;
    double radius;
    double red, green, blue;
    double speed;
    double mass;
    double ballRect;
    double frictionForce;
    int id;

    Ball(double x, double y, double red, double green, double blue, double rect, int id) {
        this->x = x;
        this->y = y;
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->ballRect = rect;
        this->speed = 0;
        this->vX = 0, this->vY = 0;
        this->aX = 0, this->aY = 0;
        this->radius = ballRadius;
        // The pool table has a coefficient of friction of 0.005 at any point on the table
        this->frictionForce = 0.005;
        this->id = id;
        this->mass = 20;
    }

    void move() {
        if (speed > (frictionForce * gravity)) {
            speed -= frictionForce * gravity;
            x += cos((ballRect * PI) / 180.0) * speed;
            y += sin((ballRect * PI) / 180.0) * speed;
        } else
            speed = 0;
    }

    // Check if getting inside a hole
    void checkHole() {
        for (auto &hole: holes) {
            double distOnX = hole->x - x;
            double distOnY = hole->y - y;
            if (((distOnX * distOnX) + (distOnY * distOnY)) <= (ballRadius + holeRadius) * (ballRadius + holeRadius)) {
                cerr << "====== Got inside a hole ======" << '\n';
                PlaySound(TEXT("C:\\Users\\User\\CLionProjects\\billiards2D\\falling.wav"), nullptr,
                          SND_FILENAME | SND_ASYNC);
                // If a white Ball
                if (red == 255 && green == 255 && blue == 255) {
                    cerr << "====== White Ball got inside a hole ======" << '\n';
                    x = hole->x;
                    y = hole->y;
                    x = 300;
                    y = 400;
                    speed = 0;
                } else {
                    x = -20, y = -20;
                    speed = 0;
                }
            }
        }
    }

    void checkTableBorder() {
        // left border
        if (((x - ballRadius) <= 70) && (y >= 104 && y <= 676)) {
            ballRect = 180 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            x = 70 + ballRadius;
            speed *= 0.55;
        }

        // right border
        if (((x + ballRadius) >= 925) && (y >= 104 && y <= 676)) {
            ballRect = 180 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            x = 925 - ballRadius;
            speed *= 0.55;
        }

        // down left border
        if ((x >= 100 && x <= 440) && ((y - ballRadius) <= 89)) {
            ballRect = 360 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            y = 90 + ballRadius;
            speed *= 0.55;
        }

        // down right border
        if ((x >= 560 && x <= 900) && ((y - ballRadius) <= 89)) {
            ballRect = 360 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            y = 90 + ballRadius;
            speed *= 0.55;
        }

        // up left border
        if ((x >= 100 && x <= 440) && ((y + ballRadius) >= 716)) {
            ballRect = 360 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            y = 716 - ballRadius;
            speed *= 0.55;
        }

        // up right border
        if ((x >= 560 && x <= 900) && ((y + ballRadius) >= 716)) {
            ballRect = 360 - ballRect;
            if (ballRect < 0)
                ballRect += 360;
            y = 716 - ballRadius;
            speed *= 0.55;
        }
    }

    bool collide(Ball &targetBall) const {
        return fabs(((x - targetBall.x) * (x - targetBall.x)) + ((y - targetBall.y) * (y - targetBall.y))) <=
               ((2 * ballRadius) * (2 * ballRadius));
    }

    void collision(Ball &targetBall) {

        if (collide(targetBall)) {

            cout << "Balls " << id << " and " << targetBall.id << " collide." << '\n';
            double dist = sqrt(((x - targetBall.x) * (x - targetBall.x)) + ((y - targetBall.y) * (y - targetBall.y)));
            double overLap = 0.5 * (dist - (2 * ballRadius));

            x -= overLap * (x - targetBall.x) / dist;
            y -= overLap * (y - targetBall.y) / dist;
            targetBall.x += overLap * (x - targetBall.x) / dist;
            targetBall.y += overLap * (y - targetBall.y) / dist;
            double rect = atan2(y- targetBall.y, x - targetBall.x);
            rect *= 180;
            rect /= PI;


            double bx1, by1, bx2, by2;

            bx1 = cos(((ballRect - rect) * PI) / 180.0) * speed;
            by1 = sin(((ballRect - rect) * PI) / 180.0) * speed;
            bx2 = cos(((targetBall.ballRect - rect) * PI) / 180.0) * targetBall.speed;
            by2 = sin(((targetBall.ballRect - rect) * PI) / 180.0) * targetBall.speed;

            speed = sqrt(pow(bx2, 2) + pow(by1, 2));
            targetBall.speed = sqrt(pow(bx1, 2) + pow(by2, 2));

            ballRect = rect + (atan2(by1, bx2) * 180 / PI);
            targetBall.ballRect = rect + (atan2(by2, bx1) * 180 / PI);
        }
    }

    void drawBall() const {
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

        glColor3ub((GLubyte) red, (GLubyte) green, (GLubyte) blue);

        glPushMatrix();
        glTranslated(x, y, 0);
        glutSolidSphere(ballRadius, 50, 50);
        glPopMatrix();

    }
};

Ball *balls[16];


#endif //BILLIARDS2D_BALL_H
