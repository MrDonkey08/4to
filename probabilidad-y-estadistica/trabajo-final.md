# Trabajo Final

## Distribuciones de probabilidad continúa.

Una distribución continua describe las probabilidades de los posibles valores de
una variable aleatoria continua. Una variable aleatoria continua es una variable
aleatoria con un conjunto de valores posibles (conocido como el rango) que es
infinito y no se puede contar.

Las probabilidades de las variables aleatorias continuas (X) se definen como el
área por debajo de la curva de su PDF. Por lo tanto, solo los rangos de valores
pueden tener una probabilidad diferente de cero. La probabilidad de que una
variable aleatoria continua equivalga a algún valor siempre es cero.

### Distribución F de Snedecor.

La **distribución F de Snedecor** es una distribución de _probabilidad continúa_
que usa la _inferencia estadística_, especialmente el análisis de la varianza,
técnica que permite detectar la existencia o inexistencia de diferencias
significativas entre muestras diferentes y que es, por tanto esencial, en todos
aquellos casos en los que se quiere investigar la relevancia de un factor en el
desarrollo y naturaleza de una característica.

#### Caracteristicas principales

Los grados de libertad de la distribución F de Snedecor, $m$ y $n$, son dos
parámetros que definen la forma de la distribución. Estos valores
característicos de la distribución F de Snedecor son números enteros y
positivos.

$$
\begin{array}{c}
	m, n ∈ ℝ, & m, n > 0
\end{array}
$$

El dominio de la distribución F de Snedecor son todos los números reales mayores
o iguales que cero $$x ∈ [0, \infty)$$

Si una variable sigue una distribución F de Snedecor con grados de libertad m y
n, entonces la inversa de dicha variable sigue una distribución F de Snedecor
con los mismos grados de libertad pero cambiando el orden de sus valores.

Para valores de $n$ más grandes que 2, la media de la distribución F de Snedecor
es igual a n partido por la resta de $n$ menos 2.

$$
\begin{array}{cc}
	X ∼ F_{m, n}\\
	E[X] = \frac{n}{n-2}, & n > 2
\end{array}
$$

Cuando el parámetro n es mayor que 2, se puede calcular la varianza de la
distribución F de Snedecor aplicando la siguiente fórmula:

$$
\begin{array}{c}
	X\sim F_{m,n}\\
	[2ex] Var(X) = \frac{2n^2 \cdot (m+n-2)}{m \cdot (n-2)^2\cdot (n-4)}, \qquad n > 4
\end{array}
$$

Si el parámetro m es mayor que 2, la moda de la distribución F de Snedecor se
puede calcular con la siguiente expresión:

$$Mo=\frac{m-2}{m}\cdot \frac{n}{n+2}\qquad \text{para }m>2$$

La fórmula de la función de densidad de la distribución F de Snedecor es la
siguiente:

$$P[X=x]=\frac{\Gamma\left(\frac{m+n}{2}\right)}{\Gamma\left(\frac{m}{2}\right)\Gamma\left(\frac{n}{2}\right)}\left(\frac{m}{n}\right)^{\frac{m}{2}}\cdot\frac{x^{\frac{m-2}{2}}}{\left(1+\frac{mx}{n}\right)^{\frac{m+n}{2}}}$$

$$X\sim F_{m,n} {\longrightarrow} \ X^{-1}\sim F_{n,m}$$

La distribución t de Student tiene la siguiente relación con la distribución F
de Snedecor: $$X\sim t_n \ {\longrightarrow} \ X^2\sim F_{1,n}$$

Si el parámetro m es mayor que 2, la moda de la distribución F de Snedecor se
puede calcular con la sigu

#### Modelo matemático

Matemáticamente, la distribución F de Snedecor es igual al cociente entre una
distribución chi-cuadrado y sus grados de libertad partido por el cociente entre
otra distribución chi-cuadrado y sus grados de libertad. De modo que la fórmula
que define la distribución F de Snedecor es la siguiente:

$$
\left.\begin{array}{c}
	X\sim \chi_m^2\\[2ex] Y\sim \chi_n^2
\end{array}\right\}
⟶ F_{m,n}= \frac{X/m}{Y/n}
$$

#### Ejemplo de aplicación

Considere dos muestras de poblaciones que tienen la misma varianza poblacional.
Si la muestra 1 tiene tamaño $n_1$ = 5 y la muestra 2 tiene tamaño $n_2 = 10$,
determine la probabilidad teórica que el cociente de sus varianzas respectivas
sea menor o igual a 2.

Como se desea saber la probabilidad teórica de que este cociente de varianzas
muestrales sea menor o igual a 2, necesitamos conocer el área bajo la
distribución F entre 0 y 2, el cual puede obtenerse por tablas o software. Para
esto ha de tenerse en cuenta que la distribución F requerida tiene

$$d1 = n1 – 1 = 5 – 1 = 4 y d2 = n2 – 1 = 10 – 1 = 9$$

Es decir la distribución F con grados de libertad (4, 9)

Mediante el uso de la herramienta estadística de geogebra se determinó que esta
área es 0.82, por lo que se concluye que la probabilidad que el cociente de
varianzas muestrales sea menor o igual a 2 es del 82%.

### Distribución Ji o Chi

La distribución de chi-cuadrada es una distribución continua que se especifica
por los grados de libertad y el parámetro de no centralidad. La distribución es
positivamente asimétrica, pero la asimetría disminuye al aumentar los grados de
libertad.

#### Caracteristicas principales

- La media de una distribución chi-cuadrado es igual a sus grados de libertad.

- La varianza de una distribución chi-cuadrado es equivalente al doble de los
  grados de libertad de la distribución.

- La moda de una distribución chi-cuadrada es dos unidades menos que sus grados
  de libertad, siempre y cuando la distribución tenga más de un grado de
  libertad.

- La función de densidad de la distribución chi-cuadrado es nula si x=0. No
  obstante, para valores de x mayores que 0, la función de densidad de una
  distribución chi-cuadrado se define mediante la siguiente fórmula:

- La función de distribución acumulada de la distribución chi-cuadrado está
  regida por la siguiente fórmula:

- El coeficiente de asimetría de la distribución chi-cuadrado es la raíz
  cuadrada del cociente de ocho entre el número de grados de libertad de la
  distribución.

- La curtosis de la distribución chi-cuadrado se calcula mediante la siguiente
  expresión:

- Como consecuencia del teorema del límite central, la distribución chi-cuadrado
  puede aproximarse por una distribución normal si k es suficientemente gradne.

#### Modelo matemático

La distribución chi-cuadrado tiene k grados de libertad. Por lo tanto, una
distribución chi-cuadrada tiene tantos grados de libertad como la suma de los
cuadrados de variables con distribución normal que representa.

$$
X\sim\chi^2_k \ {\longrightarrow}\
\begin{array}{l}\text{Distribución chi-cuadrado}\\
	[2ex]\text{con k grados de libertad}\end{array}
	X\sim\chi^2_k \ {\longrightarrow}\
\begin{array}{l}
	\text{Distribuci\'on chi-cuadrado}\\[2ex]\text{con k grados de libertad}
\end{array}
$$

La distribución chi-cuadrado también se conoce como distribución de Pearson.

Cabe destacar que la distribución chi-cuadrado es un caso especial de la
distribución gamma.

#### Ejemplo de aplicación

Para estudiar la dependencia entre la práctica de algún deporte y la derpresión,
se seleccionó una muestra aleatoria cimple de 100 jóvenes, con los siguientes
resultados

|               | Sin Depresión | Con Depresión |
| ------------- | :-----------: | :-----------: |
| Deportista    |      38       |       9       |
| No deportista |      31       |      22       |

Determinar si existe independencia entre la actividad del sujeto y su estado de
ánimo. Nivel de significancia (5%)

**Solución**

Debemos primero calcular las frecuenciar esperadas bajo el supuesto de
independencia. La tabla de frecuencias esperadas sería:

|               | Sin Depresión | Con Depresión |     |
| ------------- | :-----------: | :-----------: | :-: |
| Deportista    |     32.43     |     14.57     | 47  |
| No deportista |      31       |      22       | 53  |
|               |      69       |      31       | 100 |

Calculamos ahora el estadístico del contraste

$$
\chi² = \frac{(38 - 32.43)²}{32.43}
	+ \frac{(9 - 14.57)²}{14.57}
	+ \frac{(31 - 36.57)²}{36.57}
	+ \frac{(22 - 16.43)²}{16.43}
	= 5.82
$$

Este valor debemos compararlo con el percentil de la distribución $\chi²$ con
$(2-1)(2-1) = 1$ grado de libertad $\chi_{0.95} (1) = 3.84$

Por lo tanto como el valor del estadístico es superior al valor crítico,
concluimos que debemos rechazar la hipótesis de independencia y, por lo tanto,
asumir que existe relación entre la depresión en los hábitos de los deportistas
humanos.

### Distribución t de Student

la distribución t es una distribución de probabilidad que estima el valor de la
media de una muestra pequeña extraída de una población que sigue una
distribución normal y de la cual no conocemos su desviación típica.

#### Caracteristicas principales

- Es simétrica, con μ = 0. Su forma es muy parecida a la N(0,1), aunque menos
  apuntada.
- Puede tomar cualquier valor entre -∞ y +∞.
- A medida que aumentan los grados de libertad, la distribución se aproxima más
  a una distribución normal.
- La curva es asintótica al eje de abscisas.

#### Modelo matemático

Su expresión formal parte de dos variables $X$ e $Y$ tales que:
$$X \to N[0, 1] \qquad Y \to \chi_n² $$

de manera que $$t = \frac{X}{\sqrt{\frac{Y}{n}}}$$

siendo $t$ una nueva distribución conocida com $t$ de student con $n$ grados de
libertad.

La distribución t de student admite, tambien, una definición alternativa, tomada
como la distribución marginal de la primera variable de una distribución
"normal-gamma"; en este sentido la expresión de su función de densidad vendría
dada por:

$$
f(x) = \frac{\Gamma \left(\frac{n+1}{2} \right)} {\Gamma \left(\frac{n}{2} \right) \sqrt{\pi n}}
\left[1 + \frac{x²}{n} \right]^{\frac{-(n+1)}{2}}
$$

siendo $n$ los grados de libertad que actuan de parámetro y $\Gamma$ la función
gamma de Euler.

#### Ejemplo de aplicación

Acme Corporation fabrica bombillas. El director general afirma que una bombilla
media de Acme dura 300 días. Un investigador selecciona al azar 15 bombillas
para probarlas. Las bombillas de la muestra duran una media de 290 días, con una
desviación típica de 50 días. Si la afirmación del director general fuera
cierta, ¿cuál es la probabilidad de que 15 bombillas seleccionadas al azar
tengan una vida media no superior a 290 días?

> [!NOTE]
>
> Hay dos maneras de resolver este problema, utilizando la calculadora de
> distribución T. Ambas se presentan a continuación. Ambos enfoques se presentan
> a continuación. La solución A es el enfoque tradicional. Requiere que calcule
> la estadística t, basándose en los datos presentados en la descripción del
> problema. A continuación, se utiliza la calculadora de distribución T para
> hallar la probabilidad. La solución B es más sencilla. Basta con introducir
> los datos del problema en la Calculadora de Distribución T. La calculadora
> calcula un estadístico t. La calculadora calcula un estadístico t "entre
> bastidores" y muestra la probabilidad. Ambos métodos dan exactamente la misma
> respuesta.

**Solución:** A Lo primero que tenemos que hacer es calcular el estadístico t,
basándonos en la siguiente ecuación:

$$
\begin{array}{cc}
	t = \frac{ x - μ }{s / \sqrt{n}}\\
	t = \frac{290 - 300}{50 / \sqrt{15}}\\
	t = -\frac{10}{12.909945} = - 0.7745966
\end{array}
$$

### Distribución uniforme

La distribución uniforme es una distribución se refiere a eventos que tienen la
misma probabilidad de ocurrir. Cuando se resuelven problemas que tienen una
distribución uniforme, hay que tener en cuenta si los datos son inclusivos o
excluyentes de los extremos.

#### Caracteristicas principales

- La distribución uniforme continua queda definida por dos parámetros reales, a
  y b, que establecen los límites dentro de los cuales la probabilidad es
  constante.

- La distribución uniforme continua solo puede tomar valores que se encuentren
  dentro del intervalo formado por a y b, ambos incluidos.

- La media de una distribución uniforme continua es igual a la suma de sus dos
  parámetros característicos partido por dos.

- La varianza de una distribución uniforme continua es equivalente al cuadrado
  de la diferencia entre b y a dividido por doce.

- La mediana de una distribución uniforme continua coincide con su media, por lo
  que se calcula utilizando la misma fórmula:

- La distribución uniforme continua es simétrica, por lo tanto, el coeficiente
  de asimetría de este tipo de distribución es nulo.

- La curtosis de una distribución uniforme continua no depende de sus
  parámetros, siempre vale -6 partido por 5.

La - distribución uniforme estándar es aquella distribución uniforme continua
cuyos parámetros a y b valen 0 y 1 respectivamente.

#### Modelo matemático

La función de densidad de probabilidad (PDF) de una distribución uniforme en el
intervalo $[a, b]$ se define como:

$$f(x) = \frac{1}{b-a}$$

Para calcular la **media teorica** y la **desviación típica** tenemos las
siguientes fórmulas:

$$\mu = \frac{a+b}{2}, \qquad \sigma = \sqrt {\frac{(b-a)^2}{12}}$$

#### Ejemplo de aplicación

La cantidad de tiempo, en minutos, que una persona debe esperar un autobús se
distribuye uniformemente entre cero y 15 minutos, ambos inclusive. ¿Cuál es la
probabilidad de que una persona espere menos de 12,5 minutos?

Supongamos que $X =$ el número de minutos que una persona debe esperar el
autobús; $a = 0$ y $b = 15$. $X ~ U(0, 15)$. Escriba la función de densidad de
probabilidad y calcule $P (x < 12,5)$.

$$f(x) = \frac{1}{15-0} = \frac{1}{15} \tag{Densidad de probabilidad}$$

$$P(x<k) = (\text{base})(\text{altura})=(12.5–0) \left(\frac{1}{15} \right) = 0.8333$$

La probabilidad de que una persona espere menos de 12.5 minutos es de 0.8333.

<div style="page-break-after: always;"></div>

## Prueba de hipótesis

Una prueba de hipótesis es una regla que especifica si se puede aceptar o
rechazar una afirmación acerca de una población dependiendo de la evidencia
proporcionada por una muestra de datos.

Una prueba de hipótesis examina dos hipótesis opuestas sobre una población:

**Hipotesis Nula ($H_0$):** Hipótesis de no cambio. Es la hipótesis de que todo
queda igual. Hay otra hipótesis que es la hipótesis de cambio. Siempre en esta
hipótesis va a estar el igual.

**Hipotesis alternativa ($H_1$):** Es complementaría a la nula. Niega a la
hipótesis nula. Se utiliza o bien el símbolo de distinto $\neq$, \> o \<

### Anova

Un análisis de varianza (ANOVA) prueba la hipótesis de que las medias de dos o
más poblaciones son iguales. Los ANOVA evalúan la importancia de uno o más
factores al comparar las medias de la variable de respuesta en los diferentes
niveles de los factores. La hipótesis nula establece que todas las medias de la
población (medias de los niveles de los factores) son iguales mientras que la
hipótesis alternativa establece que al menos una es diferente.

#### De un factor.

El análisis de la varianza permite contrastar la hipótesis nula de que las
medias de K poblaciones ($K > 2$) son iguales, frente a la hipótesis alternativa
de que por lo menos una de las poblaciones difiere de las demás en cuanto a su
valor esperado. Este contraste es fundamental en el análisis de resultados
experimentales, en los que interesa comparar los resultados de K 'tratamientos'
o 'factores' con respecto a la variable dependiente o de interés.

$$
\begin{array}{cc}
	H_0: \mu_1 = \mu_2 = \cdots = \mu_k = \mu \\
	H_1: \exists \mu_i \neq \mu \qquad i = 1, 2, \dots, k
\end{array}
$$

El modelo de un factor consiste en:

$$Y = \mu X + N(0, \sigma x + N(0, \sigma²)$$

donde:

- $Y$: variable numérica de gran interés
- $X$: factor que podría influir sobre el valor final de $Y$
  - $x_1, x_2,\dots, x_a$: niveles del factor $X$ ($a =$ número de niveles)
  - Muestreo:
    - Se toma $X = x_i$
    - Se observa $y_{ij} = u_i + e_{ij}$ para $j = 1, 2, \dots$, donde
      - $\mu$ es el valor medio de $Y$ provocado por el nivel $X = x_i$ del
        factor
      - $e_{ij}$ es un valor aleatorio, sigue el modelo $N(0, \sigma²), es
        independiente de todos los valores muestreados.

#### De dos factores

**Sin interacción**

$$Y = \mu_A + \mu_B + N(0, \sigma²)$$

donde:

- $Y$: variable numérica de gran interés
- $A$ un factor que podría influir sobre el valor final de $Y$
  - $A_1, A_2, \dots, A_a$: niveles del factor $A$ ($a =$ número de niveles)
- $B$ otro factor que podría influir sobre el valor final de $Y$
  - $B_1, B_2, \dots, B_b$: niveles del factor $B$ ($b =$ número de niveles)
- Parámetros:
  - $\mu_{A_1}, \mu_{A_2}, \dots, \mu_{A_a}$ (correspondientes al factor $A$)
  - $\mu_{B_1}, \mu_{B_2}, \dots, \mu_{B_b}$ (correspondientes al factor $B$)
  - $e_{ijk}$ es un valor aleatorio, sigue el modelo $N(0, \sigma²), es
    independiente de todos los valores muestreados.

**Con interacción**

$$Y = \mu_A + \mu_B + \ γ_{(A, B)}  + N(0, \sigma²)$$

- El plantamiento es el mismo con los dos factores $A$ y $B$
- El efecto “conjunto” de una combinación de niveles $A$ y $B$ NO ES “la suma de
  los efectos marginales”, es decir:
  - $y_{ijk} = \mu_{A_i} + \mu_{B_i} + \ γ_{({A_i}, {B_i})} + e_{ijk}$
  - con $γ_{A_i, B_i} \neq 0$ al menos para alguna combinación de niveles
    $A_i, B_j$
- El ANOVA esuelve tres contrastes, uno para cada factor, y otro para la posible
  interacción, sobre la respuesta $Y$. El $p$-valor de cada estadístico $F$
  ayuda a decidir sobre la significatividad del efecto de cada factor, y el de
  la interacción, sobre la respuesta $Y$
- La interacción se puede chequear también gráficamente

#### Por bloques

La prueba de hipótesis con bloques, también conocida como análisis de covarianza
(ANCOVA), es una extensión de la ANOVA (análisis de la varianza) que incorpora
una o más variables continuas adicionales, llamadas covariables o variables de
bloque. Esta técnica se utiliza cuando se sospecha que la relación entre las
variables independientes y la variable dependiente puede estar influenciada por
una variable adicional que se utiliza como bloqueo o control.

En un diseño de bloques, los participantes o las unidades experimentales se
dividen en grupos homogéneos basados en la covariable antes de asignarlos a los
diferentes niveles de la variable independiente. La inclusión de covariables en
el análisis ayuda a eliminar parte de la variabilidad no deseada y mejora la
precisión de las estimaciones.

**Prueba Estadística:** La prueba de ANCOVA utiliza una combinación de análisis
de varianza y regresión lineal para evaluar si las diferencias en las medias de
los grupos son significativas después de tener en cuenta la covariable.

### Para qué sirve

El Análisis de la Varianza (ANOVA) es una técnica estadística muy versátil y se
utiliza en una amplia variedad de campos. Algunos de los principales usos del
ANOVA son:

- **Comparación de medias:** Para comparar la media de tres o más grupos y
  determinar si existen diferencias significativas entre ellas.

- **Experimentos controlados:** Para analizar los efectos de diferentes
  tratamientos o intervenciones en los resultados.

- **Investigación médica:** Para analizar los efectos de diferentes tratamientos
  en pacientes con una determinada enfermedad.

- **Ciencias sociales:** Para analizar la relación entre diferentes variables,
  como la edad, la educación y los ingresos.

- **Investigación de mercados:** Para analizar la preferencia de los
  consumidores por diferentes productos o servicios.

### Cómo se calcula

1. Encuentra la media para cada grupo que estás comparando.
2. Calcula la media global o la media de los grupos combinados.
3. Calcula la variación dentro del grupo, o desviación de cada puntuación
   respecto a la media del grupo
4. Calcula la variación entre grupos, o desviación de la media de cada grupo
   respecto a la media general.
5. Calcula la relación F, o relación entre la variación entre grupos y la
   variación dentro de los grupos.

<div style="page-break-after: always;"></div>

## Referencias

- Soporte de Minitab 21. (s. f.). _Distribuciones de probabilidad continuas y
  discretas_.
  https://support.minitab.com/es-mx/minitab/21/help-and-how-to/probability-distributions-random-data-and-resampling-analyses/supporting-topics/basics/continuous-and-discrete-probability-distributions/

- Academia Balderix. (s. f.). _Distribución F de Snedecor_.
  https://www.probabilidadyestadistica.net/distribucion-f-de-snedecor/

- UV (s. f.). _DISTRIBUCIÓN F DE SNEDECOR_.
  https://www.uv.es/ceaces/normaMu/f/f.htm

- Zapata, F. (diciembre 15, 2022). _Distribución F: características y ejercicios
  resueltos_. https://www.lifeder.com/distribucion-f/

- Rodó P. (noviembre 5, 2019). _Distribución t de Student_.
  https://economipedia.com/definiciones/distribucion-t-de-student.html

- UV (s. f.). _DISTRIBUCIÓN t DE STUDENT_.
  https://www.uv.es/ceaces/normaMu/t/t.htm

- Psikipedia. (s. f.). _7.3 La distribución "t" de Student_.
  https://psikipedia.com/libro/analisis-de-datos/la-distribucion-t-de-student

- Berman H.B (s. f.). _Student's t Distribution_.
  https://stattrek.com/probability-distributions/t-distribution

- https://www.jmp.com/es_pe/statistics-knowledge-portal/chi-square-test.html

- Ventero, V. (noviembre 21, 2017). _Ejemplo aplicación chi cuadrado como prueba
  de independencia_.
  https://cedepir.es/blog/ejemplo-aplicacion-chi-cuadrado-prueba-independencia/

- Soporte de Minitab (s. f.). _Distribución de chi-cuadrada_.
  https://support.minitab.com/es-mx/minitab/21/help-and-how-to/probability-distributions-random-data-and-resampling-analyses/supporting-topics/distributions/chi-square-distribution/

- Openstax. (s. f.). _5.2 La distribución uniforme_.
  https://openstax.org/books/introducci%C3%B3n-estad%C3%ADstica-empresarial/pages/5-2-la-distribucion-uniforme

- Academia Balderix (s. f.). _Distribución uniforme continua_.
  https://www.probabilidadyestadistica.net/distribucion-uniforme-continua/

- Soporte de Minitab (s. f.). _¿Qué es una prueba de hipótesis?_.
  https://support.minitab.com/es-mx/minitab/20/help-and-how-to/statistics/basic-statistics/supporting-topics/basics/what-is-a-hypothesis-test/

- Fede (octubre 14, 2016). _Prueba de Hipótesis Estadística: una explicación
  desde cero_. https://probafacil.com/prueba-de-hipotesis-estadistica/

- Soporte Minitab. (s. f.). _¿Qué es ANOVA?_.
  https://support.minitab.com/es-mx/minitab/21/help-and-how-to/statistical-modeling/anova/supporting-topics/basics/what-is-anova/

- JMP (s. f.). _ANOVA de un factor_.
  https://www.jmp.com/es_pe/statistics-knowledge-portal/one-way-anova.html

- GoCardless (diciembre, 2020). _Analysis of Variance (ANOVA)_.
  https://gocardless.com/guides/posts/how-to-calculate-analysis-of-variance/

- Gregori, P. (s. f.). _Práctica 5: El modelo ANOVA (ANalysis Of VAriance) de
  uno y dos factores_.
  https://www3.uji.es/~gregori/docencia/mt1021-2021/mt1021-2021-la-5-anova-CAST.html

- IBM (diciembre 07, 2021). _Análisis de covarianza (ANCOVA)_.
  https://www.ibm.com/docs/es/spss-statistics/beta?topic=features-analysis-covariance-ancova
