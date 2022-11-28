<?php //apertura de codigo php
session_start(); //inicio de sesion
  $user=$_SESSION['user']; //sesion iniciada segun dicte $_SESSION['user']

  echo"Bienvenido ".$user."<p></p>"; // le damos la bienvenida al usuario "$user"

$conexion=mysqli_connect("localhost","root","","php_login_database"); /*establecemos la conexion con la base de datos y la almacenamos
en la variable "$conexion" mediante la funcion mysqli_connect */
$query = 'SELECT*FROM users'; /*declaramos una consulta a la  base de datos en la cual
se requeriran los datos datos de la tabla "users" y la almacenamos en una variable llamada "$query" */
$result = mysqli_query($conexion, $query); /*realizamos mediante "mysqli_query" consultas a la base de datos mediante las variables
$conexion y $query y almacenamos este resultado en la variable "$result" */

 ?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>TABLA USUARIOS</title><! –– Definimos el titulo de nuestra pagina como "TABLA USUARIOS"––>
    <link rel="stylesheet" href="estilos/estilos.css"><! –– importamos los estilos css de nuestra pagina ––>

  </head>
  <body background="#ff0000">

    <?php require 'header1.html' ?> <! –– requerimos a traves de codigo php el header de nuestra pagina llamado
    "header1.html" ––>

                  <! ––              BUSCADOR                     ––>
                      <div class="buscar"> <! –– creamos un div de clase "buscar" que tendra dentro todo el codigo de nuestro buscador––>
                        <form action="buscar.php" method="post"> <! –– creamos un form el cual enviara los datos ingresados a "buscar.php" ––>
                          <p>Buscador</p> <! –– mostramos con un <p "Buscar" en pantalla––>
                          <input type="text" class="field" name="buscar"><! –– creamos un input de tipo text en el que ingresaremos los
                          Usuarios que deseamos buscar de nuestra tabla ––>
                          <input type="submit" class="boton" value="buscar"> <! –– creamos un input de tipo submit que funcionara como
                          boton para nuestro buscador ––>
                        </form> <! –– cierre del form––>
                      </div> <! –– cierre de nustro div de clase "buscar" ––>


                <div class="principal"><! –– creamos un div de clase "principal" donde estara alojado el principal contenido
                  de nuestra página––>

<! ––                     TABLA PARA MOSTRAR DATOS DE LA BD           ––>
                      <div class="tabla"> <! –– div de clase "tabla" en el que estara todo el codigo de nuestra tabla de usuarios ––>
                        <table> <! –– Creacion de la tabla––>
                              <thead> <! –– en el thead encontraemos todos los campos TH que conformaran la cabecera de la tabla ––>
                              <th>ID</th>
                              <th>Nombre</th>
                              <th>Usuario</th>
                              <th>DNI</th>
                              <th>Opciones</th>
                              <th>Cosas nuevas que mostraria</th>
                            </thead><! –– fin del thead––>
                            <tbody> <! –– creacion del tbody en el que se encontrara todo el codigo que muestra los datos
                              de los distintos usuarios de la base de datos ––>
                               <?php
                                  while($row=mysqli_fetch_array($result)){ /*ciclo while en el cual mostramos el contenido
                                    de la tabla users de nuestra base de datos */
                                 ?>
                                 <tr><! –– tr que contiene los td que mostraran la informacion de los datos requeridos de nuestra bd––>
                                    <td><?php echo $row['id'] ?></td> <! –– td en el cual se mostrara el id de un usuario––>
                                    <td><?php echo $row['Nombre'] ?></td><! –– td en el cual se mostrara el nombre de un usuario––>
                                    <td><?php echo $row['email'] ?></td><! –– td en el cual se mostrara el email de un usuario––>
                                    <td><?php echo $row['DNI'] ?></td><! –– td en el cual se mostrara el DNI de un usuario––>
                                        <td>
                                          <a href="editar.php?
                                          id=<?php echo $row['id'] ?> &
                                          nombre=<?php echo $row['Nombre'] ?> &
                                          email=<?php echo $row['email'] ?> &
                                          dni=<?php echo $row['DNI'] ?>
                                          "><img src="img/editar.png" height="20px"></a>
                                          <a href="mostrardatos.php"><img src="img/ver.png" height="20px"></a>
                                          <a href="eliminar.php? id=<?php echo $row['id'] ?>"><img src="img/eliminar.png" height="20px"></a>
                                        </td><! –– td que contiene los botones "editar, mostrar mas datos y eliminar" los cuales
                                        son un enlace que nos llevan a realizar cada funcion segun cada boton––>
                                        <td>Check</td> <! –– td en el cual se mostraria los datos adicionales––>
                                     </tr><! –– cierre del tr ––>
                                 <?php
                                    }
                                  ?>
                            </tbody>
                      </table>
                    </div>
                </div>
  </body>
</html>
