<?php //Apertura del codigo php
session_start(); //inicio de sesesion con la funcion "session_start"
  $user=$_SESSION['user']; //almacenamos en la variable "$user" lo ingresado en "user" de "login.php"

  echo"Bienvenido ".$user."<p></p>"; // le damos la bienvenida al usuario "$user"

$conexion=mysqli_connect("localhost","root","","php_login_database");/*establecemos la conexion con la base de datos y la almacenamos
en la variable "$conexion" mediante la funcion mysqli_connect */
$query = 'SELECT*FROM users';/*declaramos una consulta a la  base de datos en la cual
se requeriran los datos datos de la tabla "users" y la almacenamos en una variable llamada "$query" */


$result = mysqli_query($conexion, $query);/*realizamos mediante "mysqli_query" consultas a la base de datos mediante las variables
$conexion y $query y almacenamos este resultado en la variable "$result" */
 ?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>NUEVO USUARIO</title> <! –– Definimos el titulo de nuestra pagina como "NUEVO USUARIO"––>
    <link rel="stylesheet" href="estilos/estilos.css"> <! –– importamos los estilos css de nuestra pagina ––>

  </head>
  <body background="#ff0000">

                <?php require 'header1.html' ?> <! –– Requerimos el header desde "header1.html"––>
                <div class="principal"><! –– creamos un div de clase "principal" donde estara alojado el principal contenido
                  de nuestra página––>

<! ––                     INGRESAR DATOS NUEVOS           ––>
                    <div class="datos"> <! –– div de clase "datos" en el que estara todo el codigo de nuestra tabla de usuarios ––>
                      <h1>Ingrese Datos</h1><! –– Definimos el titulo de nuestro div de clase datos como "Ingrese Datos" ––>
                      <form action="metadatosNuevo.php" method="POST"> <! –– Enviamos con la etiqueta form a metadatosNuevo.php
                        los datos que vayamos a ingresar en los siguientes "input"––>
                        <p>Nombre</p><! –– Indicamos mediante un elemento P que se debe ingresar el nombre del nuevo usuario en el
                        proximo input––>
                        <input type="text" class="field" name="nombre"> <! –– input en el que se almacenara el nombre como "nombre"––>
                        <p>Usuario</p><! –– Indicamos mediante un elemento P que se debe ingresar el mail del nuevo usuario en el
                        proximo input––>
                        <input type="text" class="field" name="usuario"> <! –– input en el que se almacenara el mail como "usuario"––>
                        <p>Password</p><! –– Indicamos mediante un elemento P que se debe ingresar la contraseña del nuevo usuario en
                        proximo el input––>
                        <input type="password" class="field" name="password"> <! –– input en el que se almacenara la contraseña
                         como "password"––>
                        <p>D.N.I</p><! –– Indicamos mediante un elemento P que se debe ingresar el DNI del nuevo usuario en el
                        proximo input––>
                        <input type="text" class="field" name="dni"> <! –– input en el que se almacenara el D.N.I como "dni"––>
                        <p></p>
                        <input type="submit" class="boton" value="Enviar"> <! –– input de tipo submit que funcionara como boton para
                        enviar nuestros datos anteriormente cargados a la base de datos––>
                      </form> <! –– fin del form que enviara los datos de un nuevo usuario a la base de datos––>
                    </div>

                </div>
  </body>
</html>
