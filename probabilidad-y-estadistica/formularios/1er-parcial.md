# Probabilidad y Estadística

## Medidas de centralización

- Media: $\overline{x}$
- Mediana: $\tilde{x}$
- Moda: $\hat{x}$

## Medidas de Dispersión

> [!IMPORTANT]
>
> Población $= \sigma$ y muestras $= S$

$$\begin{align}
    R &= \text{Dato mayor} - \text{Dato menor} \tag{Rango}\\\\
    \sigma_x^2 &= \cfrac{1}{n} \sum \left(x_i - \overline{x} \right)² &
    S_x^2 &= \cfrac{1}{n-1} \sum \left(x_i - \overline{x} \right)² \tag{Varianza}\\\\
    \sigma &= \sqrt{\cfrac{1}{n} \sum \left(x_i - \overline{x} \right)}& S_x &= \sqrt{\cfrac{1}{n-1} \sum \left(x_i - \overline{x} \right)} \tag{Desviación estándar / típica}\\\\
    D_m &= \cfrac{1}{n-1} \sum |x - \overline{x} | \tag{Desviación media}\\\\
    MG &= \sqrt[n]{x_1 \cdot x_2 \cdot x_3 \cdots x_n} \tag{Media Geométrica}\\\\
    CV &= \cfrac{S_x}{| \overline{x} |} \tag{Coeficiente de variación}\\\\
    R_{ic} &= Q_3 - Q_1, && \text{donde } Q_n = \text{cuartil } n \tag{Rango intercuartil}\\\\
    S_{xy} &= \cfrac 1n \sum (x-\overline{x})(y-\overline{y})\\\\
\end{align}$$

## Relación entre dos conjuntos de datos

$$r = \cfrac{ \sum (x-\overline{x})(y-\overline{y})}{\sqrt{\sum (x-\overline{x})²(y-\overline{y})²}} = \cfrac{S_{xy}}{S_xS_y} \tag{Coeficiente de correlación muestral}$$


> [!NOTE]
>
> - $I + III > II + IV \to \text{Correlación positiva}$
> - $I + III < II + IV \to \text{Correlación negativa}$
> - $I + III = II + IV \to \text{Datos insuficientes para determinar correlación}$
