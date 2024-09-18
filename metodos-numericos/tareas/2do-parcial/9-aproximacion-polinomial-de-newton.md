# Tarea 9 - Aproximación Polinomial de Newton

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 22/10/2023
> **Fecha límite de entrega:** 22/10/2023

## Ejercicio 1

Se requiere conocer la denstidad del agua a 43.7 °C con la mayor precisión y
recurre a la siguiente tabla. Utilice un polinomio de grado 1 y 2 a la derecha y
a la izquierda

| T °C | Densidad | Primeras | Segundas | Terceras | Cuartas | Quintas | Sextas |
| :--: | :------: | :------: | :------: | :------: | :-----: | :-----: | :----: |
|  4   |    1     |          |          |          |         |         |        |
|      |          | -0.00001 |          |          |         |         |        |
|  6   | 0.99997  |          | -0.00001 |          |         |         |        |
|      |          | -0.00006 |          |    0     |         |         |        |
|  10  | 0.99973  |          | -0.00001 |          |    0    |         |        |
|      |          | -0.00015 |          |    0     |         |    0    |        |
|  20  | 0.99823  |          |    0     |          |    0    |         |   0    |
|      |          | -0.00034 |          |    0     |         |    0    |        |
|  50  | 0.98807  |          |    0     |          |    0    |         |        |
|      |          | -0.00053 |          |    0     |         |         |        |
|  75  | 0.97489  |          |    0     |          |         |         |        |
|      |          | -0.00066 |          |          |         |         |        |
| 100  | 0.95838  |          |          |          |         |         |        |

### Polinomios

$$
\begin{alignat}{2}
P_1(x) &= 0.99823 + (x - 20)(-0.00034) \\
P_1(43.7) &= 0.99823 + (43.7 - 20)(-0.00034) = 0.99017 \\
\\
\overrightarrow{P_2(x)} &= 0.99823 + (x - 20)(-0.00034) + (x - 20)(x - 50)(0) \\
\overrightarrow{P_2(43.7)} &= 0.99823 + (43.7 - 20)(-0.00034) = 0.99017  \\
\\
\overleftarrow{P_2(x)} &= 0.99973 + (x - 10)(-0.00015) + (x - 10)(x - 20)(0)  \\
\overleftarrow{P_2(43.7)} &= 0.99973 + (43.7 - 10)(-0.00015) = 0.99468 \\
\end{alignat}
$$

> [!DONE] Respuestas
>
> $$
> \begin{alignat}{2}
> P_1(43.7) &= 0.99017 \\
> \overrightarrow{P_2(43.7)} &= 0.99017  \\
> \overleftarrow{P_2(43.7)} &= 0.99468 \\
> \end{alignat}
> $$

<div style="page-break-after: always;"></div>

## Ejercicio 2

Interpolar el valor de la preción de vapor de agua a 30 °C con apoyo de la
siguiente función numérica

| $f(x)$ | P(mm Hg) | 17.535 | 55.324 | 149.380 | 335.110 |
| :----: | :------: | :----: | :----: | :-----: | :-----: |
|   x    |   T °C   |   22   |   40   |   58    |   75    |

1. Con un polinomio de grado 1
2. Con un polinomio de grado 2 →
3. con un polinomio de grado 2 ←

|  x   |   f(x)   | Primeras | Segundas | Terceras |
| :--: | :------: | :------: | :------: | :------: |
| T °C | P(mm Hg) |          |          |          |
|  22  |  17.535  |          |          |          |
|      |          | 2.09939  |          |          |
|  40  |  55.324  |          | 0.08683  |          |
|      |          | 5.22533  |          | 0.00143  |
|  58  | 149.380  |          | 0.16286  |          |
|      |          | 10.92529 |          |          |
|  75  | 335.110  |          |          |          |

### Polinomios

$$
\begin{alignat}{2}
P_1(x) &= 17.535 + (x - 22)(2.09939)   \\
P_1(30) &= 17.535 + (30 - 22)(2.09939) = 34.33012  \\
\\
\overrightarrow{P_2(30)} &= 17.535 + (30 - 22)(2.09939) + (x - 22)(x - 40)(0.08683)  \\
\overrightarrow{P_2(30)} &= 17.535 + (30 - 22)(2.09939) + (30 - 22)(30 - 40)(0.08683) = 27.38372  \\
\end{alignat}
$$

> [!BUG] Error
>
> No es posible desarrollar el polinomio de grado 2 ← debido a que no se cuentan
> con datos previos

> [!DONE] Respuestas
>
> $$
> \begin{alignat}{2}
> P_1(30) &= 34.33012  \\
> \overrightarrow{P_2(30)} &= 27.38372  \\
> \end{alignat}
> $$
