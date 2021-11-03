#define _USE_MATH_DEFINES  //*CRESENT
#include <cmath>  //*CRESENT
#include <stdio.h>
#include <GL/glut.h>
#include <math.h> //*CRESENT

void display();
void reshape(int, int);
void drawCrescentLine(float step, float scale, float fullness);  //*CRESENT
int main(int argc, char** argv)
{
	glutInit(&argc, argv);//initializing glut library
	glutInitDisplayMode(GLUT_RGB);//

	glutInitWindowPosition(300, 100);//where window will be displayed
	glutInitWindowSize(600, 600);//width and height of window
	glutCreateWindow("2D HOUSE");//Create window,name of window 2D house
    glClearColor(233.0f / 255.0f, 179.0f / 255.0f, 0.0f / 255.0f, 1.0f);  //*CRESENT

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

   
	glutMainLoop();


}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//drawing the top rectangle
	glBegin(GL_QUADS);
	glColor4f(0.0f, 1.5f, 1.0f, 1.0f);
	//vertices
	glVertex2f(-9.0, 0.0);
	glVertex2f(-9.0, 2.0);
	glVertex2f(9.0, 2.0);
	glVertex2f(9.0, 0.0);


	//drawing the lower rectangle 
	glBegin(GL_QUADS);

	//vertices
	glVertex2f(-8.0, 0.0);
	glVertex2f(-8.0, -8.0);
	glVertex2f(8.0, -8.0);
	glVertex2f(8.0, 0.0);

	glEnd();

	//drawing right window
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	//vertices
	glVertex2f(5.0, -2.0);
	glVertex2f(5.0, -4.0);
	glVertex2f(7.0, -4.0);
	glVertex2f(7.0, -2.0);

	glEnd();

	//drawing left window
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	//vertices
	glVertex2f(-5.0, -2.0);
	glVertex2f(-5.0, -4.0);
	glVertex2f(-7.0, -4.0);
	glVertex2f(-7.0, -2.0);

	glEnd();

	//drawing window lines for the first window
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-6.0, -2.0);
	glVertex2f(-6.0, -4.0);
	glVertex2f(-7.0, -3.0);
	glVertex2f(-5.0, -3.0);
	//drawing lines for the 2nd window
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(6.0, -2.0);
	glVertex2f(6.0, -4.0);
	glVertex2f(7.0, -3.0);
	glVertex2f(5.0, -3.0);



	glEnd();

	//drawing door
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	//vertices
	glVertex2f(-2.0, -2.0);
	glVertex2f(-2.0, -8.0);
	glVertex2f(2.0, -8.0);
	glVertex2f(2.0, -2.0);




	glEnd();
    drawCrescentLine(0.01, 1.0, -0.7f);  //*CRESENT



	glFlush();
}void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);




} //*CRESENT
void drawCrescentLine(float step, float scale, float fullness) {
    glBegin(GL_LINE_STRIP);
    float rightFullness=0.5f;
    float leftFullness=1.0f;
    glColor3f(117.0f / 255.0f, 166.0f / 255.0f, 217.0f / 255.0f);
    float angle = 0.0f;
    while (angle < M_PI) {
        glVertex2f(scale * sinf(angle), scale * cosf(angle));
        angle += step;
    }
    while (angle < (2.0f * M_PI)) {
        glVertex2f(fullness * scale * sinf(angle), scale * cosf(angle));
        angle += step;
    }
    glVertex2f(0.0f, scale);
    
    glEnd();
}
