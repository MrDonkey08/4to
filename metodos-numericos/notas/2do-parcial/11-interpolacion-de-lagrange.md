# Interpolación de Lagrange 

El **polinomio interpolador** de Lagrange tiene la forma 

$$\begin{array}{c}
\prod \limits_{\substack {j=0 \\ i \neq j}}^n \cfrac{x-x_j}{x_i-x_j} 
& \text{o} &
y_0 = \sum \limits_{i=1}^n y_i \prod \limits_{j=1}^{\substack{n \\ j \neq i}} \cfrac{x_0 - x_j}{x_i - x_j}
\end{array}$$

## Polinomios

$$\begin{alignat}{4}
y_0 &= y_1 \cfrac{x_0 - x_2}{x_1 - x_2} 
	&+& y_2 \cfrac{x_0 - x_1}{x_2 - x_1} \tag{Grado 1} \\
y_0 &= y_1 \cfrac{x_0 - x_2}{x_1 - x_2} \cfrac{x_0 - x_3}{x_1 - x_3} 
	&+& y_2 \cfrac{x_0 - x_1}{x_2 - x_1} \cfrac{x_0 - x_3}{x_2 - x_3}  
	&+& y_3 \cfrac{x_0 - x_1}{x_3 - x_1} \cfrac{x_0 - x_2}{x_3 - x_2} \tag{Grado 2} \\ 
y_0 &= y_1 \cfrac{x_0 - x_2}{x_1 - x_2} \cfrac{x_0 - x_3}{x_1 - x_3} \cfrac{x_0 - x_4}{x_1 - x_4} 
	&+& y_2 \cfrac{x_0 - x_1}{x_2 - x_1} \cfrac{x_0 - x_3}{x_2 - x_3} \cfrac{x_0 - x_4}{x_2 - x_4} 
	&+& y_3 \cfrac{x_0 - x_1}{x_3 - x_1} \cfrac{x_0 - x_2}{x_3 - x_2} \cfrac{x_0 - x_4}{x_3 - x_4}  
	&+& y_4 \cfrac{x_0 - x_1}{x_4 - x_1} \cfrac{x_0 - x_2}{x_4 - x_2} \cfrac{x_0 - x_3}{x_4 - x_3} \tag{Grado 3}
\end{alignat}$$

## Ejemplo

Se requiere conocer la densidad del agua a 43.7 °C con un polinomio de grado 1, grado 2 ->, grado 2 <-

|   T °C   |  4  |    6    |   10    |   20    |   50    |   75    |   100   |
|:--------:|:---:|:-------:|:-------:|:-------:|:-------:|:-------:|:-------:|
| Densidad |  1  | 0.99997 | 0.99973 | 0.99823 | 0.98807 | 0.97489 | 0.95838 |

> [!NOTE]
> 
> El **polinomio interpolador** se obtiene sustituyendo todos los puntos cercanos al "desconocido" excepto $x_0$

### Grado 1

$$\begin{alignat}{2}
y_0 &= \cfrac{x - 50}{20 - 50} + 0.98807 \cfrac{x - 20}{50 - 20} \\
&= \cfrac{0.99823}{-30} (x - 50) + \cfrac{0.98807}{30} (x-20) \\
&= -0.03327(x - 50) + 063294(x-20) \\
&= -0.03327x + 1.6635 + 0.03294x - 0.05880 \\
&= -0.00033 x + 1.0047 \\
&= 0.99029 \approx 0.99020
\end{alignat}$$

### Grado 2 (derecha)

$$y_0 = 0.99072$$

### Grado 2 (izquierda)

$$y_0 = 0.99091$$