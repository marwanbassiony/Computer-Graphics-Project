#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include<cmath>


float step=0;
float move = 0.025;
float edit_turn = 0.001;
float addx = 0;
float addy = 0;
float turn = 0;
float shift = 4;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
    
    // sun
    glColor3f(248.0 / 255, 175.0 / 255, 97.0 / 255);
    glBegin(GL_POLYGON);
    for (int i = 0; i<=360;i++) {
        double angle = i*3.14/180;
        glVertex2f((3*cos(angle)),(5*sin(angle)));
    }
    
    // ground
        glColor3f(46.0 / 255, 180.0 / 255, 190.0 / 255);
        glBegin(GL_POLYGON);

        glVertex2f(-10, 0);
        glVertex2f(10, 0);

        glVertex2f(10, 0);
        glVertex2f(10, -10);

        glVertex2f(-10, 0);
        glVertex2f(-10, -10);

        glVertex2f(-10, -10);
        glVertex2f(10, -10);

        glEnd();
        //boat
        glColor3f(96.0 / 255, 22.0 / 255, 10.0 / 255);
        glBegin(GL_POLYGON);

        glVertex2f(-4 + step - shift, 1);
        glVertex2f(4 + step - shift, 1);

        glVertex2f(-4 + step - shift, 1);
        glVertex2f(-3 + step - shift, -2);

        glVertex2f(-3 + step - shift, -2);
        glVertex2f(3 + step - shift, -2);

        glVertex2f(3 + step - shift, -2);
        glVertex2f(4 + step - shift, 1);
    glEnd();

    
    glColor3f(255.0 / 255, 255.0 / 255, 255.0 / 255);
    glBegin(GL_TRIANGLES);
    
    glVertex2f(-0.5+step-shift,-0.5);
    glVertex2f(0.5+step-shift,-0.5);
    glVertex2f(0+step-shift,0.6);
    glEnd();
    
        //line
        glColor3f(0, 0, 0);
        glBegin(GL_POLYGON);

        glVertex2f(0 + step - shift, 1);
        glVertex2f(0 + step - shift, 8);

        glVertex2f(0 + step - shift, 8);
        glVertex2f(0.5 + step - shift, 8);

        glVertex2f(0.5 + step - shift, 8);
        glVertex2f(0.5 + step - shift, 1);

        glVertex2f(0.5 + step - shift, 1);
        glVertex2f(0 + step - shift, 1);

        glEnd();

        //Flag
        glColor3f(135.0 / 255, 0, 16.0 / 255);
        glBegin(GL_POLYGON);
        glVertex2d(0.5 + step - shift, 8);
        glVertex2d(3 + step - shift, 7);

        glVertex2d(3 + step - shift, 7);
        glVertex2d(0.5 + step - shift, 6);

        glVertex2d(3 + step - shift, 6);
        glVertex2d(0.5 + step - shift, 8);
        glEnd();

    glFlush();
}


void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    step += move;
    if (step>10 ||  step<0) {
        move = -move;
    }
    turn += edit_turn;
    if (turn > 0.25 || turn < 0) {
        edit_turn = - edit_turn;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200, 800);

    glutCreateWindow("Marwan Ahmed 20103415 Ayatallah Mamdouh 20101208 ");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

   glClearColor(50.0/255, 93.0/255, 90.0, 90.0);

    glutMainLoop();
}
