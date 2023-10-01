# Tarea 7 - Métodos de Punto Fijo Multivariable

> **Nombre:** Alan Yahir Juárez Rubio 
> **Fecha de elaboración:** 30/09/2023
> **Fecha límite de entrega:** 01/10/2023

## Ejercicio 1

Con los siguientes arreglos $x = \cfrac{24 - xy - 4z}{7}$ $y = \cfrac{12 - x^2 + 3yz}{29}$ y $z = \cfrac{43 + 3xy - yz}{13}$, utilizando el Método de Punto fijo Multivariable efectué dos iteraciones con el esquema de Gauss (simultáneas) para aproximar la solución del sistema de ecuaciones utilizando los valores iniciales $(x_0, y_0, z_0) = (4, 7, 3)$

1. $(x_2, y_2, z_2) = (-0.56644, 1.94972, 0.95849)$
2. ==$(x_2, y_2, z_2) = (0.56644, 1.94972, 0.95849)$== 
3. $(x_2, y_2, z_2) = (0.56644, -1.94972, 0.95849)$
4. $(x_2, y_2, z_2) = (0.56644, 1.94972, -0.95849)$

### Procedimiento

|  n  |  $x_i$   |  $y_i$  | $z_1$   |
|:---:|:--------:|:-------:|:------- |
|  1  | -2.28571 | 2.03448 | 8.15385 |
|  2  | -0.56645 | 1.94973 | 0.95849 |


## Ejercicio 2

Con los siguientes arreglos $x = \cfrac{1 + 3xy - 2x^2}{5}$ $y = \cfrac{2 - x - 2yz}{7}$ y $z = \cfrac{3 - 3x - yz}{8}$, utilizando el Método de Punto fijo Multivariable efectué dos iteraciones con el esquema de Gauss (simultáneas) para aproximar la solución del sistema de ecuaciones utilizando los valores iniciales $(x_0, y_0, z_0) = (1, 1, 1)$

1. $(x_2, y_2, z_2) = (0.15946, 0.22347, 0.22277)$
2. $(x_2, y_2, z_2) = (0.15946, 0.12347, 0.32277)$
3. $(x_2, y_2, z_2) = (0.15946, 0.22347, 0.32277)$
4. $(x_2, y_2, z_2) = (0.25946, 0.12347, 0.32277)$
### Procedimiento

|  n  |  $x_i$  |  $y_i$   | $z_1$  |
|:---:|:-------:|:--------:|:------:|
|  1  |   0.4   | -0.14286 | -0.125 |
|  2  | 0.10171 | 0.22347  | 0.22277|

> [!SUCCESS] Resultado
> 
> $$(x_2, y_2, z_2) = (0.10171, 0.22347, 0.22277)$$

<div style="page-break-after: always;"></div>

## Ejercicio 3

Resuelve el siguiente sistema con el vector inicial: $(1, 1, 1)$ 

$$\begin{cases}
2x &-& 3xy &+& 2x^2 &=& 1 \\
x &+& 7y &+& 2yz &=& 2 \\
3x &+& xy &+& 8z &=& 3
\end{cases}$$

Utilice los despejes 

$$\begin{array}{l}
x = \cfrac{1 + 3xy - 2z^2}{2}, && y = \cfrac{2 - x - 2yz}{7},  && z = \cfrac{3 - 3x - xy}{8}
\end{array}$$

### Procedimiento

|  n  |  $x_i$  |  $y_i$   |  $z_1$  |
|:---:|:-------:|:--------:|:-------:|
|  1  |    1    | -0.14286 | -0.125  |
|  2  | 0.27009 | 0.13776  | 0.01786 |

> [!SUCCESS] Resultado
> 
> $$(x_2, y_2, z_2) = (0.27009, 0.13776, 0.01786)$$