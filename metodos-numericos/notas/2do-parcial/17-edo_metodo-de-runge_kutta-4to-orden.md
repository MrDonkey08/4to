# Método de Runge-Kutta 

El **método de Euler** aunque es sencillo, es poco exacto para ecuaciones diferenciales de alto orden. Existe un método llamado de **Runge-Kutta** de 2do, 3er y 4to odren, que es equivalente a la aplicación de **fórmulas de Taylor de orden superior**, aunque _el de **4to orden** es el **más utilizado** por brindar la **mejor aproximación** para resolver **ecuaciones diferenciales**_, aunque el cálculo de la próxima aproximación requiere de cálculos adicionales para $k_1$, $k_2$, $k_3$ y $k_4$, entre ellos, _el de 4to orden es el mejor_. El método iterativo se enuncia a continuación:

$$\begin{align}
y_{n+1} = y_n + \cfrac{h}{6} (k_1 + 2k_2 + 2k_3 + k_4)
\end{align}$$

donde:

$$\begin{align}
	k_1 &= f(x_n,\; y_n)\\
	k_2 &= f(x_n + \cfrac{h}{2},\; y_n + \cfrac{h ⋅ k_1}{2})\\
	k_3 &= f(x_n + \cfrac{h}{2},\; y_n + \cfrac{h ⋅ k_2}{2})\\
	k_4 &= f(x_n + h,\; y_n + h ⋅ k_3)
\end{align}$$

## Ejemplo

Utiliza el **método de Runge - Kutta** de 4to orden para aproximar $\cfrac{dy}{dx} = x² + y$ con $y(0) = 1$ para $y(1)$, usando $h = 0.2$

> [!INFO]+ Datos
> 
> - $h = 0.2$
> - $x_0 = 0$
> - $y_0 = 1$
> - $x_f = 1$
> - $y_f = ¿?$

### Primera Iteración

$$\begin{array}{lllllll}
	k_1 &=& f(0,\; 1)										   &&			 		&=& 1\\
	k_2 &=& f(0 + \cfrac{0.2}{2},\; 1 + \cfrac{0.2 ⋅ 1}{2})	   &=& f(0.1,\; 1.11)   &=& 1.1\\
	k_3 &=& f(0 + \cfrac{0.2}{2},\; 1 + \cfrac{0.2 ⋅ 1.111}{2}) &=& f(0.1,\; 1.111)  &=& 1.21\\
	k_4 &=& f(0 + 0.2,\; 1 + 0.2 ⋅ 1.21) 				   &=& f(0.2,\; 1.2242) &=& 1.26420\\
\end{array} $$

$$y_1 = 1 + \cfrac{0.2}{6} [1 + 2(1.11) + 2(1.121) + 1.2642] = 1.22421$$

### Segunda Iteración

$$\begin{array}{lllllll}
	k_1 &=& f(0.2,\; 1.22421)											  &&				   &=& 1.26421\\
	k_2 &=& f(0.2 + \cfrac{0.2}{2},\; 1.22421 + \cfrac{0.2 ⋅ 1.26421}{2}) &=& f(0.1,\; 1.11)   &=& 1.44063\\
	k_3 &=& f(0.2 + \cfrac{0.2}{2},\; 1.22421 + \cfrac{0.2 ⋅ 1.44063}{2}) &=& f(0.1,\; 1.111)  &=& 1.45827\\
	k_4 &=& f(0.2 + 0.2,\; 1.22421 + 0.2 ⋅ 1.45827) 					  &=& f(0.2,\; 1.2242) &=& 1.67586\\
\end{array}$$

$$y_2 = 1 + \cfrac{0.2}{6} [1.26421 + 2(1.44063) + 2(1.45827) + 1.67586] = 1.51547$$

### Tercera Iteración

$$\begin{array}{lllllll}
	k_1 &=& f(0.4,\; 1.51547)											  &&					&=& 1.67547\\
	k_2 &=& f(0.4 + \cfrac{0.2}{2},\; 1.51547 + \cfrac{0.2 ⋅ 1.67547}{2}) &=& f(0.5,\; 1.51547) &=& 1.93302\\
	k_3 &=& f(0.4 + \cfrac{0.2}{2},\; 1.51547 + \cfrac{0.2 ⋅ 1.93302}{2}) &=& f(0.5,\; 1.70877) &=& 1.95877\\
	k_4 &=& f(0.4 + 0.2,\; 1.51547 + 0.2 ⋅ 1.95877) 				 	  &=& f(0.6,\; 1.90722) &=& 2.26722\\
\end{array}$$

$$y_3 = 1 + \cfrac{0.2}{6} [1.67547 + 2(1.93302) + 2(1.95877) + 2.26722] = 1.90635$$

### Cuarta Iteración

$$\begin{align}
	k_1 &= 2.26634\\
	k_2 &= 2.62298\\
	k_3 &= 2.65864\\
	k_4 &= 3.07807\\
\end{align}$$

$$y_4 = 2.43660$$

### Quinta Iteración

$$\begin{align}
	k_1 &= 3.07660\\
	k_2 &= 3.55426\\
	k_3 &= 3.60202\\
	k_4 &= 4.15700\\
\end{align}$$

$$y_5 = 3.15480$$

> [!DONE] Resultado
>
> $$y(1) = 3.15480 \tag{h = 0.2}$$

<div style="page-break-after: always;"></div>

## Referencias

- Minerva S. (2022). _Método de Runge Kutta de cuarto orden_. https://www.loom.com/share/ecfdd3b5875f4fa78b0bb8a65c904342?sid=f9f9d2bb-48f6-4a52-aa8c-d6f8770757e2