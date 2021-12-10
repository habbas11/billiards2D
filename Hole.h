//
// Created by User on 08/12/2021.
//

#ifndef BILLIARDS2D_HOLE_H
#define BILLIARDS2D_HOLE_H

const double holeRadius = 20;

class Hole {

public:
    double x;
    double y;
    double radius;
    double lightPos;

    Hole(double x, double y, double lightPos) {
        this->x = x;
        this->y = y;
        this->lightPos = lightPos;
        this->radius = holeRadius;
    }

    void drawHoleCircle() const {
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
        glTranslated(x, y, 0);
        glutSolidSphere(radius, 50, 50);
        glPopMatrix();
    }


};

Hole *holes[6];


#endif //BILLIARDS2D_HOLE_H
