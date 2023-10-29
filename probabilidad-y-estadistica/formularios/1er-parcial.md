# Probabilidad y Estadística

## Medidas de centralización

- Media: $\overline{x}$
- Mediana: $\tilde{x}$
- Moda: $\hat{x}$ 

## Medidas de Dispersión

> [!IMPORTANT]
> 
> Población $= \sigma$ y muestras $= S$

$$R = \text{Dato mayor} -  \text{Dato menor} \tag{Rango}$$

$$\begin{array}{c}
\sigma² = \cfrac{1}{n} \sum \left(X_i - \overline{X}  \right)² &&
S_x^2 = \cfrac{1}{n-1} \sum \left(X_i - \overline{X}  \right)² \tag{Varianza}
\end{array}$$

$$\begin{array}{c}
\sigma = \sqrt{\cfrac{1}{n} \sum \left(X_i - \overline{X} \right)}&& S_x = \sqrt{\cfrac{1}{n-1} \sum \left(X_i - \overline{X} \right)} \tag{Desviación estándar / típica}
\end{array}$$

$$D_m = \cfrac{1}{n-1} \sum |X-1 - \overline{X} | \tag{Desviación media}$$

$$MG = \sqrt[n]{X_1 \cdot X_2 \cdot X_3 \cdots X_n} \tag{Media Geométrica}$$

$$CV = \cfrac{S_x}{| \overline{X} |} \tag{Coeficiente de variación}$$

$$\begin{array}{cc}
R_{ic} = Q_3 - Q_1\tag{rango intercuartil}, && \text{donde } & Q_n = \text{cuartil } n 
\end{array}$$

$$S_{xy} = \cfrac 1n \sum (x-\overline{x})(y-\overline{y})$$

## Relación entre dos conjuntos de datos

$$r = \cfrac{ \sum (x-\overline{x})(y-\overline{y})}{\sqrt{\sum (x-\overline{x})²(y-\overline{y})²}} = \cfrac{S_{xy}}{S_xS_y} \tag{coeficiente de correlación muestral}$$

> [!NOTE]
> 
> - $I + III > II + IV \to \text{Correlación positiva}$
> - $I + III < II + IV \to \text{Correlación negativa}$
> - $I + III = II + IV \to \text{Datos insuficientes para determinar correlación}$
