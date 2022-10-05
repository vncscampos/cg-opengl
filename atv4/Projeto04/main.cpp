//*****************************************************
//
// CasaEscopoTransforms.cpp
// Um programa OpenGL simples que abre uma janela GLUT,
// e usa as fun��es glPushMatrix() e glPopMatrix() para
// rotacionar, transladar e trocar a escala dos elementos
// de uma casa e depois desenha-la.
//
// Marcelo Cohen e Isabel H. Manssour
// Este c�digo acompanha o livro
// "OpenGL - Uma Abordagem Pr�tica e Objetiva"
//
//*****************************************************
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float PI = 3.14;

float left = 0.5;
float right = 0.5;
float up = 0.5;
float down = 0.5;

float scaleC = 1.0;
float scale = 1.0;
float rotate = 0;

void circulo(void) {
	int i;
	float angulo = 0.0;

	glBegin(GL_POLYGON);
		for(i=0; i<=10; i++) {
			angulo = 2 * PI * i / 10.0;
			glVertex2f(0.125*cos(angulo), 0.125*sin(angulo));
		}
	glEnd();
}

void quadrado(void)
 {
	glBegin(GL_POLYGON);
		glVertex2f(-0.125, 0.125);
		glVertex2f(0.125, 0.125);
		glVertex2f(0.125, -0.125);
		glVertex2f(-0.125, -0.125);
	glEnd();
 }
// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualiza��o com a cor de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(1.0, 0.4, 1.0);
	glScalef(scaleC, scaleC, 0);
	glRotatef(rotate, 0.0f, 0.0f, 1.0f);
	circulo();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(right, up, 0);
	glScalef(scale, scale, 0);
	quadrado();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-left, up, 0);
	glScalef(scale, scale, 0);
	quadrado();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(right, -down, 0);
	glScalef(scale, scale, 0);
	quadrado();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-left, -down, 0);
	glScalef(scale, scale, 0);
	quadrado();
	glPopMatrix();

	// Executa os comandos OpenGL
	glFlush();
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void TeclasEspeciais (int key, int x, int y)
{

    switch (key)
    {
		case GLUT_KEY_LEFT:
			left += 0.1;
			right -= 0.1;
			rotate += 45;
			break;
		case GLUT_KEY_RIGHT:
			left -= 0.1;
			right += 0.1;
			rotate -= 45;
			break;
		case GLUT_KEY_UP:
			rotate -= 45;
			up += 0.1;
			down -= 0.1;
			break;
		case GLUT_KEY_DOWN:
			rotate += 45;
			up -= 0.1;
			down += 0.1;
			break;
		case GLUT_KEY_HOME:
			scale += 0.1;
			break;
		case GLUT_KEY_END:
			scale -= 0.1;
			break;
		case GLUT_KEY_F1:
			scaleC += 0.1;
			break;
		case GLUT_KEY_F2:
			scaleC -= 0.1;
			break;
    }

    Desenha();
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Programa Principal
int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
    glutInit(&argc, argv);
	glutCreateWindow("Exercicio 01");
	Inicializa();
	glutDisplayFunc(Desenha);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(Teclado);
	glutMainLoop();

	return 0;
}
