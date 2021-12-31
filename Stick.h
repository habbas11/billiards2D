//
// Created by User on 18/12/2021.
//

#ifndef BILLIARDS2D_STICK_H
#define BILLIARDS2D_STICK_H

#include <GL/glut.h>


class Stick {
// A stick is drawn using its leftmost nd rightmost points
public:
    GLfloat x1;
    GLfloat y1;
    GLfloat x2;
    GLfloat y2;

    // The constructor
    Stick(GLfloat stickX1, GLfloat stickY1, GLfloat stickX2, GLfloat stickY2) {
        this->x1 = stickX1;
        this->y1 = stickY1;
        this->x2 = stickX2;
        this->y2 = stickY2;
    }

    // Drawing the stick
    void drawStick() const {
        glDisable(GL_LIGHTING);
        // Specifying the stick color
        glColor3ub(150, 128, 87);
        // Increasing the stroke (width) of lines
        glLineWidth(8.0);
        // Drawing
        glBegin(GL_LINES);
        glVertex2f(this->x1, this->y1);
        glVertex2f(this->x2, this->y2);
        glEnd();

        // In order not to let all the lines affected by the stick given width
        glLineWidth(1.0);
    }
};

// The stick that we'll use
Stick stick = Stick(0, 0, 0, 0);


#endif //BILLIARDS2D_STICK_H
