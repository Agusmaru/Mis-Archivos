<?php
session_start();
$user=$_POST['user'];
$password=$_POST['password'];



$conexion=mysqli_connect("localhost","root","","php_login_database");

$consulta="SELECT*FROM users where email='$user' and password='$password'";
$resultado=mysqli_query($conexion,$consulta);

$filas=mysqli_num_rows($resultado);

if($filas){
  $_SESSION['user']=$user;
  $_SESSION['password']=$password;
  header("location:home.php");

}
else{
  ?>
  <?php
  include("login.php");
  ?>
  <h1 class="bad">ERROR EN LA AUTENTIFICACION</h1>
  <?php
}
?>
