#include <iostream>
#include <cstdlib> // Libreria para funciones del sistema
#include "Fecha.h"
#include "Cliente.h"
#include "Disciplina.h"
#include "Persona.h"
#include "personaArchivo.h"
#include "disciplinaArchivo.h"
#include "Asistencia.h"
#include "asistenciaArchivo.h"
#include "pagos.h"
#include "pagosArchivo.h"
#include "identidad.h"
#include "identidadArchivo.h"
#include <ctime>
#include <limits>
#include "usuario.h"
#include "rlutil.h"
#include <fstream>

// NOMBRE DE ARCHIVO DE PAGOS = "pagos.dat"
using namespace std;

/// Definicion de la clase Menu
class Menu
{
public:

    ///FUNCION DE LISTADO COMPLETO DE CLIENTES
    void listadoCompleto()
    {
        system("cls");
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            obj.mostrar();
            cout << endl << "--------------------------------------------------------------------------------------------------------------------" << endl;
        }
        system("pause");
    }

    ///LISTADO COMPLETO DE CLIENTES ACTIVOS
    void listadoCompletoActivos()
    {
        system("cls");
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            if(obj.getEstado()==true)
            {
                obj.mostrar();
                cout << endl << "-----------------------------" << endl;
            }
        }
        system("pause");
    }

    /// LISTADO COMPLETO DE CLIENTES INACTIVOS
    void listadoCompletoInactivos()
    {

        system("cls");
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            if(obj.getEstado()==false)
            {
                obj.mostrar();
                cout << endl << "-----------------------------" << endl;
            }
        }
        system("pause");
    }
    void menuListadoClientes()
    {
        int y = 0;
        bool salir = true;
        rlutil::cls();

        while (salir)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==============================" << endl;
            rlutil::locate(30, 8);
            cout << "      VISUALIZAR CLIENTES     " << endl;
            rlutil::locate(30, 9);
            cout << "==============================" << endl;

            rlutilFuncion("1 - LISTADO COMPLETO", 30, 10, y == 0);
            rlutilFuncion("2 - CLIENTES ACTIVOS", 30, 11, y == 1);
            rlutilFuncion("3 - CLIENTES INACTIVOS", 30, 12, y == 2);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 13, y == 3);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 3) y = 3;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    listadoCompleto();
                    break;
                case 1:
                    listadoCompletoActivos();
                    break;
                case 2:
                    listadoCompletoInactivos();
                    break;
                case 3:
                    salir = false;
                    break;
                default:
                    cout << "OPCION INVALIDA" << endl;
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
    }


    ///CANTIDAD DE CLIENTES POR DISCIPLINA
    void listadoClientesPorDisciplina(int idDisciplina)
    {
        ArchivoCliente archi("Personas.dat");
        ArchivoDisciplina archiDisciplina("Disciplinas.dat");

        Cliente obj;
        int reg = archi.contarRegistros();

        for (int a = 0; a < reg; a++)
        {
            obj = archi.leerRegistro(a);

            if (idDisciplina == obj.getDisciplina().getId())
            {
                obj.mostrar();
                cout << endl;
                cout << "--------------------------------" << endl;
            }
            else if (idDisciplina == -1)
            {
                obj.mostrar();
                cout << endl;
                cout << "--------------------------------" << endl;
            }
        }
        system("pause");
    }

    /// MENU PARA LA CANTIDAD DE CLIENTES POR DISCIPLINA
    void menuCantidadClientesDisciplina()
    {
        int y = 0;
        bool salir = true;

        ArchivoDisciplina archiDis("Disciplinas.dat");
        int reg = archiDis.contarRegistros();
        rlutil::cls();

        while (salir)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "======================================" << endl;
            rlutil::locate(30, 8);
            cout << "         SELECCIONE UNA OPCION        " << endl;
            rlutil::locate(30, 9);
            cout << "======================================" << endl;

            rlutilFuncion("1 - LISTADO DE TODOS LOS CLIENTES", 30, 10, y == 0);
            rlutilFuncion("2 - LISTADO DE CLIENTES POR DISCIPLINA", 30, 11, y == 1);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 12, y == 2);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 2) y = 2;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    listadoClientesPorDisciplina(-1);
                    break;
                case 1:
                {
                    int idDisciplina;
                    for (int i = 0; i < reg; i++)
                    {
                        Disciplina dis = archiDis.leerRegistro(i);
                        cout << dis.getId() << " - LISTADO DE CLIENTES DE " << dis.getNombre() << endl;
                    }
                    cout << endl;
                    cout << "INGRESE EL ID DE LA DISCIPLINA: ";
                    cin >> idDisciplina;
                    system("cls");
                    listadoClientesPorDisciplina(idDisciplina);
                    break;
                }
                case 2:
                    salir = false;
                    break;
                default:
                    cout << "OPCION INVALIDA" << endl;
                    system("pause");
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
    }

    /// VISUALIZAR ASISTENCIA
    void visualizarAsistenciasFecha(int mes, int anio, int idDisciplina)
    {
        AsistenciaArchivo archiAsistencia("Asistencia.dat");
        ArchivoCliente archiCliente("Personas.dat");

        Asistencia asistencia;
        Cliente cliente;

        int regAsistencia = archiAsistencia.contarRegistros();
        int regCliente = archiCliente.contarRegistros();

        for (int i = 0; i < regAsistencia; i++)
        {
            asistencia = archiAsistencia.leerRegistro(i);
            int mesComparar = asistencia.getFecha().getMes();
            int anioComparar = asistencia.getFecha().getAnio();


            if (mesComparar == mes && anioComparar == anio)
            {
                if (idDisciplina == -1)
                {
                    asistencia.mostrar();
                    cout << endl;
                    cout << "--------------------------------" << endl;
                }
                else if (asistencia.getCliente().getDisciplina().getId() == idDisciplina)
                {
                    asistencia.mostrar();
                    cout << endl;
                    cout << "--------------------------------" << endl;
                }
            }
        }
        system("pause");
    }

    void buscarAsistencia()
    {

        AsistenciaArchivo archi("Asistencia.dat");
        Asistencia obj;
        int reg = archi.contarRegistros();
        system("cls");
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            obj.mostrar();
            cout << endl << "-----------------------------" << endl;
        }
        system("pause");
    }
    /// MENU VISUALIZAR ASISTENCIA
    void menuVisualizarAsistenciasFecha()
    {
        int y = 0;
        int mes, anio, idDisciplina;
        bool salir = true;

        rlutil::cls();

        while (salir)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "========================================" << endl;
            rlutil::locate(30, 8);
            cout << "          VISUALIZAR ASISTENCIAS        " << endl;
            rlutil::locate(30, 9);
            cout << "========================================" << endl;

            rlutilFuncion("1 - VISUALIZAR POR MES Y ANIO", 30, 10, y == 0);
            rlutilFuncion("2 - VISUALIZAR POR MES, ANIO Y DISCIPLINA", 30, 11, y == 1);
            rlutilFuncion("3 - VISUALIZAR LISTADO COMPLETO", 30, 12, y == 2);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 13, y == 3);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 3) y = 3;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    cout << "INGRESE EL MES: ";
                    cin >> mes;
                    cout << "INGRESE EL ANIO: ";
                    cin >> anio;
                    visualizarAsistenciasFecha(mes, anio, -1);
                    break;
                case 1:
                    cout << "INGRESE EL MES : ";
                    cin >> mes;
                    cout << "INGRESE EL ANIO: ";
                    cin >> anio;
                    cout << "INGRESE EL ID DE LA DISCIPLINA: ";
                    cin >> idDisciplina;
                    visualizarAsistenciasFecha(mes, anio, idDisciplina);
                    break;
                case 2:
                    buscarAsistencia();
                    break;
                case 3:
                    salir = false;
                    break;
                default:
                    cout << "OPCION INVALIDA" << endl;
                    system("pause");
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
    }

    ///FUNCION PARA MODIFICAR PRECIO DE DISCIPLINA
    void modificarPrecioDisciplina()
    {
        ArchivoCliente archiCli("Personas.dat");
        ArchivoDisciplina archi("Disciplinas.dat");
        int regD = archi.contarRegistros();
        int reg = archiCli.contarRegistros();
        bool encontrado = false;
        int id;
        float nuevoPrecio;
        Disciplina aux;

        while (true)
        {
            bool encontrado=false;

            for (int i = 0; i < regD; i++)
            {
                Disciplina dis = archi.leerRegistro(i);
                cout << "ID: " << dis.getId() << " | " << dis.getNombre() << endl;
            }


            while (true)
            {
                cout<< "INGRESE ID DISCIPLINA: ";
                cin>>id;

                // Verifica si la entrada es un numero entero
                if (cin.fail())
                {
                    cin.clear(); // Limpiar el estado de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                    cout << "Entrada invalida. Por favor, ingrese un número entero." << endl;
                }
                else
                {
                    // Salir del bucle si la entrada es un numero entero válido
                    break;
                }
            }
            for (int i = 0; i < regD; i++)
            {
                Disciplina dis = archi.leerRegistro(i);
                if (id == dis.getId())
                {
                    encontrado = true;
                }
            }
            if (encontrado)
            {
                cout << "El ID de disciplina existe." << endl;
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN ID DE DISCIPLINA VALIDO." << endl;
            }
        }

        cout << "Ingrese el nuevo precio de la disciplina: ";
        cin >> nuevoPrecio;

        for (int i = 0; i < regD; i++)
        {
            Disciplina dis = archi.leerRegistro(i);
            if(dis.getId()==id)
            {
                dis.setPrecio(nuevoPrecio);
                archi.modificarRegistro(dis,i);
                aux=dis;
            }
        }
        for (int i = 0; i < reg; i++)
        {
            Cliente objC = archiCli.leerRegistro(i);
            if(objC.getDisciplina().getId()==id)
            {
                objC.setDisciplina(aux);

                archiCli.modificarRegistro(objC,i);
            }
        }

    }

    /// Metodo para buscar cliente por ID
    void buscarPorID()
    {
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int id;
        bool encontrado = false; // Variable para indicar si se encontro el ID
        while (true)
        {
            cout << "INGRESE ID PARA BUSCAR: ";
            cin >> id;

            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            if (obj.getPersona().getID() == id)
            {
                encontrado = true;
                obj.mostrar();
                break; // No es necesario seguir buscando una vez encontrado
            }
        }
        if (!encontrado)
        {
            cout << "NO SE ENCONTRO EL ID BUSCADO." << endl;
        }
        system("pause");
    }

    /// Metodo para buscar cliente por nombre
    void buscarPorNombre()
    {
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        bool encontrado = false;
        string name;
        cout << "INGRESE NOMBRE A BUSCAR: ";
        cin >> name;
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            if (obj.getPersona().getNombre() == name)
            {
                encontrado = true;
                obj.mostrar();
                cout << endl << "-------------------------------------------------------" << endl;
            }
        }
        if (!encontrado)
        {
            cout<< "NO SE ENCONTRO EL VALOR BUSCADO." << endl;
        }
        system("pause");
    }

    /// Metodo para buscar cliente por apellido
    void buscarPorApellido()
    {
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        bool encontrado = false;
        string apellido;
        cout << "INGRESE APELLIDO A BUSCAR: ";
        cin >> apellido;
        int reg = archi.contarRegistros();
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            if (obj.getPersona().getApellido() == apellido)
            {
                encontrado = true;
                obj.mostrar();
                cout << endl << "-------------------------------------------------------" << endl;
            }
        }
        if (!encontrado)
        {
            cout<< "NO SE ENCONTRO EL VALOR BUSCADO." << endl;
        }
        system("pause");
    }

    /// Metodo para buscar cliente por DNI
    void buscarPorDNI()
    {
        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int dni=0;
        int reg = archi.contarRegistros();
        bool b=false;
        while (true)
        {
            cout << "Ingrese DNI a buscar: ";
            cin >> dni;
            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);
            int dniaux=obj.getPersona().getDni();
            if (dniaux== dni)
            {
                b=true;
                obj.mostrar();
                system("pause");
                break;
            }
        }
        if(b==false)
        {
            cout<< "NO SE ENCONTRO EL VALOR BUSCADO." << endl;
            system("pause");
        }
    }

    ///FUNCION DE ASISTENCIA
    void asistenciaF()
    {

        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        int dni=1;
        int reg = archi.contarRegistros();
        bool b,estado;
        string nombre,apellido,actividad;
        int id;
        // Solicitar DNI con manejo de errores
        while (true)
        {
            cout << "INGRESE DNI A BUSCAR: ";
            if (cin >> dni && dni > 0)
            {
                break;
            }
            else
            {
                cout << "ERROR: INGRESE IN DNI VALIDO (numero entero mayor que cero)." << endl;
                cin.clear();  /// Limpia el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  /// Ignora el resto de la entrada incorrecta
            }
        }
        while(dni!=0)
        {
            b=false;
            estado=false;

            for(int i=0; i<reg; i++)
            {
                obj=archi.leerRegistro(i);
                if(obj.getPersona().getDni()==dni)
                {
                    obj.mostrar();
                    system("pause");
                    estado=obj.getEstado();
                    b=true;
                    i=reg;
                }
            }
            if(b==false)
            {
                cout<< "NO SE ENCONTRO EL VALOR BUSCADO." << endl;
                system("pause");
            }
            if(b==true && estado==true)
            {
                AsistenciaArchivo archi("Asistencia.dat");
                IdentidadArchivo archiID("Identidad.dat");
                Identidad objID;
                objID=archiID.leerRegistro(0);
                int id = objID.getIdAsistencia();
                objID.setIdAsistencia(id+1);
                archiID.modificarRegistro(objID,0);
                time_t now = time(0);
                tm *localTime = localtime(&now);
                int dia = localTime->tm_mday;
                int mes = localTime->tm_mon + 1;   // tm_mon va de 0 a 11
                int anio = localTime->tm_year + 1900;
                Fecha F(dia, mes, anio);
                Asistencia asistencia(id,obj,F);

                archi.grabarRegistro(asistencia);
                cout<<"ASISTENCIA GRABADA"<<endl;
            }
            system("pause");

            cout << "INGRESE DNI A BUSCAR: ";
            cin >> dni;
        }
    }

    /// Opcion 2: Ingresar datos de cliente y mostrar menu principal
    void opc2()
    {
        string nombre, apellido;
        int dia, mes, anio, dni, actividad;
        char sexo;

        // Solicitar información del cliente
        cout << "NOMBRE: ";
        cin.ignore();  // Ignorar el caracter de nueva línea restante en el buffer
        getline(cin, nombre);

        cout << "APELLIDO: ";
        getline(cin, apellido);

        // Verificacion de fecha de nacimiento
        while (true)
        {
            cout << "INDIQUE SU NACIMIENTO: " << endl;
            cout << "Dia: ";
            if (cin >> dia && dia >= 1 && dia <= 31)
            {
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN DIA VALIDO (1-31)." << endl;
                cin.clear();  // Limpia el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la entrada incorrecta
            }
        }

        while (true)
        {
            cout << "Mes: ";
            if (cin >> mes && mes >= 1 && mes <= 12)
            {
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN MES VALIDO (1-12)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true)
        {
            cout << "ANIO: ";
            if (cin >> anio && anio > 0)
            {
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN ANIO VALIDO." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true)
        {
            cout << "INDIQUE SU DNI DIN PUNTOS Y ESPACIOS: ";
            if (cin >> dni && dni > 0)
            {
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN DNI VALIDO." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true)
        {
            cout << "SEXO: M o F: ";
            cin >> sexo;
            if (sexo == 'M' || sexo == 'F' || sexo == 'm' || sexo == 'f')
            {
                break;
            }
            else
            {
                cout << "ERROR: Ingrese M para masculino o F para femenino." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true)
        {
            ArchivoDisciplina archiDis("Disciplinas.dat");
            int regD = archiDis.contarRegistros();
            bool encontrado=false;

            for (int i = 0; i < regD; i++)
            {
                Disciplina dis = archiDis.leerRegistro(i);
                cout << "ID: " << dis.getId() << " | " << dis.getNombre() << endl;
            }

            cout<< "INGRESE ID DISCIPLINA: ";
            cin>>actividad;
            for (int i = 0; i < regD; i++)
            {
                Disciplina dis = archiDis.leerRegistro(i);
                if (actividad == dis.getId())
                {
                    encontrado = true;
                }
            }
            if (encontrado)
            {
                cout << "El ID de disciplina existe." << endl;
                break;
            }
            else
            {
                cout << "ERROR: INGRESE UN ID DE DISCIPLINA VALIDO." << endl;
            }
        }
        /// ---------------------FIN DE FORMULARIO----------------------
        ArchivoCliente archi("Personas.dat");
        IdentidadArchivo archiID("Identidad.dat");
        Identidad objID;
        objID = archiID.leerRegistro(0);
        int id = objID.getIdPersona();
        objID.setIdPersona(id + 1);
        archiID.modificarRegistro(objID, 0);
        ArchivoDisciplina archiDis("Disciplinas.dat");
        Disciplina obj;
        obj = archiDis.leerRegistro(actividad - 1);

        Fecha fechaNacimiento(dia, mes, anio);
        Persona persona(id, nombre, apellido, fechaNacimiento, dni, sexo);

        // Obtener la fecha actual
        time_t t = time(nullptr);
        tm* now = localtime(&t);

        Fecha fechaIngreso(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
        Cliente cliente(persona, true, obj, fechaIngreso, 1);
        archi.grabarRegistro(cliente);
        system("cls");
        cout<<"NUEVO CLIENTE INGRESADO:"<<endl;
        cliente.mostrar();
        system("pause");
    }

    void opc3()
    {
        int y = 0;
        bool salir = true;

        rlutil::cls();

        while (salir)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==============================" << endl;
            rlutil::locate(30, 8);
            cout << "     BUSQUEDA DE CLIENTES     " << endl;
            rlutil::locate(30, 9);
            cout << "==============================" << endl;

            rlutilFuncion("1 - VER LISTADO DE CLIENTES", 30, 10, y == 0);
            rlutilFuncion("2 - BUSCAR POR ID", 30, 11, y == 1);
            rlutilFuncion("3 - BUSCAR POR NOMBRE", 30, 12, y == 2);
            rlutilFuncion("4 - BUSCAR POR APELLIDO", 30, 13, y == 3);
            rlutilFuncion("5 - BUSCAR POR DNI", 30, 14, y == 4);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 15, y == 5);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 5) y = 5;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    menuListadoClientes();
                    break;
                case 1:
                    buscarPorID();
                    break;
                case 2:
                    buscarPorNombre();
                    break;
                case 3:
                    buscarPorApellido();
                    break;
                case 4:
                    buscarPorDNI();
                    break;
                case 5:
                    salir = false;
                    break;
                default:
                    cout << "OPCION INVALIDA, POR FAVOR SELECCIONE NUEVAMENTE." << endl;
                    system("pause");
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
    }

    /// LISTADO DE MESES CON NUEVOS INGRESOS
    void listadoMesesNuevosIngresos()
    {
        int anio;
        while (true)
        {
            cout <<"INGRESE EL ANIO QUE DESEA VER LOS INGRESOS POR MES" <<endl;
            cin >> anio;
            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        int contadorPorMes [12]= {0};
        string meses[12]= {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

        ArchivoCliente archiCliente("Personas.dat");
        int cantClientes=archiCliente.contarRegistros();

        for(int i=0; i< cantClientes; i++)
        {
            Cliente cli= archiCliente.leerRegistro(i);
            Fecha fechaIngreso= cli.getIngreso();
            if(fechaIngreso.getAnio()==anio)
            {
                int mes= fechaIngreso.getMes();
                if(mes>=1 && mes<=12)
                {
                    contadorPorMes[mes -1] ++;
                }
            }


        }
        cout <<"LISTADO DE NUEVOS INGRESOS EN EL ANIO: " <<anio <<endl;
        for(int m=0; m<12; m++)
        {
            cout << meses[m] << "| INGRESANTES NUEVOS |" << contadorPorMes[m] <<endl;
        }
        system("pause");

    }

    ///Funcion de recaudacion segun año deseado
    void recaudacionAnual()
    {
        PagosArchivo paguitoAr("Pagos.dat");
        Pagos paguito;
        int cant,anio;
        float recAnual;
        cant=paguitoAr.contarRegistros();
        while (true)
        {
            cout <<"INGRESE EL ANIO DE PAGO" <<endl;
            cin >> anio;
            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        for (int i=0; i<cant; i++)
        {
            paguito=paguitoAr.leerRegistro(i);
            if(   paguito.getFecha().getAnio()==anio)//verifica que el pago sea del anio ingresado
            {
                recAnual+=paguito.getMonto();//acumula el monto del pago
            }
        }
        cout<<"LA RECAUDACION DEL ANIO "<<anio<<" ES: "<<recAnual<<endl;//muestra el acumulador
        system("pause");
    }

    ///Funcion de recaudacion de disciplina por año
    void recaudacionDisciplina()
    {
        PagosArchivo paguitoAr("Pagos.dat");
        Pagos paguito;
        int cant,anio,disciplina;
        float recDisci=0;
        cant=paguitoAr.contarRegistros();

        while (true)
        {
            cout <<"INGRESE ANIO: " <<endl;
            cin >> anio;
            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }

        ArchivoDisciplina archiDis("Disciplinas.dat");
        int reg=archiDis.contarRegistros();
        int idDisciplina;
        for(int i=0; i<reg; i++)
        {
            Disciplina dis= archiDis.leerRegistro(i);

            cout << dis.getId() <<" - LISTADO DE CLIENTES DE " << dis.getNombre() << endl;
        }
        while (true)
        {
            cout <<endl<< "INGRESE EL ID DE LA DISCIPLINA: ";
            cin >> idDisciplina;
            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada inválida. Por favor, ingrese un número entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        system("cls");
        for (int i=0; i<cant; i++)
        {
            paguito=paguitoAr.leerRegistro(i);
            if(paguito.getCliente().getDisciplina().getId()==idDisciplina)//verifica que el pago sea de la disciplina ingresada
            {

                if(paguito.getFecha().getAnio()==anio);//verifica la fecha
                {
                    recDisci+=paguito.getMonto();//acumula la recaudacion
                }
            }
        }
        cout<<"LA RECAUDACION DEL ANIO "<<anio<<" DE LA DISCIPLINA "<<disciplina <<" ES: "<<recDisci<<endl;
        system("pause");
    }


    /// FUNCIONES DE DASHBOARD

    void recaudacionMesActual()
    {
        PagosArchivo pagosArch("pagos.dat");
        Pagos pago;
        int cantidadPagos = pagosArch.contarRegistros();
        float recaudacionMes = 0.0;

        // Obtener la fecha actual
        time_t now = time(0);
        tm *localTime = localtime(&now);
        int mesActual = localTime->tm_mon + 1;   // tm_mon va de 0 a 11
        int anioActual = localTime->tm_year + 1900;

        for (int i = 0; i < cantidadPagos; i++)
        {
            pago = pagosArch.leerRegistro(i);
            Fecha fechaPago = pago.getFecha();

            // Comparar si el pago es del mes y anio actual
            if (fechaPago.getMes() == mesActual && fechaPago.getAnio() == anioActual)
            {
                recaudacionMes += pago.getMonto();
            }
        }

        cout << "RECAUDACION DEL MES " << mesActual << "/" << anioActual << ": $" << recaudacionMes << endl;
    }

    void totalAnotadosEnDisciplinas()
    {
        ArchivoCliente archi("Personas.dat");
        ArchivoDisciplina archiDis("Disciplinas.dat");
        Cliente obj;
        int reg = archi.contarRegistros();
        int regD=archiDis.contarRegistros();
        int *vec;
        vec = new int [regD];

        for(int i=0; i<regD; i++)
        {
            vec[i]=0;
        }
        for (int a = 0; a < reg; a++)
        {
            obj = archi.leerRegistro(a);
            int idDisciplina = obj.getDisciplina().getId();
            vec[idDisciplina-1]++;
        };
        int cont=0;
        for(int i=0; i<regD; i++)
        {
            Disciplina dis;
            dis=archiDis.leerRegistro(i);
            cout<<dis.getNombre();
            cout<<": "<<vec[i]<<" | ";
            cont++;
            if(cont==3)
            {
                cout<<endl;
            }
        }
        cout<<endl;
        delete[] vec;
    }

    void contarClientesActivos()
    {
        int contadorActivos = 0, contadorInactivos = 0;

        ArchivoCliente archi("Personas.dat");
        int reg = archi.contarRegistros(); // Obtener la cantidad de registros en el archivo

        for (int i = 0; i < reg; ++i)
        {
            Cliente obj = archi.leerRegistro(i);

            // Verificar el estado del cliente
            if (obj.getEstado())
            {
                contadorActivos++;
            }
            else
            {
                contadorInactivos++;
            }
        }

        // Mostrar resultados
        cout << "CLIENTES ACTIVOS: " << contadorActivos << endl;
        cout << "CLIENTES INACTIVOS: " << contadorInactivos << endl;
    }

    ///FUNCION PARA ELIMINAR UN CLIENTE
    void eliminarPorID()
    {
        ArchivoCliente archi("Personas.dat");
        int id;
        Cliente obj;
        char eliminar;
        bool eliminado=false;
        while (true)
        {
            cout << "INGRESE EL ID DEL CLIENTE A EIMINAR O '0'" << endl << "PARA VOLVER AL MENU PRINCIPAL: ";
            cin >> id;

            if (cin.fail())
            {
                cin.clear();  // Limpia el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la entrada incorrecta
                cout << "ERROR: INGRESE UN ID VALIDO (numero entero mayor que cero)." << endl;
            }
            else if (id == 0)
            {
                return;  // Volver al menu principal
            }
            else if (id > 0)
            {
                break;  /// ID válido ingresado
            }
            else
            {
                cout << "ERROR: INGRESE UN ID VALIDO (numero entero mayor que cero)." << endl;
            }
        }
        int pos=archi.buscarRegistro(id);
        obj=archi.leerRegistro(pos);
        int idaux=obj.getPersona().getID();
        if(idaux==id)
        {
            cout << endl << "-------------------------------------------------------" << endl;
            obj.mostrar();
            cout << endl << "-------------------------------------------------------" << endl;
            while (true)
            {
                cout << endl << "¿ESTA SEGURO DE ELIMINARLO? S/N: ";
                cin >> eliminar;

                // Convertir a mayuscula para simplificar la comparacion
                eliminar = toupper(eliminar);

                if (eliminar == 'S'|| eliminar=='s' || eliminar == 'N'|| eliminar=='n')
                {
                    break;
                }
                else
                {
                    cout << "ERROR: Ingrese 'S' para si o 'N' para no." << endl;
                    cin.clear();  // Limpia el estado de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la entrada incorrecta
                }
            }

            if(eliminar=='S' || eliminar=='s')
            {
                eliminado = archi.eliminarRegistroPorID(id);
            }
            if(eliminar=='N' || eliminar=='n')
            {
                cout<<endl<<"CLIENTE NO ELIMINADO"<<endl;
                system("pause");
                return;
            }


            if (eliminado)
            {
                cout << "SE HA ELIMINADO EL REGISTRO CON ID " << id << " CORRECTAMENTE." << endl;
            }
        }
        else
        {
            cout << "NO SE ENCONTRO EL ID BUSCADO O NO SE PUDO ELIMINAR EL REGISTRO." << endl;
        }

        system("pause");
    }

    void rlutilFuncion(const char* text, int posx, int posy, bool selec)
    {
        if(selec)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::locate(posx-2,posy);
            cout <<(char)175 << " "<< text <<" " << (char)174  << endl;
        }
        else
        {
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(posx-2,posy);
            cout << "    " << text  <<"     " << endl;
        }

        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }

    /// MOSTRAR MENU PRINCIPAL
    void display()
    {
        int y=0;
        bool verdadero = true;

        rlutil::hidecursor();

        // Bucle para mostrar el menu principal hasta que se seleccione salir
        ArchivoUsuario archivoUsuarios("usuarios.dat"); // Archivo de usuarios

        // Verificar la existencia de usuarios y realizar el inicio de sesion
        Usuario usuarioLogueado = archivoUsuarios.verificarExistenciaUsuarios();

        // Continuar con el programa si el inicio de sesion es exitoso
        cout << "Inicio de sesion exitoso. Presione ENTER para continuar..." << endl;
        system("pause");
        cin.ignore();
        cin.get();
        system("cls");
        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30,7);
            cout <<"==========================================" <<endl;
            rlutil::locate(30,8);
            cout <<"               MENU PRINCIPAL             "<<endl;
            rlutil::locate(30,9);
            cout <<"==========================================" <<endl;
            rlutilFuncion("1 - ASISTENCIA", 30, 10, y==0);
            rlutilFuncion("2 - CLIENTES", 30, 11, y==1);
            rlutilFuncion("3 - REGISTRAR PAGOS", 30, 12, y==2);
            rlutilFuncion("4 - LISTADO DE ASISTENCIA Y DISCIPLINA", 30, 13, y==3);
            rlutilFuncion("5 - RECAUDACION  ", 30, 14, y==4);
            rlutilFuncion("6 - DASHBOARD", 30, 15, y==5);
            rlutilFuncion("7 - COPIA DE SEGURIDAD", 30, 16, y==6);
            rlutilFuncion("8 - RANKING MAS ASISTIDORES", 30, 17, y==7);
            rlutilFuncion("9 - RESTAURAR COPIA DE SEGURIDAD ", 30, 18, y==8);
            rlutilFuncion("10 - EDAD PROMEDIO POR DISCIPLINA ", 30, 19, y==9);
            rlutilFuncion("11 - VISUALIZAR TICKETS DE PAGO ", 30, 20, y==10);
            rlutilFuncion("12 - CREAR ARCHIVO CSV DE CLIENTES ", 30, 21, y==11);

            rlutilFuncion("SALIR", 30, 22, y==12);


            if (usuarioLogueado.getJerarquia() == 1)
            {
                rlutil::locate(30,23);
                cout <<"==========================================" <<endl;
                rlutil::locate(30,24);
                cout<< "         OPCIONES DE ADMINISTRADOR        " << endl;
                rlutil::locate(30,25);
                cout <<"==========================================" <<endl;

                rlutilFuncion("12 - CREAR USUARIO", 30, 26, y==13);
                rlutilFuncion("13 - ELIMINAR USUARIO", 30, 27, y==14);
                rlutilFuncion("14 - MODIFICAR CONTRASENIA", 30, 28, y==15);
            }

            rlutil::locate(28,10 + y);
            int key = rlutil::getkey();

            switch(key)
            {
            case 14: //ARRRIBA
                y--;
                if(y<0)
                {
                    y=0;
                }
                else if (y == 12 && usuarioLogueado.getJerarquia() != 1)  // Saltar titulo de administrador
                {
                    y = 12;
                }
                else if (y > 15)
                {
                    y = 15;
                }
                break;
            case 15: //ABAJO
                y++;
                if (y > 12 && usuarioLogueado.getJerarquia() != 1)
                {
                    y = 12;
                }
                else if (y == 13 && usuarioLogueado.getJerarquia() != 1)  // Saltar titulo de administrador
                {
                    y = 13;
                }
                else if (y > 15)
                {
                    y = 15;
                }
                break;
            case 1: //ENTER
                rlutil::cls();
                switch(y)
                {
                case 0:
                    opc1(); // Opcion 1: Asistencia
                    break;
                case 1:
                    menuClientes(); /// Opcion 2: Nuevo Cliente
                    break;
                case 2:
                    opc4(); /// Opcion 3: Registrar Pagos
                    break;
                case 3:
                    menuAsistenciaDisciplina();
                    break;
                case 4:
                    menuRecaudacion();
                    break;
                case 5:
                    Dashboard();
                    break;
                case 6:
                    copias();
                    break;
                case 7:
                    MasAsistidos();
                    break;
                case 8:
                    restaurarCopia();
                    break;
                case 9:
                    edadPromedioXDisciplina();
                    break;
                case 10:
                    visualizarTickets();
                    break;

                case 11:
                    crearArchivoCSV("Personas.dat", "clientes.csv");
                    system("pause");
                    system("cls");
                    break;

                case 12: // salir
                    return;
                    break;

                case 13:
                    if (usuarioLogueado.getJerarquia() == 1)
                    {
                        archivoUsuarios.ingresarUsuario();
                    }
                    break;
                case 14:
                    if (usuarioLogueado.getJerarquia() == 1)
                    {
                        archivoUsuarios.eliminarUsuarioPorNombre(); //eliminar usuario
                    }
                    break;
                case 15:
                    if (usuarioLogueado.getJerarquia() == 1)
                    {
                        archivoUsuarios.modificarContraseniaPorNombre(); //modificar contraseña
                    }
                }
                break;

            default:
                break;
            }

        }
        while(verdadero);
    }

    /// OPCION 1: Solicitar DNI hasta que sea 0
    void opc1()
    {
        asistenciaF();
        system("pause");
        rlutil::cls();

    }

    ///OPCION 2
    void menuClientes()
    {
        int y = 0;
        bool verdadero = true;
        rlutil::cls();

        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==================================" << endl;
            rlutil::locate(30, 8);
            cout << "          MENU CLIENTES           " << endl;
            rlutil::locate(30, 9);
            cout << "==================================" << endl;

            rlutilFuncion("1 - INGRESAR NUEVO CLIENTE", 30, 10, y==0);
            rlutilFuncion("2 - BUSCAR CLIENTE", 30, 11, y==1);
            rlutilFuncion("3 - ELIMINAR CLIENTE", 30, 12, y==2);
            rlutilFuncion("4 - VER NUEVOS INGRESOS POR MES", 30, 13, y==3);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 14, y==4);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;
            case 15: // ABAJO
                y++;
                if (y > 4)
                {
                    y = 4;
                }
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    opc2();  // Ingresar nuevo cliente
                    break;
                case 1:
                    opc3();  // Buscar cliente
                    break;
                case 2:
                    eliminarPorID();  // Eliminar cliente
                    break;
                case 3:
                    listadoMesesNuevosIngresos();  // Ver nuevos ingresos por mes
                    break;
                case 4:
                    verdadero = false;  // Volver al menu principal
                    break;
                default:
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
        while(verdadero);
    }

/// OPCION 3 MENU

    void opc4()
    {
        int dni, n;
        int y=0;
        bool verdadero =true;

        ArchivoCliente archi("Personas.dat");
        Cliente obj;
        PagosArchivo archiPa("pagos.dat");
        int reg = archi.contarRegistros();
        int regPa = archiPa.contarRegistros();
        time_t t = time(nullptr);
        tm* now = localtime(&t);

        Fecha fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);

        rlutil::cls();
        while (verdadero)
        {

            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            // Mostrar título del menu
            rlutil::locate(30, 7);
            cout << "==============================" << endl;
            rlutil::locate(30, 8);
            cout << "       REGISTRAR PAGOS        " << endl;
            rlutil::locate(30, 9);
            cout << "==============================" << endl;

            // Mostrar opciones del menú
            rlutilFuncion("1 - CARGAR PAGO", 30, 10, y == 0);
            rlutilFuncion("2 - MODIFICAR PRECIO DE DISCIPLINA", 30, 11, y == 1);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 12, y == 2);

            // Leer la tecla presionada por el usuario
            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14:  // ARRIBA
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;

            case 15:  // ABAJO
                y++;
                if (y > 2)
                {
                    y = 2;
                }
                break;

            case 1:  // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:  // CARGAR PAGO
                    while (true)
                    {
                        int dni;
                        cout << "INGRESE DNI A BUSCAR: ";
                        if (cin >> dni && dni > 0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "ERROR: INGRESE UN DNI VALIDO (numero entero mayor que cero)." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    while (dni != 0)
                    {
                        system("cls");
                        for (int i = 0; i < reg; i++)
                        {
                            obj = archi.leerRegistro(i);
                            if (obj.getPersona().getDni() == dni)
                            {
                                obj.mostrar();
                                cout << endl << "MONTO A PAGAR: ";
                                float monto = obj.getDisciplina().getPrecio();
                                cout << monto << endl;
                                cout << "1 - REALIZAR PAGO" << endl;
                                cout << "0 - CANCELAR OPERACION" << endl;
                                cin >> n;
                                if (n == 1)
                                {
                                    IdentidadArchivo archiID("Identidad.dat");
                                    Identidad objID;
                                    objID = archiID.leerRegistro(0);
                                    int id = objID.getIdPagos();
                                    objID.setIdPagos(id + 1);
                                    archiID.modificarRegistro(objID, 0);
                                    Pagos objPa(id, obj, monto, fecha);
                                    archiPa.grabarRegistro(objPa);
                                    obj.setEstado(true);
                                    int cred = obj.getCreditos();
                                    obj.setCreditos(cred + 1);
                                    archi.modificarRegistro(obj, i);
                                    cout << "PAGO REALIZADO." << endl;
                                    system("pause");
                                }
                                if (n == 0)
                                {
                                    break;
                                }
                            }
                        }
                        system("cls");
                        cout << "INGRESE DNI (o 0 para cancelar): ";
                        cin >> dni;
                    }
                    break;

                case 1:
                    modificarPrecioDisciplina();
                    break;

                case 2:
                    verdadero = false;
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }
    }

    /// OPCION 4 - MENU ASISTENCIA Y DISCIPLINA
    void menuAsistenciaDisciplina()
    {
        int y = 0;
        bool verdadero = true;
        rlutil::cls();

        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==========================================" << endl;
            rlutil::locate(30, 8);
            cout << "    LISTADO DE ASISTENCIA Y DISCIPLINA    " << endl;
            rlutil::locate(30, 9);
            cout << "==========================================" << endl;

            rlutilFuncion("1 - LISTADO DE ASISTENCIA", 30, 10, y==0);
            rlutilFuncion("2 - CANTIDAD DE CLIENTES POR DISCIPLINA", 30, 11, y==1);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 12, y==2);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;
            case 15: // ABAJO
                y++;
                if (y > 2)
                {
                    y = 2;
                }
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    menuVisualizarAsistenciasFecha();
                    break;
                case 1:
                    menuCantidadClientesDisciplina();
                    break;
                case 2:
                    verdadero = false;
                    break;
                default:
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
        while (verdadero);
    }


    /// OPCION 5 - MENU RECAUDACION
    void menuRecaudacion()
    {
        int y = 0;
        bool verdadero = true;
        rlutil::cls();

        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==================================" << endl;
            rlutil::locate(30, 8);
            cout << "         MENU RECAUDACION         " << endl;
            rlutil::locate(30, 9);
            cout << "==================================" << endl;

            rlutilFuncion("1 - RECAUDACION ANUAL", 30, 10, y==0);
            rlutilFuncion("2 - RECAUDACION POR DISCIPLINA", 30, 11, y==1);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 12, y==2);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;
            case 15: // ABAJO
                y++;
                if (y > 2)
                {
                    y = 2;
                }
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    recaudacionAnual();
                    break;
                case 1:
                    recaudacionDisciplina();
                    break;
                case 2:
                    verdadero = false;
                    break;
                default:
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
        while (verdadero);
    }

    ///OPCION 6 DASHBOARD
    void Dashboard()
    {
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::cls();


        cout << "==================================" << endl;
        cout << "           DASHBOARD             " << endl;
        cout << "==================================" << endl;

        cout<<"----------------------------------"<<endl;
        contarClientesActivos();
        cout<<"----------------------------------"<<endl;
        totalAnotadosEnDisciplinas();
        cout<<"----------------------------------"<<endl;
        recaudacionMesActual();
        cout<<"----------------------------------"<<endl;

        system("pause");
        rlutil::cls();
    }

/// OPCION 7 COPIA DE SEGURIDAD
    void copias()
    {
        int y = 0;
        bool verdadero = true;
        rlutil::cls();

        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==============================" << endl;
            rlutil::locate(30, 8);
            cout << "       COPIA DE SEGURIDAD    " << endl;
            rlutil::locate(30, 9);
            cout << "==============================" << endl;

            rlutilFuncion("1 - ASISTENCIA", 30, 10, y==0);
            rlutilFuncion("2 - DISCIPLINA", 30, 11, y==1);
            rlutilFuncion("3 - IDENTIDAD", 30, 12, y==2);
            rlutilFuncion("4 - PERSONAS", 30, 13, y==3);
            rlutilFuncion("5 - PAGOS", 30, 14, y==4);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 15, y==5);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                break;
            case 15: // ABAJO
                y++;
                if (y > 5)
                {
                    y = 5;
                }
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                {
                    char confirm;
                    cout << "¿DESEA REALIZAR COPIA DE SEGURIDAD DE ASISTENCIA? (S-N): ";
                    cin >> confirm;
                    if (confirm == 's' || confirm == 'S')
                    {
                        AsistenciaArchivo archiC("copiaAsistencia.dat");
                        AsistenciaArchivo archi("Asistencia.dat");
                        for (int i = 0; i < archi.contarRegistros(); i++)
                        {
                            archiC.grabarRegistro(archi.leerRegistro(i));
                        }
                        cout << "COPIA DE SEGURIDAD REALIZADA PARA ASISTENCIA" << endl;
                        system("pause");
                    }
                    else if (confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "OPCION INCORRECTA" << endl;
                    }
                }
                break;

                case 1:
                {
                    char confirm;
                    cout << "¿DESEA REALIZAR COPIA DE SEGURIDAD DE DISCIPLINA? (S-N): ";
                    cin >> confirm;
                    if (confirm == 's' || confirm == 'S')
                    {
                        ArchivoDisciplina archiC("copiaDisciplina.dat");
                        ArchivoDisciplina archi("Disciplinas.dat");
                        for (int i = 0; i < archi.contarRegistros(); i++)
                        {
                            archiC.grabarRegistro(archi.leerRegistro(i));
                        }
                        cout << "COPIA DE SEGURIDAD REALIZADA PARA DISCIPLINA" << endl;
                    }
                    else if (confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "OPCION INCORRECTA" << endl;
                    }
                }
                break;

                case 2:
                {
                    char confirm;
                    cout << "¿DESEA REALIZAR COPIA DE SEGURIDAD DE IDENTIDAD? (S-N): ";
                    cin >> confirm;
                    if (confirm == 's' || confirm == 'S')
                    {
                        IdentidadArchivo archiC("copiaIdentidad.dat");
                        IdentidadArchivo archi("Identidad.dat");
                        for (int i = 0; i < archi.contarRegistros(); i++)
                        {
                            archiC.grabarRegistro(archi.leerRegistro(i));
                        }
                        cout << "COPIA DE SEGURIDAD REALIZADA PARA IDENTIDAD" << endl;
                        system("pause");
                    }
                    else if (confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "OPCION INCORRECTA" << endl;
                    }
                }
                break;

                case 3:
                {
                    char confirm;
                    cout << "¿DESEA REALIZAR COPIA DE SEGURIDAD DE PERSONAS? (S-N): ";
                    cin >> confirm;
                    if (confirm == 's' || confirm == 'S')
                    {
                        ArchivoCliente archiC("copiaPersonas.dat");
                        ArchivoCliente archi("Personas.dat");
                        for (int i = 0; i < archi.contarRegistros(); i++)
                        {
                            archiC.grabarRegistro(archi.leerRegistro(i));
                        }
                        cout << "COPIA DE SEGURIDAD REALIZADA PARA PERSONAS" << endl;
                        system("pause");
                    }
                    else if (confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "OPCION INCORRECTA" << endl;
                    }
                }
                break;

                case 4:
                {
                    char confirm;
                    cout << "¿DESEA REALIZAR COPIA DE SEGURIDAD DE PAGOS? (S-N): ";
                    cin >> confirm;
                    if (confirm == 's' || confirm == 'S')
                    {
                        PagosArchivo archiC("copiaPagos.dat");
                        PagosArchivo archi("Pagos.dat");
                        for (int i = 0; i < archi.contarRegistros(); i++)
                        {
                            archiC.grabarRegistro(archi.leerRegistro(i));
                        }
                        cout << "COPIA DE SEGURIDAD REALIZADA PARA PAGOS" << endl;
                        system("pause");
                    }
                    else if (confirm == 'n' || confirm == 'N')
                    {
                        break;
                    }
                    else
                    {
                        cout << "OPCION INCORRECTA" << endl;
                    }
                }
                break;

                case 5:
                    verdadero = false;
                    break;

                default:
                    break;
                }
                rlutil::cls();
                break;

            default:
                break;
            }
        }
        while (verdadero);
    }


    /// RANCKING OPCION 8
    void MasAsistidos()
    {
        AsistenciaArchivo asistencias("asistencia.dat");
        ArchivoCliente archiC("personas.dat");
        Asistencia asist;
        Cliente Cli;

        int regCli=archiC.contarRegistros();
        int regAsis=asistencias.contarRegistros();
        int TamVec=0;
        int posVec=0;
        int *asisXCliente= {};
        int TamRanking, disciplina, anio;

        ArchivoDisciplina archiDis("Disciplinas.dat");
        int reg=archiDis.contarRegistros();
        int idDisciplina;
        for(int i=0; i<reg; i++)
        {
            Disciplina dis= archiDis.leerRegistro(i);

            cout << dis.getId() <<" - " << dis.getNombre() << endl;
        }
        cout <<endl;
        cout << "INGRESE EL ID DE LA DISCIPLINA: ";
        cin >> disciplina;

        while (true)
        {
            cout<< "INGRESE ANIO: ";
            cin >> anio;

            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        while (true)
        {
            cout << "POSICIONES DEL RANKING A MOSTRAR: ";
            cin >> TamRanking;

            // Verifica si la entrada es un numero entero
            if (cin.fail())
            {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            }
            else
            {
                // Salir del bucle si la entrada es un numero entero valido
                break;
            }
        }
        // Obtenemos la cantidad de clientes de la disciplina buscada
        for (int i = 0; i < regCli; i++)
        {
            Cli=archiC.leerRegistro(i);
            if(disciplina==Cli.getDisciplina().getId())
            {
                TamVec++;
            }
        }
        int *AcumAsis,*Vec;
        AcumAsis = new int [TamVec];
        Vec = new int [TamVec];
        for (int i = 0; i < TamVec; i++)
        {
            AcumAsis[i]=0;
            Vec[i]=0;
        }
        //Cargamos los vectores con los clientes de la disciplina buscada y su cantidad de asistencias
        for (int i = 0; i < regCli; i++)
        {
            Cli=archiC.leerRegistro(i);
            if(disciplina==Cli.getDisciplina().getId())
            {
                Vec[posVec]=Cli.getPersona().getID();
                for (int x = 0; x < regAsis; x++)
                {
                    asist=asistencias.leerRegistro(x);
                    if(asist.getCliente().getPersona().getID()==Cli.getPersona().getID() && asist.getFecha().getAnio()==anio)
                    {
                        AcumAsis[posVec]++;
                    }
                }
                posVec++;
            }
        }
        int *MayVec,*IdVec;
        MayVec = new int [TamRanking];
        IdVec = new int [TamRanking];
        for (int i = 0; i < TamRanking; i++)
        {
            MayVec[i]=0;
            IdVec[i]=0;
        }
        int j=0;
        int acum=AcumAsis[j];
        int pos=Vec[j];
        MayVec[j]=acum;
        IdVec[j]=pos;
        //Elaboramos el renking

        for (int i = 0; i < TamRanking; i++)
        {
            for (int x = 0; x < TamVec; x++)
            {
                if(i==0 && MayVec[i]<AcumAsis[x])
                {
                    MayVec[i]=AcumAsis[x];
                    IdVec[i]=Vec[x];
                }
                if(i!=0 && MayVec[i]<AcumAsis[x] && MayVec[i-1]>AcumAsis[x])
                {
                    MayVec[i]=AcumAsis[x];
                    IdVec[i]=Vec[x];
                }
            }
            posVec++;
        }

        for (int i = 0; i < TamRanking; i++)
        {
            int id=IdVec[i];
            int posi=archiC.buscarRegistro(id);
            Cli=archiC.leerRegistro(posi);
            cout<<endl<<"Puesto #"<<i+1<<endl;
            Cli.mostrarRank();
            cout<<endl<<"Asistencias: "<<MayVec[i]<<endl;
        }
        // Liberar memoria

        delete[] AcumAsis;
        delete[] Vec;
        delete[] IdVec;
        delete[] MayVec;
        system("pause");
        rlutil::cls();
    }

/// opcion 9 restaurar copia

    void restaurarCopia()
    {
        int y = 0;
        bool verdadero = true;
        rlutil::cls();

        do
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "==================================" << endl;
            rlutil::locate(30, 8);
            cout << "   RESTAURAR COPIA DE SEGURIDAD   " << endl;
            rlutil::locate(30, 9);
            cout << "==================================" << endl;

            rlutilFuncion("1 - ASISTENCIA", 30, 10, y == 0);
            rlutilFuncion("2 - DISCIPLINA", 30, 11, y == 1);
            rlutilFuncion("3 - PERSONAS", 30, 12, y == 2);
            rlutilFuncion("4 - IDENTIDAD", 30, 13, y == 3);
            rlutilFuncion("5 - PAGOS", 30, 14, y == 4);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 15, y == 5);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 5) y = 5;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                {
                    AsistenciaArchivo archi("Asistencia.dat");
                    AsistenciaArchivo archiC("copiaAsistencia.dat");

                    //Limpiar Asistencia.dat antes de restaurar
                    archi.limpiarArchivo();

                    for (int i = 0; i < archiC.contarRegistros(); i++)
                    {
                        archi.grabarRegistro(archiC.leerRegistro(i));
                    }
                    cout << "RESTAURACION COMPLETADA PARA Asistencia.dat" << endl;
                    system("pause");
                    break;
                }
                case 1:
                {
                    ArchivoDisciplina archi("Disciplinas.dat");
                    ArchivoDisciplina archiC("copiaDisciplina.dat");

                    //Limpiar Disciplinas.dat antes de restaurar
                    archi.limpiarArchivo();

                    for (int i = 0; i < archiC.contarRegistros(); i++)
                    {
                        archi.grabarRegistro(archiC.leerRegistro(i));
                    }
                    cout << "RESTAURACION COMPLETADA PARA Disciplinas.dat" << endl;
                    system("pause");
                    break;
                }
                case 2:
                {
                    ArchivoCliente archi("Personas.dat");
                    ArchivoCliente archiC("copiaPersonas.dat");

                    // Limpiar Personas.dat antes de restaurar
                    archi.limpiarArchivo();

                    for (int i = 0; i < archiC.contarRegistros(); i++)
                    {
                        archi.grabarRegistro(archiC.leerRegistro(i));
                    }
                    cout << "RESTAURACION COMPLETADA PARA Personas.dat" << endl;
                    system("pause");
                    break;
                }
                case 3:
                {
                    IdentidadArchivo archi("Identidad.dat");
                    IdentidadArchivo archiC("copiaIdentidad.dat");

                    // Limpiar Identidad.dat antes de restaurar
                    archi.limpiarArchivo();

                    for (int i = 0; i < archiC.contarRegistros(); i++)
                    {
                        archi.grabarRegistro(archiC.leerRegistro(i));
                    }
                    cout << "RESTAURACION COMPLETADA PARA Identidad.dat" << endl;
                    system("pause");
                    break;
                }
                case 4:
                {
                    PagosArchivo archi("Pagos.dat");
                    PagosArchivo archiC("copiasPagos.dat");

                    // Limpiar Pagos.dat antes de restaurar
                    archi.limpiarArchivo();

                    for (int i = 0; i < archiC.contarRegistros(); i++)
                    {
                        archi.grabarRegistro(archiC.leerRegistro(i));
                    }
                    cout << "RESTAURACION COMPLETADA PARA Pagos.dat" << endl;
                    system("pause");
                    break;
                }
                case 5:
                    verdadero = false;
                    break;
                default:
                    cout << "OPCION INVALIDA" << endl;
                    system("pause");
                    break;
                }
                rlutil::cls();
                break;
            default:
                break;
            }
        }
        while (verdadero);
    }

    /// OPCION 10 EDAD PROMEDIO

    void edadPromedioXDisciplina()
    {
        ArchivoCliente archi("Personas.dat");
        ArchivoDisciplina archiDis("Disciplinas.dat");
        Cliente obj;
        Disciplina objD;
        int reg = archi.contarRegistros();
        int regD = archiDis.contarRegistros();
        int idDisciplina;
        int acum=0;
        int cont=0;
        int edad,anio,mes;
        cout<<"EDAD PROMEDIO POR DISCIPLINA Y ANIO"<<endl;
        for(int i=0; i<regD; i++)
        {
            Disciplina dis= archiDis.leerRegistro(i);
            cout << dis.getId() <<" - LISTADO DE CLIENTES DE " << dis.getNombre() << endl;
        }
        cout <<endl;
        cout << "INGRESE EL ID DE LA DISCIPLINA o 0 PARA VOLVER AL MENU PRINCIPAL: ";
        cin >> idDisciplina;
        if(idDisciplina==0)
        {
            return;
        }
        for (int a = 0; a < reg; a++)
        {
            obj = archi.leerRegistro(a);

            if (idDisciplina == obj.getDisciplina().getId() && obj.getEstado()==true)
            {
                edad=2024-obj.getPersona().getNacimiento().getAnio();
                acum+=edad;
                cont++;
            }
        }
        cout<<endl<<"LA EDAD PROMEDIO DE LA  DISCIPLINA: "<<idDisciplina<<" ES: "<<acum/cont<<endl;
        system("pause");
        rlutil::cls();
    }

    /// OPCION 11 VISUALIZAR TICKETS DE PAGO

    void visualizarTickets()
    {
        int y = 0;
        bool verdadero = true;
        Fecha filtro;
        Pagos p;
        PagosArchivo pp("Pagos.dat");
        int anio, mes;

        rlutil::cls();

        while (verdadero)
        {
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            rlutil::setColor(rlutil::COLOR::WHITE);

            rlutil::locate(30, 7);
            cout << "=====================================" << endl;
            rlutil::locate(30, 8);
            cout << "       VISUALIZAR TICKETS DE PAGO    " << endl;
            rlutil::locate(30, 9);
            cout << "=====================================" << endl;

            rlutilFuncion("1 - VER LISTADO COMPLETO", 30, 10, y == 0);
            rlutilFuncion("2 - FILTRAR POR ANIO", 30, 11, y == 1);
            rlutilFuncion("3 - FILTRAR POR ANIO Y MES", 30, 12, y == 2);
            rlutilFuncion("VOLVER AL MENU PRINCIPAL", 30, 13, y == 3);

            rlutil::locate(28, 10 + y);
            int key = rlutil::getkey();

            switch (key)
            {
            case 14: // ARRIBA
                y--;
                if (y < 0) y = 0;
                break;
            case 15: // ABAJO
                y++;
                if (y > 3) y = 3;
                break;
            case 1: // ENTER
                rlutil::cls();
                switch (y)
                {
                case 0:
                    for (int i = 0; i < pp.contarRegistros(); i++)
                    {
                        p = pp.leerRegistro(i);
                        p.mostrar();
                    }
                    system("pause");
                    break;

                case 1: // Filtrar por anio
                    rlutil::cls();
                    while (true)
                    {
                        cout << "INGRESE ANIO: ";
                        cin >> anio;

                        if (cin.fail()) // Verifica si la entrada es un numero entero
                        {
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                            cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
                        }
                        else
                        {
                            break; // Salir del bucle si la entrada es un numero entero valido
                        }
                    }
                    filtro.setAnio(anio);
                    for (int i = 0; i < pp.contarRegistros(); i++)
                    {
                        p = pp.leerRegistro(i);
                        if (p.getFecha().getAnio() == filtro.getAnio())
                        {
                            p.mostrar();
                        }
                    }
                    system("pause");
                    break;

                case 2: // Filtrar por anio y mes
                    rlutil::cls();

                    while (true)
                    {
                        cout << "INGRESE ANIO: ";
                        cin >> anio;

                        if (cin.fail()) // Verifica si la entrada es un numero entero
                        {
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                            cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
                        }
                        else
                        {
                            break; // Salir del bucle si la entrada es un numero entero valido
                        }
                    }
                    filtro.setAnio(anio);
                    cout<<endl;

                    while (true)
                    {
                        cout << "INGRESE MES: ";
                        cin >> mes;

                        if (cin.fail())   // Verifica si la entrada es un numero entero
                        {
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada incorrecta
                            cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
                        }
                        else if (mes < 1 || mes > 12)
                        {
                            cout << "Mes invalido. Por favor, ingrese un valor entre 1 y 12." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    filtro.setMes(mes);
                    for (int i = 0; i < pp.contarRegistros(); i++)
                    {
                        p = pp.leerRegistro(i);
                        if (p.getFecha().getAnio() == filtro.getAnio() && p.getFecha().getMes() == filtro.getMes())
                        {
                            p.mostrar();
                        }
                    }
                    system("pause");
                    break;

                case 3:
                    verdadero = false;
                    break;

                default:
                    cout << "OPCION INVALIDA" << endl;
                    system("pause");
                    break;
                }
                rlutil::cls();
                break;

            default:
                break;
            }
        }
    }

    /// OPCION 12
    void crearArchivoCSV(const char* nombreArchivoBinario, const char* nombreArchivoCSV)
    {
        ArchivoCliente archi(nombreArchivoBinario);
        Cliente obj;
        int reg = archi.contarRegistros();

        ofstream archivoCSV(nombreArchivoCSV);

        if (!archivoCSV.is_open())
        {
            cout << "No se pudo abrir el archivo " << nombreArchivoCSV << endl;
            return;
        }

        // Escribir la cabecera
        archivoCSV << "Nombre,Apellido,DNI,Estado,Disciplina,Fecha de Ingreso,Creditos\n";

        for (int i = 0; i < reg; i++)
        {
            obj = archi.leerRegistro(i);

            // Escribir los datos de los clientes en el archivo CSV
            archivoCSV << obj.getPersona().getNombre() << ","
                       << obj.getPersona().getApellido() << ","
                       << obj.getPersona().getDni() << ","
                       << (obj.getEstado() ? "activo" : "inactivo") << ","
                       << obj.getDisciplina().getNombre() << ","
                       << obj.getIngreso().toString() << ","
                       << obj.getCreditos() << "\n";
        }

        archivoCSV.close();
        cout << "Archivo CSV creado exitosamente: " << nombreArchivoCSV << endl;
    }
};
