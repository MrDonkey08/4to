# Derivación Numérica

Recordar el **polinomio de Newton**

$$
\begin{align}
y &= a_0 + a_1(x - x_0)\\
y' &= a_1(1) = a_1\\
y'' &= 0
\end{align} \tag{grado 1}
$$

$$
\begin{align}
y    &= a_0 + a_1(x - x_0) + a_2(x - x_0)(x - x_1)\\
y'   &= a_1(1) + a_2((x - x_0)(1) + (x - x_1)(1)) = a_1\\
y'   &= a_1 + a_2(2x - x_0 - x_1) \\
y''  &= a_2 (2) = 2a_2\\
y''' &= 0
\end{align} \tag{grado 2}
$$

$$
\begin{align}
y &= a_0 + a_1(x - x_0) + a_2(x - x_0)(x - x_1) + a_3(x - x_0)(x - x_1)(x - x_2)\\
y' &= a_1 + a_2[(x - x_0) + (x - x_1)] + a_3[(x - x_0)(x - x_1) + (x - x_0)(x - x_2) + (x - x_1)(x - x_2)]\\
y'' &= a_2 (1+1) + a_3 [x - x_0) + (x - x_1) + (x - x_0) + (x - x_2) + (x - x_1) + (x - x_2)]\\
y'' &= 2a_2 + a_3[2(x - x_0) + 2(x - x_1) + 2 (x - x_2)]\\
y''' &= a_3[2 + 2 + 2] = 6a_3
\end{align} \tag{grado 3}
$$

Para $n=4$

$$y^{IV} = 24a_4$$

Para un polinomio de grado $n$

$$y^n = n!a_n$$

## Ejemplo 1

> [!NOTE]
>
> - Solamente cuando son $x$-distantes se puede tomar un punto de la tabla
> - Solo para $x$-distantes se puede calcular la primer derivada centrada, con
>   un promedio

Encuentra la primera y segunda derivada en $x = 5$ a partir de los datos

|  x   |  2  |  3  |  4  |  5  |  6  |  7  |
| :--: | :-: | :-: | :-: | :-: | :-: | :-: |
| f(x) |  8  | 13  | 18  | 21  | 16  |  9  |

### Primera

|  5  | 21  |     |
| :-: | :-: | :-: |
|     |     | -5  |
|  6  | 16  |     |

|  4  | 18  |     |
| :-: | :-: | :-: |
|     |     |  3  |
|  5  | 21  |     |

$$f'(5) = \cfrac{-5 + 3}{2} = -1$$

### Segunda

|  4  | 18  |     |     |
| :-: | :-: | :-: | :-: |
|     |     |  3  |     |
|  5  | 21  |     | -4  |
|     |     | -5  |     |
|  6  | 16  |     |     |

$$F'(5) = 2a_2 = 2(-4) = -8$$

## Ejemplo 2

En una carrera de 400 m planos se tomaron los siguientes tiempos parciales

| Distancia | f(x) |  0  | 100  | 200  | 300  | 400  |
| :-------: | :--: | :-: | :--: | :--: | :--: | :--: |
|  Tiempo   |  x   |  0  | 13.1 | 25.2 | 36.4 | 46.1 |

Encuentre la velocidad y la aceleración del atleta a la mitad de la carrera

### Primer derivada ->

| 25.2 | 200 |         |
| :--: | :-: | :-----: |
|      |     | 8.92857 |
| 36.4 | 300 |         |

### Primer derivada <-

| 13.1 | 100 |        |
| :--: | :-: | :----: |
|      |     | 8.2645 |
| 25.2 | 200 |        |

### Segunda derivada

| 13.1 | 100 |         |        |
| :--: | :-: | :-----: | :----: |
|      |     | 8.2645  |        |
| 25.2 | 200 |         | 0.0285 |
|      |     | 8.92857 |        |
| 36.4 | 300 |         |        |

$$y'' (25.2) = 2(0.0285) = 0.0570\ m/s$$
