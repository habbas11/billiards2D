//
// Created by User on 17/12/2021.
//

#ifndef BILLIARDS2D_TABLE_H
#define BILLIARDS2D_TABLE_H


#include <GL/glut.h>
#include "Ball.h"

class Table {

public:
    static void drawTable() {
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

        // mid up corner
        glColor3ub(159, 104, 40);
        glBegin(GL_POLYGON);
        glVertex2f(460.0f, 711.0f);
        glVertex2f(460.0f, 800.0f);
        glVertex2f(540.0f, 800.0f);
        glVertex2f(540.0f, 711.0f);
        glEnd();

        // mid down corner
        glColor3ub(159, 104, 40);
        glBegin(GL_POLYGON);
        glVertex2f(460.0f, 0.0f);
        glVertex2f(460.0f, 89.0f);
        glVertex2f(540.0f, 89.0f);
        glVertex2f(540.0f, 0.0f);
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
        // ====


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
        // up left green border
        glColor3ub(13, 137, 67);
        glBegin(GL_POLYGON);
        glVertex2f(70.0f, 756.0f);
        glVertex2f(470.0f, 756.0f);
        glVertex2f(460.0f, 716.0f);
        glVertex2f(100.0f, 716.0f);
        glEnd();
        // up left green stoke
        glColor3ub(23, 60, 26);
        glBegin(GL_POLYGON);
        glVertex2f(100.0f, 711.0f);
        glVertex2f(460.0f, 711.0f);
        glVertex2f(460.0f, 716.0f);
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
        glVertex2f(540.0f, 716.0f);
        glEnd();
        // up right green stoke
        glColor3ub(23, 60, 26);
        glBegin(GL_POLYGON);
        glVertex2f(540.0f, 711.0f);
        glVertex2f(900.0f, 711.0f);
        glVertex2f(900.0f, 716.0f);
        glVertex2f(540.0f, 716.0f);
        glEnd();
        // ====

        // DOWN LEFT
        // ====
        // down left green border
        glColor3ub(13, 137, 67);
        glBegin(GL_POLYGON);
        glVertex2f(70.0f, 44.0f);
        glVertex2f(100.0f, 84.0f);
        glVertex2f(460.0f, 84.0f);
        glVertex2f(470.0f, 44.0f);
        glEnd();
        // down left green stroke
        glColor3ub(23, 60, 26);
        glBegin(GL_POLYGON);
        glVertex2f(100.0f, 84.0f);
        glVertex2f(100.0f, 89.0f);
        glVertex2f(460.0f, 89.0f);
        glVertex2f(460.0f, 84.0f);
        glEnd();
        // ====

        // DOWN RIGHT
        // ====
        // down right green border
        glColor3ub(13, 137, 67);
        glBegin(GL_POLYGON);
        glVertex2f(530.0f, 44.0f);
        glVertex2f(540.0f, 84.0f);
        glVertex2f(900.0f, 84.0f);
        glVertex2f(930.0f, 44.0f);
        glEnd();
        // down right green stroke
        glColor3ub(23, 60, 26);
        glBegin(GL_POLYGON);
        glVertex2f(540.0f, 84.0f);
        glVertex2f(540.0f, 89.0f);
        glVertex2f(900.0f, 89.0f);
        glVertex2f(900.0f, 84.0f);
        glEnd();
        // ====

        // Mid-rectangle
        glColor3ub(32, 91, 47);
        glBegin(GL_POLYGON);
        glVertex2f(40.0f, 44.0f);
        glVertex2f(40.0f, 756.0f);
        glVertex2f(960.0f, 756.0f);
        glVertex2f(960.0f, 44.0f);
        glEnd();
    }

    static void drawMidCircle() {
        double radius = 100;
        // Drawing
        glBegin(GL_POINTS);
        for (float i = 0.0; i <= PI;) {
            glVertex2f(400 + (sin(-i) * radius), 400 + (cos(-i) * radius));
            i += 0.00001;
        }
        glEnd();
    }

    static void drawMidLine() {
        // Drawing
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(400.0f, 89.0f);
        glVertex2d(400.0f, 711.0f);
        glEnd();
    }
};


#endif //BILLIARDS2D_TABLE_H
