---
title: Métodos Numéricos
author: Alan Yahir Juárez Rubio
aliases:
  - Metodos Numericos
tags:
  - formulario/matematicas
  - matematicas
creation date: 02-09-2023
last modification date: 01-10-2023
type: Formulario, Guía de Estudio
---

# Formulario - Métodos Numéricos (1er parcial)

## Serie de Taylor y Melaurines

$$
\begin{alignat}{2}
f(x) &\approx f(a) + f'(a)(x-a) + \cfrac{f''(a)(x-a)^2}{2!} + \cfrac{f'''(a)(x-a)^3}{3!} + ⋅s + \cfrac{f^{(n)}(a)(x-a)^n}{n!} \tag{Taylor} \\ \\
f(x) &\approx f(0) + f'(0)x + \cfrac{f''(0)x^2}{2!} + \cfrac{f'''(0)x^3}{3!} + ⋅s + \cfrac{f^{(n)}(0)x^n}{n!} \tag{Melaurines}
\end{alignat}
$$

### Errores

$$
\begin{alignat}{2}
	E_A &= | V_c - V_a |  \tag{Error Absoluto} \\\\
	E_R &= \cfrac{E_A}{V_c} \tag{Error Relativo} \\\\
	E_{RP} &= E_R ⋅ 100\% \tag{Error Relativo Porcentual}
\end{alignat}
$$

## Métodos iterativos

### Ecuaciones

> [!IMPORTANT]
>
> $$ε = | x_{act} - x_{ant} |$$

#### Bisección

> [!NOTE]
>
> $x_m$ remplaza al $x_k$ ($x_i$ o $x_d$) que al ser remplazada en la función
> tenga el mismo signo que $f(x_m)$

$$
\begin{alignat}{2}
	x_m &= \cfrac{x_i + x_d}{2} \\\\
	n &≥ \cfrac{\ln[x_d - x_i] - \ln ε}{\ln 2} \tag{No. iteraciones}
\end{alignat}
$$

#### Regla Falsa

$$x_m = \cfrac{x_i f(x_d) - x_d f(x_i)} {f(x_d) - f(x_i)}$$

#### Newton-Raphson

$$
\begin{alignat}{2}
	x_{n+1} = x_n - \cfrac {f(x_n)}{f'(x_n)}
\end{alignat}
$$

#### Punto Fijo

$$
\begin{alignat}{2}
	\begin{array}{c}
		x_1 = g \left(x_0 \right) \\
		x_2 = g \left(x_1 \right) \\
		x_3 = g \left(x_2 \right) \\
		\vdots \\
		x_{n+1} = g \left(x_n \right)
	\end{array} \tag{Arreglos} \\\\
	\lvert g\:' \left(x_n \right) \rvert < 1 \tag{Criterio de convergencia}
\end{alignat}
$$

### Sistemas de Ecuaciones

#### Lineales

> [!IMPORTANT]
>
> Es necesario el **predominio diagonal**

1. Acomodas respecto al **predominio diagonal**.
2. Despejas con respecto a $x_1$ en $f_1$, $x_2$ en $f_2 \dots$

##### Newton-Raphson

3. Evalúas los arreglos encontrados con el vector inicial y en cada iteración
   remplazas las incógnitas por los valores previamente encontrados.

##### Gauss Seidel

3. Remplazas los valores encontrados en la misma iteración, es decir, al
   encontrar $x_n$ se remplaza en las siguientes ecuaciones.

#### No lineales

##### Newton-Raphson Multivariable

$$
J =\begin{vmatrix}
	\cfrac{\partial f_1}{\partial_x} & \cfrac{\partial f_1}{\partial_y} \\
	\cfrac{\partial f_2}{\partial_x} & \cfrac{\partial f_2}{\partial_y} \\
	\end{vmatrix}
=
\begin{vmatrix}
	f_{1x} & f_{1y} \\
	f_{2x} & f_{2_y}
\end{vmatrix}
\neq 0\tag{Criterio de convergencia}
$$

$$
\begin{alignat}{2}
	x_1 = x_0 - \cfrac{f^0_{2y}f^0_{1} - f^0_{1y}f^0_2}{f^0_{1x}f^0_{2y} - f^0_{1y}f^0_{2x}} \\\\
	y_1 = y_0 - \cfrac{f^0_{1x}f^0_{2} - f^0_{2x}f^0_1}{f^0_{1x}f^0_{2y} - f^0_{1y}f^0_{2x}}
\end{alignat}
$$

##### Punto Fijo Multivariable

$$
\begin{matrix}
	\left | \cfrac{\partial g_1}{∂x}  \right | &+& \left | \cfrac{\partial g_2}{∂x} \right | \leq 1 \\\\
	\left | \cfrac{\partial g_1}{∂y} \right | &+& \left | \cfrac{\partial g_2}{∂y} \right | \leq 1
\end{matrix} \tag{Criterio de convergencia}
$$
