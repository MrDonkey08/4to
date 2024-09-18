# Método de la Regla falsa o la falsa posición

... $[Xi, Xd]$, tales que los dos valores de las funciones en esos puntos tengan
signo diferente, por los cuales se calcula el valor aproximado a la raíz de la
ecuación $Xm$, mediante la siguiente fórmula:

$$X_m = \cfrac{X_i f(X_d) - X_d f(X_i)} {f(X_d) - f(X_i)}$$

Se evalúa $f(X_m)$ y se compara su signo con el de de $f(Xi)$ y el de $f(X_d)$
sustituyendo el valor de $X_i$ o $X_d$ por el de $X_m$, el proceso se repite
hasta que se satisfaga el criterio de convergencia

$$
\begin{array}{c}
\lvert X_{i+1} - X_i \rvert < \varepsilon &o& \lvert X_{act} - X_{ant} \rvert < \varepsilon
\end{array}
$$

## Ejemplo

$$
\begin{array}{c}
f(x) = \cos x - \ln x && x = 0 && [1, 2] && \text{con }  \epsilon = 0.001
\end{array}
$$

| $n$ | $X_i$ |  $X_d$  | $f(X_i)$ | $f(X_d)$ |    $X_m$    | $\lvert X_{act} - X_{ant} \rvert$ | $f(X_m)$ |
| :-: | :---: | :-----: | :------: | :------: | :---------: | :-------------------------------: | :------: |
|  1  |   1   |    2    |  0.5403  | -1.10929 |   1.32754   |                 -                 | -0.04246 |
|  2  |   1   | 1.32754 |  0.5403  | -0.4226  |   1.30367   |              0.2386               | -0.00123 |
|  3  |   1   | 1.30367 |  0.5403  | -0.00123 | **1.30298** |              0.00069              | -0.0004  |
