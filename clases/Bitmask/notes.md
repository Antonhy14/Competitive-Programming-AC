# Bitmask o Máscara de bits

Bitmask es una secuencia de bits que puede ser utilizada para manipular y examinar partes específicas de datos binarios.

## Bits
Un bit es el dato más fundamental de los lenguajes de programación. Cualquier otro dato tiene una representación en binario, es decir, que cualquier dato se puede transformar a $0$'s y $1$'s.

Los bits tienen solo dos estados.

**0**: bit apagado.
**1**: bit encendido.

## Operaciones

Los bits tiene operaciones especificas que podemos usar para hacer ciertas cosas.

* AND (&): 
* OR (|): Se utiliza para establecer bits específicos en un número.
* XOR (^): Se utiliza para invertir bits específicos.
* NOT (\~): Se utiliza para invertir todos los bits.
* Desplazamiento de bits (<< y >>): 

## And(&)

Con and(&) podemos saber si un bit está encendido.

## Desplazamiento de bits.

**x << y**: el bit $x$ se recorre $y$ bits $0$ a la izquierda.
Por ejemplo: 1 << 5 sería igual a 100000

**x >> y**: el bit $x$ se recorre $y$ bits $0$ a la derecha.
Por ejemplo: 100000 >> 5 sería igual a 1