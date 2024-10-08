# Tarea 4 - Regla Falsa

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 08/09/2023
> **Fecha límite de entrega:** 10/09/2023

1. Aproxime la solución de $f(x) = (x+1)³$ en $[-1.2, 0]$ con
   $\varepsilon = 0.004$.

| $n$ |  $X_i$   | $X_d$ | $f(X_i)$ | $f(X_d)$ |  $X_m$   | $\varepsilon$ | $f(X_m)$ |
| :-: | :------: | :---: | :------: | :------: | :------: | :-----------: | :------: |
|  1  |   -1.2   |   0   |  -0.008  |    1     | -1.19048 |       -       | -0.00691 |
|  2  | -1.19048 |   0   | -0.00691 |    1     | -1.18231 |    0.00817    | -0.00606 |
|  3  | -1.18231 |   0   | -0.00606 |    1     | -1.17519 |    0.00712    | -0.00538 |
|  4  | -1.17519 |   0   | -0.00538 |    1     | -1.16890 |    0.00628    | -0.00482 |
|  5  | -1.16890 |   0   | -0.00482 |    1     | -1.16330 |    0.00561    | -0.00435 |
|  6  | -1.16330 |   0   | -0.00435 |    1     | -1.15825 |    0.00504    | -0.00396 |
|  7  | -1.15825 |   0   | -0.00396 |    1     | -1.15368 |    0.00457    | -0.00363 |
|  8  | -1.15368 |   0   | -0.00363 |    1     | -1.14951 |    0.00417    | -0.00334 |
|  9  | -1.15951 |   0   | -0.00334 |    1     | -1.14568 |    0.00383    | -0.00309 |

> [!SUCCESS] Respuesta
>
> $$x \approx -1.14568$$

2. Aproxime la solución de $f(x) = x³ + 2x² + 7x - 20 = 0$ en $[1, 2]$ con
   $\varepsilon = 0.001$.

| $n$ |  $X_i$  | $X_d$ | $f(X_i)$ | $f(X_d)$ |  $X_m$  | $\varepsilon$ | $f(X_m)$ |
| :-: | :-----: | :---: | :------: | :------: | :-----: | :-----------: | :------: |
|  1  |    1    |   2   |   -10    |    10    |   1.5   |       -       |  -1.625  |
|  2  |   1.5   |   2   |  -1.625  |    10    | 1.56989 |    0.06989    | -0.21253 |
|  3  | 1.56989 |   2   | -0.21253 |    10    | 1.57884 |    0.00895    | -0.02695 |
|  4  | 1.57884 |   2   | -0.02695 |    10    | 1.57998 |    0.00113    | -0.00340 |
|  5  | 1.57998 |   2   | -0.00340 |    11    | 1.58012 |    0.00014    | -0.00043 |

> [!SUCCESS] Respuesta
>
> $$x \approx 1.58012$$

3. Aproxime la solución de $f(x) = \sqrt{x} - \cos x - 0.262 = 0$ en
   $[0.25, 1.51]$ con $\varepsilon = 0.001$.

| $n$ |  $X_i$  | $X_d$ | $f(X_i)$ | $f(X_d)$ |  $X_m$  | $\varepsilon$ | $f(X_m)$ |
| :-: | :-----: | :---: | :------: | :------: | :-----: | :-----------: | :------: |
|  1  |  0.25   | 1.51  | -0.73091 | 0.90606  | 0.81259 |       -       | -0.04818 |
|  2  | 0.81259 | 1.51  | -0.04818 | 0.90606  | 0.84780 |    0.03521    | -0.00287 |
|  3  | 0.84780 | 1.51  | -0.0287  | 0.90606  | 0.84989 |    0.00209    | -0.00017 |
|  4  | 0.84989 | 1.51  | -0.00017 | 0.90606  | 0.85001 |    0.00012    | -0.00001 |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.85001$$

4. Aproxime la solución de $f(x) = e^x - 3x² = 0$ en $[0.3, 1.5]$ con
   $\varepsilon = 0.003$

| $n$ |  $X_i$  | $X_d$ | $f(X_i)$ | $f(X_d)$ |  $X_m$  | $\varepsilon$ | $f(X_m)$ |
| :-: | :-----: | :---: | :------: | :------: | :-----: | :-----------: | :------: |
|  1  |   0.3   |  1.5  | 1.07986  | -2.26831 | 0.68703 |       -       | 0.57178  |
|  2  | 0.68703 |  1.5  | 0.57178  | -2.26831 | 0.85070 |    0.16367    | 0.17022  |
|  3  | 0.85070 |  1.5  | 0.17022  | -2.26831 | 0.89602 |    0.04532    | 0.04127  |
|  4  | 0.89602 |  1.5  | 0.04127  | -2.26831 | 0.90681 |    0.01079    | 0.00948  |
|  5  | 0.90681 |  1.5  | 0.00948  | -2.26831 | 0.90928 |    0.00247    | 0.00215  |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.90928$$
