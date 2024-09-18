# Estabilidad y error

---

## Métodos numéricos

Los **métodos numéricos** son aquellas técnicas mediante las cuales es posible
formular problemas matemáticas, de tal manera que puedan solucionarse usando
**operaciones aritméticas**.

-- Si bien los **métodos numéricos** requieren de un gran cantidad de tediosos
**cálculos aritméticos**, la evolución de las computadoras nos ha permitido
realizar estos cálculos rápida y efictivamente y con ello resolver problemas
que, sin ellas, implicarían muchos recursos.

---

## Método analítico

Los **métodos analíticos** son aquellos que tienen una serie de **fórmulas**
bien definidas, ordenadas y finitas, de modo que al aplicarse a un problema en
particular siempre se llegaa un resultado real

---

## Método recursivo

El **método recursivo** es aquel en el que el que el procedimiento se llama a sí
mismo hasta cumplir cierta condición para, de esta manera, llegar a un
resultado.

---

## Análisis numérico

El **análisis numérico** consiste en solucionar **problemas matemáticos**
mediante el uso de una computadora.

Este se encarga de realizar un _análisis de los **algoritmos numéricos**_ con la
finalidad de controlar el error asociado por la **aproximación matemática**, y
obtener un resultado muy aproximado a la solución exacta del problema.

---

## Análisis matemático

El **análisis matemático** es una _área de las **matemáticas**_ que estudia el
comportamiento de los **números reales** y los **números complejos**.

Abarca también las construcciones que se obtienen de estos números, tales como
las funciones, series, sucesiones, continuidad, límites y convergencia así como
las ramas de la integración y derivabilidad.

---

## Iteración

Se le llama **iteración** a la acción de repetir un **proceso** varias veces con
el objetivo de conseguir un **resultado**.

---

## Cifras significativas

Se les llama **cifras significativas** (c.s.) al **conjunto de dígitos** que se
conocen con **certeza** (cifras exactas) más **uno estimado**.

Todos los _**dígitos** diferentes de **cero**_ son **cifras significativas**.

--

### Ceros

Los **ceros** que se encuentran entre _**cifras** diferentes de **cero**_ son
**cifras significativas**.

> [!NOTE] Números con ceros al principio o al final
>
> Para indicar los **ceros significativos** de estos números, se puede utilizar
> **notación científica**.

--

### Ceros en números decimales

- Cuando los **ceros** de un **número** solo se utilizan para indicar el
  **número decimal** (e.g. **0.000**827 = 8.27 ⋅ 10⁻⁴), _no son **cifras
  significativas**_.

- Cuando los **ceros** de un **número decimal** se encuentran **al final**, son
  **cifras significativas** (e.g. 0.02700 = 2,700 ⋅ 10⁻³).

--

### Ceros en números enteros

Cuando los **ceros** de un **número entero** se encuentran **al final** y son
**exactos**, son **cifras significativas**; se le puede agregar una _línea
encima_ del _último **dígito significativo**_ para indicarlo (e.g. 182,0̅**00** =
1,820 ⋅ 10²).

Adicionalmente, si _todos los **ceros** son **exactos**_, se agrega un _punto al
final del **número**_ para indicarlo (e.g. 3,400.).

---

## Errores en el manejo de los números.

Los **errores numéricos** surgen del uso de las **aproximaciones** para
representar operaciones y cantidades exactas.

---

## Error de redondeo

El **error de redondeo** es el hecho de omitir el resto de **cifras
significativas**.

Los **números irracionales** (e.g. $\pi, e, \sqrt{2}$), como su definición
indica, son números que no se pueden expresar con un cantidad finita de dígitos.
Esto conlleva que, al trabajar con ellos, es imposible definir una **cantidad
exacta**, lo que conlleva al **error de redondeo**.

---

## Error de truncamiento

Los **errores de truncamiento** son aquellos que resultan al utilizar una
aproximación en lugar de un procedimiento matemático exacto.

La substitución de procesos infinitos por procesos finitos, tales como el
truncamiento de series, el uso se sumas limitadas para el cálculo de integrales
o el uso de diferencias finitas para el cálculo de derivadas. Los **errores de
truncamiento** provocan inexactitud.

---

## Error inherente

Los **errores inherentes**, también conocidos como **error por neglicencia** o
**por equivocación** son aquellos que las personas cometemos con el manejo de
los instrumentos de medición o por el incorrecto manejo de los datos.

---

## Error absoluto

El **error absoluta** es la diferencia entre el valor **valor verdadero** y el
valor aproximado, esto es:

$$E_t = \text{valor verdadero} - \text{valor aproximado}$$

---

## Error relativo

A diferencia del **error absoluto** el **error relativo** es permite tomar en
cuenta las magnitudes de las cantidades que se evaluan, para así normalizar el
error respecto al valor vedadero:

$$\text{Error relativo fraccional verdadero} = \cfrac{\text{error verdadero}}{\text{valor verdadero}}$$

---

## Error relativo porcentual

El **error relativo porcentual** permite expresar el **error relativo** a manera
de **porcentaje**:

$$E_r = \cfrac{\text{error verdadero}}{\text{valor verdadero}} 100\%$$

---

## Exactitud y precisión

> [!QUOTE]
>
> La exactitud se refiere a qué tan cercano está el valor calculado o medido del
> valor verdadero. La precisión se refiere a qué tan cercanos se encuentran,
> unos de otros, diversos valores calculados o medidos.

-- ![Exactitud y precisión  | 400](attachments/exactitud-y-presición.png)

Un ejemplo de puntería ilustra los conceptos de exactitud y precisión. a)
Inexacto e empreciso; b) exacto e impreciso; c) inexacto y preciso; d) exacto y
preciso.

---

## Aritmética de punto flotante.

El **punto flotante** es una forma de **notación científica** que permite a las
computadoras representar **números reales** extremadamente grandes y pequeños
eficiente y compactamente.

La **aritmética de punto flotante** es la manera en la que el computador realiza
las diferentes **operaciones** utilizando \*\*números de punto flotante.

---

## Algoritmo

Un **algoritmo** es una serie de pasos, instrucciones o reglas definidas que
permiten conseguir un resultado y con ello resolver un problema.

---

## Estabilidad y convergencia

La **convergencia** se refiere a que conforme $\Delta x$ y $\Delta y$ tiendan a
cero, los resultados de la por diferencias finitas se aproximaran a la
**solución verdadera**

Por otra parte, la **estabilidad** es el hecho de que en una _etapa del cálculo_
no se _amplifican los **errores**_, sino que se atenúan conforme avanza el
cálculo. Se puede demostrar que

--

### Demostración de convergencia y estabilidad

Se puede **demostrar** que el **método explicíto** es **convergente** y
**estable** si:

$$
\begin{array}{cc}
\lambda ≤  \cfrac{1}{2}&& o && \Delta t ≤ \cfrac{1}{2} \cfrac{\Delta x²}{k}
\end{array}
$$

---

## Referencias

- Chapra, S., Canale, R. (2015). _Métodos numéricos para ingenieros_
  (7<sup>a</sup> ed.) (pp. 3, 44-46, 63, 83, 681). Mc Graw Hill Education

- Gutiérrez, J., Olmos, M. & Casillas, J. (2010). _Análisis numérico_ (pp 12).
  Mc Graw Hill

--

- Métodos Garlex (16 de febrero de 2023). _Tipos de errores y su clasificación
  en los métodos numéricos_.
- https://metodosgeralex.home.blog/2019/02/16/tipos-de-errores-y-su-clasificacion-en-los-metodos-numericos

- Noguera, B. (27 de noviembre de 2021). _¿Qué son los métodos numéricos?_.
  https://www.ingenieriaquimicareviews.com/2020/10/metodos-numericos.html

--

- Garza M. (s.f.). _DIFERENCIA ENTRE UN METODO NUMERICO Y UN ANALITICO_.
  https://www.scribd.com/document/298552511/Diferencia-Entre-Un-Metodo-Numerico-y-Un-Analitico

- Serra, B. (s.f.). _ANÁLISIS MATEMÁTICO_.
  https://www.universoformulas.com/matematicas/analisis/
