# Solución de Sistemas de Ecuaciones no Lineales

## Método de Newton-Raphson Multivariable

El criterio de convergencia de este método se cumple si el determinante (Jacobiano) es distinto de cero, es decir, 

$$\begin{bmatrix}
\cfrac{af1}{a_x} & \cfrac{af1}{a_y} \\
\cfrac{af2}{a_x} & \cfrac{af2}{a_y} \\
\end{bmatrix}$$

Luego la primera iteración está dada por 

$$x_1 = x_0 - \cfrac{f^0_{2y}f^0_{1} - f^0_{1y}f^0_2}{f^0_{2x}f^0_{1} - f^0_{1x}f^0_2}$$

$$y_1 = y_0 - \cfrac{f^0_{1x}f^0_{1} - f^0_{1y}f^0_2}{f^0_{2x}f^0_{1} - f^0_{1x}f^0_2}$$
