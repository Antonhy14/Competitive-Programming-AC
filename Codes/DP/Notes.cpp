# PROGRAMACIÓN DINÁMICA(DP)

La programación dinámica se usa en casos en cuáles podemos eligir entre una serie de decisiones pero no sabemos cual es la mejor, así que probamos todas y almacenamos la mejor.
Y para esto, dividimos el problema principal en otros subproblemas.
Los subproblemas se repiten, así que para aprovechar las demás caracteristicas, vamos guardando lo mejor que podemos obtener en cada subtarea, para que no tengamos que recalcular cosas que ya hemos hecho.

## ESTRUCTURA DE LA DP

* Analizar el problema, y determinar como podemos divirlo en casos más pequeños.
* Definir cuales serán los subproblemas que podemos resolver directamente o cuando ya no podemos dividir más un problema, es decir, los casos base.
* Definir que guardaremos en la resolución de cada tarea.
* Definir los estados/transiciones que podemos hacer para generar los subproblemas.
* Preguntar si el estado actual ya lo hicimos.

## IMPLEMENTACIÓN
* Top-Down: Empieza por los problemas más grandes, los divide, resuelve esos subproblemas y regresa las respuestas. **Recursión & Memorización**
* Bottom-Up: Empieza por los subproblemas que ya podemos resolver y va resolviendo los más grandes. **Iterativas**

## DIFERENCIAS

|  Top-Down                           |  Bottom-Up                                   |
|-------------------------------------|----------------------------------------------|
|Solo hace los estados que ocupa.     |Prueba todos los casos.                       |
|Es más intuitiva.                    |Llega a ser más confusa.                      |
|Puede haber desbordamiento.          |No hay sobrecarga.                            |
|Puede ser más lenta.                 |Tiene mejores tiempos.                        |
|Puede ocupas más espacio.            |Ocupa solo hasta el caso máximo.              |
|Se puede pasar a Bottom-Up.          |Tal vez no exista manera de pasar a Top-Down. |
