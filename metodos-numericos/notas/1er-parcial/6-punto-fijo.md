# Método de punto fijo

Un **punto fijo** de una función $g \left(x \right)$ es un número real $x$ tal
que $x=g \left(x \right)$. Este método sirve para resolver funciones del tipo
$f \left(x \right) = 0$. Para tal objetivo, la ecuación se transforma de alguna
manera a la forma: $x = g \left(x \right)$.

Este se logra despejando $x$ de alguno de los miembros de la ecuación,
factorizando $x$ o despejándola o sumando $x$ a ambos lados de la ecuación. Se
requiere un solo valor inicial $x_0$ y el método iterativo surge de aplicar la
siguiente fórmula:

$$
\begin{array}{c}
x_1 = g \left(x_0 \right) \\
x_2 = g \left(x_1 \right) \\
x_3 = g \left(x_2 \right) \\
\vdots \\
x_{n+1} = g \left(x_n \right)
\end{array}
$$

Hasta satisfacer la _tolerancia del error_ o bien hasta encontrar el _punto
fijo_.

Para determinar cuál arreglo (despeje, $g(x)$) es el adecuado, existe un
criterio de convergencia _suficiente, más no necesario_, el cual se muestra en
seguida:

$$\lvert g\:' \left(x_0 \right) \rvert < 1$$

## Ejemplos

1. Use el **método de punto fijo** para encontrar una solución con
   $\varepsilon = x \cdot 10^{-3}$ para $f(x) = \cos x - \ln x = 0$ con
   $x_0 = 1.3$.

**Arreglos:**

$$
\begin{alignat}{2}
\cos x - \ln x &= 0 \\
\cos^{-1}(\cos x &= \ln x) \\
x &=\cos^{-1} (\ln x) \tag{Arreglo 1}
\end{alignat}
$$

---

$$
\begin{alignat}{2}
\cos x - \ln x &= 0 \\
 {\huge e^{(\cos x\ =\ \ln x )}}  \\
e^{\cos x} &= x \tag{Arreglo 2}
\end{alignat}
$$

**Criterio de convergencia**

$$
\begin{alignat}{2}
g_1(x) &= \cos^{-1} (\ln x) \\
g_1'(x) &= \frac{\cfrac{1}{x}}{\sqrt{1 - \ln^2 x}}
=  -\frac{1}{x \sqrt{1 - \ln^2 x}} \\
|g_1'(1.3)| &= 0.79716 < 1
\end{alignat}
$$

---

$$
\begin{alignat}{2}
g_2(x) &= e^{\cos x} \\
g_2'(x) &= -\sin x e^{\cos x} \\
|g_2'(1.3)| &= 1.25907 > 1
\end{alignat}
$$

---

Como el arreglo que cumple con el criterio de convergencia es:

$$
\begin{array}{c}
x =\cos^{-1} (\ln x), && x_0 = 1.3
\end{array}
$$

| $n$ | $g(x)$  |   $ε$   |
| :-: | :-----: | :-----: |
|  1  | 1.30532 |    -    |
|  2  | 1.30109 | 0.00424 |
|  3  | 1.30446 | 0.00337 |
|  4  | 1.30177 | 0.00268 |
|  5  | 1.30391 | 0.00214 |
|  6  | 1.30221 | 0.00170 |
|  7  | 1.30356 | 0.00135 |
|  8  | 1.30249 | 0.00108 |
|  9  | 1.30334 | 0.00086 |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.00086$$

2. Aproxime la raíz de $f(x) = x-3\sin x + 1$ con $\varepsilon = 0.005$ y
   $x_0 = 0.5$, utilizando el **método de punto fijo**

**Arreglos:**

$$
\begin{alignat}{3}
x - 3\sin x + 1 &= 0 \\
x &= 3\sin x - 1 \tag{Arreglo 1}
\end{alignat}
$$

---

$$
\begin{alignat}{2}
x - 3\sin x + 1 &= 0 \\
\sin^{-1}(\sin x &= \frac{x + 1}{3}) \\
x &= \sin^{-1} \left( \frac{x + 1}{3} \right) \tag{Arreglo 2}\\
\end{alignat}
$$

---

**Criterio de convergencia**

$$
\begin{alignat}{2}
g_1(x) &= 3\sin x - 1 \\
g_1'(x) &= 3\cos x \\
|g_1'(0.5)| &= 2.63275 > 1
\end{alignat}
$$

$$
\begin{alignat}{2}
g_2(x) &= \sin^{-1} \left( \frac{x + 1}{3} \right) \\
g_2'(x) &= \frac{\cfrac{1}{3}}{\sqrt{1 - \left( \cfrac{x + 1}{3} \right)^2}} \\
g_2'(0.5) &= 0.38490 < 1
\end{alignat}
$$

El arreglo que cumple con el criterio de convergencia es:

$$g(x) = \sin^{-1} \left( \frac{x + 1}{3} \right)$$

| $n$ | $g(x)$  |   $ε$   |
| :-: | :-----: | :-----: |
|  1  | 0.52350 |    -    |
|  2  | 0.53271 | 0.00911 |
|  3  | 0.53623 | 0.00353 |

> [!SUCCESS] Respuesta
>
> $$x \approx 0.53623$$
