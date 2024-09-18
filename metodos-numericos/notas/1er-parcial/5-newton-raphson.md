# Método de Newton-Raphson

Es uno de los métodos más conocidos y poderosos para resolver _ecuaciones no
lineales_, ya que es posible encontrar _raíces reales o complejas_, aunque para
estos últimos presentan grandes ventajas ya que, de antemano, se debe conocer la
complejidad de trabajar con ellas.

El método de Newton-Raphson requiere de un solo valor inicial "cercano a la
raíz".

El método iterativo tiene la forma:

$$X_{n+1} = X_n - \cfrac {f(x_n)}{f'(x_n)}$$

$$X_1 = X_0 = $$

> [!NOTE]
>
> Converge más rápido Newton Rapson y más lento bisección

> [!IMPORTANT]
>
> $$| X_{act} - X_{ant} |$$

## Ejemplo

Aproxime la raíz de $f(x) = \cos x - \ln x = 0$ con $\varepsilon = 0.001$ y
$x_0 = 1$

$$
\begin{array}{c}
f(x) = \cos x - \ln x \\
f'(x) = -\sin x - \cfrac 1x \\ \\
\end{array}
$$

$$
\begin{array}{c}
x_0 = 1  && 0.29341\\
x_1 = 1.29341 && 0.00955 \\
x_2 = 1.30906 && 0.00000
\end{array}
$$

Usar la función del ejemplo 1 con el valor inicial $1.7$ $\varepsilon = 0.001$
