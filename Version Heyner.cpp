#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void primerMenu();
void imprimirTablero();
void mecanica();
void matrizvect();
void ceros();
void segundoMenu();
void comp();

string tablero[3][3] = {};
string vectorTablero[9] = {};
string nombre1, nombre2, nombre;

bool boolDosjugadores = true,boolMenu = true;
int modoJuego = 0, posicion = 0, confirmarGanador = 0;



int main()
{
    while (boolMenu)
    {
        ceros();
        primerMenu();
        mecanica();
    }
}


//Funcion que imprime el menu principal
void primerMenu()
{
    bool boolDesicion = true;
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

    cout << "Digite el numero del juego:" << endl;
    //c=true se usa para que vuelva a entrar al ciclo while
    
    while (boolDesicion == true)
    {
        modoJuego = 0;

        cin >> modoJuego;
        if (modoJuego < 2 && modoJuego > 0)
        {
            break;
            system("clear");
        }
        else
        {
            cout << "Digite un modo de juego valido: " << endl;
        }
    }
}






//funcion encargada llenar el tablero con espacios para que no pierda la forma la impresion del tablero
    void imprimirTablero()
    {

        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                if (j != 2)
                {
                    cout << " " << tablero[i][j] << " ║";
                }
                else
                {
                    cout << " " << tablero[i][j];
                }
            }
            if (i != 2)
            {
                cout << "\n═══╬═══╬═══\n";
            }
        }
    }


//llena todo con 0 para volver a jugar
    void ceros()
    {
        int posVector = 0;

        confirmarGanador = 0;
        
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                vectorTablero[posVector] = " ";
                posVector++;
                tablero[i][j] = " ";
            }
        }
    }



void mecanica()
{
bool boolCasillasmarc = true;
int p = 0;
int eleccion = 0;

system("clear");
    if (modoJuego == 1)
    {

        cout << "Escriba el nombre del Jugador 1:" << endl;
        cin >> nombre1;
        cout << "Escriba el nombre del Jugador 2:" << endl;
        cin >> nombre2;
        system("clear");

        while (boolDosjugadores == true)
        {
            

            imprimirTablero();
            cout << "\n\nTurno de " << nombre1 << " X :" << endl;
            nombre = nombre1;
            while (boolCasillasmarc == true)
            {
                cin >> posicion;

                if (vectorTablero[posicion - 1] != " ")
                {
                    cout << "Esta casilla ya fue marcada, digite una vacia:" << endl;
                }
                else
                {
                    break;
                }
            }
            system("clear");
            vectorTablero[posicion - 1] = "X";

            p = 0;
            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {
                    tablero[i][j] = vectorTablero[p];
                    p++;
                }
            }
            comp();
            if (confirmarGanador == 1)
            {
                goto etc;
            }

            imprimirTablero();
            cout << "\n\nTurno de " << nombre2 << " O :" << endl;
            nombre = nombre2;
            while (boolCasillasmarc == true)
            {
                cin >> posicion;

                if (vectorTablero[posicion - 1] != " ")
                {
                    cout << "Esta casilla ya fue marcada, digite una vacia:" << endl;
                }
                else
                {
                    break;
                }
            }
            vectorTablero[posicion - 1] = "O";
            p = 0;
            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {
                    tablero[i][j] = vectorTablero[p];
                    p++;
                }
            }
            system("clear");
            
            comp();
            if (confirmarGanador == 1)
            {
            etc:
                imprimirTablero();
                segundoMenu();
                cin >> eleccion;
                if (eleccion == 1)
                {
                    ceros();
                }
                else if (eleccion == 0)
                {
                    system("clear");
                    break;
                }
                else
                {
                    boolMenu = false;
                    break;
                }
            }
        }
    }

            
}

void segundoMenu(){
cout << "\n\n¡Tres en raya!" << endl;
                cout << "\nEl ganador es " << nombre << endl;
                cout << "══════════════════════════════════" << endl;
                cout << "Escriba el numero de la opcion: " << endl;
                cout << "0.Volver al menu principal" << endl;
                cout << "1.Para volver a jugar" << endl;
                cout << "2.Salir" << endl;

}


void comp()
{
    int j = 0;
    for (int i = 0; i < 3; i++)
    {

            if ((tablero[i][j] == "X" && tablero[i][j + 1] == "X" && tablero[i][j + 2] == "X") || (tablero[i][j] == "O" && tablero[i][j + 1] == "O" && tablero[i][j + 2] == "O"))
            {
                confirmarGanador = 1;
            }
            if ((tablero[j][i] == "X" && tablero[j + 1][i] == "X" && tablero[j + 2][i] == "X") || (tablero[j][i] == "O" && tablero[j + 1][i] == "O" && tablero[j + 2][i] == "O"))
            {

                confirmarGanador = 1;
            }

            if ((vectorTablero[0] == "X" && vectorTablero[4] == "X" && vectorTablero[8] == "X") || (vectorTablero[0] == "O" && vectorTablero[4] == "O" && vectorTablero[8] == "O"))
            {
                confirmarGanador = 1;
            }

            if ((vectorTablero[6] == "X" && vectorTablero[4] == "X" && vectorTablero[2] == "X") || (vectorTablero[6] == "O" && vectorTablero[4] == "O" && vectorTablero[2] == "O"))
            {
                confirmarGanador = 1;
            }
        
    }
}


