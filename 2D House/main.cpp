#include <stdio.h>
#include <GL/glut.h>

void display();
void reshape(int, int);
int main(int argc, char** argv)
{
	glutInit(&argc, argv);//initializing glut library
	glutInitDisplayMode(GLUT_RGB);//

	glutInitWindowPosition(300, 100);//where window will be displayed
	glutInitWindowSize(600, 600);//width and height of window
	glutCreateWindow("2D HOUSE");//Create window,name of window 2D house


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();


}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//drawing rectangle part
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

	//drawing lines
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-6.0, -2.0);
	glVertex2f(-6.0, -4.0);
	glVertex2f(-7.0, -3.0);
	glVertex2f(-5.0, -3.0);


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



	glFlush();
}void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);




}