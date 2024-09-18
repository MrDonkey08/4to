# Interpolación

Existen dos tipos de problema que se pueden considerar dentro de este concepto;
primero el problema de interpolación que involucra el encontrar valores
intermedios cuando estos están dados como un conjunto finito de datos y segundo,
el problema de aproximarse a una función dentro de un intérvalo, por medio de
una función simple (p. ej. un polinomio). La función aproximada debe ser capaz
de reducir el error de aproximación tanto como sea posible.

El proceso de Interpolación consiste en determinar un valor desconocido para una
función, el cual no se conoce, pero sí se conoce otros valores entre los que
queda comprendido el valor desconocido.

- **Interpolación gráfica:** Se colocan los puntos que representen los valores
  conocidos en un sistemas coordenado cartesiano; luego, se traza la curva que
  representa la función y se ubica el valor en el eje que le corresponde,
  trazando una línea perpendicular hacia los dos ejes.

- **Intepolación numérica:** Los métodos de **intepolación numérica** son
  - Polinomial Simple
  - Lagrange
  - Newton
    - Diferencias divididas
    - Diferencias finitas

## Interpolación Polinomial Simple

Sin alcanzar una precisión absoluta, generalmente es mucho mayor que la obtenida
graficamente y es suficiente para la gran mayoría de los problemas prácticos. El
**algoritmo** es el siguiente

1. Se supone una función para representar los datos (un polinomio de grado $m$)
2. Se selecciona un conjunto de puntos conocidos cercanos al desconocido. El
   grado del polinomio es el número de puntos - 1, es decir, para un polinomio
   de grado uno, se requieren dos puntos, para el grado dos, tres puntos, etc.
3. Se sustituyen los datos en el polinomio, obteniendo así un **sistema de
   ecuaciones** que puede resolverse por cualquier método.
4. Se sustituyen el valor de las constantes en el polinomio supuesto y el valor
   para obtener el resultado

$$P_n(x) = a_0 + a_1x + a_2x^2 + \cdots + a_{n}x^{n}$$

### Ejemplo 1

Se requiere conocer la densidad del agua a 43.7 °C y se tienen los siguientes
datos:

|   1 °C   |  4  |    6    |   10    |   20    |   50    |   75    |   100   |
| :------: | :-: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
| Densidad |  1  | 0.99997 | 0.99993 | 0.99823 | 0.98807 | 0.97489 | 0.95838 |

1. Polinomio de grado 1 (2 pts)

$$
\begin{array}{c}
y = a_0 + a_1x \\\\
(20, 0.99823) \\\\
(50, 0.98807)
\end{array}
$$

$$
\begin{array}{c}
0.99823 = a_0 + a_1(20) \\\\
0.98807 = a_0 + a_1(50) \\\\
a_0 = 1.005, 0.00034
\end{array}
$$

<!--

| 1 20 | 0.99823 |
| ---- | ------- |
|      |         |

-->

$$
\begin{array}{l}
y = 1.005 - 0.00034x \tag{polonimio interpolador} \\
y = 1.005 - 0.0034 (4.37) = 0.99014
\end{array}
$$

Por lo tanto una temperatura de 43.7 °C se tiene una densidad de 0.99014

> [!SUCCESS] Respuesta
>
> $$y(43.7) = 0.99014$$

### Ejemplo 2

Polinomio grado 2: (3 pts) ->

$$
\begin{array}{c}
y = a_0 + a_1x + a_2x^2 \\\\
(20, 0.99823) \\\\
(50, 0.98807) \\\\
(75, 0.97489) \\\\
\end{array}
$$

$$
\begin{cases}
a_0 &+& 20a_1 &+& 20^2a_2 &=& 0.99823 \\
a_0 &+& 50a_1 &+& 50^2a_2 &=& 0.98807 \\
a_0 &+& 75a_1 &+& 75^2a_2 &=& 0.97489 \\
\end{cases}
$$

$$
\begin{array}{c} \\
(a_0, a_1, a_2) = (1.00158, -0.00010, 0) \\\\
y = 1.00158 - 0.0010x \\\\
\end{array}
$$

> [!SUCCESS] Respuesta
>
> $$y(43.7) = 0.99721$$

### Ejemplo 3

Polinomio grado 2: (3 pts) ->

$$
\begin{array}{c}
y = a_0 + a_1x + a_2x^2 \\\\
(10, 0.99997) \\\\\
(20, 0.98823) \\\\
(50, 0.98807)
\end{array}
$$

$$
\begin{cases}
a_0 &+& 10a_1 &+& 10^2a_2 &=& 0.99997 \\
a_0 &+& 20a_1 &+& 20^2a_2 &=& 0.99823 \\
a_0 &+& 50_a1 &+& 50^2a_2 &=& 0.98807
\end{cases}
$$

$$
\begin{array}{c}
y = (a_0, a_1, a_2) = (1.00089, -0.00005, -0.00004) \\\\
y = 1.00029 - 0.00001x \\\\
\end{array}
$$

> [!SUCCESS] Respuesta
>
> $$y(43.7) = 0.99985$$
