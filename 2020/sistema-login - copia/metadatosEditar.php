<?php
$id = $_POST['id'];
$nombre = $_POST['nombre'];
$usuario = $_POST['usuario'];
$password = $_POST['password'];
$dni = $_POST['dni'];


$conexion=mysqli_connect("localhost","root","","php_login_database");
  //Se realiza la consulta Mysql
$query = "UPDATE users set Nombre='$nombre', DNI='$dni', email='$usuario', password='$password' where id like $id";
$result = mysqli_query($conexion, $query);

if(!$result){
  echo "No se actualizo!";
}
else{
    header("location:home.php");
}
 ?>
