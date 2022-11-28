<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>EDITAR USUARIO</title> <! –– Definimos el titulo de nuestra pagina como "EDITAR USUARIO"––>
    <link rel="stylesheet" href="estilos/estilos.css">

  </head>
  <body background="#ff0000">

        <?php require 'header1.html'; //requerimos el header de "header1.html"
        $id = $_GET['id']; //asignamos a la variable $id el valor de "id" obtenido del metodo GET
        $nombre = $_GET['nombre']; //asignamos a la variable $nombre el valor de "nombre" obtenido del metodo GET
        $email = $_GET['email']; //asignamos a la variable $email el valor de "email" obtenido del metodo GET
        $dni = $_GET['dni']; //asignamos a la variable $dni el valor de "dni" obtenido del metodo GET
?>
                <div class="principal"><! –– creamos un div de clase "principal" donde estara alojado el principal contenido
                  de nuestra página––>

<! ––                     INGRESAR DATOS NUEVOS           ––>
                    <div class="datos"> <! –– div de clase "datos" en el que estara todo el codigo de nuestra tabla de usuarios ––>
                      <h1>Ingrese Datos</h1> <! –– Definimos el titulo de nuestro div de clase datos como "Ingrese Datos" ––>
                      <form action="metadatosEditar.php" method="POST"> <! –– Enviamos con la etiqueta form a metadatosEditar.php
                        los datos que vayamos a ingresar en los siguientes "input"––>
                        <p>ID</p> <! –– mostramos en pantalla "ID"––>
                        <input type="text" class="field" name="id" style="visibility:hidden" value="<?=$id?>"> <! –– Desabilitamos la edicion
                        de el ID para evitar errores ––>
                        <p>Nombre</p><! –– Indicamos mediante un elemento P que sebe ingresar el nombre del usuario en el
                        proximo input––>
                        <input type="text" class="field" name="nombre" value="<?=$nombre?>"> <! –– input en el que se almacenara el nombre como "nombre"––>
                        <p>Usuario</p><! –– Indicamos mediante un elemento P que sebe ingresar el mail del usuario en el
                        proximo input––>
                        <input type="text" class="field" name="usuario" value="<?=$email?>"> <! –– input en el que se almacenara el usuario como "usuario"––>
                        <p>Password</p><! –– Indicamos mediante un elemento P que sebe ingresar la contraseña del usuario en el
                        proximo input––>
                        <input type="password" class="field" name="password"> <! –– input en el que se almacenara la contraseña como "password"––>
                        <p>D.N.I</p><! –– Indicamos mediante un elemento P que sebe ingresar el DNI del usuario en el
                        proximo input––>
                        <input type="text" class="field" name="dni" value="<?=$dni?>"> <! –– input en el que se almacenara el dni como "dni"––>
                        <p></p>
                        <input type="submit" class="boton" value="Actualizar"><! –– input de tipo submit que funcionara como boton para
                        Actualizar nuestros datos anteriormente cargados a la base de datos––>
                        <a href="home.php">Cancelar</a> <! –– a href que funcionara como boton para cancelar la edicion de los datos––>
                      </form> <! –– fin del form que enviara los datos de un nuevo usuario a la base de datos––>
                    </div>
                    </div>
                  </body>
                </html>
