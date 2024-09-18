# Tarea 6

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 16/09/2023
> **Fecha límite de entrega:** 17/09/2023

1. Encuentre la aproximación a la raíz de la función $f(x) = e^x - 3x^2$ con
   $x_0 = 0$ y $\varepsilon = 0.001$. Utilizando el arreglo
   $g(x) = \sqrt{\cfrac{e^x}{3}}$

| $n$ | $g(x)$  |   $ε$   |
| :-: | :-----: | :-----: |
|  1  | 0.57735 |    -    |
|  2  | 0.77057 | 0.19321 |
|  3  | 0.84872 | 0.07816 |
|  4  | 0.88255 | 0.03382 |
|  5  | 0.89760 | 0.01505 |
|  6  | 0.90438 | 0.00678 |
|  7  | 0.90745 | 0.00307 |
|  8  | 0.90884 | 0.00139 |
|  9  | 0.90948 | 0.00063 |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.90948$$

2. Con el arreglo $\cfrac{x^2-e^{-x}+2}{3}$, aplique el criterio de convergencia
   y determine con cuál valor inicial existe garatía de convergencia (muestre
   procedimiento).

$$
\begin{array}{c}
\text{a) } x_0 = -2 &&&
\text{b) } x_0 = 2 &&&
\text{c) } x_0 = -1 &&&
\text{d) } x_0 = 3 &&&
\end{array}
$$

$$
\begin{alignat}{2}
g(x) &= \frac{x^2-e^{-x}+2}{3} \\
g'(x) &= \frac{2x-e^{-x}\cdot-1}{3} = \frac{2x + e^{-x}}{3} \\
\\
g'(2) = 1.37845\\
g'(-2) = 1.12969\\
g'(-1) = 0.23943\\
g'(3) = 2.01660\\
\end{alignat}
$$

> [!SUCCESS] Respuesta
>
> $$\text{c) } x_0 = -1 $$

3. Utilice el método de punto fijo para aproximar la solución de
   $f(x) = x-e^{-x} = 0$, despeje el término lineal (use el arreglo) y
   $x_0 = 0.4$ con $\varepsilon = 0.003$

**Arreglo:**

$$
\begin{alignat}{2}
x-e^{-x} &= 0 \\
x &= e^{-x} \tag{Arreglo 1}
\end{alignat}
$$

**Criterio de convergencia:**

$$
\begin{alignat}{2}
g(x) &= e^{-x} \\
g'(x) &= -e^{-x} \\
|g'(0.4)| &= 0.67032
\end{alignat}
$$

| $n$ | $g(x)$  |   $ε$   |
| :-: | :-----: | :-----: |
|  1  | 0.67032 |    -    |
|  2  | 0.51154 | 0.15878 |
|  3  | 0.59957 | 0.08802 |
|  4  | 0.54905 | 0.05052 |
|  5  | 0.57750 | 0.02845 |
|  6  | 0.56130 | 0.01620 |
|  7  | 0.57047 | 0.00917 |
|  8  | 0.56526 | 0.00521 |
|  9  | 0.56821 | 0.00295 |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.56821 $$
