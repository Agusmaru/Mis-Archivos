<?php
$nombre = $_POST['nombre'];
$usuario = $_POST['usuario'];
$password = $_POST['password'];
$dni = $_POST['dni'];


$conexion=mysqli_connect("localhost","root","","php_login_database");
  //Se realiza la consulta Mysql
$query = "INSERT INTO users(Nombre, DNI, email, password) VALUES('$nombre', '$dni', '$usuario', '$password')";
$result = mysqli_query($conexion, $query);

if(!$result){
  echo "No se inserto!";
}
else{
    header("location:home.php");
}
 ?>
