<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>TABLA USUARIOS</title>
    <link rel="stylesheet" href="estilos/estilos.css">

  </head>
  <body background="#ff0000">

                <?php require 'header1.html';
                $id = $_GET['id'];
                $nombre = $_GET['nombre'];
                $email = $_GET['email'];
                $dni = $_GET['dni'];
?>
                <div class="principal">

<! ––                     INGRESAR DATOS NUEVOS           ––>
                    <div class="datos">
                      <h1>Ingrese Datos</h1>
                      <form action="metadatosEditar.php" method="POST">
                        <p>ID</p>
                        <input type="text" class="field" name="id" style="visibility:hidden" value="<?=$id?>">
                        <p>Nombre</p>
                        <input type="text" class="field" name="nombre" value="<?=$nombre?>">
                        <p>Usuario</p>
                        <input type="text" class="field" name="usuario" value="<?=$email?>">
                        <p>Password</p>
                        <input type="password" class="field" name="password">
                        <p>D.N.I</p>
                        <input type="text" class="field" name="dni" value="<?=$dni?>">
                        <p></p>
                        <input type="submit" class="boton" value="Actualizar">
                        <a href="home.php">Cancelar</a>
                      </form>
                    </div>
                    </div>
                  </body>
                </html>
