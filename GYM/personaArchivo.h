#ifndef PERSONAARCHIVO_H_INCLUDED
#define PERSONAARCHIVO_H_INCLUDED

#include "Cliente.h"
#include <cstdio>
#include <cstring>

class ArchivoCliente
{
private:
    char nombre[30];

public:
    ArchivoCliente(const char *n)
    {
        strcpy(nombre, n);
    }

    // Metodos para operaciones basicas con el archivo
    Cliente leerRegistro(int pos)
    {
        Cliente reg;
        FILE *p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return reg;
        }
        fseek(p, pos * sizeof(reg), 0);
        fread(&reg, sizeof(reg), 1, p);
        fclose(p);
        return reg;
    }

    int contarRegistros()
    {
        FILE *p = fopen(nombre, "rb");
        if (p == NULL)
        {
            return -1;
        }
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(Cliente);
        fclose(p);
        return cant;
    }

    bool grabarRegistro(Cliente reg)
    {
        FILE *p;
        p = fopen(nombre, "ab");
        if (p == NULL)
            return false;
        int escribio = fwrite(&reg, sizeof(reg), 1, p);
        fclose(p);
        return escribio;
    }

    bool modificarRegistro(Cliente obj, int pos)
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

    int buscarRegistro(int num)
    {
        FILE *p;
        Cliente obj;
        p = fopen(nombre, "rb");
        int pos = 0;
        if (p == NULL)
            return -1;
        while (fread(&obj, sizeof(obj), 1, p) == 1)
        {
            if (obj.getPersona().getID() == num)
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
        FILE *p;
        p = fopen(nombre, "w"); // Abrir archivo en modo escritura binaria truncada
        if (p == NULL)
        {
            return false;
        }
        fclose(p);
        return true;
    }

    // Nueva funcion para eliminar un registro por ID
    bool eliminarRegistroPorID(int id)
    {
        FILE *p;
        FILE *temp;
        Cliente obj;
        bool eliminado = false;

        p = fopen(nombre, "rb");
        if (p == NULL)
            return false;

        temp = fopen("temp.dat", "wb"); // Archivo temporal para escribir los registros sin el eliminado
        if (temp == NULL)
        {
            fclose(p);
            return false;
        }

        while (fread(&obj, sizeof(obj), 1, p) == 1)
        {
            if (obj.getPersona().getID() != id)
            {
                fwrite(&obj, sizeof(obj), 1, temp); // Escribir en el archivo temporal si no es el registro a eliminar
            }
            else
            {
                eliminado = true; // Marcar como eliminado si se encontro y elimino el registro
            }
        }

        fclose(p);
        fclose(temp);

        // Eliminar el archivo original y renombrar el temporal
        remove(nombre);
        rename("temp.dat", nombre);

        return eliminado;
    }
};

#endif // PERSONAARCHIVO_H_INCLUDED

