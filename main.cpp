/*
 * SVU - ITE - BCG601 - S21
 * Dr.Samer Jamal
 *
 * Participants:
 *  omar_116205
 *  omar_108591
 *  mhd_hussam_109817
 *
 * */

#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "Hole.h"
#include "Ball.h"
#include "Table.h"
#include "Stick.h"

using namespace std;

const float step = 5.0;
bool gameOver = false;
const float aspect = float(WIDTH) / HEIGHT;

void init() {
    // Initializing the Display Mode
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Specifying the window dimensions
    glutInitWindowSize(WIDTH, HEIGHT);
    // Creating the window, with its label
    glutCreateWindow("BCG601 - Billiards 2D");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);
    // At the beginning the number of balls is 16
    remainingBalls = 16;

    // Initializing the holes
    // down leftmost hole
    holes[0] = new Hole(73, 79, -0.6);
    // down rightmost hole
    holes[1] = new Hole(925, 79, 0.6);
    // down mid-hole
    holes[2] = new Hole(500, 79, 0.0);
    // up leftmost hole
    holes[3] = new Hole(73, 721, -0.4);
    // up rightmost hole
    holes[4] = new Hole(925, 721, 0.4);
    // up mid-hole
    holes[5] = new Hole(500, 721, 0.0);

    // Initializing the balls
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

// To make our scene responsive
void reshapeScene(GLint width, GLint height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // w is width adjusted for aspect ratio
    int w = height * 1.0 * aspect;
    int left = (width - w) / 2;
    glViewport(left, 0, w, height);
    // fix up the viewport to maintain aspect ratio
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);
    // only the window is changing, not the camera
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}


// To check if the mouse left button is pressed or not
bool onClickEvent;

void draw() {
    // Specifying the window color
    glClearColor(0.4f, 0.2f, 0.1f, 0.12);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glDisable(GL_LIGHTING);

    // Drawing the stick
    // if the left mouse button has been pressed, and the left end of the stick is anything except zero
    if (onClickEvent && stick.x2) {
        PlaySound(TEXT("C:\\Users\\User\\CLionProjects\\billiards2D\\hit.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        stick.drawStick();
    }

    // Drawing the table components
    Table::drawMidLine();
    Table::drawMidCircle();
    Table::drawTable();

    // Drawing holes
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

    // Drawing balls
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

    // Finally, empty all these buffers
    glFlush();
    glutSwapBuffers();
}

void mouseEventHandler(int button, int state, int mouseX, int mouseY) {
    cout << button << '\n';
    mouseY = HEIGHT - mouseY;
    double ballX = balls[0]->x;
    double ballY = balls[0]->y;

    cout << "Pressing at: mouseX = " << mouseX << ", mouseY = " << mouseY << '\n';

    // If the left mouse button is pressed
    if (button == GLUT_LEFT_BUTTON)
        // If the white ball has no speed
        if (!balls[0]->speed) {
            // If the state of pressing the mouse button is down (pressing)
            if (state == GLUT_DOWN) {
                double d = ((mouseX - ballX) * (mouseX - ballX)) + ((mouseY - ballY) * (mouseY - ballY));
                cout << "Press" << '\n';
                if ((ballRadius * ballRadius) >= d) {
                    onClickEvent = true;
                    stick.x1 = (GLfloat) balls[0]->x;
                    stick.y1 = (GLfloat) balls[0]->y;
                }
            }
            // If the left mouse button is released
            if (state == GLUT_UP) {
                cout << "Un-press" << '\n';
                onClickEvent = false;

                // Calculating the angle between the two ends of the stick
                double xDiff = stick.x1 - stick.x2;
                double yDiff = stick.y1 - stick.y2;

                // Assigning the new straight line of the ball to follow
                balls[0]->ballRect = atan2(yDiff, xDiff) * (180 / PI);

                // Assigning the new speed of the white ball after being hit by the stick
                balls[0]->speed = sqrt(pow(xDiff, 2.0) + pow(yDiff, 2.0));
                balls[0]->speed *= 0.05;

                // Relocate the stick
                stick.x1 = stick.y1 = 0;
                stick.x2 = stick.y2 = 0;
            }
        }

}

void onMouseMovement(int x, int y) {
    // If the left mouse button has been pressed, change the x2 and y2 coordinated of the stick
    if (onClickEvent) {
        y = HEIGHT - y;
        stick.x2 = (GLfloat) x;
        stick.y2 = (GLfloat) y;
    }
}

// Handling key presses
void keyboardEventHandler(unsigned char key, int x, int y) {
    // If the white ball is not moving
    if (!balls[0]->speed) {
        switch (key) {
            // w or W
            case 119:
            case 87:
                balls[0]->y += step;
                break;
                // s or S
            case 115:
            case 83:
                balls[0]->y -= step;
                break;
                // a or A
            case 97:
            case 65:
                balls[0]->x -= step;
                break;
                // d or D
            case 100:
            case 68:
                balls[0]->x += step;
                break;
                // Escape key
            case 27:
                cout << "Exiting..." << '\n';
                exit(1);
            default:
                cout << "Unknown key pressed." << '\n';
        }
    }
    glutPostRedisplay();
}

void specialButtons(int key, int, int) {
    // Up arrow
    if (GLUT_KEY_UP == key)
        balls[0]->y += step;

    // Down arrow
    if (GLUT_KEY_DOWN == key)
        balls[0]->y -= step;

    // Left arrow
    if (GLUT_KEY_LEFT == key)
        balls[0]->x -= step;

    // Right arrow
    if (GLUT_KEY_RIGHT == key)
        balls[0]->x += step;

    glutPostRedisplay();
}

// A timer function for refreshing the display every 1 ms
void timerCallBack(int) {
    for (auto &ball: balls) {
        // Move every ball that has speed
        // Check every ball hitting a wall, or entering a hole
        ball->moveBall(), ball->checkTableBorder(), ball->checkHole();

        // Check for colliding between any two balls
        for (auto &targetBall: balls) {
            // No need to check ballsCollision for a ball and itself
            if (ball->id == targetBall->id)
                continue;
            ball->ballsCollision(*targetBall);
        }

    }

    // The game ends when only the white ball remains
    if (remainingBalls == 1 && !gameOver) {
        cout << "GAME OVER" << '\n';
        gameOver = true;
    }

    // Refresh display
    glutPostRedisplay();
    // Calling the timer function recursively
    glutTimerFunc(1, timerCallBack, 1);
}

int main(int argc, char **argv) {
    // Initializing the OpenGL Utility Toolkit first
    glutInit(&argc, argv);
    // Initializing and drawing our basic objects
    init();
    // For handling mouse events
    glutMouseFunc(mouseEventHandler);
    glutMotionFunc(onMouseMovement);
    // For displaying our view
    glutDisplayFunc(draw);
    glutReshapeFunc(reshapeScene);
    // For handling key presses
    glutKeyboardFunc(keyboardEventHandler);
    glutSpecialFunc(specialButtons);
    // Registering a timer callback to be triggered every 1ms
    glutTimerFunc(1, timerCallBack, 1);
    // For viewing and not closing the window
    glutMainLoop();

    return 0;
}
