//*****************************************************
//
// PrimeiroPrograma.cpp
// Um programa OpenGL simples que abre uma janela GLUT
// e desenha um tri�ngulo no centro
//
// Isabel H. Manssour e Marcelo Cohen
// Este c�digo acompanha o livro
// "OpenGL - Uma Abordagem Pr�tica e Objetiva"
//
//*****************************************************

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Desenha(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(0, -1);
		glVertex2f(0, 1);

		glColor3f(1, 1, 1);
		glVertex2f(1, -0.1);
		glVertex2f(-1, -0.1);
	glEnd();

	// // Desenha um tri�ngulo no centro da janela
	glLineWidth(3); // Determina a espessura da linha que será desenhada
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.2, 0.1);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0, 0.22);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.2, 0.1);
	glEnd();

	glLineWidth(1); // Determina a espessura da linha que será desenhada
	glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 139);
		glVertex2f(0.2, 0.1);

		glColor3f(0, 0, 139);
		glVertex2f(0.2, -0.1);

		glColor3f(0, 0, 139);
		glVertex2f(-0.2, -0.1);

		glColor3f(0, 0, 139);
		glVertex2f(-0.2, 0.1);
	glEnd();

	// Executa os comandos OpenGL
	glFlush();
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(void)
{
	// Define a janela de visualiza��o 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

// Programa Principal
int main(int argc, char *argv[])
{
	// Utilizada para inicializar a biblioteca GLUT
	glutInit(&argc, argv);

	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(600, 400);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Exercicio Aula 1");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc(Teclado);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
