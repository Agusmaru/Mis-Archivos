#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

#include <cstring>
#include <string>
#include <iostream>
#include "Cliente.h"
#include "Fecha.h"

using namespace std;
class Pagos
{
private:
    int _id;
    Cliente _cliente;
    float _monto;
    Fecha _fechaP;

public:
    /// Constructor por defecto
    Pagos() {};

    /// Constructor con parametros
    Pagos(int id, Cliente cliente, float monto, Fecha fecha)
    {
        _id=id;
        _monto=monto;
        _cliente=cliente;
        _fechaP=fecha;
    };

    /// Getter y Setter para id
    int getId()
    {
        return _id;
    };
    void setId(int id)
    {
        _id = id;
    };

    /// Getter y Setter para CLIENTE
    Cliente getCliente()
    {
        return _cliente;
    };
    void setCliente(Cliente cliente)
    {
        _cliente=cliente;
    };

    /// Getter y Setter para MONTO
    float getMonto()
    {
        return _monto;
    };
    void setMonto(float monto)
    {
        _monto=monto;
    };

    /// Getter y Setter para FECHA
    Fecha getFecha()
    {
        return _fechaP;
    };
    void setFecha(Fecha fecha)
    {
        _fechaP=fecha;
    };

    ///FUNCION MOSTRAR
    void mostrar()
    {
        cout<<"ID: "<<_id<<endl;
        cout<< "Cliente: ";
        _cliente.mostrar();
        cout<<"Monto: "<<_monto<<endl;
        cout<<"Fecha: ";
        _fechaP.mostrar();
    }
};

#endif // PAGOS_H_INCLUDED
