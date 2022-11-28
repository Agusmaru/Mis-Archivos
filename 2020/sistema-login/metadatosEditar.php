<?php //Apertura del codigo php
$id = $_POST['id']; //asignamos a la variable $id el valor de "id" obtenido del metodo POST
$nombre = $_POST['nombre']; //asignamos a la variable $nombre el valor de "nombre" obtenido del metodo POST
$usuario = $_POST['usuario']; //asignamos a la variable $usuario el valor de "usuario" obtenido del metodo POST
$password = $_POST['password']; //asignamos a la variable $password el valor de "password" obtenido del metodo POST
$dni = $_POST['dni']; //asignamos a la variable $dni el valor de "dni" obtenido del metodo POST


$conexion=mysqli_connect("localhost","root","","php_login_database");/*establecemos la conexion con la base de datos y la almacenamos
en la variable "$conexion" mediante la funcion mysqli_connect */
$query = "UPDATE users set Nombre='$nombre', DNI='$dni', email='$usuario', password='$password' where id like $id"; /*declaramos una
consulta a la  base de datos en la cual se editaran los datos "Nombre, DNI, email, password" obtenidos de las variables previamente
cargadas con la funcion sql "UPDATE". Esta consulta sera almacenada en la variable "$query" */
$result = mysqli_query($conexion, $query); /*realizamos mediante "mysqli_query" consultas a la base de datos mediante las variables
$conexion y $consulta y almacenamos este resultado en la variable "$resultado" */

if(!$result){ //La sentencia IF se cumplira en caso de que $result sea erroneo
  echo "No se actualizo!"; //Imprimiremos en pantalla con echo "No se actualizo!"
} //cierre del if
else{ //apertura del else
    header("location:home.php"); //redireccionaremos a "home.php" donde se veran los datos actualizados
} //cierre del else
 ?>
