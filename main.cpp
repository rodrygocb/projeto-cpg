
/*
#include <GL/glut.h>

void init() {
   // Habilita a iluminação
   glEnable(GL_LIGHTING);
   
   // Define a cor de fundo
   glClearColor(0.0, 0.0, 0.0, 0.0);

   // Define a posição da luz
   GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

   // Define as propriedades de iluminação
   GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat shininess[] = { 50.0 };
   glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

   // Habilita a fonte de luz
   glEnable(GL_LIGHT0);

}

void display() {
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glutSolidTeapot(0.5);
  // glutSwapBuffers();
}
*/
/*
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(400, 400);
   glutCreateWindow("Iluminação com GLUT");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
*/


#include <GL/glut.h>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h> 
#include <windows.h>
#include <locale.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 30


float playerX = -0.8; // Posição X do jogador 1
float playerY = -0.8; // Posição Y do jogador 1
int score = 0; // Pontuação do jogador 1

float playerX2 = +0.8; // Posição X do jogador 2
float playerY2 = +0.8; // Posição Y do jogador 2
int score2 = 0; // Pontuação do jogador 2

float exitX; // Posição X da saída do labirinto
float exitY; // Posição Y da saída do labirinto

///cronometro
int tempo_total = 100; // tempo total em segundos
int tempo_atual = 0; // tempo atual do cronômetro
int milissegundos = 0; // milissegundos atuais
int tempo_anterior = 0; // tempo anterior em milissegundos
char tempo_str[10]; // string que armazena o tempo formatado

//data
time_t agora = time(NULL);
struct tm *data = localtime(&agora);

int dia = data->tm_mday;
int mes = data->tm_mon + 1;  // Adicionar 1 ao mês, pois janeiro é representado como 0
int ano = data->tm_year + 1900;  // Adicionar 1900 ao ano, pois o valor armazenado é o número de anos desde 1900


////// cores 
float red = 1.0f, green = 1.0f, blue = 1.0f; // cor da flag
float red1 = 1.0f, green1 = 1.0f, blue1 = 1.0f; // cor do jogador 1
float red2 = 1.0f, green2 = 1.0f, blue2 = 1.0f; // cor do jogador 2


float v1 = 0.0, v2 = 0.0, v3 = 0.0, v4 = 0.0; 

void display(void) {

    // desenha o cronometro
    glRasterPos2f(-0.5, 0.8);
    for (int i = 0; i < strlen(tempo_str); i++) {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tempo_str[i]);
    }
    glutSwapBuffers();


	
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

    glColor3f(red, green, blue); // Cor da flag

    // Desenhar a flag
    glBegin(GL_QUADS);
    glVertex2f(exitX - 0.05, exitY - 0.05); // Ponto inferior esquerdo
    glVertex2f(exitX + 0.05, exitY - 0.05); // Ponto inferior direito
    glVertex2f(exitX + 0.05, exitY + 0.05); // Ponto superior direito
    glVertex2f(exitX - 0.05, exitY + 0.05); // Ponto superior esquerdo
    glEnd();
	


///// Definções do jogador 2 ////////////////////////

	// Cor do jogador 1
    glColor3f(red1, green1, blue1);
	
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
    glColor3f(red2, green2, blue2);
	
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
	    
    
    
    
    
	
    // Define a posição da luz
    // Define a posição da luz
    GLfloat light_pos[] = { v1, v2, v3, v4 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    // Define as propriedades de iluminação
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    //GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat shininess[] = { 100.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	
    // Habilita a fonte de luz
    //glEnable(GL_LIGHT0);
}



void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor de fundo
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Sistema de coordenadas
       
    
}



void mover_flag(){ // função para mover a flag dentro do espaço
	
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
     		

	    	sprintf(string_formatada, "%.1f", num2); // formata o número em uma string com uma casa decimal
   			sscanf(string_formatada, "%f", &num); // lê a string formatada em uma nova variável float
   
			//printf("%f",num);  
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

void fecharJanela() {
    // Liberar recursos e encerrar o programa
    glutDestroyWindow(glutGetWindow());
    exit(0);
}




void records(){
	system("cls");
	printf("\n\n");
	FILE* arquivo = fopen("recordes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        
    }

    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
    printf("\n\n\n");
	system("pause");
	int main();
}



// Função de callback do teclado para mover o jogador
void keyboard(unsigned char key, int x, int y) {


int jog, recorde;

    
    switch (key) {
    	int tecla;
    	tecla = getch();
    	case 27: // tecla esc
        	printf("\n\nVocê escolheu sair...");
        	printf("\n\nVolte logo...\n\n");
        	exit(0);
			break;
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
        // 1 a 3 - cores do jogador 1
        case '1': // amarelo
        	red1 = 1.0f;
            green1 = 1.0f;
            blue1 = 0.0f;
            break;
    	case '2': // marrom
        	red1 = 0.65f;
            green1 = 0.16f;
            blue1 = 0.16f;
    		break;
    	case '3': // cinza
        	red1 = 0.2f;
            green1 = 0.2f;
            blue1 = 0.2f;
    		break;
    	// 4 a 6 - cores do jogador 2
        case '4': //magenta
        	red2 = 1.0f;
            green2 = 0.0f;
            blue2 = 1.0f;
    		break;
    	case '5': // safira
        	red2 = 0.0f;
            green2 = 0.08f;
            blue2 = 0.5f;
    		break;
    	case '6': // lavanda
        	red2 = 0.9f;
            green2 = 0.7f;
            blue2 = 0.9f;
    		break;
		// 7 a 9 - cores da flag    
        case '7': // vermelho
        	red = 1.0f;
            green = 0.0f;
            blue = 0.0f;
    		break;
		case '8': // verde
        	red = 0.0f;
            green = 1.0f;
            blue = 0.0f;
    		break;
    	case '9': // azul
        	red = 0.0f;
            green = 0.0f;
            blue = 1.0f;
    		break;
    	///// iluminação
       case 'r': // Habilita a fonte de luz - ligar a luz
           	glEnable(GL_LIGHTING);
   			glEnable(GL_LIGHT0);
			break;
		case 'b': // Desabilito a fonte de Luz - desligar a luz  
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0); 	
        default:
            break;
    }

   if (playerX >= (exitX - 0.05) && playerX <= (exitX + 0.05) && playerY >= (exitY - 0.05) && playerY <= (exitY + 0.05)) {
        	score++; // Incrementar a pontuação
        	//printf("Pontuacao: %d\n", score); // Exibir a pontuação atualizada
        	
        	
        	
        	mover_flag();      
    }
    	
  	if (playerX2 <= (exitX + 0.05) && playerX2 >= (exitX - 0.05) && playerY2 <= (exitY + 0.05) && playerY2 >= (exitY - 0.05)) {
        	score2++; // Incrementar a pontuação
        	//printf("Pontuacao: %d\n", score2); // Exibir a pontuação atualizada
        	   
        	
        	   mover_flag();    
    }
    
    if(score==5 || score2==5){
    	if(score>score2){
			recorde=score;
			jog=1;
		}else if(score2>score){
			recorde=score2;
			jog=2;
		}
		
			FILE* arquivo = fopen("recordes.txt", "a");
    		if (arquivo == NULL) {
        		printf("Erro ao abrir arquivo.\n");
        	}
			 
   			fprintf(arquivo, "\n  Jogador %d    |      %d    |    %d s    |  %02d/%02d/%d", jog, recorde, tempo_atual, dia, mes, ano);
   		
		    fclose(arquivo);
		    
		    
		    
		    /////////////////////////////////////////////////////////
    	
    	printf("\n\nParabéns..\n\nVocê entrou no nosso livro dos recordes");
    	exit(0);
    	
	}	
	  
	glutPostRedisplay(); // Atualizar a tela

}


void specialKeys(int key, int x, int y) {
 
   int jog, recorde;
    
    switch (key) {
    	int tecla;
    	tecla = getch();
		case GLUT_KEY_UP: // Movimentar para cima
            if (playerY2 < 0.9) { // Verificar se não há colisão na direção desejada
                playerY2 += 0.1;
            }
            break;
        case GLUT_KEY_LEFT: // Movimentar para a esquerda
            if (playerX2 > -0.9) { // Verificar se não há colisão na direção desejada
                playerX2 -= 0.1;
            }
            break;
        case GLUT_KEY_DOWN: // Movimentar para baixo
            if (playerY2 > -0.9) { // Verificar se não há colisão na direção desejada
                playerY2 -= 0.1;
            }
            break;
        case GLUT_KEY_RIGHT: // Movimentar para a direita
            if (playerX2 < 0.9) { // Verificar se não há colisão na direção desejada
                playerX2 += 0.1;
            }
            break;    
        default:
            break;
    }

   if (playerX >= (exitX - 0.05) && playerX <= (exitX + 0.05) && playerY >= (exitY - 0.05) && playerY <= (exitY + 0.05)) {
        	score++; // Incrementar a pontuação
        	//printf("Pontuacao: %d\n", score); // Exibir a pontuação atualizada
        	
        	
        	
        	mover_flag();      
    }
    	
  	if (playerX2 <= (exitX + 0.05) && playerX2 >= (exitX - 0.05) && playerY2 <= (exitY + 0.05) && playerY2 >= (exitY - 0.05)) {
        	score2++; // Incrementar a pontuação
        	//printf("Pontuacao: %d\n", score2); // Exibir a pontuação atualizada
        	   
        	
        	   mover_flag();    
    }
    
    if(score==5 || score2==5){
    	if(score>score2){
			recorde=score;
			jog=1;
		}else if(score2>score){
			recorde=score2;
			jog=2;
		}
		
			FILE* arquivo = fopen("recordes.txt", "a");
    		if (arquivo == NULL) {
        		printf("Erro ao abrir arquivo.\n");
        	}
			 
   			fprintf(arquivo, "\n  Jogador %d    |      %d    |    %d s    |  %02d/%02d/%d", jog, recorde, tempo_atual, dia, mes, ano);
   		
		    fclose(arquivo);
    
    	exit(0);
	}	
	  
	glutPostRedisplay(); // Atualizar a tela

}


void instrucoes(){
	system("cls");
	printf("\netteete\n\n\n");

	system("pause");
	int main();
	

}





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
    glutTimerFunc(0, atualizaTempo, 0);
}



int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	glutInit(&argc, argv);

    

	 
	do{
		system("cls");
		printf(" -------------------------- \n"); 
		printf(" |        Jonjo Game        | \n"); 
		printf(" --------------------------\n");
		printf("1. Start Game\n");
		printf("2. Instruções\n");	 
		printf("3. Recordes\n");
		printf("4. Quit\n\n");
		printf("Select option: ");
				
		char op = getche();
		system("cls");
		
		if(op=='1'){
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
			glutInitWindowSize(500, 500);
			glutInitWindowPosition(100, 100);
			glutCreateWindow("Labirinto");
	
			init();
			glutDisplayFunc(display);
			glutKeyboardFunc(keyboard);
			glutSpecialFunc(specialKeys);
			// registra a função que atualiza o tempo
    		tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
    		glutTimerFunc(10, atualizaTempo, 0);
			glutMainLoop();
		}else if(op=='2'){
			instrucoes();		
		}else if(op=='3'){
			records();
		}else if(op=='4'){
			exit(0);
		}else{
		} 
		
	}while(9);

	
return 0;
}






