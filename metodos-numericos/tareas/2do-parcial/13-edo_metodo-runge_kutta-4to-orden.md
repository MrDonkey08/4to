# Tarea 13 - Solución de EDO: Método de Runge-Kutta

> **Nombre:** Alan Yahir Juárez Rubio **Fecha de elaboración:** 19/11/2023
> **Fecha límite de entrega:** 19/11//2023

## Ejercicio 1

Resolver $\cfrac{dy}{dx} = -2xy$ para $y(0) = 2$ hasta $y(1.5) = ¿?$, con
$n = 5$, es decir; $h = \cfrac{1.5 - 0}{5} = 0.3$

### Primera iteración

$$
\begin{array}{lllll}
	k_1 &=& f(0, 2) &=& \;\;\: 0 \\
	k_2 &=& f(0.15, 2) &=& -0.6\\
	k_3 &=& f(0.15, 1.92) &=& -0.573\\
	k_4 &=& f(0.3, 1.8281) &=& -1.09686
\end{array}
$$

$$y_1 = 1.82786$$

### Segunda Iteración

$$
\begin{array}{lllll}
	k_1 &=& f(0.3, 1.82786) &=& -1.09671\\
	k_2 &=& f(0.45, 1.66335) &=& -1.49701\\
	k_3 &=& f(0.45, 1.6033) &=& -1.44297\\
	k_4 &=& f(0.6, 1.39496) &=& -1.67396\\
\end{array}
$$

$$y_2 = 1.39533$$

### Tercera Iteración

$$
\begin{array}{lllll}
	k_1 &=& f(0.6, 1.39533) &=& -1.67439\\
	k_2 &=& f(0.75, 1.14417) &=& -1.71625\\
	k_3 &=& f(0.75, 1.13789) &=& -1.70683 \\
	k_4 &=& f(0.9, 0.88328) &=& -1.58990\\
\end{array}
$$

$$y_3 = 0.8898$$

### Cuarta Iteración

$$
\begin{array}{lllll}
	k_1 &=& f(0.9, 0.8898) &=& -1.60165\\
	k_2 &=& f(1.05, 0.64956) &=& -1.36407\\
	k_3 &=& f(1.05, 0.68519) &=& -1.43891\\
	k_4 &=& f(1.2, 0.45813) &=& -1.09952\\
\end{array}
$$

$$y_4 = 0.47445$$

### Quinta Iteración

$$
\begin{array}{llll}
	k_1 &=& f(1.2, 0.47445) &=& -1.13867\\
	k_2 &=& f(1.35, 0.30365) &=& -0.81984\\
	k_3 &=& f(1.35, 0.35147) &=& -0.94897\\
	k_4 &=& f(1.5, 0.18976) &=& -0.56927\\
\end{array}
$$

$$y_5 = 0.21217$$

> [!DONE] Respuesta
>
> $$y(1.5) = 0.21217 \tag{h = 0.3}$$

## Ejercicio 2

Calcular la primera iteración de la EDO $y' + y = 9$; se tiene que: $y(0) = 4$,
$h = 0.001$

> [!NOTE]
>
> Recuerde igualar $y ' = f(x,\; y)$

### Despeje de la EDO

$$
\begin{align}
	y' + y &= 9\\
	y' &= 9-y
\end{align}
$$

### Primera iteración

$$
\begin{array}{llll}
	k_1 &=& f(0, 4) &=& 5\\
	k_2 &=& f(0.0005, 4.0025) &=& 4.9975\\
	k_3 &=& f(0.0005, 4.0025) &=& 4.9975\\
	k_4 &=& f(0.001, 4.005) &=& 4.995\\
\end{array}
$$

> [!DONE] Respuesta
>
> $$y_1 = 4.005 \tag{h = 0.001}$$
