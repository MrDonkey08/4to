# Punto Fijo Multivariable

**Criterio de convergencia:** Una condición suficiente aunque no necesaria, para
asegurar la convergencia es que:

$$
\begin{matrix}
\left | \cfrac{\partial g_1}{∂x}  \right | &+& \left | \cfrac{\partial g_2}{∂x} \right | \leq 1 \\
\left | \cfrac{\partial g_1}{∂y} \right | &+& \left | \cfrac{\partial g_2}{∂y} \right | \leq 1 \\
\end{matrix}
$$

Para todos los apuntes $(x, y)$ de la región del plano que contiene todos los
valores y la raíz buscada.

## Ejemplo 1

Resuelve el siguiente sistema:

$$
\begin{cases}
x^2 &-& 10x &+& y^2 &+& 8 \\
xy^2 &+& x &-& 10y &+& 8
\end{cases}
$$

Obtenemos los despejes:

$$
\begin{array}{l}
\cfrac{\partial g_1}{∂x}  = \cfrac x5 && \cfrac{\partial g_2}{∂x} = \cfrac{y^2 + 1}{10} &&
	\left | \cfrac{\partial g_1}{∂x}  \right | &+& \left | \cfrac{\partial g_2}{∂x} \right | = \cfrac 1{10} \\
\\
\cfrac{\partial g_1}{∂x}  = \cfrac y5 && \cfrac{\partial g_2}{∂x} = \cfrac{xy}5 &&
	\left | \cfrac{\partial g_1}{∂y} \right | &+& \left | \cfrac{\partial g_2}{∂y} \right | = 0 \\
\end{array}
$$

Una vez revisado el criterio comenzamos a iterar

|  n  |  $x_i$  |  $y_i$  |
| :-: | :-----: | :-----: |
|  0  |    0    |    0    |
|  1  |   0.8   |   0.8   |
|  2  |  0.928  | 0.93120 |
|  3  | 0.97283 | 0.97327 |
|  4  | 0.98937 | 0.98943 |
|  5  | 0.99578 | 0.99579 |
|  6  | 0.99832 | 0.99832 |

> [!SUCCESS] Resultado
>
> $$(x, y) \approx (0.99832, 0.99832)$$

<div style="page-break-after: always;"></div>

## Ejemplo 2

Usando el método de **punto fijo multivariable** con los despejes datos y con
$x_0 = y_0 = 0$. Use los arreglos:

$$
\begin{array}{l}
x = \cfrac{y}{4} + x^2 - \cfrac{1}{2}, && y= x^2 - 5xy
\end{array}
$$

Realiza 3 iteraciones

|  n  | $x_i$  | $y_i$ |
| :-: | :----: | :---: |
|  0  |   0    |   0   |
|  1  |  -0.5  |   0   |
|  2  | -0.25  | 0.25  |
|  3  | -0.375 | 0.375 |

> [!SUCCESS] Resultado
>
> $$(x_3, y_3) \approx (-0.375, 0.375)$$
