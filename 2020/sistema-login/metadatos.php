<?php //Apertura del codigo php
session_start(); //inicio de sesesion con la funcion "session_start"
$user=$_POST['user']; //almacenamos en la variable "$user" lo ingresado en "user" de "login.php"
$password=$_POST['password']; //almacenamos en la variable "$password" lo ingresado en "password" de "login.php"



$conexion=mysqli_connect("localhost","root","","php_login_database"); /*establecemos la conexion con la base de datos y la almacenamos
en la variable "$conexion" mediante la funcion mysqli_connect */

$consulta="SELECT*FROM users where email='$user' and password='$password'"; /*declaramos una consulta a la  base de datos en la cual
se requeriran los datos datos de "email" y "password" y la almacenamos en una variable llamada "$consulta" */
$resultado=mysqli_query($conexion,$consulta); /*realizamos mediante "mysqli_query" consultas a la base de datos mediante las variables
$conexion y $consulta y almacenamos este resultado en la variable "$resultado" */

$filas=mysqli_num_rows($resultado); /*mediante la funcion mysqli_num_rows almacenamos en la variable "$filas" que fila se a de utilizar
 como resultado de "$resultado" */
if($filas){ //en el caso de que $filas sea verdadero se ejecutara lo siguiente
  $_SESSION['user']=$user; // guardamos en nuestra sesion el valor de $user
  $_SESSION['password']=$password; //guardamos en nuestra sesion el valor de $password
  header("location:home.php"); //redireccionamos a "home.php"

} //cierre del if
else{ //apertura del else
  ?>
  <?php
  include("login.php"); //redireccionamiento a "login.php"
  ?>
  <h1 class="bad">ERROR EN LA AUTENTIFICACION</h1> <! –– se devuelve ademas del refresco de pantalla el mensaje de
  ERROR DE AUTENTIFICACION ––>
  <?php
}
?> <! –– cierre de php ––>
