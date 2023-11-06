# Tarea 11 - Integración Numérica

> **Nombre:** Alan Yahir Juárez Rubio 
> **Fecha de elaboración:** 05/11/2023
> **Fecha límite de entrega:** 05/11//2023

## Ejercicio 1

Aproxime la $\int^2_1 \ln x \ dx$ con la **regla del trapecio** $n = 5$

$$h = \cfrac{2-1}{5} = 0.2$$

|   x   |  1  |   1.2   |   1.4   | 1.6  |   1.8   |    2    |
|:-----:|:---:|:-------:|:-------:|:----:|:-------:|:-------:|
| f(x)  |  0  | 0.18232 | 0.33647 | 0.47 | 0.58779 | 0.69315 |
| Bases |  1  |    2    |    2    |  2   |    2    |    1    |

$$I \approx \cfrac{0.2}{2}[3.84631] = 0.38463$$

## Ejercicio 2

Aproxime la $\int^{\pi/3}_{0} (\sin x)^2 \ dx$ con $n = 6$ para **trapecio**, **S. 1/3**, **S. 3/8**.

$$h = \cfrac{\pi /3}{6} = \cfrac{\pi}{18}$$

|    x     |  0  | $\pi / 18$ | $\pi/9$ | $\pi/6$ | $2\pi/9$ | $5\pi/18$ | $\pi/3$ |
|:--------:|:---:|:----------:|:-------:|:-------:|:--------:|:---------:|:-------:|
|   f(x)   |  0  |   0.03015   | 0.11698 |  0.25   | 0.41318  |  0.58682  |  0.75   |
| Trapecio |  1  |     2      |    2    |    2    |    2     |     2     |    1    |
|  S. 1/3  |  1  |     4      |    2    |    4    |    2     |     4     |    1    |
|  S. 3/8  |  1  |     3      |    3    |    2    |    3     |     3     |    1    |

$$\begin{align}
I &\approx \cfrac{\pi/18}{2}[3.54426] = 0.30930 \tag{Trapecio}\\
I &\approx \cfrac{\pi/18}{3}[5.27820] = 0.30707 \tag{S. 1/3}\\
I &\approx \cfrac{3\pi/18}{8}[4.69139] = 3.30705 \tag{S. 3/8}
\end{align}$$

## Ejercicio 3

Aproxime $\int^{0.1}_{0} x^{1/3} \ dx$ con $n = 8$ con **regla de S** $1/3$ 

$$h = \cfrac{0.1 - 0}{8} = 0.0125$$

|   x   |  0  | 0.0125  |  0.025  | 0.0375  |  0.05   | 0.0625  |  0.075  | 0.0875  |   0.1   |
|:-----:|:---:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| f(x)  |  0  | 0.23208 | 0.29240 | 0.33472 | 0.36840 | 0.39685 | 0.42172 | 0.44395 | 0.46416 |
| Bases |  1  |    4    |    2    |    4    |    2    |    4    |    2    |    4    |    1    | 

$$I \approx \cfrac{0.0125}{3}[8.25960] = 0.03441$$

## Ejercicio 4

Se desea integrar $\int^{5}_{1} f(x) \ dx$ y se tienen los valores:

|    x     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
|:--------:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|   f(x)   |  3  |  5  | 15  | 28  | 21  | 19  | 12  |  7  |  2  |
| Trapecio |  1  |  2  |  2  |  2  |  1  |     |     |     |     |
|  S. 1/3  |  1  |  4  |  2  |  4  |  1  |     |     |     |     |
|  S. 3/8  |  1  |  3  |  3  |  2  |  3  |  3  | 1    |     |     |

1. Aproxime la integral $\int^{5}_{1} f(x) \ dx$ con $n = 4$ y **regla del trapecio**
2. Aproxime la integral $\int^{5}_{1} f(x) \ dx$ con $n = 4$ y **regla de S. 1/3**
3. Aproxime la integral $\int^{7}_{1} f(x) \ dx$ con $n = 6$ y **regla de S. 3/8**

$$h = 1$$

$$\begin{align}
I &\approx \cfrac{1}{2}[120] = 60 &n=4 \tag{Trapecio}\\
I &\approx \cfrac{1}{3}[186] = 62 &n=4 \tag{S. 1/3}\\
I &\approx \cfrac{3}{8}[251] = 94.125 &n=6 \tag{S. 3/8}\\
\end{align}$$