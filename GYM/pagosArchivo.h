#ifndef PAGOSARCHIVO_H_INCLUDED
#define PAGOSARCHIVO_H_INCLUDED

#include "Pagos.h"
#include <iostream>
#include <cstdio>

using namespace std;

class PagosArchivo
{
private:
    char nombre[30];

public:
    PagosArchivo(const char* n)
    {
        strcpy(nombre, n);
    }

    Pagos leerRegistro(int pos)
    {
        Pagos reg;
        FILE* p = fopen(nombre, "rb");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return reg;
        }

        fseek(p, pos * sizeof(Pagos), 0);
        fread(&reg, sizeof(Pagos), 1, p);
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
        return tam / sizeof(Pagos);
    }

    bool grabarRegistro(const Pagos& reg)
    {
        FILE* p = fopen(nombre, "ab");
        if (p == NULL)
        {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }

        int escribio = fwrite(&reg, sizeof(Pagos), 1, p);
        fclose(p);
        return escribio;
    }

    bool modificarRegistro(Pagos obj, int pos)
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
        Pagos obj;
        p = fopen(nombre, "rb");
        int pos = 0;
        if (p == NULL)
            return -1;
        while (fread(&obj, sizeof(obj), 1, p) == 1)
        {
            if (obj.getId() == num)
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

#endif // PAGOSARCHIVO_H_INCLUDED

