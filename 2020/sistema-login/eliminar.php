<?php //Apertura del codigo php
$id = $_GET['id']; //asignamos a la variable $id el valor de "id" obtenido del metodo GET 

$conexion=mysqli_connect("localhost","root","","php_login_database"); /*establecemos la conexion con la base de datos
y la almacenamos en la variable "$conexion" mediante la funcion mysqli_connect */
$query = "DELETE FROM users where id like $id"; /*declaramos una consulta a la base de datos en la cual se eliminara
el usuario obtenido de la variable $id */
$result = mysqli_query($conexion, $query);/*realizamos mediante "mysqli_query" consultas a la base de datos mediante
las variables $conexion y $query y almacenamos este resultado en la variable "$result" */

if(!$result){ //en el caso de que $result sea falso se ejecutara lo siguiente
  echo "No se elimino!"; //se mostrara en pantalla con echo "No se elimino"
}
else{ //caso contrario y se cumpla $result se ejectura el else
    header("location:home.php"); //se redireccionara a "home.php"
}
 ?>
