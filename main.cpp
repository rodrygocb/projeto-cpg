
#include <GL/glut.h>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26


float playerX = -0.8; // Posição X do jogador
float playerY = -0.8; // Posição Y do jogador
float exitX; // Posição X da saída do labirinto
float exitY; // Posição Y da saída do labirinto
int score = 0; // Pontuação do jogador

float playerX2 = +0.8; // Posição X do jogador
float playerY2 = +0.8; // Posição Y do jogador
float exitX2; // Posição X da saída do labirinto
float exitY2; // Posição Y da saída do labirinto
int score2 = 0; // Pontuação do jogador
  
  /*
///cronometro
int tempo_total = 30; // tempo total em segundos
int tempo_atual = 0; // tempo atual do cronômetro
int milissegundos = 0; // milissegundos atuais
int tempo_anterior = 0; // tempo anterior em milissegundos
char tempo_str[10]; // string que armazena o tempo formatado
*/
/*
unsigned long rand_seed = 1;

unsigned int rand_custom() {
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}
*/

void display(void) {

 /*   // desenha o texto com o tempo na posição (10, 10)
    glRasterPos2i(10, 10);
    for (int i = 0; i < strlen(tempo_str); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tempo_str[i]);
    }

    //glutSwapBuffers();
*/	
	
	
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Cor dos caminhos do labirinto

    // Desenhar os caminhos do labirinto
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.9); // Ponto inicial
    glVertex2f(0.9, -0.9); // Ponto final
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.9, 0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glEnd();

    glColor3f(1.0, 0.5, 1.0); // Cor da saída do labirinto



	

    // Desenhar a saída do labirinto
    glBegin(GL_QUADS);
    glVertex2f(exitX - 0.05, exitY - 0.05); // Ponto inferior esquerdo
    glVertex2f(exitX + 0.05, exitY - 0.05); // Ponto inferior direito
    glVertex2f(exitX + 0.05, exitY + 0.05); // Ponto superior direito
    glVertex2f(exitX - 0.05, exitY + 0.05); // Ponto superior esquerdo
    glEnd();
	
//  glBegin(GL_QUADS);
//  glVertex2f(0.8, -0.9); // Ponto inferior esquerdo
//  glVertex2f(0.9, -0.9); // Ponto inferior direito
//  glVertex2f(0.9, -0.8); // Ponto superior direito
//  glVertex2f(0.8, -0.8); // Ponto superior esquerdo
//  glEnd();


///// Definções do jogador 2 ////////////////////////

	// Cor do jogador 1
    glColor3f(1.0, 0.0, 0.0); 
	
    // Desenhar o jogador 1
    glBegin(GL_QUADS);
    glVertex2f(playerX - 0.05, playerY - 0.05); // Ponto inferior esquerdo
    glVertex2f(playerX + 0.05, playerY - 0.05); // Ponto inferior direito
    glVertex2f(playerX + 0.05, playerY + 0.05); // Ponto superior direito
    glVertex2f(playerX - 0.05, playerY + 0.05); // Ponto superior esquerdo
    glEnd();
    
    // Exibir a pontuação do jogador 1
    glRasterPos2f(-0.9, 0.8);
    char scoreStr[50];
    sprintf(scoreStr, "Pontuacao: %d", score);
    for (int i = 0; scoreStr[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, scoreStr[i]);
    }


///// Definções do jogador 2 //////////////////////////
    // Cor do jogador 2
    glColor3f(0.0, 0.0, 1.0); 
	
	// Desenhar o jogador 2
    glBegin(GL_QUADS);
    glVertex2f(playerX2 + 0.05, playerY2 + 0.05); // Ponto inferior esquerdo
    glVertex2f(playerX2 - 0.05, playerY2 + 0.05); // Ponto inferior direito
    glVertex2f(playerX2 - 0.05, playerY2 - 0.05); // Ponto superior direito
    glVertex2f(playerX2 + 0.05, playerY2 - 0.05); // Ponto superior esquerdo
    glEnd();

    

    // Exibir a pontuação do jogador 2
    glRasterPos2f(-0.9, 0.7);
    char score2Str[50];
    sprintf(score2Str, "Pontuacao: %d", score2);
    for (int ii = 0; score2Str[ii] != '\0'; ii++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, score2Str[ii]);
    }
    glFlush();
}



void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor de fundo
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Sistema de coordenadas
}




void mover_flag(){
	
  int i;
    	float min = -0.9, max = 0.9, step = 0.05;
    	int range = (max - min) / step + 1;
    	float num, num2;
    	char string_formatada[10];

	    // seed para a função rand()
    	srand(time(NULL));

    	for (i = 0; i < 10; i++) {
        	// gera um número aleatório inteiro entre 0 e range-1
        	int random_int = rand() % range;

        	// ajusta o número para que fique dentro da faixa desejada e com a variação desejada
        	num2 = min + random_int * step;
     		// printf("%f",num);
   

	    	sprintf(string_formatada, "%.1f", num2); // formata o número em uma string com uma casa decimal
   			sscanf(string_formatada, "%f", &num); // lê a string formatada em uma nova variável float
   
			printf("%f",num);
		}
 		
		
		exitX=exitX-num;
    	exitY=exitY+num;
		


	if(exitX<-0.9 && exitY<-0.9){
		exitX=exitX+num;
		exitY=exitX+num;	
	}else if(exitX>0.9 && exitY>0.9){
		exitX=exitX-num;
		exitY=exitX-num;	
	}else if(exitX<-0.9 && exitY>0.9){
		exitX=exitX+num;
		exitY=exitY-num;	
	}else if(exitX>0.9 && exitY<-0.9){
		exitX=exitX-num;
		exitY=exitY+num;
	}else if(exitX<-0.9){
			exitX=exitX-num;
	}else if(exitX>0.9){
			exitX=exitX+num;
	}else if(exitY>0.9){
			exitY=exitY-num;
	}else if(exitY<-0.9){
			exitY=exitY+num;
	}else{
	}
		
    
   
	
	
	
	
		
		
   	
 
}



void keyboard(unsigned char key, int x, int y) {
    // Função de callback do teclado para mover o jogador

	
	

    switch (key) {
    	int tecla;
    	tecla = getch();
		case 'w': // Movimentar para cima
            if (playerY < 0.9) { // Verificar se não há colisão na direção desejada
                playerY += 0.1;
            }
            break;
        case 'a': // Movimentar para a esquerda
            if (playerX > -0.9) { // Verificar se não há colisão na direção desejada
                playerX -= 0.1;
            }
            break;
        case 's': // Movimentar para baixo
            if (playerY > -0.9) { // Verificar se não há colisão na direção desejada
                playerY -= 0.1;
            }
            break;
        case 'd': // Movimentar para a direita
            if (playerX < 0.9) { // Verificar se não há colisão na direção desejada
                playerX += 0.1;
            }
            break;
        case 'i': // Movimentar para cima
            if (playerY2 < 0.9) { // Verificar se não há colisão na direção desejada
                playerY2 += 0.1;
            }
            break;
        case 'j': // Movimentar para a esquerda
            if (playerX2 > -0.9) { // Verificar se não há colisão na direção desejada
                playerX2 -= 0.1;
            }
            break;
        case 'k': // Movimentar para baixo
            if (playerY2 > -0.9) { // Verificar se não há colisão na direção desejada
                playerY2 -= 0.1;
            }
            break;
        case 'l': // Movimentar para a direita
            if (playerX2 < 0.9) { // Verificar se não há colisão na direção desejada
                playerX2 += 0.1;
            }
            break;    
        case 'r': // Reiniciar o jogo
        	break;
        case 'p': // Mudar a cor do jogador
			break; 	
        default:
            break;
    }

   if (playerX >= (exitX - 0.05) && playerX <= (exitX + 0.05) && playerY >= (exitY - 0.05) && playerY <= (exitY + 0.05)) {
        	score++; // Incrementar a pontuação
        	printf("Pontuacao: %d\n", score); // Exibir a pontuação atualizada
        	
        	
        	
        	mover_flag();      
    	}
    	
  	if (playerX2 <= (exitX + 0.05) && playerX2 >= (exitX - 0.05) && playerY2 <= (exitY + 0.05) && playerY2 >= (exitY - 0.05)) {
        	score2++; // Incrementar a pontuação
        	printf("Pontuacao: %d\n", score2); // Exibir a pontuação atualizada
        	
        	
        	   mover_flag();    
    	}
    	
	glutPostRedisplay(); // Atualizar a tela
	
	


}

  /*  	int ii;
    	float min2 = -0.9, max2 = 0.9, step2 = 0.05;
    	int range2 = (max2 - min2) / step2 + 1;
    	float num3, num4;
    	char string_formatada2[10];

    // seed para a função rand()
    srand(time(NULL));

    for (ii = 0; ii < 10; ii++) {
        // gera um número aleatório inteiro entre 0 e range-1
        int random_int2 = rand() % range2;

        // ajusta o número para que fique dentro da faixa desejada e com a variação desejada
        num4 = min2 + random_int2 * step2;
     //   printf("%f",num);
        
        
        
    sprintf(string_formatada2, "%.1f", num4); // formata o número em uma string com uma casa decimal
    sscanf(string_formatada2, "%f", &num3); // lê a string formatada em uma nova variável float
   
 	printf("%f",num3);
 	}
		
		exitX2=exitX2-num3;
    	exitY2=exitY2+num3;
		
		
		

	if(exitX2<-0.9 && exitY2<-0.9){
		exitX2=exitX2+num3;
		exitY2=exitX2+num3;	
	}else if(exitX2>0.9 && exitY2>0.9){
		exitX2=exitX2-num3;
		exitY2=exitX2-num3;	
	}else if(exitX2<-0.9 && exitY2>0.9){
		exitX2=exitX2+num3;
		exitY2=exitY2-num3;	
	}else if(exitX2>0.9 && exitY2<-0.9){
		exitX2=exitX2-num3;
		exitY2=exitY2+num3;
	}else if(exitX2<-0.9){
			exitX2=exitX2-num3;
	}else if(exitX2>0.9){
			exitX2=exitX2+num3;
	}else if(exitY2>0.9){
			exitY2=exitY2-num3;
	}else if(exitY2<-0.9){
			exitY2=exitY2+num3;
	}else{
	}
		
    }


    glutPostRedisplay(); // Atualizar a tela
}
*/















/*
void cronometro{
	time_t start_time, current_time;
    double elapsed_time;
    
    start_time = time(NULL);
    
    while (1) {
        current_time = time(NULL);
        elapsed_time = difftime(current_time, start_time);
        printf("%.1lf\n", elapsed_time);
        if (elapsed_time >= 30.0) {
            break;
        }
    }
}
*/

/*

void atualizaTempo(int valor) {
    // atualiza o tempo atual do cronômetro
    tempo_atual = (glutGet(GLUT_ELAPSED_TIME) - tempo_anterior + milissegundos) / 1000;
    if (tempo_atual > tempo_total) {
        tempo_atual = tempo_total;
    }

    // formata o tempo em segundos com uma casa decimal
    sprintf(tempo_str, "%.1f", (float)tempo_atual);

    // redesenha a janela
    glutPostRedisplay();

    // registra a função novamente para atualizar o tempo a cada 10 milissegundos
    glutTimerFunc(10, atualizaTempo, 0);
}

void desenhaCena() {
    
}*/




  

    




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Labirinto");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
 

/*    // registra a função que atualiza o tempo
    tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
    glutTimerFunc(10, atualizaTempo, 0);
*/


	glutMainLoop();
	
	return 0;
}


















/*
#include <GL/glut.h>

float playerX = -0.8; // Posição X do jogador
float playerY = -0.8; // Posição Y do jogador

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Cor dos caminhos do labirinto

    // Desenhar os caminhos do labirinto
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.9); // Ponto inicial
    glVertex2f(0.9, -0.9); // Ponto final
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.9, 0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glEnd();

    glColor3f(0.0, 1.0, 0.0); // Cor da saída do labirinto

    // Desenhar a saída do labirinto
    glBegin(GL_QUADS);
    glVertex2f(0.8, -0.9); // Ponto inferior esquerdo
    glVertex2f(0.9, -0.9); // Ponto inferior direito
    glVertex2f(0.9, -0.8); // Ponto superior direito
    glVertex2f(0.8, -0.8); // Ponto superior esquerdo
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Cor do jogador

    // Desenhar o jogador
    glBegin(GL_QUADS);
    glVertex2f(playerX - 0.05, playerY - 0.05); // Ponto inferior esquerdo
    glVertex2f(playerX + 0.05, playerY - 0.05); // Ponto inferior direito
    glVertex2f(playerX + 0.05, playerY + 0.05); // Ponto superior direito
    glVertex2f(playerX - 0.05, playerY + 0.05); // Ponto superior esquerdo
    glEnd();

    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor de fundo
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Sistema de coordenadas
}

void keyboard(unsigned char key, int x, int y) {
    // Função de callback do teclado para mover o jogador

    switch (key) {
        case 'w': // Movimentar para cima
            if (playerY < 0.9) { // Verificar se não há colisão na direção desejada
                playerY += 0.1;
            }
            break;
        case 'a': // Movimentar para a esquerda
            if (playerX > -0.9) { // Verificar se não há colisão na direção deseja
				playerX -= 0.1;
			}
			break;
		case 's': // Movimentar para baixo
			if (playerY > -0.9) { // Verificar se não há colisão na direção desejada
				playerY -= 0.1;
			}
			break;
		case 'd': // Movimentar para a direita
			if (playerX < 0.9) { // Verificar se não há colisão na direção desejada
				playerX += 0.1;
			}
			break;
		default:
			break;
			}
			glutPostRedisplay(); // Atualizar a tela
			}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Labirinto");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
	return 0;
}
*/





























//////////////  controle de colisão
/*
var rect1 = {x: 5, y: 5, width: 50, height: 50}
var rect2 = {x: 20, y: 10, width: 10, height: 10}


if (rect1.x < rect2.x + rect2.width &&
   rect1.x + rect1.width > rect2.x &&
   rect1.y < rect2.y + rect2.height &&
   rect1.y + rect1.height > rect2.y) {
    // collision detected!
}

// filling in the values =>

if (5 < 30 &&
    55 > 20 &&
    5 < 20 &&
    55 > 10) {
    // collision detected!
}
*/










/*

#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>



#define COLS 30
#define ROWS 30
#define CELL_SIZE 30
#define WALL_THICKNESS 7

#define WIDTH 800 // largura da janela
#define HEIGHT 700 // altura da janela


int maze[COLS][ROWS];

void draw_maze()
{
    int x, y;
    setcolor(WHITE);
    // Desenha as paredes horizontais
    for (y = 0; y <= ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            if (maze[x][y] & 1) {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x*CELL_SIZE, y*CELL_SIZE, (x+1)*CELL_SIZE, y*CELL_SIZE+WALL_THICKNESS);
            }
        }
    }
    // Desenha as paredes verticais
    for (x = 0; x <= COLS; x++) {
        for (y = 0; y < ROWS; y++) {
            if (maze[x][y] & 2) {
                setfillstyle(SOLID_FILL, WHITE);
                bar(x*CELL_SIZE, y*CELL_SIZE, x*CELL_SIZE+WALL_THICKNESS, (y+1)*CELL_SIZE);
            }
        }
    }
}




void draw_triangle(){
	
	int a = WIDTH / 2; // posição inicial do triângulo
    int b = HEIGHT / 2;
    int size = 5; // tamanho do triângulo

    while (1) {
        if (kbhit()) { // se alguma tecla for pressionada
            int key = getch(); // obtém o código da tecla pressionada

            if (key == 27) { // se for a tecla ESC, sai do programa
                break;
            }
            else if (key == 'a') { // se for a tecla 'a', move o triângulo para a esquerda
                a -= 10;
            }
            else if (key == 'd') { // se for a tecla 'd', move o triângulo para a direita
                a += 10;
            }
            else if (key == 'w') { // se for a tecla 'w', move o triângulo para cima
                b -= 10;
            }
            else if (key == 's') { // se for a tecla 's', move o triângulo para baixo
                b += 10;
            }
    
}
    
            
            //cleardevice(); // limpa a tela
            setfillstyle(SOLID_FILL, COLOR(255, 255, 255));
            int points[] = { a, b - size, a - size, b + size, a + size, b + size };
            fillpoly(3, points);
        }
    }
    

int main()
{
	

    int gd = DETECT, gm;
    
    // Inicializa a biblioteca graphics
    initgraph(&gd, &gm, "");
    
    
    
	int x, y;
// Define a semente aleatória
    srand(time(NULL));
    // Inicializa o labirinto com todas as paredes
    for (x = 0; x < COLS; x++) {
        for (y = 0; y < ROWS; y++) {
            maze[x][y] = 15;
        }
    }
    // Gera o labirinto
    // Aqui você pode utilizar o algoritmo de sua preferência para gerar o labirinto
    // Por exemplo, o algoritmo de Kruskal, Prim ou Recursive Backtracker
    // Neste exemplo, eu vou gerar um labirinto aleatório
    for (x = 0; x < COLS; x++) {
        for (y = 0; y < ROWS; y++) {
            int r = rand() % 4;
            if (r == 0 && x > 0) {
                maze[x][y] &= ~1;
                maze[x-1][y] &= ~2;
            } else if (r == 1 && x < COLS-1) {
                maze[x][y] &= ~1;
                maze[x+1][y] &= ~2;
            } else if (r == 2 && y > 0) {
                maze[x][y] &= ~2;
                maze[x][y-1] &= ~1;
            } else if (r == 3 && y < ROWS-1) {
                maze[x][y] &= ~2;
                maze[x][y+1] &= ~1;
            }
        }
    }
    // Desenha o labirinto na tela
    draw_maze();
	
	
	
	
	
	
	 
	draw_triangle();
    
    
    
    
    
    // Aguarda uma tecla ser pressionada para finalizar o programa
    getch();
    // Finaliza a biblioteca graphics
    closegraph();
    return 0;
}
*/
