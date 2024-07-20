#ifndef DISCIPLINA_H_INCLUDED
#define DISCIPLINA_H_INCLUDED
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Disciplina
{
private:
    int _id;
    char _nombre[30];
    float _precio;

public:
    // Constructor por defecto
    Disciplina()
    {
        _id=0;
        _precio=0.0;
        std::strcpy(_nombre, "");
    };

    // Constructor con parametros
    Disciplina(int id, const char *nombre, float precio)
    {
        _id=id;
        _precio=precio;
        std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0'; // Asegurar la terminacion nula
    };

    // Getter y Setter para id
    int getId()
    {
        return _id;
    };
    void setId(int id)
    {
        _id = id;
    };

    // Getter y Setter para nombre
    std::string getNombre()
    {
        return _nombre;
    }
    void setNombre(const char *nombre)
    {
        std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0'; // Asegurar la terminacion nula
    };

    // Getter y Setter para precio
    float getPrecio()
    {
        return _precio;
    };
    void setPrecio(float precio)
    {
        _precio = precio;
    };

    //FUNCION MOSTRAR
    void mostrar() const
    {
        cout<<"ID: "<<_id <<" | ";
        cout<< "Nombre: "<<_nombre;
        cout<<" | ";
        cout<< "Precio: "<<_precio;
        cout<<" | ";
    }
};

#endif // DISCIPLINA_H_INCLUDED
