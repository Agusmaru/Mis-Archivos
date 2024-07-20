#ifndef IDENTIDADARCHIVO_H_INCLUDED
#define IDENTIDADARCHIVO_H_INCLUDED

#include "Identidad.h"
#include <iostream>
#include <cstdio>

using namespace std;

class IdentidadArchivo
{
private:
    char nombre[30];

public:
    IdentidadArchivo(const char* n)
    {
        strcpy(nombre, n);
    }

    Identidad leerRegistro(int pos)
    {
        Identidad reg;
        FILE* p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return reg;
        }

        fseek(p, pos * sizeof(Identidad), 0);
        fread(&reg, sizeof(Identidad), 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros()
    {
        FILE* p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return -1;
        }

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Identidad);
    }

    bool grabarRegistro(const Identidad& reg)
    {
        FILE* p = fopen(nombre, "ab");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }

        int escribio = fwrite(&reg, sizeof(Identidad), 1, p);
        fclose(p);
        return escribio;
    }

    bool modificarRegistro(Identidad obj, int pos)
    {
        FILE* p = fopen(nombre, "rb+");
        if (p == NULL)
            return false;
        fseek(p, pos * sizeof(obj), 0);
        bool escribio = fwrite(&obj, sizeof(obj), 1, p);
        fclose(p);
        return escribio;
    }

    int buscarRegistro(int num)
    {
        FILE* p;
        Identidad obj;
        p = fopen(nombre, "rb");
        int pos = 0;
        if (p == NULL)
            return -1;
        while (fread(&obj, sizeof(obj), 1, p) == 1)
        {
            if (obj.getIdPersona() == num)
            {
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -2;
    }

    bool limpiarArchivo()
    {
        FILE* p = fopen(nombre, "w"); // Abrir archivo en modo escritura binaria truncada
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo para limpiar." << endl;
            return false;
        }
        fclose(p);
        return true;
    }
};

#endif // IDENTIDADARCHIVO_H_INCLUDED
