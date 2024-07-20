#ifndef ASISTENCIA_H_INCLUDED
#define ASISTENCIA_H_INCLUDED
#include "Persona.h"
#include "Cliente.h"
#include "Fecha.h"
#include <string>
#include <iostream>
#include <cstring>

using std::string;
using namespace std;

class Asistencia
{
private:
    int id;
    Cliente _cliente;
    Fecha fecha;

public:
    // Constructor por defecto
    Asistencia() {};

    // Constructor con parametros
    Asistencia(int _id, Cliente cliente, Fecha _fecha)
    {
        setId(_id);
        _cliente=cliente;
        setFecha(_fecha);
    };

    // SETTER Y GETTER DE ID
    void setId(int _id)
    {
        id = _id;
    };
    int getId() const
    {
        return id;
    };

    // SETTER Y GETTER DE CLIENTE
    void setCliente(Cliente cliente)
    {
        _cliente = cliente;
    };
    Cliente getCliente() const
    {
        return _cliente;
    };

    // SETTER Y GETTER DE FECHA
    void setFecha(Fecha _fecha)
    {
        fecha = _fecha;
    };
    Fecha getFecha() const
    {
        return fecha;
    };

    void mostrar()
    {

        cout<<"ID: "<<id<<" | ";
        string nombre=_cliente.getPersona().getNombre();
        cout<<nombre<<" | ";
        string apellido=_cliente.getPersona().getApellido();
        cout<<apellido<<" | ";
        fecha.mostrar();
        cout<<" | ";
        string actividad=_cliente.getDisciplina().getNombre();
        cout<<actividad<<" | "<<endl;

    };
};

#endif // ASISTENCIA_H_INCLUDED
