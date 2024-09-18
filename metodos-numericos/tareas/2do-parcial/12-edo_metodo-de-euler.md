# Tarea 12 - Solución de EDO: Método de Euler

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 12/11/2023
> **Fecha límite de entrega:** 12/11//2023

## Ejercicio 1

Resolver $\cfrac{dy}{dx} = y - t² + 1$ con $y(0) = 0.5$ en el intérvalo
$0 \leq t \leq 2$, con $h = 0.2$

|  n  |  t  |    y    |
| :-: | :-: | :-----: |
|  0  |  0  |   0.5   |
|  1  | 0.2 |   0.8   |
|  2  | 0.4 |  1.152  |
|  3  | 0.6 | 1.5504  |
|  4  | 0.8 | 1.98848 |
|  5  |  1  | 2.45818 |
|  6  | 1.2 | 2.94981 |
|  7  | 1.4 | 3.45177 |
|  8  | 1.6 | 3.95013 |
|  9  | 1.8 | 4.42815 |
| 10  |  2  | 4.86578 |

> [!DONE] Respuesta
>
> $$y(2) \approx 4.86578$$

## Ejercicio 2

Utilizando el **método de Euler**, calcula la 3ra iteración de
$y' = \sin x - 3y$, $y(0) = 2$. Utilice $h = 0.001$

|  n  |   x   |    y    |
| :-: | :---: | :-----: |
|  0  |   0   |    2    |
|  1  | 0.001 |  1.994  |
|  2  | 0.002 | 1.98802 |
|  3  | 0.003 | 1.98206 |

> [!DONE] Respuesta
>
> $$y(0.003) \approx 1.98206 \tag{3ra iteración}$$

<div style="page-break-after: always;"></div>

## Ejercicio 3

Calcula la 4ta iteración para aproximar $y' = t² - 0.1y$ con $y(0) = 1$, con un
pase de $h = 0.001$

|  n  |   t   |    y    |
| :-: | :---: | :-----: |
|  0  |   0   |    1    |
|  1  | 0.001 | 0.99990 |
|  2  | 0.002 | 0.99980 |
|  3  | 0.003 | 0.99970 |
|  4  | 0.004 | 0.99960 |

> [!DONE] Respuesta
>
> $$y(0.004) \approx 0.9996 \tag{4ta iteración}$$
