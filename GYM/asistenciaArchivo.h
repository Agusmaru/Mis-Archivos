#ifndef ASISTENCIAARCHIVO_H_INCLUDED
#define ASISTENCIAARCHIVO_H_INCLUDED

#include "Asistencia.h"
#include <iostream>
#include <cstdio>

using namespace std;

class AsistenciaArchivo
{
private:
    char nombre[30];

public:
    AsistenciaArchivo(const char* n)
    {
        strcpy(nombre, n);
    }

    Asistencia leerRegistro(int pos)
    {
        Asistencia reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return reg;
        }

        fseek(p, sizeof(Asistencia) * pos, 0);
        fread(&reg, sizeof(Asistencia), 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros()
    {
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return -1;
        }

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Asistencia);
    }

    bool grabarRegistro(const Asistencia& reg)
    {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }

        int escribio = fwrite(&reg, sizeof(Asistencia), 1, p);
        fclose(p);
        return escribio;
    }

    bool limpiarArchivo()
    {
        FILE* p;
        p = fopen(nombre, "w"); // Abrir archivo en modo escritura binaria truncada
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo para limpiar." << endl;
            return false;
        }
        fclose(p);
        return true;
    }
};

#endif // ASISTENCIAARCHIVO_H_INCLUDED
