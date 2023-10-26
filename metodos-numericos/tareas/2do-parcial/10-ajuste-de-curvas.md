# Tarea 10 - Ajuste de Curvas

> **Nombre:** Alan Yahir Juárez Rubio 
> **Fecha de elaboración:** 22/10/2023
> **Fecha límite de entrega:** 29/10/2023

## Ejercicio 1

La siguiente tabla representa las vueltas recorridas en óvalo  de carreras en tiempos distintos. Se desea conocer en cuántas vueltas se lograrán en 6 min. Realice la aproximación con un polinomio de **grado 1** y **grado 2**.

| n       | T min   | Vueltas   | x²    | xy    | x²y   | x³    | x⁴    |
| :-----: | :-----: | :-------: | :---: | :---: | :---: | :---: | :---: |
| 1       | 1       | 2.5       | 1     | 2.5   | 2.5   | 1.0   | 1.0   |
| 2       | 2       | 4.7       | 4     | 9.4   | 18.8  | 8.0   | 16.0  |
| 3       | 3       | 7.9       | 9     | 23.7  | 71.1  | 27.0  | 81.0  |
| 4       | 4       | 8.1       | 16    | 32.4  | 129.6 | 64.0  | 256.0 |
| 5       | 5       | 10        | 25    | 50    | 250   | 125.0 | 625   |
| 6       | 8       | 15.9      | 64    | 127   | 1018  | 512.0 | 4096  |
| Total   | 23      | 49        | 119   | 245   | 1490  | 737   | 5075  |

### Grado 1

$$\begin{bmatrix}
	 6 & 23 \\
	23 & 119
\end{bmatrix}
\begin{bmatrix}
	a_0 \\ a_1
\end{bmatrix} = 
\begin{bmatrix}
	49 \\ 245
\end{bmatrix} \Rightarrow
\begin{pmatrix}
	a_0 \\ a_1
\end{pmatrix} = 
\begin{pmatrix}
	\frac{196}{185} &\approx& 1.05946\\
	\frac{343}{185} &\approx& 1.85405
\end{pmatrix}$$

$$ y = 1.05946 + 1.85405x \tag{Ajuste lineal}$$
> [!SUCCESS] Resultado
> 
> $$y(6) = 12.18376$$
### Grado 2

$$\begin{bmatrix}
	 6  &  23 & 119 \\
	23  & 119 & 737 \\
	119 & 737 & 5075
\end{bmatrix}
\begin{bmatrix}
	a_0 \\ a_1 \\ a_2
\end{bmatrix} = 
\begin{bmatrix}
	49 \\ 245 \\ 1490
\end{bmatrix} \Rightarrow
\begin{pmatrix}
	a_0 \\ a_1 \\ a_2
\end{pmatrix} = 
\begin{pmatrix}
	 \frac{3959}{4840}  &\approx& 0.08161\\
	 \frac{19359}{9680} &\approx& 1.99990\\
	-\frac{31}{1936}    &\approx& 0.01601
\end{pmatrix}$$

$$ y = 0.08161 + 1.99990x + 0.01601 = \tag{Ajuste lineal}$$

> [!SUCCESS] Resultado
> 
> $$y(6) = 2.55905$$
## Ejercicio 2

Uitlice la técnica de **mínimos cuadrados** y construya un polinomio de **grado 1 y 2** para aproximar el valor de $f(x = 12)$

| n       | x     | f(x)   | x²    | xy    | x²y   | x³    | x⁴      |
| :-----: | :---: | :----: | :---: | :---: | :---: | :---: | :---:   |
| 1       | 2     | 7      | 4     | 14    | 28    | 8     | 16      |
| 2       | 7     | 6      | 49    | 42    | 294   | 343   | 2401    |
| 3       | 11    | 5      | 121   | 55    | 605   | 1331  | 14641   |
| 4       | 15    | 4      | 225   | 60    | 900   | 3375  | 50625   |
| 5       | 19    | 3      | 361   | 57    | 1083  | 6859  | 130321  |
| 6       | 23    | 2      | 529   | 46    | 1058  | 12167 | 279841  |
| 7       | 27    | 1      | 729   | 27    | 729   | 19683 | 531441  |
| Total   | 102   | 21     | 2014  | 287   | 4669  | 43758 | 1009270 |