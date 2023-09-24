# Métodos para la Solución de Sistemas de Ecuaciones Lineales

Tenemos dos métodos iterativos:

- Método de Jacobi
- Método de Gausts-Seidel

Para ambos métodos se deben ordenar las ecuaciones e incógnitas de forma que se obtenga **predominio diagonal**, que cada elemento de la diagonal $a_{ij}$ sea superior **en valor absoluto**, que las magnitudes del resto de los elementos en la fila $i$ y la fila $j$.

## Ejemplo

Resolver el siguiente **sistema de ecuaciones lineales** con el vector inicial $x_0 = (1, 1, 1)$ y $ε = 0.005$

$$\begin{cases}
4x_1 &+& 2x_2 &+&  x_3 &=& 11 \\
-x_1 &+& 2x_2 & &      &=& 3 \\
2x_1 &+&  x_2 &+& 4x_3 &=& 16
\end{cases}$$

Despejando:

$$\begin{eqnarray}
x_1 &=& \cfrac{11 - 2x_2 - x_3}{4} \\
x_2 &=& \cfrac{3+x_1}{2} \\
x_3 &=& \cfrac{16 - 2x_1 - x_2}{4}
\end{eqnarray}$$
### Método de Jacobi

En este método se evalua las ecuaciones encontradas con el vector inicial y en cada iteración se remplazan las incógnitas por los valores previamente encontrados

|  n  |  $x_1$  |  $x_2$  |  $x_3$  |     |  $ε_1$  |  $ε_2$  |  $ε_3$  |
|:---:|:-------:|:-------:|:-------:|:---:|:-------:|:-------:|:-------:|
|  1  |    2    |    2    |  3.25   |     |    -    |    -    |    -    |
|  2  | 0.9375  |   2.5   |   2.5   |     | 1.0625  |   0.5   |  0.75   |
|  3  |  0.875  | 1.96875 | 2.90625 |     | 0.0625  | 0.53125 | 0.40625 |
|  4  | 1.03906 | 1.9375  | 3.07031 |     | 0.16406 | 0.03125 | 0.16406 |
|  5  | 1.01367 | 2.01953 | 2.99609 |     | 0.02539 | 0.08203 | 0.07422 |
|  6  | 0.99121 | 2.00684 | 2.98828 |     | 0.02246 | 0.01270 | 0.00781 |
|  7  | 0.99951 | 1.99561 | 3.00269 |     | 0.00830 | 0.01123 | 0.01440 |
|  8  | 1.00153 | 1.99976 | 3.00134 |     | 0.00201 | 0.00415 | 0.00134        |


> [!SUCCESS] Respuesta
> 
>$$(x_1, x_2, x_3) \approx (1.00153, 1.99976, 3.00134)$$
### Método de Gauss-Seidel

En este método, a diferencia del de Jacobi, se remplaza los valores encontrados en la misma iteración, es decir, al encontrar $x_n$ se remplaza en las siguientes ecuaciones.

> [!NOTE]
> 
> Este método es más rápido que el de Jacobi

|  n  |  $x_1$  |  $x_2$  |  $x_3$  |     |  $ε_1$  |  $ε_2$  |  $ε_3$  |
|:---:|:-------:|:-------:|:-------:|:---:|:-------:|:-------:|:-------:|
|  1  |    2    |   2.5   |  2.375  |     |    -    |    -    |    -    |
|  2  | 0.90625 | 1.95313 | 3.05859 |     | 1.09375 | 0.54687 | 0.68359 |
|  3  | 1.00879 | 2.00439 | 2.99451 |     | 0.10521 | 0.05126 | 0.06408 |
|  4  | 0.99918 | 1.99959 | 3.00051 |     | 0.00961 | 0.00480 | 0.00600 |
|  5  | 1.00008 | 2.00004 | 2.99995 |     | 0.00090 | 0.00045 | 0.00056 |

> [!SUCCESS] Respuesta
> 
>$$(x_1, x_2, x_3) \approx ( 1.00008, 2.00004, 2.99995)$$
