#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <cstdio>
#include "rlutil.h"


using namespace std;

#include "utils.h"

int main()
{
    int mp,mr;
    string mj;
    bool bandera = true;

    while (true)
    {


        if (bandera == true)
        {
            mp = 0;
            mr=0;
            bandera = false;
        }

        char opc;

        // Limpia la pantalla y muestra el men�
        system("cls");
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(55,3);
        // Imprime el t�tulo del juego
        cout << "El dados malditos" << endl;
        rlutil::setColor(rlutil::CYAN);
        // Imprime las opciones del men�
        rlutil::locate(55,4);
        cout << "1- Un jugador" << endl;
        rlutil::locate(55,5);
        cout << "2- Dos jugadores" << endl;
        rlutil::locate(55,6);
        cout << "3- Mayor puntaje" << endl;
        rlutil::locate(55,7);
        cout << "4- Salir" << endl;
        rlutil::locate(55,8);
        // Solicita al usuario ingresar una opci�n
        rlutil::setColor(rlutil::GREEN);
        cout << "Ingrese una opcion" << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(55,9);
        cin >> opc;

        system("cls");
        // Eval�a la opci�n ingresada por el usuario
        switch (opc)
        {
        case '1':
            // Llama a la funci�n para un jugador
            unJugador(mp,mj,mr);
            break;

        case '2':
            // Llama a la funci�n para dos jugadores (debe estar implementada)
            dosJugadores(mp,mj,mr);
            break;

        case '3':
            // Llama a la funci�n para el mayor puntaje (debe estar implementada)
            mayorPuntuacion( mp,mj,mr);
            break;

        case '4':
            system("pause");
            // Sale del programa
            return 0;

        default:
            // Mensaje para opciones inv�lidas

            cout << "Opcion invalida. Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

