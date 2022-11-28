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
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="/php-login/assets/css/style.css">
  </head>
  <body>

      <?php require 'header.php' ?>

      <h1>Login</h1>
      <span>or <a href="signup.php">SignUp </a></span>

    <form action="metadatos.php" method="post">
      <input type="text" name="user" placeholder="Enter your mail">
      <input type="password" name="password" placeholder="Enter your password">
      <input type="submit" value="Send">
      </form>

  </body>
</html>
