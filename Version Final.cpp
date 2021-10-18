#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

void eleccion();
void primerMenu();
void imprimirTablero();
void ceros();
void dosJugadores();
void contraCpu();
void segundoMenu();
void historial();
void limpiarHistorial();
int  ganador();

string tablero[3][3] = {};
string vectorTablero[9] = {};
string nombre1, nombre2, nombre;
char aux[3];
int n = 0;

bool boolDosjugadores = true, boolMenu = true;
int modoJuego = 0, posicion = 0, contVector = 0;

int main()
{
    while (boolMenu)
    {
        ceros();
        primerMenu();
        eleccion();
    }
}
//Aqui se define cual modo de juego va a usarse
void eleccion()
{

    switch (modoJuego)
    {
    case 1:
    {
        dosJugadores();
    }
    break;
    case 2:
    {
        contraCpu();
    }
    break;
    case 3:
    {
        //AQUI VA LO DEl HISTORIAL
        limpiarHistorial();
        system("clear");
    }
    break;

    
        
}
}

//Funcion que imprime el menu principal y permite elegir el modo de juego
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
    cout << "\n\t\t\t\t║           1 - Dos Jugadores            ║" << endl;
    usleep(tiempoDelay);
    cout << "\t\t\t\t║           2 - Jugador vs CPU           ║" << endl;
    usleep(tiempoDelay);
    cout << "\t\t\t\t║        3 - Reiniciar historial         ║" << endl;
    usleep(tiempoDelay);
    cout << "\t\t\t\t║               4 - Salir                ║" << endl;
    usleep(tiempoDelay);
    cout << "\t\t\t\t╚════════════════════════════════════════╝" << endl;
    usleep(tiempoDelay);

    cout << "Digite el numero del juego: ";

    while (boolDesicion == true)
    {
        modoJuego = 0;

        cin >> modoJuego;
        if (modoJuego <= 3 && modoJuego > 0)
        {
            break;
            system("clear");
        }
        else if (modoJuego == 4) {
            boolDesicion = false;
            boolMenu = false;
        }
        else
        {
            cout << "Digite un modo de juego valido: ";
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
    contVector = 0;

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

//Funcion encargada de la mecanica del modo 2 jugadores
void dosJugadores()
{
    bool boolCasillasmarc = true;
    int p = 0;
    int eleccion = 0;

    system("clear");

    cout << "Escriba el nombre del Jugador 1: ";
    cin >> nombre1;
    cout << "Escriba el nombre del Jugador 2: ";
    cin >> nombre2;
    system("clear");

    while (boolDosjugadores == true)
    {
        system("clear");

        imprimirTablero();
        cout << "\n\nTurno de " << nombre1 << " X: " ;
        nombre = nombre1;
        //este while se usa para comprobar que la casilla que se quiere poner este vacia 
        while (boolCasillasmarc == true)
        {
            cin >> posicion;

            if (vectorTablero[posicion - 1] != " ")
            {
                cout << "Esta casilla ya fue marcada, digite una vacia: ";
            }
            else
            {
                break;
            }
        }
        system("clear");
        //Usamos un vector y despues lo trascribimos a la matriz 
        vectorTablero[posicion - 1] = "X";
        //La variable contVector se encarga de contar los turnos que van del juego para no hacer comparaciones antes de lo necesario
        contVector++;

        p = 0;
        //trascribimos del vector a la matriz
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                tablero[i][j] = vectorTablero[p];
                p++;
            }
        }
    //La funcion ganador verifica 3 casillas al tiempo horizontales, verticales y las dos diagonales
        ganador();
        //Usamos este if y esta etiqueta por si el jugador 1 dio con una combinacion ganadora no le quede el turno al jugador 2
        //ya que podria ocasionar un  bucle o una falla en la victoria
        if (ganador() == 1 || ganador() == 2)
        {

            goto etc;
        }

        imprimirTablero();
        cout << "\n\nTurno de " << nombre2 << " O: ";
        nombre = nombre2;
        while (boolCasillasmarc == true)
        {
            cin >> posicion;

            if (vectorTablero[posicion - 1] != " ")
            {
                cout << "Esta casilla ya fue marcada, digite una vacia: ";
            }
            else
            {
                break;
            }
        }
        vectorTablero[posicion - 1] = "O";
        contVector++;
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
//Usamos la funcion ganador aqui para analizar el movimiento inmediatamente se de
        ganador();
        
//Usamos este if para solo comparar despues de 5 turno que es la cantidad minima para ganar
        if (contVector >= 5 && ganador() == 1)
        {
            //aqui es usada la etiqueta
        etc:
    historial();
            imprimirTablero();
            //El segundo menu es el que aparece despues de acabar una partida 
            segundoMenu();
            cin >> eleccion;
            if (eleccion == 1)
            {
                //Ponemos todo en cero para volver a jugar sin problema
                ceros();
            }
            else if (eleccion == 0)
            {
                system("clear");
             //La funcion Dosjugadores se encuenta en un ciclo while, por tanto al dar un break de rompe 
             //Y vuelve al menu
                break;
            }
            else
            {
                //Para salir cambiamos la variable bool del inicio en el main y el programa termina
                boolMenu = false;

                break;
            }
        }
    }
    
}
//Esta es la funcion usada para la mecanica del modo Contra cpu
void contraCpu()
{
    bool boolCasillasCpu = true;
    int p = 0;
    srand((unsigned)time(0));
    int eleccion = 0;
    system("clear");
    cout << " ╔══════╗  " << endl;
    cout << "╔╝ ●  ● ╚╗ HOLA, MI NOMBRE ES DJH Y YO JUGARE CONTIGO " << endl;
    cout << "╚╗  ▆▆  ╔╝" << endl;
    cout << " ╚══════╝" << endl;
    usleep(2000000);
    system("clear");
    cout << " ╔══════╗  " << endl;
    cout << "╔╝ ●  ● ╚╗ ESPERO QUE SEAS BUENO " << endl;
    cout << "╚╗  ▆▆  ╔╝" << endl;
    cout << " ╚══════╝" << endl;
    usleep(2000000);

    cout << "Escribe tu nombre:" << endl;
    cin >> nombre1;

    system("clear");
    cout << " ╔══════╗  " << endl;
    cout << "╔╝ ●  ● ╚╗ HOLA " << nombre1 << " EMPEZEMOS A JUGAR" << endl;
    cout << "╚╗  ▆▆  ╔╝" << endl;
    cout << " ╚══════╝" << endl;
    usleep(2000000);
//Usamos la  misma mecanica que en la funcion dos jugadores
    while (boolDosjugadores == true)
    {
        system("clear");

        imprimirTablero();
        cout << "\n\nTurno de " << nombre1 << " X :" << endl;
        nombre = nombre1;
        n = 2;
        while (boolCasillasCpu)
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
        contVector++;

        p = 0;
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                tablero[i][j] = vectorTablero[p];
                p++;
            }
        }

        ganador();
        if (ganador() == 1 || ganador() == 2)
        {
            goto etc;
        }

        imprimirTablero();
        cout << "\n\nTurno de la CPU O :" << endl;

        cout << " ╔══════╗  " << endl;
        cout << "╔╝ ◍  ◍ ╚╗  " << endl;
        cout << "╚╗  ▆▆  ╔╝" << endl;
        cout << " ╚══════╝" << endl;

        cout << "DEJAME PENSAR..." << endl;
        usleep(2000000);
        cout << "YA LO TENGO!" << endl;
        usleep(800000);
        nombre = "CPU";
        nombre2="CPU";
        n = 1;
        while (boolCasillasCpu == true)
        {
            //Aqui se le asigna el valor random para la cpu
            posicion = 1 + rand() % 9;

            if (vectorTablero[posicion - 1] == " ")
            {
                break;
            }
        }
        vectorTablero[posicion - 1] = "O";
        contVector++;
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

        ganador();

        if (contVector >= 5 && ganador() == 1)
        {
        etc:

            imprimirTablero();
            //Usamos la variable "n" para saber si la cpu perdio o gano
            
            if (n == 2 && ganador() == 1)

            {
                //Estas son las reacciones que tiene la cpu al momento de perder
                cout << "\n ╔══════╗  " << endl;
                cout << "╔╝ ⊙  ⊙ ╚╗  ¿!COMO ME GANASTE¡?" << endl;
                cout << "╚╗  ●   ╔╝" << endl;
                cout << " ╚══════╝" << endl;
                usleep(2000000);
                system("clear");
                cout << " ╔══════╗  " << endl;
                cout << "╔╝ ⊙  ⊙ ╚╗  ¡DAME UNA REVANCHA SUERTUDO!" << endl;
                cout << "╚╗  ●   ╔╝" << endl;
                cout << " ╚══════╝" << endl;
                usleep(2000000);
                cout << "\n ╔══════╗  " << endl;
                cout << "╔╝ ⊙  ⊙ ╚╗  VAMOS, INTRODUCE EL 1 SI TE CREES BUENO" << endl;
                cout << "╚╗  ●   ╔╝" << endl;
                cout << " ╚══════╝" << endl;
                usleep(2990000);
            }
            else if (n == 1 && ganador() == 1)
            {
                // Al momento de ganar
                cout << "\n ╔══════╗  " << endl;
                cout << "╔╝ ●  ● ╚╗  FUE UNA VICTORIA MUY FACIL" << endl;
                cout << "╚╗  ▆▆  ╔╝  NO SABES JUGAR HA HA HA HA" << endl;
                cout << " ╚══════╝" << endl;
                usleep(2000000);
            }

            n = 0;

            segundoMenu();
            historial();
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

void segundoMenu()
{
    if (ganador() == 1)
    {
        cout << "\n\n¡Tres en raya!" << endl;
        cout << "\nEl ganador es " << nombre << endl;
    }
    //Si la funcion ganador retorna 2 es porque es un empate 
    // y la variable modoJuego==2 es para diferenciar el modo de juego 1 del 2
    else if (ganador() == 2 && modoJuego == 2)
    {
        cout << "\n\nEMPATAMOS " << nombre << ".\nBIEN JUGADO" << endl;
        cout << " ╔══════╗  " << endl;
        cout << "╔╝ ⊙  ⊙ ╚╗ " << endl;
        cout << "╚╗  ▆▆  ╔╝" << endl;
        cout << " ╚══════╝" << endl;
        usleep(2000000);
    }
    else if (ganador() == 2 && modoJuego == 1)
    {

        cout << "\n¡Ha sido un empate!" << endl;
    }
    cout << "══════════════════════════════════" << endl;
    cout << "Escriba el numero de la opcion: " << endl;
    cout << "\n0. Volver al menu principal" << endl;
    cout << "\n1. Para volver a jugar" << endl;
    cout << "\nPara salir presione cualquier otro número" << endl;
}

int ganador()
{
    int j = 0;
    if (contVector >= 5)
    {
//Comparamos las 3 casilas al tiempo 
        for (int i = 0; i < 3; i++)
        {

            if ((tablero[i][j] == "X" && tablero[i][j + 1] == "X" && tablero[i][j + 2] == "X") || (tablero[i][j] == "O" && tablero[i][j + 1] == "O" && tablero[i][j + 2] == "O"))
            {
                return 1;
            }
            if ((tablero[j][i] == "X" && tablero[j + 1][i] == "X" && tablero[j + 2][i] == "X") || (tablero[j][i] == "O" && tablero[j + 1][i] == "O" && tablero[j + 2][i] == "O"))
            {

                return 1;
            }

            if ((vectorTablero[0] == "X" && vectorTablero[4] == "X" && vectorTablero[8] == "X") || (vectorTablero[0] == "O" && vectorTablero[4] == "O" && vectorTablero[8] == "O"))
            {
                return 1;
            }

            if ((vectorTablero[6] == "X" && vectorTablero[4] == "X" && vectorTablero[2] == "X") || (vectorTablero[6] == "O" && vectorTablero[4] == "O" && vectorTablero[2] == "O"))
            {
                return 1;
            }
        }
    }
//Si ya pasaron 9 turnos y la funcion no retorno nada es porque no se llego a una posicion ganadora 
//Pero las casillas ya estan llenas
    if (contVector == 9)
    {
        return 2;
    }

    return 0;
}
//Esta funcion es encargada de crear un archivo de texto en donde esten las partidas jugadas
void historial() {
    time_t t;
    struct tm * timeinfo;
    time ( &t );
    auto tm = *localtime(&t);
    fstream his("historial.txt", fstream::in | fstream::app);
    his << nombre1 << " VS " << nombre2 << endl;
    if(ganador()==1){
    his << "El ganador fue: " << nombre << endl;
    }
    else if(ganador()==2){
        his << "Empate" << endl;
    }
    his << put_time(&tm, "%d/%m/%Y -- %H:%M:%S") << endl;
    his << "\n";     
    his.close();          
}

void limpiarHistorial() {
    ofstream historia("historial.txt");
}


