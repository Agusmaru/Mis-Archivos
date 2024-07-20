#include <iostream>
#include <fstream>
#include "Persona.h"
#include "personaArchivo.h"
#include "disciplinaArchivo.h"
#include "Cliente.h"
#include "Disciplina.h"
#include "menu.cpp"
#include "Fecha.h"
#include "identidad.h"
#include "identidadArchivo.h"


using namespace std;

void restarCreditosFechaLimite(int diaLimite, int &mesLimite, int anioLimite)
{
    ArchivoCliente archi("Personas.dat");
    Cliente obj;
    int reg = archi.contarRegistros();

    // Obtener la fecha actual
    time_t now = time(0);
    tm *localTime = localtime(&now);
    int diaActual = localTime->tm_mday;
    int mesActual = localTime->tm_mon + 1;   // tm_mon va de 0 a 11
    int anioActual = localTime->tm_year + 1900; // tm_year cuenta los a�os desde 1900

    // Comparar con la fecha limite
    if (anioActual > anioLimite ||
            (anioActual == anioLimite && mesActual > mesLimite) ||
            (anioActual == anioLimite && mesActual == mesLimite && diaActual >= diaLimite))
    {
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);

            // Restar credito si el usuario tiene creditos disponibles
            int creditos = obj.getCreditos();
            if (creditos > 0)
            {
                obj.setCreditos(creditos - 1);
                archi.modificarRegistro(obj, i);
                cout << "Se ha restado 1 credito a: ";
                obj.mostrar();  // Mostrar informacion del usuario
            }
        }

        // Actualizar mes limite al siguiente mes
        if (mesLimite == 12)
        {
            mesLimite = 1;  // Si es diciembre, el siguiente mes es enero del siguiente anio
            anioLimite++;
        }
        else
        {
            mesLimite++;
        }

        // Guardar el nuevo mes limite en el archivo
        ofstream archivoSalida("mesLimite.txt");
        if (archivoSalida.is_open())
        {
            archivoSalida << mesLimite << endl;
            archivoSalida << anioLimite << endl;
            archivoSalida.close();
        }
        else
        {
            cout << "Error al guardar el mes limite." << endl;
        }

        cout << "Se han restado los creditos correspondientes." << endl;
        system("pause");
    }
    else
    {
        cout << "Aun no ha llegado la fecha limite para restar los creditos." << endl;
        system("pause");
    }
}



int main()
{
    int diaLimite = 28;
    int mesLimite;
    int anioLimite;

    system("pause");

    ifstream archivoMesLimite("mesLimite.txt");
    if (archivoMesLimite.is_open())
    {
        archivoMesLimite >> mesLimite;
        archivoMesLimite >> anioLimite;
        archivoMesLimite.close();
    }
    else
    {
        mesLimite = 6;
        anioLimite = 2024;  // Fecha limite para la resta de creditos
    }

    restarCreditosFechaLimite(diaLimite, mesLimite, anioLimite);
    system("cls");
    Menu menu;  // Descomentar si tienes definida la clase Menu
    menu.display();

    return 0;
}

