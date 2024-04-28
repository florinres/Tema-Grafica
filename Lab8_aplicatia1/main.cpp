/*
 *  Programul afiseaza trei cesti de ceai, cu aceeasi sursa de lumina
 *  dar cu diferite valori pentru coeficientii de reflexie pentru lumina ambientala
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"


GLfloat unghiRotatie = 1.0f;


void CALLBACK display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //curata ecranul
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//resetare vedere
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//activare wireframe

	glTranslatef(0.0f, 0.0f, -8.0f);
	glRotatef(unghiRotatie, 1.0f, 1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	// Linia 1 baza
	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	// Linia 2 baza
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	//Linia 5 tangenta
	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	//Linia 6 tangenta
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glEnd();

	//aici linii punctate
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF); // setari linie punctata
	glBegin(GL_LINES);
	// Linia 3 punctata baza
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	// Linia 4 punctata baza
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);
	//Linia 7 punctata tangenta NU SE VEDE !
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	//Linia 8 punctata tangenta
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();

	glDisable(GL_LINE_STIPPLE); // dezactivare line stipple

	unghiRotatie += 2.0f;
	glFlush();
	auxSwapBuffers();
}

void myInit() {

}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	}
	else {
		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH16);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("piramida");
	myInit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;

}
