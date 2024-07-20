#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>
#include <iostream>
using std::string;
using namespace std;

class Fecha
{
private:
    int _dia, _mes, _anio;

public:
    Fecha()
    {
        _dia = 1;
        _mes = 1;
        _anio = 1;
    };
    Fecha(int dia, int mes, int anio)
    {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    };
    int getDia()
    {
        return _dia;
    };
    int getMes()
    {
        return _mes;
    };
    int getAnio()
    {
        return _anio;
    };
    void setDia(int dia)
    {
        _dia = dia;
    };
    void setMes(int mes)
    {
        _mes = mes;
    };
    void setAnio(int anio)
    {
        _anio = anio;
    };
    std::string toString()
    {
        return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    };
    void mostrar()
    {
        cout<<_dia<<"/";
        cout<<_mes<<"/";
        cout<<_anio;
    }
};

#endif // FECHA_H_INCLUDED
