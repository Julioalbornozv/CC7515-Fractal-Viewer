# Tarea 3 Curso CC7515-1 Computación en GPU

<p float="left">
  <img src="https://raw.githubusercontent.com/Julioalbornozv/CC7515-Fractal-Viewer/master/img/img_1.png" width=450/>
  <img src="https://raw.githubusercontent.com/Julioalbornozv/CC7515-Fractal-Viewer/master/img/img_2.png" width=454/>
</p>

## Compilación

El proyecto es compilado a través del comando `make install`. Este programa fue compilado con g++ utilizando las librerias glew32, glfw y glm.

## Utilizacion
Ejecutando el programa `fractal_viewer.exe`, se listaran diferentes sets de julia para renderizar, seleccione una de ellas esribiendo el numero de la entrada y apretar `Enter`.

El visualizador permite la modificacion de diferentes parametros (cte Julia, R, Nro iteraciones, colores). Una de estos parametros aparecera en consola con su valor actual, presionando las flechas derecha e izquierda se puede modificar el valor mostrado en consola, mientras que apretando los botones `q` o `e` se cambia el parametro a modificar.

El visor tambien permite hacer zoom solo al centro de la pantalla haciendo click en el display (click derecho para deshacer).
