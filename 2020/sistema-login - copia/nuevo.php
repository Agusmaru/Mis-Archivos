<?php
session_start();
  $user=$_SESSION['user'];

  echo"Bienvenido ".$user."<p></p>";

$conexion=mysqli_connect("localhost","root","","php_login_database");
  //Se realiza la consulta Mysql
$query = 'SELECT*FROM users';

$result = mysqli_query($conexion, $query);



 ?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>TABLA USUARIOS</title>
    <link rel="stylesheet" href="estilos/estilos.css">

  </head>
  <body background="#ff0000">

                <?php require 'header1.html' ?>
                <div class="principal">

<! ––                     INGRESAR DATOS NUEVOS           ––>
                    <div class="datos">
                      <h1>Ingrese Datos</h1>
                      <form action="metadatosNuevo.php" method="POST">
                        <p>Nombre</p>
                        <input type="text" class="field" name="nombre">
                        <p>Usuario</p>
                        <input type="text" class="field" name="usuario">
                        <p>Password</p>
                        <input type="password" class="field" name="password">
                        <p>D.N.I</p>
                        <input type="text" class="field" name="dni">
                        <p></p>
                        <input type="submit" class="boton" value="Enviar">
                      </form>
                    </div>

                </div>
  </body>
</html>
