# Ajuste de curvas por método de mínimos cuadrados

La propiedad fundamental de este método es que la suma de los cuadrados de los errores se hace tan pequeña como sea pocible. Su popósito es encontrar la ecuación que proporcionla la **desviación promedio** más cercana a cero. Para que esto funcione se emplea la **técnica de máximos y mínimos**.

Para realizar el _ajuste polinomial_ se resuelve el siguiense sistema de ecuaciones

$$\begin{matrix}
	\sum y    &=& a_0n          &+& a_1 \sum  x      &+& a_2 \sum x²      &+ \cdots +& a_n   \sum x^n \\ 
	\sum xy   &=&  a_0 \sum x   &+& a_1 \sum x²      &+& a_2 \sum x³      &+ ⋯  +& a_{n+1} \sum x^{n+1} \\
	\sum x²y  &=&  a_0 \sum x²  &+& a_1 \sum x³      &+& a_2 \sum x⁴      &+ ⋯ +& a_{n+2} \sum x^{n+2} \\ 
	\vdots && ⋮ && ⋮ && ⋮ && ⋮ \\
	\sum x^ny &=&  a_0 \sum x^n &+& a_1 \sum x^{n+1} &+& a_2 \sum x^{n+2} &+ ⋯ +& a_{n+2} \sum x^{2n} \\ 
\end{matrix}$$

## Ejemplo

Realice el ajuste lineal y cuadrático con los datos de la siguiente tabla

|   n   |  x  |  y  | x²  | xy  | x²y  | x³  | x⁴  |
|:-----:|:---:|:---:|:---:|:---:|:----:|:---:|:---:|
|   1   | -3  | -27 |  9  | 81  | -243 | -27 | 81  |
|   2   | -2  | -16 |  4  | 32  | -64  | -8  | 16  |
|   3   | -1  | -9  |  1  |  9  |  -9  | -1  |  1  |
|   4   |  0  |  1  |  0  |  0  |  0   |  0  |  0  |
|   5   |  1  |  8  |  1  |  8  |  8   |  1  |  1  |
|   6   |  2  | 18  |  4  | 36  |  72  |  8  | 16  |
|   7   |  3  | 26  |  9  | 78  | 234  | 27  | 81  |
| Total |  0  |  1  | 28  | 244 |  -2  | -0  | 196 |

### Ajuste lineal

$$\begin{cases}
	  1 &=& 7a_0 &+&  0a_1 \\
	244 &=& 0a_0 &+& 28a_1
	\end{cases} \tag{grado 1}
	\Rightarrow
	\begin{pmatrix}
	a_0 &=&  \frac{3}{7}  &\approx& 0.14286 \\
	a_1 &=&  \frac{61}{7} &\approx& 8.71429 \\
\end{pmatrix}$$

$$y = 0.14268 + 8.71429x \tag{Ajuste lineal}$$

> [!SUCCESS] Resultado
> 
> $$y(1.7) = 14.95715$$

### Ajuste cuadrático


$$\begin{cases}
	  1 &=&  7a_0 &+&  0a_1 &+& 28a_2\\
	244 &=&  0a_0 &+& 28a_1 &+& 0a_2 \\
	 -2 &=& 28a_0 &+&  0a_1 &+& 196a_2
	\end{cases} \tag{grado 3} 
	\Rightarrow
	\begin{pmatrix}
	a_0 &=&  \frac{3}{7}  &\approx& 0.14286 \\
	a_1 &=&  \frac{61}{7} &\approx& 8.71429 \\
	a_1 &=& -\frac{1}{14} &\approx& -0.07143
\end{pmatrix}$$


$$y = 0.42857 + 8.71429x - 0.07143x² \tag{Ajuste cuadrático}$$

> [!SUCCESS] Resultado
> 
> $$y(1.7) = 15.03643$$
