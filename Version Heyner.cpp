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

string tablero[3][5] = {};
string posicion2[9] = {};
string nombre1, nombre2, nombre;
bool continuar = true, boolDesicion = true;
bool boolDosjugadores = true, o = true, boolCasillasmarc = true, boolMenu = true;
int modoJuego = 0, posicion = 0, p = 0, v = 0, confirmarGanador = 0, tiempoDelay = 70000;
int eleccion = 0;


int main()
{
    while (boolMenu)
    {
        ceros();
        inicio();
        mecanica();
    }
}


//Funcion que imprime el menu principal
void primerMenu()
{

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
    boolDesicion = true;
    while (boolDesicion == true)
    {
        modoJuego = 0;

        cin >> modoJuego;
        if (modoJuego < 2 && modoJuego > 0)
        {
            boolDesicion = false;
            system("clear");
        }
        else
        {
            cout << "Digite un modo de juego valido: " << endl;
        }
    }
}




void segundoMenu(){
system("clear");
            
            comp();
            if (confirmarGanador == 1)
            {
            etc:
                imprimirTablero();
                cout << "\n\n¡Tres en raya!" << endl;
                cout << "\nEl ganador es " << nombre << endl;
                cout << "══════════════════════════════════" << endl;
                cout << "Escriba el numero de la opcion: " << endl;
                cout << "0.Volver al menu principal" << endl;
                cout << "1.Para volver a jugar" << endl;
                cout << "2.Salir" << endl;
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
        confirmarGanador = 0;
        v = 0;
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                posicion2[v] = " ";
                v++;
                tablero[i][j] = " ";
            }
        }
    }



void mecanica()
{

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

                if (posicion2[posicion - 1] != " ")
                {
                    cout << "Esta casilla ya fue marcada, digite una vacia:" << endl;
                }
                else
                {
                    break;
                }
            }
            system("clear");
            posicion2[posicion - 1] = "X";

            p = 0;
            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {
                    tablero[i][j] = posicion2[p];
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
            while (o == true)
            {
                cin >> posicion;

                if (posicion2[posicion - 1] != " ")
                {
                    cout << "Esta casilla ya fue marcada, digite una vacia:" << endl;
                }
                else
                {
                    break;
                }
            }
            posicion2[posicion - 1] = "O";
            p = 0;
            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {
                    tablero[i][j] = posicion2[p];
                    p++;
                }
            }
            segundoMenu();
}


//
void comp()
{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            if ((tablero[i][j] == "X" && tablero[i][j + 1] == "X" && tablero[i][j + 2] == "X") || (tablero[i][j] == "O" && tablero[i][j + 1] == "O" && tablero[i][j + 2] == "O"))
            {
                confirmarGanador = 1;
            }
            if ((tablero[j][i] == "X" && tablero[j + 1][i] == "X" && tablero[j + 2][i] == "X") || (tablero[j][i] == "O" && tablero[j + 1][i] == "O" && tablero[j + 2][i] == "O"))
            {

                confirmarGanador = 1;
            }

            if ((posicion2[0] == "X" && posicion2[4] == "X" && posicion2[8] == "X") || (posicion2[0] == "O" && posicion2[4] == "O" && posicion2[8] == "O"))
            {
                confirmarGanador = 1;
            }

            if ((posicion2[6] == "X" && posicion2[4] == "X" && posicion2[2] == "X") || (posicion2[6] == "O" && posicion2[4] == "O" && posicion2[2] == "O"))
            {
                confirmarGanador = 1;
            }
        }
    }
}

