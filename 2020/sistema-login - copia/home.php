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
                <div class="buscar">
                  <form action="buscar.php" method="post">
                    <p>Buscador</p>
                    <input type="text" class="field" name="buscar">
                    <input type="submit" class="boton" value="buscar">
                  </form>
                </div>
                <div class="principal">

<! ––                     TABLA PARA MOSTRAR DATOS DE LA BD           ––>
                    <div class="tabla">
                      <table>
                            <thead>
                              <th>ID</th>
                              <th>Nombre</th>
                              <th>Usuario</th>
                              <th>DNI</th>
                              <th>Opciones</th>
                            </thead>
                            <tbody>
                               <?php
                                  while($row=mysqli_fetch_array($result)){
                                 ?>
                                     <tr>
                                        <td><?php echo $row['id'] ?></td>
                                        <td><?php echo $row['Nombre'] ?></td>
                                        <td><?php echo $row['email'] ?></td>
                                        <td><?php echo $row['DNI'] ?></td>
                                        <td>
                                          <a href="editar.php?
                                          id=<?php echo $row['id'] ?> &
                                          nombre=<?php echo $row['Nombre'] ?> &
                                          email=<?php echo $row['email'] ?> &
                                          dni=<?php echo $row['DNI'] ?>
                                          "><img src="img/editar.png" height="20px"></a>
                                          <a href="mostrardatos.php"><img src="img/ver.png" height="20px"></a>
                                          <a href="eliminar.php? id=<?php echo $row['id'] ?>"><img src="img/eliminar.png" height="20px"></a>
                                        </td>
                                     </tr>
                                 <?php
                                    }
                                  ?>
                            </tbody>
                      </table>
                    </div>
                </div>
  </body>
</html>
