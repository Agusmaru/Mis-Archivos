#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define UN_JUGADOR_H_INCLUDED
#include "rlutil.h"
using namespace std;



int mostrarDados(int dado[])
{
    rlutil::setColor(rlutil::MAGENTA);
    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 2)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 3)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 4)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 5)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 6)
        {
            cout << " -------   ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "| *     |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "| *     |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "|     * |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "|     * |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 2)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 3)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 4)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 5)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 6)
        {
            cout << " -------   ";
        }
    }
    rlutil::setColor(rlutil::WHITE);
}


int mayorPuntuacion (int mp, string mj,int mr)
{
    if (mr == 0)
    {

        system("cls");
        rlutil::setColor(rlutil::RED);
        rlutil::locate(44,3);
        cout<<"-----------------------------------------";
        rlutil::locate(44,5);
        cout<<"Aun no se ha registrado ningun puntaje"<<endl;
        rlutil::locate(44,7);
        cout<<"-----------------------------------------";
        cout<<endl;
        rlutil::locate(44,8);
        rlutil::setColor(rlutil::WHITE);
        system("pause");

    }
    else
    {
        system("cls");
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(44,3);
        cout<<"-----------------------------------------";
        rlutil::locate(44,5);
        cout << "El Jugador con menos rondas registrado es: "<<mj<< endl;
        rlutil::locate(44,6);
        cout << "con "<<mr<<" rondas "<<" y un puntaje de "<<mp<<  endl;
        rlutil::locate(44,7);
        cout<<"-----------------------------------------";
        cout<<endl;
        rlutil::locate(44,9);
        rlutil::setColor(rlutil::WHITE);
        system("pause");


    }
}


// Función principal del juego para un solo jugador
int unJugador(int& mp, string& mj,int&mr)
{
    int dado[6], puntuacion = 0, rondas =0, comparaPuntuaciones[3], puntuacionJugador1 = 0;
    int c,p,x,i,limiterondas, Max = 0, banderaV = 0, contadorTrio = 0, Max1 = 0, Max2 = 0, puntuacionFinal = 0, bandera6 = 0;
    string jugador1;
    rlutil::setColor(rlutil::YELLOW);
    cout << "Ingrese nombre de jugador:" << endl;
    cin >> jugador1;

    cout<<" limite de rondas "<<endl;
    cin>>limiterondas;
    rlutil::setColor(rlutil::WHITE);
    // Bucle principal del juego
    while (puntuacionFinal <= 500 && rondas<limiterondas )
    {
rondas++;
        Max1 = 0, Max2 = 0, Max = 0;
        banderaV = 0, bandera6 = 0;
        int contadorEscalera = 0;
        system("cls");
        rlutil::setColor(rlutil::GREEN);
        cout<<" ronda "<<rondas<<" jugador "<<jugador1<<endl;
        rlutil::setColor(rlutil::WHITE);
        // Bucle para realizar 3 rondas por jugador

        for (int x = 0; x < 3; x++ )
        {
            puntuacion = 0;
            banderaV = 0;
            contadorEscalera = 0;

            // Inicialización del arreglo comparaPuntuaciones
            if(x==0)
            {
                for (int i = 0; i < 3; i++)
                {
                    comparaPuntuaciones[i] = 0;

                }

            }

            // Generación de valores aleatorios para los dados
            srand(time(NULL));
            for (int c = 0; c < 6; c++)
            {
                dado[c] = 1 + rand() % 6;
                //cin>>dado[c];
                if (dado[c] == c + 1)
                {
                    contadorEscalera++;
                }
            }
// Pausa para mostrar la puntuación antes de la siguiente ronda
            system("pause");

            // Llamada a la función para mostrar los valores de los dados
            cout<<endl<<" Lanzamiento N "<<x+1<<endl;
            mostrarDados(dado);

            // Comprobación de si todos los dados son iguales
            if (contadorEscalera == 6)
            {
                rlutil::setColor(rlutil::YELLOW);
                system("cls");
                rlutil::locate(55,5);
                cout<<"Escalera, ganaste la partida!" <<endl;
                rlutil::setColor(rlutil::WHITE);
                puntuacionFinal = 501;
                break;
            }

            bool sonIguales = true;
            for (int i = 0; i < 6; i++)
            {
                if (dado[i] != dado[0])
                {
                    sonIguales = false;
                }
            }

            // Manejo de la situación cuando todos los dados son iguales
            if (sonIguales == true)
            {
                banderaV = 1;
                if (dado[0] == 6)
                {
                    rlutil::setColor(rlutil::LIGHTBLUE);
                    cout<<endl;
                    cout<<"-----------------------------------------"<<endl;
                    cout <<endl<< "Sexteto! la puntuación vuelve a cero" << endl;
                    cout<<"-----------------------------------------"<<endl;
                    rlutil::setColor(rlutil::WHITE);
                    bandera6=1;
                    puntuacion=0;

                    break;
                }
                else
                {
                    rlutil::setColor(rlutil::BROWN);
                    cout<<endl;
                    cout<<"-----------------------------------------"<<endl;
                    cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                    puntuacion += dado[0] * 50;
                    cout<<"La puntuacion actual es: "<<puntuacion<<endl;
                    cout<<"-----------------------------------------";
                    rlutil::setColor(rlutil::WHITE);




                }
            }

            // Manejo de la situación cuando no todos los dados son iguales
            Max1 = 0;
            Max2 = 0;
            if (sonIguales == false)
            {
                // Comprobación de tríos
                for (int N = 0; N < 6; N++)
                {
                    contadorTrio = 0;
                    for (int D = 0; D < 6; D++)
                    {
                        if (dado[D] == dado[N])
                        {
                            contadorTrio++;
                        }
                        if (contadorTrio == 3)
                        {
                            banderaV = 1;
                            if (Max1 == 0)
                            {
                                Max1 = dado[D];
                                contadorTrio = 0;
                            }
                            else
                            {
                                Max2 = dado[D];
                                contadorTrio = 0;
                            }
                            if (Max2 > Max1)
                            {
                                Max1 = Max2;
                            }
                        }
                    }
                }
                // Manejo de la situación cuando se obtiene un trío
                if (Max1 != 0)
                {
                    rlutil::setColor(rlutil::RED);
                    cout<<endl;
                    cout<<"-----------------------------------------"<<endl;
                    cout<<"Salio un -TRIOX++- GENIAL"<<endl;
                    cout<<"-----------------------------------------";
                    rlutil::setColor(rlutil::WHITE);
                    puntuacion += Max1 * 10;
                }

                // Manejo de la situación cuando no se obtiene un trío
                if (banderaV == 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        puntuacion += dado[i];
                    }
                }
            }

            // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
            comparaPuntuaciones[x] = puntuacion;
            cout <<endl<< " Puntuacion " << puntuacion  << endl;



            // Determinación de la puntuación máxima de la ronda
            for (int y = 0; y < 3; y++)
            {
                if (comparaPuntuaciones[y] > Max && bandera6 != 1)
                {
                    Max = comparaPuntuaciones[y];
                }
            }
            puntuacionJugador1 = Max;
        }


        // Mostrar la puntuación de la ronda
        cout << "Puntuacion de la ronda: " << puntuacionJugador1 << endl;
        system("pause");
        system("cls");


        // Actualización de la puntuación total y visualización
        puntuacionFinal += Max;
        if(bandera6==1)
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<<endl<<"Recorda que sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
            rlutil::setColor(rlutil::WHITE);
            puntuacionJugador1=0;
            puntuacionFinal=0;
        }
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(44,3);
        cout<<"-----------------------------------------";
        rlutil::locate(44,5);
        cout << "La puntuacion Total es: " << puntuacionFinal << " Ronda: " << rondas << endl;
        rlutil::locate(44,7);
        cout<<"-----------------------------------------";
        cout<<endl;
        rlutil::locate(44,8);
        rlutil::setColor(rlutil::WHITE);
        system("pause");



    }//W22
    // Actualización de la máxima puntuación y el nombre del jugador
    if ( mr==0)
    {

        mr=rondas;
        mp = puntuacionFinal;

        mj = jugador1;

    }
    else
    {
        if (rondas<mr)
        {
            mr=rondas;
            mp = puntuacionFinal;
            mj = jugador1;
        }
    }

    system("cls");
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(44,3);
    cout<<"-----------------------------------------";
    rlutil::locate(44,5);
    cout << "El ganador es: " << jugador1 << " le tomo: " << rondas << " rondas ganar" << endl;
    rlutil::locate(44,7);
    cout<<"-----------------------------------------";
    cout<<endl;
    rlutil::locate(44,8);
    system("pause");
    rlutil::setColor(rlutil::WHITE);
    system("cls");

    // Finalización del juego y retorno de 0
    return 0;
}

int dosJugadores(int& mp, string& mj,int& mr)
{
    int dado[6], puntuacionJugador1 = 0, puntuacionJugador2 = 0, puntuacion = 0, rondas = 1, comparaPuntuaciones[3];
    int Max = 0, banderaV = 0, contadorTrio = 0, Max1 = 0, Max2 = 0, puntuacionFinalJugador1 = 0, puntuacionFinalJugador2 = 0, contador = 0, bandera6 = 0;
    string jugador1, jugador2;
    bool bandera = true;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "Ingrese nombre del jugador 1: " << endl;
    cin >> jugador1;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "Ingrese nombre del jugador 2: " << endl;
    cin >> jugador2;
    system("pause");
    rlutil::setColor(rlutil::WHITE);
    system("cls");

    // Bucle principal del juego

    while (puntuacionFinalJugador1 <= 500 && puntuacionFinalJugador2 <= 500)
    {
        Max1 = 0, Max2 = 0, Max = 0;
        banderaV = 0;
        bool banderaEscalera = false;

        if (contador != 0)
        {

            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(44,3);
            cout<<"-----------------------------------------";
            rlutil::locate(44,5);
            cout << "La puntuacion Total de " <<jugador1 <<" es: " << puntuacionFinalJugador1 << " Ronda: " << rondas << endl;
            rlutil::locate(44,7);
            cout << "La puntuacion Total de " <<jugador2 <<" es: "<< puntuacionFinalJugador2 << " Ronda: " << rondas << endl;
            rlutil::locate(44,9);
            cout<<"-----------------------------------------";
            cout<<endl;
            rlutil::locate(44,11);
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
        }
        contador++;
        if (bandera == true)
        {

            rlutil::setColor(rlutil::CYAN);
            rlutil::locate(44,3);
            cout<<"-----------------------------------------";
            rlutil::locate(44,5);
            cout << "Es el turno de " <<jugador1 <<" Puntaje total  " << puntuacionFinalJugador1 << " Ronda: " << rondas << endl;
            rlutil::locate(44,7);
            cout<<"-----------------------------------------";
            cout<<endl;
            rlutil::locate(44,9);
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");

            cout << "Es el turno de " <<jugador1 <<" Puntaje total  " << puntuacionFinalJugador1 << " Ronda: " << rondas << endl;
            // Bucle para realizar 3 rondas por jugador
            for (int x = 0; x < 3; x++ )
            {
                puntuacion = 0;
                banderaV = 0;
                Max1 = 0;
                Max2 = 0;
                int contadorEscalera = 0;


                // Inicialización del arreglo comparaPuntuaciones
                if(x==0)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        comparaPuntuaciones[i] = 0;
                    }
                }

                // Generación de valores aleatorios para los dados
                srand(time(NULL));
                for (int c = 0; c < 6; c++)
                {
                    dado[c] = 1 + rand() % 6;
                    //cin>>dado[c];
                    if (dado[c] == c + 1)
                    {
                        contadorEscalera++;
                    }

                }

                if (contadorEscalera == 6)
                {


                    rlutil::setColor(rlutil::YELLOW);
                    system("cls");
                    rlutil::locate(55,5);
                    cout<<" Escalera, ganaste la partida "<<jugador1 <<"!" <<endl;
                    rlutil::setColor(rlutil::WHITE);
                    puntuacionFinalJugador1 = 501;
                    banderaEscalera = true;
                    rondas = rondas - 1;
                    break;
                }

                // Llamada a la función para mostrar los valores de los dados
                system("pause");
                cout<<endl<<"Lanzamiento N "<<x+1<<endl;
                mostrarDados(dado);

                // Comprobación de si todos los dados son iguales
                bool sonIguales = true;
                for (int i = 0; i < 6; i++)
                {
                    if (dado[i] != dado[0])
                    {
                        sonIguales = false;
                    }
                }

                // Manejo de la situación cuando todos los dados son iguales
                if (sonIguales == true)
                {
                    banderaV = 1;
                    if (dado[0] == 6)
                    {
                        rlutil::setColor(rlutil::LIGHTBLUE);
                        cout<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout <<endl<< "Sexteto! la puntuación vuelve a cero" << endl;
                        cout<<"-----------------------------------------"<<endl;
                        rlutil::setColor(rlutil::WHITE);

                        bandera6=1;
                        puntuacion=0;
                        break;
                    }
                    else
                    {
                        rlutil::setColor(rlutil::BROWN);
                        cout<<"-----------------------------------------"<<endl;
                        cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                        puntuacion += dado[0] * 50;
                        cout<<"La puntuacion actual es: "<<puntuacion<<endl;
                        cout<<"-----------------------------------------";
                        rlutil::setColor(rlutil::WHITE);

                    }
                }

                // Manejo de la situación cuando no todos los dados son iguales
                Max1 = 0;
                Max2 = 0;
                if (sonIguales == false)
                {
                    // Comprobación de tríos
                    for (int N = 0; N < 6; N++)
                    {
                        contadorTrio = 0;
                        for (int D = 0; D < 6; D++)
                        {
                            if (dado[D] == dado[N])
                            {
                                contadorTrio++;
                            }
                            if (contadorTrio == 3)
                            {
                                banderaV = 1;
                                if (Max1 == 0)
                                {
                                    Max1 = dado[D];
                                    contadorTrio = 0;
                                }
                                else
                                {
                                    Max2 = dado[D];
                                    contadorTrio = 0;
                                }
                                if (Max2 > Max1)
                                {
                                    Max1 = Max2;
                                }
                            }
                        }
                    }

                    // Manejo de la situación cuando se obtiene un trío
                    if (Max1 != 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"Salio un -TRIOX++- GENIAL"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        rlutil::setColor(rlutil::WHITE);
                        puntuacion += Max1 * 10;
                    }

                    // Manejo de la situación cuando no se obtiene un trío
                    if (banderaV == 0)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            puntuacion += dado[i];
                        }
                    }
                }
                // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
                comparaPuntuaciones[x] = puntuacion;
                cout <<endl<< " Puntuacion " << puntuacion  << endl;




                // Determinación de la puntuación máxima de la ronda
                for (int y = 0; y < 3; y++)
                {
                    if (comparaPuntuaciones[y] > Max && bandera6 != 1)
                    {
                        Max = comparaPuntuaciones[y];
                    }

                }
                puntuacionJugador1 = Max;
            }

            // Mostrar la puntuación de la ronda
            cout <<endl<< "Puntuacion de la ronda: " << puntuacionJugador1 << endl;
            system("pause");
            system("cls");

            // Actualización de la puntuación total y visualización
            puntuacionFinalJugador1 += Max;
            if(bandera6==1)
            {

                rlutil::setColor(rlutil::LIGHTCYAN);
                cout<<endl<<jugador1<<" sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
                puntuacionFinalJugador1=0;
                bandera6 = 0;
                rlutil::setColor(rlutil::WHITE);
                system("pause");
                system("cls");
            }
            bandera = !bandera;

        }

        if (bandera == false && banderaEscalera == false)
        {

            rlutil::setColor(rlutil::CYAN);
            rlutil::locate(44,3);
            cout<<"-----------------------------------------";
            rlutil::locate(44,5);
            cout << "Es el turno de " <<jugador2 <<" Puntaje total  " << puntuacionFinalJugador2 << " Ronda: " << rondas << endl;
            rlutil::locate(44,7);
            cout<<"-----------------------------------------";
            cout<<endl;
            rlutil::locate(44,9);
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");

            cout<<"Turno de: " <<jugador2 <<" Ronda " <<rondas <<" Puntaje total: " <<puntuacionFinalJugador2<<endl;
            puntuacion = 0;
            Max = 0;
            // Bucle para realizar 3 rondas por jugador
            for (int x = 0; x < 3; x++ )
            {
                puntuacion = 0;
                banderaV = 0;
                Max1 = 0;
                Max2 = 0;
                int contadorEscalera = 0;


                // Inicialización del arreglo comparaPuntuaciones
                if(x==0)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        comparaPuntuaciones[i] = 0;
                    }
                }

                // Generación de valores aleatorios para los dados
                srand(time(NULL));
                for (int c = 0; c < 6; c++)
                {
                    dado[c] = 1 + rand() % 6;
                    //cin>>dado[c];
                    if (dado[c] == c + 1)
                    {
                        contadorEscalera++;
                    }
                }

                // Llamada a la función para mostrar los valores de los dados
                system("pause");
                cout<<endl<<"Lanzamiento N "<<x+1<<endl;
                mostrarDados(dado);

                if (contadorEscalera == 6)
                {

                    rlutil::setColor(rlutil::YELLOW);
                    system("cls");
                    rlutil::locate(55,5);
                    cout<<" Escalera, ganaste la partida "<<jugador2 <<"!" <<endl;
                    rlutil::setColor(rlutil::WHITE);
                    puntuacionFinalJugador2 = 501;
                    rondas = rondas - 1;
                    break;
                }

                // Comprobación de si todos los dados son iguales
                bool sonIguales = true;
                for (int i = 0; i < 6; i++)
                {
                    if (dado[i] != dado[0])
                    {
                        sonIguales = false;
                    }
                }

                // Manejo de la situación cuando todos los dados son iguales
                if (sonIguales == true)
                {
                    banderaV = 1;
                    if (dado[0] == 6)
                    {
                        rlutil::setColor(rlutil::LIGHTBLUE);
                        cout<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout <<endl<< "Sexteto! la puntuación vuelve a cero" << endl;
                        cout<<"-----------------------------------------"<<endl;
                        rlutil::setColor(rlutil::WHITE);
                        bandera6=1;
                        puntuacion=0;
                        break;
                    }
                    else
                    {
                        rlutil::setColor(rlutil::BROWN);
                        cout<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                        puntuacion += dado[0] * 50;
                        cout<<"La puntuacion actual es: "<<puntuacion<<endl;
                        cout<<"-----------------------------------------";
                        rlutil::setColor(rlutil::WHITE);
                    }
                }

                // Manejo de la situación cuando no todos los dados son iguales
                Max1 = 0;
                Max2 = 0;
                if (sonIguales == false)
                {
                    // Comprobación de tríos
                    for (int N = 0; N < 6; N++)
                    {
                        contadorTrio = 0;
                        for (int D = 0; D < 6; D++)
                        {
                            if (dado[D] == dado[N])
                            {
                                contadorTrio++;
                            }
                            if (contadorTrio == 3)
                            {
                                banderaV = 1;
                                if (Max1 == 0)
                                {
                                    Max1 = dado[D];
                                    contadorTrio = 0;
                                }
                                else
                                {
                                    Max2 = dado[D];
                                    contadorTrio = 0;
                                }
                                if (Max2 > Max1)
                                {
                                    Max1 = Max2;
                                }
                            }
                        }
                    }

                    // Manejo de la situación cuando se obtiene un trío
                    if (Max1 != 0)
                    {

                        rlutil::setColor(rlutil::LIGHTRED);
                        cout<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"Salio un -TRIOX++- GENIAL"<<endl;
                        cout<<"-----------------------------------------";
                        rlutil::setColor(rlutil::WHITE);
                        puntuacion += Max1 * 10;
                    }

                    // Manejo de la situación cuando no se obtiene un trío
                    if (banderaV == 0)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            puntuacion += dado[i];
                        }
                    }
                }
                // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
                comparaPuntuaciones[x] = puntuacion;
                cout <<endl<< " Puntuacion " << puntuacion  << endl;


                // Determinación de la puntuación máxima de la ronda
                for (int y = 0; y < 3; y++)
                {
                    if (comparaPuntuaciones[y] > Max)
                    {
                        Max = comparaPuntuaciones[y];
                    }

                }
                puntuacionJugador2 = Max;
            }

            // Mostrar la puntuación de la ronda
            cout <<endl<< "Puntuacion de la ronda: " << puntuacionJugador2 << endl;
            system("pause");
            system("cls");

            // Actualización de la puntuación total y visualización
            puntuacionFinalJugador2 += Max;
            if(bandera6==1)
            {
                rlutil::setColor(rlutil::LIGHTBLUE);
                cout<<endl<<jugador2<<" sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
                puntuacionFinalJugador2=0;
                rlutil::setColor(rlutil::WHITE);
                bandera6 = 0;
                system("pause");
                system("cls");
            }
            bandera = !bandera;

        }
        rondas++;




    }

    if (puntuacionFinalJugador1 > puntuacionFinalJugador2)
    {
        if(mr==0)
        {
            mp = puntuacionFinalJugador1;
            mj = jugador1;
            mr=rondas;
        }


        else
        {
            if (rondas<mr)
            {
                mp = puntuacionFinalJugador1;
                mj = jugador1;
                mr=rondas;
            }
        }


        system("cls");
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(44,3);
        cout<<"-----------------------------------------";
        rlutil::locate(48,5);
        cout<<"VICTORIA USTED GANO "<<jugador1<<endl;
        rlutil::locate(48,6);
        cout<<" con "<<puntuacionFinalJugador1<<" puntos "<<" y "<<mr<<" rondas"<<endl;
        rlutil::locate(44,7);
        cout<<"-----------------------------------------";
        cout<<endl;
        rlutil::locate(44,8);
        system("pause");
        rlutil::setColor(rlutil::WHITE);
        system("cls");





    }
    else
    {
        if(mr==0)
        {
            mp = puntuacionFinalJugador2;
            mj = jugador2;
            mr=rondas;
        }
        else
        {
            if (rondas<mr)
            {
                mp = puntuacionFinalJugador2;
                mj = jugador2;
                mr=rondas;
            }
        }
        system("cls");
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(44,3);
        cout<<"-----------------------------------------";
        rlutil::locate(48,5);
        cout<<"VICTORIA USTED GANO "<<jugador2<<endl;
        rlutil::locate(48,6);
        cout<<" con "<<puntuacionFinalJugador2<<" puntos "<<" y "<<mr<<" rondas"<<endl;
        rlutil::locate(44,7);
        cout<<"-----------------------------------------";
        cout<<endl;
        rlutil::locate(44,8);
        system("pause");
        rlutil::setColor(rlutil::WHITE);
        system("cls");

    }


}
