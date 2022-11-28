<!DOCTYPE html> <! –– "html" Es una instruccion especial que va al inicio de nuestro documento y permite que el navegador
entienda que version de html estamos usando––>
<html lang="en" dir="ltr"> <! –– Aqui definimos el idioma de nuestra pagina y El atributo global dir
es un atributo enumerado que indica la direccionalidad del texto de los elementos .  ––>
  <head> <! –– El elemento HTML "head" provee información general (metadatos) acerca del documento, incluyendo
    su título y enlaces a scripts y hojas de estilos. ––>
    <meta charset="utf-8"> <! –– El elemento meta con atributo charset en un documento HTML está el destinado a indicar la
    codificación de caracteres utilizada (charset). ––>
    <title>Login</title> <! –– El tag title (título) es un tag de código HTML que le permite darle un título a una página web. Este
    título se puede encontrar en la barra de título del navegador, así como en las páginas de resultados
     de los buscadores ––>
    <link rel="preconnect" href="https://fonts.googleapis.com"> <! –– importamos fuentes para nuestra pagina con "link"––>
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin> <! –– importamos fuentes para nuestra pagina con "link"––>
    <link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet"> <! –– importamos fuentes para nuestra
    pagina con "link"––>
    <link rel="stylesheet" href="estilos/style.css"> <! –– importamos estilos css para nuestra pagina con "link"––>
  </head> <! –– cierre del head––>
  <body> <! –– El elemento body de HTML representa el contenido de un documento HTML.
     Solo puede haber un elemento body en un documento. ––>

      <?php require 'header.php' ?> <! –– con codigo php llamamos al header a traves de  la funcion "require"––>

      <h1>Login</h1> <! –– h1 es una etiqueta usada para presentar un titulo, en este caso "Login" ––>

    <form action="metadatos.php" method="post"> <! –– Form es una etiqueta de HTML que representa un formulario. En este formulario
       se agregan los diferentes campos de entrada de datos o de confirmación, así como los botones, que como mínimo ha de
       haber uno,  el de envío. En este caso enviaremos los datos ingresados a metadatos.php ––>
      <input type="text" name="user" placeholder="Enter your mail"> <! –– creamos un input de tipo texto en el cual ingresaremos
      nuestro mail el cual sera captado como "user"––>
      <input type="password" name="password" placeholder="Enter your password"> <! –– creamos un input de tipo password en el cual
      ingresaremos nuestra contraseña y sera almacenada en "password" ––>
      <input type="submit" value="Send"> <! –– creamos un input de tipo submit el cual sera usado como boton para enviar nuestros
      datos ––>
    </form> <! –– cierre del form ––>

  </body> <! –– cierre del body ––>
</html> <! –– cierre del html––>
