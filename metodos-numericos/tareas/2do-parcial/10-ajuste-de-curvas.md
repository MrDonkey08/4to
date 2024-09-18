# Tarea 10 - Ajuste de Curvas

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 29/10/2023
> **Fecha límite de entrega:** 29/10/2023

## Ejercicio 1

La siguiente tabla representa las vueltas recorridas en óvalo de carreras en
tiempos distintos. Se desea conocer en cuántas vueltas se lograrán en 6 min.
Realice la aproximación con un polinomio de **grado 1** y **grado 2**.

|   n   | T min | Vueltas | x²  |  xy   |  x²y   | x³  |  x⁴  |
| :---: | :---: | :-----: | :-: | :---: | :----: | :-: | :--: |
|   1   |   1   |   2.5   |  1  |  2.5  |  2.5   |  1  |  1   |
|   2   |   2   |   4.7   |  4  |  9.4  |  18.8  |  8  |  16  |
|   3   |   3   |   7.9   |  9  | 23.7  |  71.1  | 27  |  81  |
|   4   |   4   |   8.1   | 16  | 32.4  | 129.6  | 64  | 256  |
|   5   |   5   |   10    | 25  |  50   |  250   | 125 | 625  |
|   6   |   8   |  15.9   | 64  | 127.2 | 1017.6 | 512 | 4096 |
| Total |  23   |  49.1   | 119 | 245.2 | 1489.6 | 737 | 5075 |

### Grado 1

$$
\begin{bmatrix}
	 6 & 23\\
	23 & 119
\end{bmatrix}
\begin{bmatrix}
	a_0\\ a_1
\end{bmatrix} =
\begin{bmatrix}
	49.1\\ 245.2
\end{bmatrix} \Rightarrow
\begin{pmatrix}
	a_0\\ a_1
\end{pmatrix} =
\begin{pmatrix}
	\cfrac{2033}{1850} &\approx& 1.09892\\
	\cfrac{3419}{1850} &\approx& 1.84811
\end{pmatrix}
$$

$$ y = 1.09892 + 1.84811x \tag{Ajuste lineal}$$

> [!SUCCESS] Resultado
>
> $$y(6) = 12.18758$$

### Grado 2

$$
\begin{bmatrix}
	 6  &  23 & 119\\
	23  & 119 & 737\\
	119 & 737 & 5075
\end{bmatrix}
\begin{bmatrix}
	a_0\\ a_1\\ a_2
\end{bmatrix} =
\begin{bmatrix}
	49.1\\ 245.2\\ 1489.6
\end{bmatrix} \Rightarrow
\begin{pmatrix}
	a_0\\ a_1\\ a_2
\end{pmatrix} =
\begin{pmatrix}
	 \cfrac{19091}{24200}  &\approx& 0.78888\\
	 \cfrac{98511}{48400} &\approx& 2.03535\\
	-\cfrac{199}{9698}    &\approx& 0.02052
\end{pmatrix}
$$

$$ y = 0.78888 + 2.03535x - 0.02052x² \tag{Ajuste cuadrático}$$

> [!SUCCESS] Resultado
>
> $$y(6) = 12.26226$$

<div style="page-break-after: always;"></div>

## Ejercicio 2

Uitlice la técnica de **mínimos cuadrados** y construya un polinomio de **grado
1 y 2** para aproximar el valor de $f(x = 12)$

|   n   |  x  | f(x) |  x²  | xy  | x²y  |  x³   |   x⁴    |
| :---: | :-: | :--: | :--: | :-: | :--: | :---: | :-----: |
|   1   |  2  |  7   |  4   | 14  |  28  |   8   |   16    |
|   2   |  7  |  6   |  49  | 42  | 294  |  343  |  2401   |
|   3   | 11  |  5   | 121  | 55  | 605  | 1331  |  14641  |
|   4   | 15  |  4   | 225  | 60  | 900  | 3375  |  50625  |
|   5   | 19  |  3   | 361  | 57  | 1083 | 6859  | 130321  |
|   6   | 23  |  2   | 529  | 46  | 1058 | 12167 | 279841  |
|   7   | 27  |  1   | 729  | 27  | 729  | 19683 | 531441  |
| Total | 104 |  28  | 2018 | 301 | 4697 | 43766 | 1009286 |

### Grado 1

$$
\left[\begin{array}{rr|r}
	  7 &  104  & 28\\
	104 & 2018 & 301
\end{array} \right] \Rightarrow
\left(\begin{array}{r|rrr}
	a_0 &  \cfrac{2520}{331} &\approx&  7.61329\\
	a_1 & -\cfrac{161}{662}  &\approx& -0.24773
\end{array} \right)
$$

$$ y \approx 7.61329 - 0.24773x \tag{Ajuste lineal}$$

> [!SUCCESS] Resultado
>
> $$y(12) \approx 4.64053$$

### Grado 2

$$
\left[\begin{array}{rrr|r}
	   7 &   104 &    2018 &   28\\
	 104 &  2018 &   43766 &  301\\
	2018 & 43766 & 1009286 & 4697
\end{array} \right] \Rightarrow
\left(\begin{array}{r|rrr}
	a_0 &  \cfrac{758055}{101266} &\approx&  7.48578\\
	a_1 & -\cfrac{132173}{607596} &\approx& -0.21753\\
	a_2 & -\cfrac{535}{607596}    &\approx& -0.00088\\
\end{array} \right)
$$

$$ y \approx 7.48578 - 0.21753x - 0.00088x² \tag{Ajuste cuadrático}$$

> [!SUCCESS] Resultado
>
> $$y(12) \approx 4.74870$$
