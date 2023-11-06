# Integración Numérica

**Integración numérica** Aquí se presentas los métodos numéricos para evaluar una integral definda con la siguiente estructura

$$I \approx \int^a_bf(x) dx$$

Los métodos considerados se desarrollan tomando una función simple $Q_n(x)$ que tiene el mismo valor que $f(x)$ en un número de puntos elegidos $x_i$ (con $i = 0, 1, 2, \dots n$) y usando la integral de $Q_n(x)$  como una aproximación de la integral de $f(x)$. Las funciones $Q_n(x)$ deben de ser fáciles de integrar y los puntos $x_i$ en los que se tendrá  que $Q_n(x_i) = f(x_i)$ se conocen como nodos de la fórmula de integración. Si los nodos elegidos $x$-distantes, entonces se pueden emplear una serie de fórmulas conocidas como **fórmulas de Newton-Cotes**

## Fórmulas Newton-Cotes

### Simples

$$\begin{align}
	\int^a_b f(x) dx &= \cfrac{\Delta x}{2} [f_0 + f_1], &n = 1 \tag{Trapecio}\\
	\int^a_b f(x) dx &= \cfrac{\Delta x}{3} [f_0 + 4f_1 + f_2], &n = 2 \tag{Simpson 1/3}\\
	\int^a_b f(x) dx &= \cfrac{3\Delta x}{8} [f_0 + 3f_1 + 3f_2 + f_3], &n = 3 \tag{Simpson 3/8}\\
\end{align}$$

### Compuestas

> [!NOTE]
> 
> $$\Delta x = h = \cfrac{b - a}{n}$$

$$\begin{align}
	\int^a_b f(x) dx &= \cfrac{h}{2} [f_0 + 2f_1 + 2f_2 + 2f_3 + \cdots + f_n], &n = 1\tag{Trapecio}\\
	\int^a_b f(x) dx &= \cfrac{h}{3} [f_0 + 4f_1 + 2f_2 + 4f_3 + \cdots + f_n], &n = 2\tag{Simpson 1/3}\\
	\int^a_b f(x) dx &= \cfrac{3h}{8} [f_0 + 3f_1 + 3f_2 + 2f_3 + \cdots + f_n], &n = 3\tag{Simpson 3/8}\\
\end{align}$$

## Ejemplo 1

Aproxime la integral $\int^4_1 e^x dx$ usando la 

$$\begin{align}
	n = 1 \tag{R.T}\\
	n = 5 \tag{R.S 1/3}\\
	n = 2 \tag{R.S 3/8}\\
	n = 6 \tag{R.S}\\
\end{align}$$

compare el resultado con el **valor exacto**.

### Valor exacto

$$\int^4_1 e^x dx = e \bigg |^4_1 = e⁴ - e¹ \approx 51.87987 $$

### R.T $n = 1$

$$\begin{align}
x_0 &= 1 \ \ f_0 = 2.7183\\ 
x_1 &= 4 \ \ f_1 = 54.5982\\ 
I &\approx 2.7183 + 54.5982] \approx 88.9798
\end{align}$$

### R.S 1/3 ($n=5$)

$$\begin{align}
	x_0 &= 1			 && f_0 =  2.7183 && 1\\
	x_1 &= \cfrac{8}{5}  && f_1 =  4.9530 && 2\\
	x_2 &= \cfrac{11}{5} && f_2 =  4.0250 && 2\\
	x_3 &= \cfrac{14}{5} && f_3 = 16.4446 && 2\\
	x_4 &= \cfrac{17}{5} && f_4 = 24.9641 && 2\\
	x_5 &= 4 			 && f_5 = 54.5982 && 1\\
\end{align}$$

$$I \approx \cfrac{3}{10}[] \approx 53.4270$$

> [!ERROR] Errores
> 
> $$\begin{align}
>	 E_A &= 5\\
>    E_R &\approx 0.02932\\
> E_{RP} &\approx 2.9%\\
> \end{align}$$

### R.S 1/3 n = 2 (Regla Simple)

$$\begin{align}
	x_0 = 1 		   &&f_0 =  2.7183 && 1\\
	x_1 = \cfrac{5}{2} &&f_1 = 12.1825 && 4\\
	x_2 = 4 		   &&f_2 = 54.5982 && 1\\
\end{align}$$

$$I = \cfrac{\frac{3}{2}}{3} [106.0465] \approx 53.0233$$

### R.S 1/3 n = 6 (Regla Compuesta)

$$\begin{align}
	x_0 &= 1   &&& f_0 &=  2.7183 && 1\\
	x_1 &= 1.5 &&& f_1 &=  4.4817 && 4\\
	x_2 &= 2   &&& f_2 &=  7.3891 && 2\\
	x_3 &= 2.5 &&& f_3 &= 12.1825 && 4\\
	x_4 &= 3   &&& f_4 &= 20.0855 && 2\\
	x_5 &= 3.5 &&& f_5 &= 33.1155 && 4\\
	x_6 &= 4   &&& f_6 &= 54.5982 && 1\\
\end{align}$$

$$I = \cfrac{\frac{3}{2}}{3} [311.3845] \approx 51.8974$$

### R.S 3/8 n = 3 (Regla compuesta)

$$h = \cfrac{4-1}{3} = 3$$

$$\begin{align}
	x_0 &= 1   &&& f_0 &=  2.7183 && 1\\
	x_2 &= 2   &&& f_2 &=  7.3891 && 3\\
	x_4 &= 3   &&& f_4 &= 20.0855 && 3\\
	x_6 &= 4   &&& f_6 &= 54.5982 && 1\\
\end{align}$$

$$I \approx \cfrac{\frac{3}{2}}{3} [106.0465] = 53.0233$$


### R.S 1/3 n = 6 (Regla compuesta)

$$\begin{align}
	x_0 &= 1   &&& f_0 &=  2.7183 && 1\\
	x_1 &= 1.5 &&& f_1 &=  4.4817 && 3\\
	x_2 &= 2   &&& f_2 &=  7.3891 && 3\\
	x_3 &= 2.5 &&& f_3 &= 12.1825 && 2\\
	x_4 &= 3   &&& f_4 &= 20.0855 && 3\\
	x_5 &= 3.5 &&& f_5 &= 33.1155 && 3\\
	x_6 &= 4   &&& f_6 &= 54.5982 && 1\\
\end{align}$$

$$I \approx \cfrac{\frac{1}{2}}{3} [311.3845] = 51.8974$$

## Ejemplo 2

### Valor exacto

Aproxime $\int^{0.4}_{0.2} e^{3x} \cos 2x dx$ con la regla de S 3/8 con $n=6$

$$I = 0.4038$$

### Aproximación

$$h = \cfrac{0.4 - 0.2}{6} = \cfrac{1}{30}$$

$$\begin{align}
	x_0 &= 0.2			  &&& f_0 &= 1.6783 && 1\\
	x_1 &= \cfrac{7}{30}  &&& f_1 &= 1.7984 && 3\\
	x_2 &= \cfrac{4}{15}  &&& f_2 &= 1.9165 && 3\\
	x_3 &= \cfrac{3}{10}  &&& f_3 &= 2.0300 && 2\\
	x_4 &= \cfrac{1}{3}   &&& f_4 &= 2.1363 && 3\\
	x_5 &= \cfrac{11}{30} &&& f_5 &= 2.2319 && 3\\
	x_6 &= \cfrac{2}{5}   &&& f_6 &= 2.3131 && 1\\
\end{align}$$

$$I \approx \cfrac{3\frac{1}{30}}{8} [32.3007] \approx 0.4083$$

## Ejemplo 3

Aplica el método de S 3/8 para evaluar $\int^{10}_4 f(x) dx$ con $n = 6$

|  x   |   4    |   5    |   6    |   7    |   8    |   9    |   10   |
|:----:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
| f(x) | 2.0276 | 2.5189 | 2.8835 | 3.1918 | 3.4589 | 3.6944 | 3.9052 |
|  S. 3/8   |   1    |   3    |   3    |   2    |   3    |   3    |   1    |
|  Trapecio   |   1    |   2    |   2    |   2    |   2    |   2    |   1    |
|  S. 1/8   |   1    |   4    |   2    |   4    |   2    |   4    | 1       |

$$\begin{array}{cc}
h = 1 &&h = \cfrac{10 - 4}{6} = 1
\end{array}$$

$$\begin{align}
I &\approx \cfrac{3(1)}{8} [49.9835] &= 18.7437 &&n = 6 \tag{S. 3/8}\\
I &\approx \cfrac{1}{2} [37.4278] 	 &= 18.7139 &&n = 6 \tag{Trapecio}\\
I &\approx \cfrac{1}{3} [56.2380] 	 &= 18.7460 &&n = 6 \tag{S 1/8}
\end{align}$$

## Referencias

- Minerva S. (2022). _Integración numérica - parte1_. https://www.loom.com/share/70c5fcff624043e991d6de0c00008a6b

- Minerva S. (2022). _Integración numérica - parte2_. https://www.loom.com/share/e73c3d866cd14b42a289dd8e6c14d9de

- Minerva S. (2022). _Integración numérica - parte3_. https://www.loom.com/share/d44c892d9a4f46a0a1a380146c3fa58b

- Minerva S. (2022). _Integración numérica - parte4_. https://www.loom.com/share/433010810c384f0590194701c11ba043

- Minerva S. (2022). _Integración numérica - parte5_. https://loom.com/share/60ddfef7e73743aa8a1ae358f8c5a71b
