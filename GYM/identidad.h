#ifndef IDENTIDAD_H_INCLUDED
#define IDENTIDAD_H_INCLUDED

using namespace std;
class Identidad
{
private:
    int _idPersona;
    int _idAsistencia;
    int _idPagos;

public:
    // Constructor por defecto
    Identidad() {};

    // Constructor con parametros
    Identidad(int idPe, int idA, int idPa)
    {
        _idPersona=idPe;
        _idAsistencia=idA;
        _idPagos=idPa;
    };

    // Getter y Setter para id PERSONA
    int getIdPersona()
    {
        return _idPersona;
    };
    void setIdPersona(int idPe)
    {
        _idPersona = idPe;
    };

    // Getter y Setter para id ASISTENCIA
    int getIdAsistencia()
    {
        return _idAsistencia;
    };
    void setIdAsistencia(int idA)
    {
        _idAsistencia = idA;
    };
    // Getter y Setter para id PAGOS
    int getIdPagos()
    {
        return _idPagos;
    };
    void setIdPagos(int idPa)
    {
        _idPagos = idPa;
    };
};

#endif // IDENTIDAD_H_INCLUDED
