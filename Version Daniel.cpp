//triqui boseto mio
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

void loop(char c[3][3]);
void loop2(char c[3][3]);
void intro_primera(char c[3][3]);
void tablero(char c[3][3]);
void introducir(char c[3][3]);
void introducir2(char c[3][3]);
void introducir_IA(char c[3][3]);
int ganar(char c[3][3]);

int main()
{
	char c[3][3];
	int a;
	int tiempoDelay = 70000;

	cout << "\t\t\t\t\t╔════════════════════════╗" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t\t║Bienvenido a Tic-Tac-Toe║" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t\t╚════════════════════════╝" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t╔════════════════════════════════════════╗" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t║       Seleccione un modo de juego      ║" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t║                                        ║";
	usleep(tiempoDelay);
	cout << "\n\t\t\t\t║       1-Dos Jugadores                  ║" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t║       2-Jugador vs CPU                 ║" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t║                                        ║" << endl;
	usleep(tiempoDelay);
	cout << "\t\t\t\t╚════════════════════════════════════════╝" << endl;
	usleep(tiempoDelay);
	scanf("%d", &a);

	if (a == 2)
	{
		loop(c);
	}
	else
	{
		loop2(c);
	}

	return 0;
}

void loop(char c[3][3])
{

	int i, j;
	i = 0;

	intro_primera(c);
	do
	{
		system("clear");
		tablero(c);

		if (i % 2 == 0)
		{
			introducir(c);
		}
		else
		{
			introducir_IA(c);
		}

		j = ganar(c);

		i++;

	} while (1 <= 9 && j == 2);

	system("clear");
	tablero(c);

	if (j == 0)
	{
		printf("\n\nFelicidades has ganado la partida!\n ");
	}
	else if (j == 1)
	{
		printf("\n\nintentalo otra vez, has perdido la partida!\n");
	}
	else
	{
		printf("\n\nHa sido un empate!\n");
	}
}

void loop2(char c[3][3])
{

	int i, j;
	i = 0;

	intro_primera(c);
	do
	{
		system("clear");
		tablero(c);

		if (i % 2 == 0)
		{
			introducir(c);
		}
		else
		{
			introducir2(c);
		}

		j = ganar(c);

		i++;

	} while (1 <= 9 && j == 2);

	system("clear");
	tablero(c);

	if (j == 0)
	{
		printf("\n\nFelicidades has ganado la partida!\n ");
	}
	else if (j == 1)
	{
		printf("\n\nintentalo otra vez, has perdido la partida!\n");
	}
	else
	{
		printf("\n\nHa sido un empate!\n");
	}
}

void intro_primera(char c[3][3])
{
	int i = 0;
	int j = 0;
	char aux = '1';
	// aux = 49;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = aux++;
		}
	}
}

void introducir(char c[3][3])
{

	int i = 0;
	int j = 0;
	int k = 0;
	char aux;

	do
	{
		do
		{
			printf("\n\ncolocar un ficha: ");
			fflush(stdin);
			scanf("%c", &aux);
		} while (aux < '1' || aux > '9');

		k = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{

					printf("Seleccione otra casilla.\n");
					k = 1;
				}
			}
		}
		// switch(aux){
		// 		case '1':{
		// 		i=0;
		// 		j=0;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '2':{
		// 		i=0;
		// 		j=1;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '3':{
		// 		i=0;
		// 		j=2;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '4':{
		// 		i=1;
		// 		j=0;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '5':{
		// 		i=1;
		// 		j=1;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '6':{
		// 		i=1;
		// 		j=2;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '7':{
		// 		i=2;
		// 		j=0;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '8':{
		// 		i=2;
		// 		j=1;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}

		// 		case '9':{
		// 		i=2;
		// 		j=2;
		// 		if (c[i][j]== 'X' || c[i][j]== 'O'){
		// 			k=1;
		// 			printf("la casilla seleccionada ya esta ocupada, por favor inentelo de nuevo\n\n");
		// 		}
		// 		break;
		// 	}
		// }
	} while (k == 1);
	c[i][j] = 'X';
}

void introducir2(char c[3][3])
{

	int i = 0;
	int j = 0;
	int k = 0;
	char aux;

	do
	{
		do
		{
			printf("\n\ncolocar un ficha: ");
			fflush(stdin);
			scanf("%c", &aux);
		} while (aux < '1' || aux > '9');

		aux = 49;
		k = 0;			
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++) {
				aux++;
				if (c[i][j] != aux){
					printf("Seleccione otra casilla.\n");
					k = 2;
				}
			}
		}
		
	} while (k == 2);
	c[i][j] = 'O';
}

void introducir_IA(char c[3][3])
{

	printf("\n\n");
	int i, j, k;
	srand(NULL);

	do
	{
		i = rand() % 3;
		j = rand() % 3;
		k = 0;

		if (c[i][j] == 'X' || c[i][j] == 'O')
		{
			k = 1;
		}
	} while (k == 1);

	c[i][j] = 'O';
}

void tablero(char c[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j < 2)
			{
				printf(" %c |", c[i][j]);
			}
			else
			{
				printf(" %c ", c[i][j]);
			}
		}
		if (i < 2)
		{
			printf("\n-----------\n");
		}
	}
}

//0 gana
//1 pierde
//c matriz
int ganar(char c[3][3])
{
	int j = 0;
	//primera jugada tomando en cuenta la casilla c[0][0], es decir la posición 1
	for (int i = 0; i < 3; i++)
	{

		if ((c[i][j] == 'X' && c[i][j + 1] == 'X' && c[i][j + 2] == 'X') || (c[i][j] == 'O' && c[i][j + 1] == 'O' && c[i][j + 2] == 'O'))
		{
			return 0;
		}
		if ((c[j][i] == 'X' && c[j + 1][i] == 'X' && c[j + 2][i] == 'X') || (c[j][i] == 'O' && c[j + 1][i] == 'O' && c[j + 2][i] == 'O'))
		{

			return 0;
		}

		if ((c[0][0] == 'X' && c[1][1] == 'X' && c[2][2] == 'X') || (c[0][0] == 'O' && c[1][1] == 'O' && c[2][2] == 'O'))
		{
			return 0;
		}

		if ((c[0][2] == 'X' && c[1][1] == 'X' && c[2][0] == 'X') || (c[0][2] == 'O' && c[1][1] == 'O' && c[2][0] == 'O'))
		{
			return 0;
		}
	}

	else
	{
		return 2;
	}
}
