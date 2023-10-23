# Aproximación Polinomial de Newton

> [!ABSTRACT] Concepto
> 
> **$x$-distante:** Se le dice $x$ - distante cuando todos los $x_i$ tengan la misma diferencia con su sucesor y su antecesor.

## Diferencias Divididas

> [!IMPORTANT]
> 
> Método utilizado para valores en $x$ que no son $x$ -distantes

| $x_i$ | $f(x_i)$ |                       Primeras                        |                                Segundas                                 |                                         Terceras                                          |
|:-----:|:--------:|:-----------------------------------------------------:|:-----------------------------------------------------------------------:|:-----------------------------------------------------------------------------------------:|
| $x_0$ | $f(x_0)$ |                                                       |                                                                         |                                                                                           |
|       |          | $$f[x_0 - x_1] = \cfrac{f(x_1) - f(x_0)}{x_1 - x_0}$$ |                                                                         |                                                                                           |
| $x_1$ | $f(x_1)$ |                                                       | $$f[x_0 - x_1 - x_2] = \cfrac{f[x_1 - x_2] - f[x_0 - x_1]}{x_2 - x_0}$$ |                                                                                           |
|       |          | $$f[x_1 - x_2] = \cfrac{f(x_2) - f(x_1)}{x_2 - x_1}$$ |                                                                         | $$f[x_0 - x_1 - x_2 - x_3] = \cfrac{f[x_1 - x_2 - x_3] - f[x_0 - x_1 - x_2]}{x_3 - x_0}$$ |
| $x_2$ | $f(x_2)$ |                                                       | $$f[x_1 - x_2 - x_3] = \cfrac{f[x_2 - x_3] - f[x_1 - x_2]}{x_3 - x_1}$$ |                                                                                           |
|       |          | $$f[x_2 - x_3] = \cfrac{f(x_3) - f(x_2)}{x_3 - x_2}$$ |                                                                         |                                                                                           |
| $x_3$ | $f(x_3)$ |                                                       |                                                                         |                                                                                           |

### Polinomios de Newton

$$\begin{alignat}{2}
P_1(x) &= f(x_0) + (x - x_0) f[x_0, x_1] \tag{Grado 1} \\
P_2(x) &= f(x_0) + (x - x_0) f[x_0, x_1] + (x - x_0)(x - x_1)f[x_0, x_1, x_2] \tag{Grado 2} \\
P_3(x) &= f(x_0) + (x - x_0) f[x_0, x_1] + (x - x_0)(x - x_1)f[x_0, x_1, x_2] + (x - x_0)(x - x_1)(x - x_2)f[x_0, x_1, x_2, x_3] \tag{Grado 3} \\
P_n(x) &= \sum^n_{k=0} a_k \prod_{i=0}^{k-1} (x - x_i) \tag{Grado n}
\end{alignat}$$

### Ejemplo 

Calcule la tabla de diferencias con los siguientes puntos:

| $x_i$ | $f(x_i)$ |     |     |     |     |     |
|:-----:|:--------:|:---:|:---:|:---:|:---:|:---:|
|  -2   |   -18    |     |     |     |     |     |
|       |          | 13  |     |     |     |     |
|  -1   |    -5    |     | -5  |     |     |     |
|       |          |  3  |     |  1  |     |     |
|   0   |    -2    |     | -1  |     |  0  |     |
|       |          |  0  |     |  1  |     |  0  |
|   2   |    -2    |     |  3  |     |  0  |     |
|       |          |  9  |     |  1  |     |     |
|   3   |    7     |     |  9  |     |     |     |
|       |          | 45  |     |     |     |     |
|   6   |   142    |     |     |     |     |     |

luego interpole el valor de $f(x_i)$ para $x_i = 2.2$ con un polinomio de grado 1, grado 2 hacia atrás y grado 2 hacia adelante

$$\begin{alignat}{2}
P_1(2.2) &= -2 + (2.2 - 2)(9) = 0.2 \tag{Grado 1} \\
P_2(2.2) &= -2 + (2.2 - 0) (0) + (2.2 - 0)(2.2 - 2)(3) = 0.68 \tag{Grado 2 <-} \\
P_3(2.2) &= -2 + (2.2 - 2)(9) + (2.2 - 2)(2.2 - 3)(9) =  1.64 \tag{Grado 2 ->} \\

\end{alignat}$$

## Diferencias Finitas

> [!IMPORTANT]
> 
> Método utilizado para valores en $x$ que son $x$ -distantes

| $x_i$ | $f(x_i)$ |          $\Delta f(x_i)$          |                 $\Delta^2 f(x_i)$                 | $\Delta^3 f(x_i)$                                     |
|:-----:|:--------:|:---------------------------------:|:-------------------------------------------------:| ----------------------------------------------------- |
| $x_0$ | $f(x_0)$ |                                   |                                                   |                                                       |
|       |          | $\Delta f(x_0) = f(x_1) - f(x_0)$ |                                                   |                                                       |
| $x_1$ | $f(x_1)$ |                                   | $\Delta^2 f(x_0) = \Delta f(x_1) - \Delta f(x_0)$ |                                                       |
|       |          | $\Delta f(x_1) = f(x_2) - f(x_1)$ |                                                   | $\Delta^3 f(x_0) = \Delta^2 f(x_1) - \Delta^2 f(x_0)$ |
| $x_2$ | $f(x_2)$ |                                   | $\Delta^2 f(x_1) = \Delta f(x_2) - \Delta f(x_1)$ |                                                       |
|       |          | $\Delta f(x_2) = f(x_3) - f(x_2)$ |                                                   |                                                       |
| $x_3$ | $f(x_3)$ |                                   |                                                   |                                                       |

### Polinomios

Sea $s = \cfrac{x - x_0}{h}$, entonces:

$$\begin{alignat}{2}
P_1(x) &= f(x_0) + s \Delta f(x_0)  \tag{Grado 1} \\
P_2(x) &= f(x_0) + s \Delta f(x_0) + \cfrac{s(s-1)}{2!} \Delta^2 f(x_0) \tag{Grado 2} \\
P_3(x) &= f(x_0) + s \Delta f(x_0) + \cfrac{s(s-1)}{2!} \Delta^2 f(x_0) + \cfrac{s(s - 1)(s - 2)}{3!} \Delta^3 f(x_0) \tag{Grado 3} \\
P_n(x) &= f(x_0) + s \Delta f(x_0) + \cfrac{s(s-1)}{2!} \Delta^2 f(x_0) + \cfrac{s(s - 1)(s - 2)}{3!} \Delta^3 f(x_0) + \cdots + \cfrac{s(s - 1)(s - 2) \cdots (s - (n - 1))}{n!} \Delta^n f(x_0) \tag{Grado n} 
\end{alignat}$$
