#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Persona.h"
#include "Fecha.h"
#include "Disciplina.h" // Suponiendo que tienes una clase Disciplina definida en este archivo
class Cliente
{
private:
    Persona _persona;
    bool _estado;
    Disciplina _disciplina;
    Fecha _ingreso;
    int _creditos;

public:
    Cliente() {}; // Inicializacion por defecto
    Cliente(Persona persona, bool estado, Disciplina disciplina, Fecha ingreso, int creditos)
    {
        _persona=persona;
        _estado=estado;
        _disciplina=disciplina;
        _ingreso=ingreso;
        _creditos=creditos;
    };

    // SETTER Y GETTER DE PERSONA
    Persona getPersona() const
    {
        return _persona;
    };
    void setPersona(const Persona &persona)
    {
        _persona = persona;
    };

    // SETTER Y GETTER DE ESTADO
    bool getEstado() const
    {
        return _estado;
    };
    void setEstado(bool estado)
    {
        _estado = estado;
    };

    // SETTER Y GETTER DE DISCIPLINA
    Disciplina getDisciplina() const
    {
        return _disciplina;
    };
    void setDisciplina(const Disciplina &disciplina)
    {
        _disciplina = disciplina;
    };

    // SETTER Y GETTER DE INGRESO
    Fecha getIngreso() const
    {
        return _ingreso;
    };
    void setIngreso(const Fecha &ingreso)
    {
        _ingreso = ingreso;
    };

    // SETTER Y GETTER DE CREDITOS
    int getCreditos() const
    {
        return _creditos;
    };
    void setCreditos(int creditos)
    {
        _creditos=creditos;
    };

    void mostrar()
    {
        cout << "Persona:\n";
        _persona.mostrar() ;
        cout << "Estado: " <<getEstado() <<" | ";
        cout <<endl;
        cout <<endl;
        cout<<"Disciplina:\n";
        _disciplina.mostrar();
        cout <<"Fecha de ingreso: ";
        _ingreso.mostrar();
        cout<<" | ";
        cout<< "Creditos: " <<getCreditos()<<endl;
    }
    void mostrarRank()
    {
        cout << "Persona:\n";
        _persona.mostrar() ;
        cout <<endl;
    }
};

#endif // CLIENTE_H_INCLUDED
