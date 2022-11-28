<?php
$id = $_GET['id'];

$conexion=mysqli_connect("localhost","root","","php_login_database");
  //Se realiza la consulta Mysql
$query = "DELETE FROM users where id like $id";
$result = mysqli_query($conexion, $query);

if(!$result){
  echo "No se elimino!";
}
else{
    header("location:home.php");
}
 ?>
