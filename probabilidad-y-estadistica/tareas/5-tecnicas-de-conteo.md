# Ejercicios

## Técnicas básicas

**4.18 Dispone de _tres_ grupos de artfculos diferentes, cuatro en el primer
grupo, siete en el segundo y tres en el tercero. Si seleciona un articulo de
cada de grupo, ¿cuántos diferentes conjuntos de tres puede formar?**

$$4×7×3=84$$

**4.19 Evalúe las siguientes _permutaciones_. (Sugerencia: su calculadora
científica puede tener una función que le permita calcular permutaciones y
combinaciones con bastante facilidad.)**

a) $P^5_3$ b) $P^{10}_9$ c) $P^6_6$ d) $P^{20}_1$

$$
\begin{align}
P^5_3 &= 60\\
P^{10}_9 &= 3\ 628\ 800\\
P^6_6 &= 72\\
P^{20}_1 &= 20\\
\end{align}
$$

---

## Aplicaciones

4.26 **Usted tiene 4 pares de pantalones vaqueros, 12 camisetas limpias y 4
pares de zapatos deportivos. ¿Cuántas combinaciones (pantalón vaquero, camiseta
y zapatos) puede crear?**

$$C = 4×12×4 = 192$$

**4.27 Un hombre de negocios en Nueva York está preparando un itinerario para
visitar seis ciudades importantes. La distancia recorrida y. por tanto, el costo
del viaje, dependerá del orden en que planee su ruta. ¿Cuántos itinerarios
diferentes (y costos de viaje) son posibles?**

Necesitamos considerar las permutaciones de las seis ciudades, ya que el orden
en que las visita afecta tanto la distancia total recorrida como el costo del
viaje.

$$P = 6! = 720$$

**4.28 Sus vacaciones familiares incluyen un vuelo para cruzar el país, un
arrendamiento de un automóvil y la estancia en un hotel en Boston. Si usted
puede escoger entre cuatro líneas aéreas cinco agencias de renta de automóviles
y tres cadenas de hoteles. ¿Cuántas opciones de alojamiento dispone?**

$$C = 4×5×3 = 60$$

**4.31 De un mazo de 52 cartas se eligen cinco para una mano de póquer.**

**a) ¿Cuántos eventos simples están en el espacio muestral?** **b) Una _flor
imperial_ es una mano que contiene la A, K, Q, J, 10, todos del mismo palo.
¿Cuántas maneras hay de obtener una flor imperial?** **c) ¿Cual es la
probabilidad de recibir en el reparto una flor imperial?**

$$
\begin{align}
C^{52}_5 &= 2\ 598\ 960\\
\text{Flores imperiales} &= 4\\
P(\text{Flor imperial}) &= \cfrac{4}{ 2\ 598\ 960} \approx 1.54 \cdot 10^{-07}
\end{align}
$$

---

**4.33 En un hospital se realiza un estudio para determinar las actitudes de las
enfermedades hacia varios procedimientos administrativos. Si se selecciona una
muestra de 10 enfermedades de un total de 90, ¿cuántos muestras diferentes se
pueden extraer? (Sugerencia: ¿es importante el orden para determinar la
composición de la muestra que se seleccionará con el fin de realizar el
estudio?)**

Lo que nos interesa es simplemente el grupo de enfermeras seleccionadas, no el
orden en el que se eligen, por lo tanto se trata de combinaciones

$$C^{90}_{10} \approx 5.72065^{-12}$$

**4.34 Se seleccionarán dos miembros del consejo ciudadano de un total de cinco
para formar un subcomité que estudie los problemas de tránsito en la ciudad.**

**a) ¿Cuántos subcomités diferentes se pueden formar?** **b) ¿Si todos los
miembros del consejo tienen igual oportunidad de ser elegidos, ¿cuál es la
probabilidad de que sean seleccionados miembros Suárez. y Jiménez?**

$$
\begin{align}
C^5_2 &= 10\\
P(\text{Suarez y Jiménez}) &= \cfrac{1}{10}= 10%
\end{align}
$$

**4.38 Una estudiante se prepara para un examen resolviendo una lista de diez
problemas. Ella puede resolver seis ellos. Para el examen el instructor
selecciona al azar cinco preguntas de la lista de diez.. ¿Cuál es la
probabilidad de que la estudiante pueda resolver los cinco problemas en el
examen?**

$$P(\text{resolver 5}) = \cfrac{C^6_5}{C^{10}_5} \approx 0.02381$$
