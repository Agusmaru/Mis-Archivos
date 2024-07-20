#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
#include <iostream>
#include "Fecha.h"
#include <cstring>

using std::string;
using namespace std;

class Persona
{
private:
    int _id;
    char _nombre[30];
    char _apellido[30];
    Fecha _nacimiento;
    int _dni;
    char _genero;
public:
    Persona()
        : _nacimiento(1, 1, 1)
    {
        _id = 0;
        strcpy(_nombre, "");
        strcpy(_apellido, "");
        _dni = 0;
        _genero = ' ';
    }

    Persona(int id, std::string nombre, std::string apellido, Fecha nacimiento, int dni, char genero)
        : _nacimiento(1, 1, 1)
    {
        setID(id);
        setNombre(nombre);
        setApellido(apellido);
        setNacimiento(nacimiento);
        setDni(dni);
        setGenero(genero);
    }

    // SETTER Y GETTER DE ID
    int getID()
    {
        return _id;
    }

    void setID(int id)
    {
        _id = id;
    };

    // SETTER Y GETTER DE NOMBRE
    std::string getNombre()
    {
        return _nombre;
    }
    void setNombre(std::string nombre)
    {
        if (nombre.size() <= 30)
        {
            strcpy(_nombre, nombre.c_str());
        }
        else
        {
            strcpy(_nombre, "SIN DATOS");
        }
    };


    // SETTER Y GETTER DE APELLIDO
    std::string getApellido()
    {
        return _apellido;
    };
    void setApellido(std::string apellido)
    {
        if (apellido.size() <= 30)
        {
            strcpy(_apellido, apellido.c_str());
        }
        else
        {
            strcpy(_apellido, "SIN DATOS");
        }
    };


    // SETTER Y GETTER DE NACIMIENTO
    Fecha getNacimiento()
    {
        return _nacimiento;
    };
    void setNacimiento(Fecha nacimiento)
    {
        _nacimiento = nacimiento;
    };

    // SETTER Y GETTER DE DNI
    int getDni()
    {
        return _dni;
    };
    void setDni(int dni)
    {
        _dni = dni;
    };

    // SETTER Y GETTER DE GENERO
    char getGenero()
    {
        return _genero;
    };
    void setGenero(char genero)
    {
        _genero = genero;
    };

    void mostrar()
    {
        cout << "ID: " << getID()<<" | ";
        cout<<"Nombre: "<< getNombre();
        cout << " | ";
        cout<< "Apellido: " << getApellido();
        cout << " | ";
        cout<< "Nacimiento: ";
        _nacimiento.mostrar();
        cout << " | ";
        cout<< "DNI: " << getDni()<< " | ";
        cout<< "Genero: " << getGenero() << " | ";
    }


};
#endif // PERSONA_H_INCLUDED
