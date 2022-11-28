<?php //Apertura del codigo php
$nombre = $_POST['nombre']; //almacenamos en la variable "$nombre" lo ingresado en "nombre" de "nuevo.php"
$usuario = $_POST['usuario']; //almacenamos en la variable "$usuario" lo ingresado en "usuario" de "nuevo.php"
$password = $_POST['password']; //almacenamos en la variable "$password" lo ingresado en "password" de "nuevo.php"
$dni = $_POST['dni']; //almacenamos en la variable "$dni" lo ingresado en "dni" de "nuevo.php"


$conexion=mysqli_connect("localhost","root","","php_login_database"); /*establecemos la conexion con la base de datos y la almacenamos
en la variable "$conexion" mediante la funcion mysqli_connect */
$query = "INSERT INTO users(Nombre, DNI, email, password) VALUES('$nombre', '$dni', '$usuario', '$password')"; /*declaramos una
consulta a la  base de datos en la cual se ingresaran los datos "Nombre, DNI, email, password" obtenidos de las variables previamente
cargadas con la funcion sql "INSERT INTO". Esta consulta sera almacenada en la variable "$query" */

$result = mysqli_query($conexion, $query); /*realizamos mediante "mysqli_query" consultas a la base de datos mediante las variables
$conexion y $consulta y almacenamos este resultado en la variable "$resultado" */

if(!$result){ //if que se cumplira si $result es falso
  echo "No se inserto!"; //en caso de cumplirse esta sentencia if se imprimira en pantalla con echo "No se inserto"
} //fin del if
else{ //Caso contrario de que $result sea verdadera
    header("location:home.php"); // nos redireccionara a "home.php" y deberiamos de visualizar en la tabla el nuevo usuario ingresado
} //fin del else
 ?>
