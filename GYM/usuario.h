#ifndef USUARIOARCHIVO_H_INCLUDED
#define USUARIOARCHIVO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Usuario
{
private:
    char nombre[30];
    char contrasenia[30];
    int jerarquia;

public:
    Usuario(const char* n = "", const char* c = "", int j = 1)
    {
        strcpy(nombre, n);
        strcpy(contrasenia, c);
        jerarquia = j;
    }

    // Getters
    const char* getNombre() const
    {
        return nombre;
    }
    const char* getContrasenia() const
    {
        return contrasenia;
    }
    int getJerarquia() const
    {
        return jerarquia;
    }

    // Setters
    void setNombre(const char* n)
    {
        strcpy(nombre, n);
    }
    void setContrasenia(const char* c)
    {
        strcpy(contrasenia, c);
    }
    void setJerarquia(int j)
    {
        jerarquia = j;
    }
};

class ArchivoUsuario
{
private:
    char nombreArchivo[30];

public:
    ArchivoUsuario(const char* n)
    {
        strcpy(nombreArchivo, n);
        // Verificar y crear el archivo si no existe
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo)
        {
            ofstream crearArchivo(nombreArchivo, ios::binary);
            if (!crearArchivo)
            {
                cerr << "Error al crear el archivo " << nombreArchivo << endl;
            }
            else
            {
                cout << "Archivo " << nombreArchivo << " creado exitosamente." << endl;
                crearArchivo.close();
            }
        }
        archivo.close();
    }

    // Metodos para operaciones basicas con el archivo
    Usuario leerRegistro(int pos)
    {
        Usuario reg;
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
            return reg;
        }
        archivo.seekg(pos * sizeof(reg));
        archivo.read(reinterpret_cast<char*>(&reg), sizeof(reg));
        archivo.close();
        return reg;
    }

    int contarRegistros()
    {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
            return -1;
        }
        archivo.seekg(0, ios::end);
        int cant = archivo.tellg() / sizeof(Usuario);
        archivo.close();
        return cant;
    }

    bool grabarRegistro(Usuario reg)
    {
        ofstream archivo(nombreArchivo, ios::binary | ios::app);
        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
            return false;
        }
        archivo.write(reinterpret_cast<const char*>(&reg), sizeof(reg));
        archivo.close();
        return true;
    }

    bool modificarRegistro(Usuario obj, int pos)
    {
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
            return false;
        }
        archivo.seekp(pos * sizeof(obj));
        archivo.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
        archivo.close();
        return true;
    }

    int buscarRegistroPorNombre(const char* nombreBuscado)
    {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
            return -1;
        }

        Usuario obj;
        int pos = 0;
        while (archivo.read(reinterpret_cast<char*>(&obj), sizeof(obj)))
        {
            if (strcmp(obj.getNombre(), nombreBuscado) == 0)
            {
                archivo.close();
                return pos;
            }
            pos++;
        }

        archivo.close();
        return -2;
    }

    bool eliminarRegistroPorNombre(const char* nombreBuscado)
    {
        ifstream archivoEntrada(nombreArchivo, ios::binary);
        if (!archivoEntrada)
        {
            cerr << "Error al abrir el archivo." << endl;
            return false;
        }

        ofstream archivoSalida("temp.dat", ios::binary);
        if (!archivoSalida)
        {
            cerr << "Error al abrir el archivo temporal." << endl;
            archivoEntrada.close();
            return false;
        }

        Usuario obj;
        bool eliminado = false;

        while (archivoEntrada.read(reinterpret_cast<char*>(&obj), sizeof(obj)))
        {
            if (strcmp(obj.getNombre(), nombreBuscado) != 0)
            {
                archivoSalida.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
            }
            else
            {
                eliminado = true;
            }
        }

        archivoEntrada.close();
        archivoSalida.close();

        remove(nombreArchivo);
        rename("temp.dat", nombreArchivo);

        return eliminado;
    }

    // Funcion para ingresar un nuevo usuario y añadirlo al archivo
    void ingresarUsuario()
    {
        char nombre[30];
        char contrasenia[30];
        int jerarquia;

        cout << "Ingrese el nombre del usuario: ";
        cin >> nombre;
        cout << "Ingrese la contrasenia del usuario: ";
        cin >> contrasenia;
        cout << "Ingrese la jerarquia del usuario (1 o 2): ";
        cin >> jerarquia;

        Usuario nuevoUsuario(nombre, contrasenia, jerarquia);

        if (grabarRegistro(nuevoUsuario))
        {
            cout << "Usuario agregado exitosamente." << endl;
        }
        else
        {
            cout << "Error al agregar el usuario." << endl;
        }
    }

    // Funcion para eliminar un usuario por nombre
    void eliminarUsuarioPorNombre()
    {
        char nombreBuscado[30];
        cout << "Ingrese el nombre del usuario a eliminar: ";
        cin >> nombreBuscado;

        if (eliminarRegistroPorNombre(nombreBuscado))
        {
            cout << "Usuario eliminado exitosamente." << endl;
        }
        else
        {
            cout << "Error al eliminar el usuario o usuario no encontrado." << endl;
        }
    }

    // Funcion para modificar la contraseña de un usuario por nombre
    void modificarContraseniaPorNombre()
    {
        char nombreBuscado[30];
        char nuevaContrasenia[30];

        cout << "Ingrese el nombre del usuario cuya contrasenia desea modificar: ";
        cin >> nombreBuscado;
        cout << "Ingrese la nueva contrasenia: ";
        cin >> nuevaContrasenia;

        int pos = buscarRegistroPorNombre(nombreBuscado);
        if (pos >= 0)
        {
            Usuario usuario = leerRegistro(pos);
            usuario.setContrasenia(nuevaContrasenia);

            if (modificarRegistro(usuario, pos))
            {
                cout << "Contrasenia modificada exitosamente." << endl;
            }
            else
            {
                cout << "Error al modificar la contrasenia." << endl;
            }
        }
        else
        {
            cout << "Usuario no encontrado." << endl;
        }
    }

    // Funcion para verificar la existencia de usuarios en el archivo
    Usuario verificarExistenciaUsuarios()
    {
        while (true)
        {
            int cantidad = contarRegistros();
            if (cantidad == 0)
            {
                cout << "No hay usuarios registrados. Creando uno nuevo..." << endl;
                ingresarUsuario();
                continue; // No salir del bucle, seguir verificando
            }
            else
            {
                char nombre[30];
                char contrasenia[30];

                cout << "Ingrese su nombre de usuario: ";
                cin >> nombre;
                cout << "Ingrese su contrasenia: ";
                cin >> contrasenia;

                int pos = buscarRegistroPorNombre(nombre);
                if (pos >= 0)
                {
                    Usuario usuario = leerRegistro(pos);
                    if (strcmp(usuario.getContrasenia(), contrasenia) == 0)
                    {
                        return usuario; // Retornar el usuario logueado
                    }
                    else
                    {
                        cout << "Contrasenia incorrecta. Intenta nuevamente." << endl;
                    }
                }
                else
                {
                    cout << "Usuario no encontrado. Intenta nuevamente." << endl;
                }
            }
        }
    }
};

#endif // USUARIOARCHIVO_H_INCLUDED
