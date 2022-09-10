#include <GL/glut.h>
#include <math.h>

void desenhaCirculo(int vertex, int type)
{
    float angulo, incremento;

    // Especifica que a cor corrente � vermelha RGB
    glColor3f(1.0f, 0.0f, 0.0f);

    // Especifica o tamanho do ponto
    glPointSize(4.0f);

    incremento = (2 * M_PI) / vertex; // 7 � o n�mero de v�rtices

    // Desenha um c�rculo de pontos
    if(type == 0) {
        glBegin(GL_POINTS);
    } else {
        glBegin(GL_LINE_LOOP);
    }
    for (angulo = 0; angulo < 2 * M_PI; angulo += incremento)
    {
        glVertex2f(20 * cos(angulo), 20 * sin(angulo));
    }
    glEnd();
}

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
    // Limpa a janela de visualiza��o com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 400);
    desenhaCirculo(7, 0);

    glViewport(400, 0, 400, 400);
    desenhaCirculo(7, 1);

    glViewport(0, 300, 400, 400);
    desenhaCirculo(30, 1);

    glViewport(400, 300, 400, 400);
    desenhaCirculo(10, 1);

    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa par�metros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

    GLsizei largura, altura;

    // Evita a divisao por zero
    if (h == 0)
        h = 1;

    // Atualiza as vari�veis
    largura = w;
    altura = h;

    glViewport(0, 0, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de sele��o (esquerda, direita, inferior,
    // superior) mantendo a propor��o com a janela de visualiza��o
    if (largura <= altura)
        gluOrtho2D(-40.0f, 40.0f, -40.0f * altura / largura, 40.0f * altura / largura);
    else
        gluOrtho2D(-40.0f * largura / altura, 40.0f * largura / altura, -40.0f, 40.0f);
}
// Programa Principal
int main(int argc, char *argv[])
{
    // Utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);
    // Define do modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Especifica o tamanho e localiza��o inicial em pixels da janela GLUT
    glutInitWindowSize(800, 800);
    // Cria a janela passando como argumento o t�tulo da mesma
    glutCreateWindow("Projeto 01");
    // Registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(Desenha);
    // Registra a fun��o callback de redimensionamento da janela de visualiza��o
    glutReshapeFunc(AlteraTamanhoJanela);
    // Registra a fun��o callback para tratamento das teclas ASCII
    glutKeyboardFunc(Teclado);
    // Chama a fun��o respons�vel por fazer as inicializa��es
    Inicializa();
    // Inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();
}
