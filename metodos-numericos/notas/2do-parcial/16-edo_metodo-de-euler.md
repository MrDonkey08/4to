# Solución de EDO: Método de Euler

Solución de una **ecuación ordinaria de primer orden**. El problema clásico:

$$\cfrac{dy}{dx} = f(x, y) =
\begin{cases}
    y = y_0, & x = x_0 \\
    y =\ ?,  & x = x_f
\end{cases}$$

El **método de Euler** es usado para _E.O de primer orden_. Se tiene que:

$$\begin{align}
	\cfrac{dy}{dx} \sim \cfrac{y_1 - y_0}{x_1 - x_0} = f(x_0, y_0) \\\\
	y_1 - y_0 = \Delta x\ f(x_0, y_0)\\\\
	y_1 = y_0 + \Delta x\ f(x_0, y_0) \tag{Fórmula de Euler}
\end{align}$$

El método requiere proponer un $\Delta x$ y el método iterativo es el siguiente

$$\begin{array}{ccc}
	x_1 &=& x_0 + \Delta x && y_1 &=& y_0 + \Delta x\ f(x_0, y_0)\\
	x_2 &=& x_1 + \Delta x && y_2 &=& y_1 + \Delta x\ f(x_1, y_1)\\
	x_3 &=& x_2 + \Delta x && y_3 &=& y_2 + \Delta x\ f(x_2, y_2)\\
	\vdots &&&& \vdots\\
	x_{n+1} &=& x_n + \Delta x && y_{n+1} &=& y_n + \Delta x\ f(x_n, y_n)\\
\end{array}$$

## Ejemplo 1


Sea $\cfrac{dy}{dx} = \cfrac{x^2}{y}$, $y_0 = 2$ en $x_0 = 1$ y $y_f = ¿?$ en $x =2$, proponga $h = \Delta x = 0.2$

|  n  |  x  |   y    |
|:---:|:---:|:------:|
|  0  |  1  |   2    |
|  1  | 1.2 |  2.1   |
|  2  | 1.4 | 2.237  |
|  3  | 1.6 | 2.4122 |
|  4  | 1.8 | 2.6244 |
|  5  |  2  | 2.8713 |

> [!DONE] Respuesta
>
> $$y(0.1) \approx 2.8713$$

### Analíticamente

$$\cfrac{dy}{dx} = \cfrac{x^2}{y} \Rightarrow ydy = x^2dx \tag{Variables Separables}$$

integramos

$$\int y\ dy = \int x^2\ dx \Rightarrow \cfrac{y^2}{2} \tag{Solución General}$$

Sustituyendo $x_1 = 1$ y $y = 2$:

$$\begin{align}
	\cfrac{2^2}{2} &= \cfrac{1}{3} + c\\
	\cfrac{4}{2} -\cfrac{1}{3} &= c\\
	\cfrac{5}{3} &= c
\end{align}$$

Sustituyendo $c$ en la **solución general** y evaluando en $x = 2$

$$\begin{align}
\cfrac{y²}{2} &= \cfrac{2³}{3} + \cfrac{5}{3}\\
	y &= \sqrt{26/3}\\
	y &= 2.9439
\end{align}$$

> [!DONE] Respuesta
>
> $$y(0.1) = 2.9439$$

## Ejemplo 2

Resolver $y = 20y + 7e^{-0.5t}$ con $y(0) = 5$ por el **método de Euler** con $h = 0.02$ para $0 \leq t \leq 0.1$, usar $h = \Delta t = 0.02$ 

|  n  |  t   |    y    |
|:---:|:----:|:-------:|
|  0  |  0   |    5    |
|  1  | 0.02 |  3.14   |
|  2  | 0.04 | 2.02261 |
|  3  | 0.06 | 1.35079 |
|  4  | 0.08 | 0.94634 |
|  5  | 0.1  | 0.70321 |

> [!DONE] Respuesta
>
> $$y(0.1) \approx 0.70231$$