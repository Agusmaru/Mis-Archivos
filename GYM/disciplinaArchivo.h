#ifndef DISCIPLINAARCHIVO_H_INCLUDED
#define DISCIPLINAARCHIVO_H_INCLUDED

#include "Disciplina.h"
#include <iostream>
#include <cstdio>

using namespace std;

class ArchivoDisciplina
{
private:
    char nombre[30];

public:
    ArchivoDisciplina(const char* n)
    {
        strcpy(nombre, n);
    }

    Disciplina leerRegistro(int pos)
    {
        Disciplina reg;
        FILE* p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return reg;
        }

        fseek(p, pos * sizeof(Disciplina), 0);
        fread(&reg, sizeof(Disciplina), 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros()
    {
        FILE* p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }

        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Disciplina);
        fclose(p);
        return cant;
    }

    bool grabarRegistro(const Disciplina& reg)
    {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL)
            return false;
        int escribio = fwrite(&reg, sizeof(Disciplina), 1, p);
        fclose(p);
        return escribio;
    }

    bool limpiarArchivo()
    {
        FILE* p;
        p = fopen(nombre, "wb"); // Abrir archivo en modo escritura binaria truncada
        if (p == NULL)
        {
            return false;
        }
        fclose(p);
        return true;
    }
    bool modificarRegistro(Disciplina obj, int pos)
    {
        FILE *p;
        p = fopen(nombre, "rb+");
        if (p == NULL)
            return false;
        fseek(p, pos * sizeof(obj), 0);
        bool escribio = fwrite(&obj, sizeof(obj), 1, p);
        fclose(p);
        return escribio;
    }
};

#endif // DISCIPLINAARCHIVO_H_INCLUDED

