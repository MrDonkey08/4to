## Circuitos Lógicos Combinacionales

> **Nombre:** Alan Yahir Juárez Rubio **Fecha:** 11/09/2023 **Materia:**
> Arquitectura de computadoras

Un **circuito lógico combinacional** es aquel que, dependiendo de la combinación
de las entradas lógicas, da una salida específica.

Las **puertas lógicas** son los bloques de construcción fundamentales de un
circuito combinacional. Mediante el uso de la _combinación de puertas lógicas_
se pueden implementar circuitos combinacionales más complejos como multiplexores
y demultiplexores, comparadores, sumadores y restadores, etc.

Un **circuito combinacional** se conforma de _variables de entrada_, _puertas
lógicas_ y _variables de salida_. Las puertas lógicas aceptan las entradas y,
según el tipo de funcionamiento de la puerta lógica, a partir de ellas se
generan señales de salida.

- **Circuitos Lógicos Básicos:** Estos realizan operaciones fundamentales como
  AND, OR y NOT. Por ejemplo, un circuito que toma dos entradas y produce una
  salida que es el resultado de la operación lógica AND sería un circuito lógico
  básico.

- **Circuitos Aritméticos:** Estos se utilizan para llevar a cabo operaciones
  aritméticas. Por ejemplo, un sumador binario es un circuito aritmético que
  toma dos números binarios como entrada y produce la suma de esos números como
  salida.

- **Circuitos Lógicos Complejos:** Estos combinan múltiples operaciones lógicas
  básicas y aritméticas para realizar tareas más complejas. Un ejemplo común de
  un circuito lógico complejo es una Unidad de Control en un procesador, que
  coordina las operaciones del CPU.

### Aritméticos

##### Características

- Realizan Operaciones Aritméticas
- Utilizan Números Binarios
- Pueden Tener Múltiples Bits de Entrada y Salida

- Ejemplos de Circuitos Aritméticos: Un ejemplo común es un sumador binario, que
  toma dos números binarios de entrada y produce la suma binaria. Otro ejemplo
  sería un multiplicador que toma dos números binarios y produce su producto.

### Lógicos

##### Características

- Están diseñados para realizar operaciones lógicas como AND, OR, NOT, NAND,
  NOR, XOR, XNOR, etc.
- Operan sobre niveles lógicos (0 y 1)
- Pueden combinar múltiples operaciones lógicas simples para implementar
  funciones lógicas más complejas
- Son esenciales en la construcción de procesadores, sistemas de control,
  memorias y otros componentes digitales

#### Semisumador.

Un **semisumador** es un _circuito digital_ sencillo que nos permite sumar dos
bits y registrar el acarreo.

|  A  |  B  |     | Suma | Carry out |
| :-: | :-: | :-: | :--: | :-------: |
|  0  |  0  |     |  0   |     0     |
|  0  |  1  |     |  1   |     0     |
|  1  |  0  |     |  1   |     0     |
|  1  |  1  |     |  0   |     1     |

![ center | 200 ](https://imgs.search.brave.com/7-bm5k5OfUsvEu8EBV5ioD_tVdv0XLH1KAldUuXmQ6g/rs:fit:860:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy9k/L2Q5L0hhbGZfQWRk/ZXIuc3Zn.svg)

#### Full Adder

A diferencia del _semisumador_, el **sumador completo** tiene dos acarreos.
Gracias a esto, es posible realizar sumas de más de un bit para las cuales
utilizaremos el acarreo de salida del anterior en el acarreo de entrada del
siguiente. Así completamos la suma correctamente.

| $A$ | $B$ | $C$ |     | $C$ | $S$ |
| :-: | :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |     |  0  |  0  |
|  0  |  0  |  1  |     |  0  |  1  |
|  0  |  1  |  0  |     |  0  |  1  |
|  0  |  1  |  1  |     |  1  |  0  |
|  1  |  0  |  0  |     |  0  |  1  |
|  1  |  0  |  1  |     |  1  |  0  |
|  1  |  1  |  0  |     |  1  |  0  |
|  1  |  1  |  1  |     |  1  |  1  |

![ center | 400](https://imgs.search.brave.com/IARVdYMLFRwlFwN6lESF2C2Frl6Q5JTTmsCGBsxhWC0/rs:fit:860:0:0/g:ce/aHR0cHM6Ly91bmln/YWwubXgvd3AtY29u/dGVudC91cGxvYWRz/LzIwMjIvMDMvMTY0/NzQ3MTc2NV85MDNf/Q2lyY3VpdG8tZGUt/bWVkaW8tc3VtYWRv/ci15LXN1bWFkb3It/Y29tcGxldG8uanBn)

#### Comparadores

Un **comparador** es un circuito combinacional cuya función es la de comparar
dos magnitudes binarias para determinar su relación.

Existen distintos tipos de comparadores, los que simplemente determinan si dos
números son iguales y los que, además, en caso de no serlo, indican cuál de los
dos es mayor. El número de bits del comparador indica la longitud de los datos
que compara.

La forma de realizar la comparación se inspira en el proceso mental que efectúa
cualquier persona al comparar dos números, es decir, ir comparando sucesivamente
los dígitos de mayor a menor peso de ambos números hasta encontrar dos que sean
desiguales.

Los comparadores más comunes son aquellos que permiten comparar dos palabras de
4 bits. Así, si la comparación debe ser entre palabras de 8 bits, lo que hacemos
es poner en cascada dos comparadores de 4 bits.

Normalmente tienen 3 salidas:

- A\>B, indica que la palabra A es mayor que la B.

- A=B, indica que ambas palabras tienen el mismo peso o son iguales.

- A\<B, indica que la palabra A es de menor peso o menor que B.

##### Ejemplo

| A   | B   | C   | D   |     | m   | i   | M   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |     | 0   | 1   | 0   |
| 0   | 0   | 0   | 1   |     | 1   | 0   | 0   |
| 0   | 0   | 1   | 0   |     | 1   | 0   | 0   |
| 0   | 0   | 1   | 1   |     | 1   | 0   | 0   |
| 0   | 1   | 0   | 0   |     | 0   | 0   | 1   |
| 0   | 1   | 0   | 1   |     | 0   | 1   | 0   |
| 0   | 1   | 1   | 0   |     | 1   | 0   | 0   |
| 0   | 1   | 1   | 1   |     | 1   | 0   | 0   |
| 1   | 0   | 0   | 0   |     | 0   | 0   | 1   |
| 1   | 0   | 0   | 1   |     | 0   | 0   | 1   |
| 1   | 0   | 1   | 0   |     | 0   | 1   | 0   |
| 1   | 0   | 1   | 1   |     | 1   | 0   | 0   |
| 1   | 1   | 0   | 0   |     | 0   | 0   | 1   |
| 1   | 1   | 0   | 1   |     | 0   | 0   | 1   |
| 1   | 1   | 1   | 0   |     | 0   | 0   | 1   |
| 1   | 1   | 1   | 1   |     | 0   | 1   | 0   |

![ center | ](https://imgs.search.brave.com/7104HIPVLtar9zm7U_ecjR72aX0H_fq2jpx1LHuX3T8/rs:fit:860:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy84/LzgyL0NvbXBhcmFk/b3JjYXNjYWRhLnBu/Zw)

#### Transmisión de datos

Los circuitos lógicos combinacionales de transmisión de datos están diseñados
para mover y manipular información digital de un lugar a otro dentro de un
sistema digital. Estos circuitos son fundamentales en una amplia gama de
aplicaciones, desde la comunicación digital hasta el procesamiento de datos.

Estos circuitos desempeñan un papel crucial en la _transmisión, manipulación y
procesamiento de datos en sistemas digitales_. Su combinación y configuración
adecuada permite la implementación de sistemas digitales complejos y
funcionales.

**Características.**

- Combinacionales: Al igual que otros circuitos lógicos combinacionales, no
  tienen estados internos y la salida depende únicamente del estado actual de
  las entradas.

- Flexibilidad: Pueden ser configurados para manejar diferentes tamaños de datos
  y configuraciones. Por ejemplo, un multiplexor puede tener varios canales de
  entrada, y un comparador puede trabajar con números de diferentes longitudes
  de bits.

- Operaciones Específicas: Cada tipo de circuito tiene una función o conjunto de
  funciones específicas. Por ejemplo, un multiplexor selecciona una entrada de
  un conjunto y la transmite a la salida, mientras que un comparador verifica la
  relación entre dos o más entradas.

- Señales de Control: Muchos de estos circuitos requieren señales de control
  adicionales para determinar qué operación realizar. Por ejemplo, un
  multiplexor tiene entradas de datos y señales de selección para elegir qué
  dato se transmite.

- Tiempo de Propagación: Es importante considerar el tiempo que toma para que
  una señal de entrada se propague a través del circuito y produzca una salida.
  Esto es crítico en sistemas donde la sincronización es esencial.

- Consumo energético: Cada tipo de circuito tendrá diferentes requerimientos de
  energía en función de su complejidad y de las operaciones que realiza.

#### Multiplexores.

Un **multiplexor** es un _circuito digital_ que selecciona una de entre varias
entradas de datos Ii y lleva su valor lógico a la única salida Z del circuito.
La selección de los datos se realiza mediante una o varias entradas de control
Sj. La codificación binaria resultante de las entradas S indica el índice de la
entrada I que pasa a la salida. Existiendo una entrada de habilitación
(enable),la cual pone en funcionamiento el circuito,y trabaj en bajo áctivo.

**Diseño un multiplexor de 2 canales de entrada.**

1. Se procede a la implementación de una tabla de verdad, en la cual se aprecian
   los valores de la salida dependiendo del valor de la señal de control y de la
   señal de habilitación(enable): Ejemplos de explicación:

   1. Si el Enable está en alto activo, el circuito está apagado.
   2. Si el Enable está en bajo activo, el circuito funciona y selecciona la
      entrada atribuida a la señal de control.

2. Minimización mediante mapas de Karnaugh:

3. Diseño del circuito y simulación mediante puertas lógicas.

##### Ejemplo

Comparador de 3 a 1

| $m$ | $S$ | $I_1$ | $I_0$ | $Y$ | $\to$                                   |
| --- | --- | ----- | ----- | --- | --------------------------------------- |
| 0   | 0   | 0     | 0     | 0   |                                         |
| 1   | 0   | 0     | 1     | 1   | $m_1 = \overline{S}\ \overline{I_1}I_0$ |
| 2   | 0   | 1     | 0     | 0   |                                         |
| 3   | 0   | 1     | 1     | 1   | $m_3 = \overline{S}I_1 I_0$             |
| 4   | 1   | 0     | 0     | 0   |                                         |
| 5   | 1   | 0     | 1     | 0   |                                         |
| 6   | 1   | 1     | 0     | 1   | $m_6 = S \overline{I_1}I_0$             |
| 7   | 1   | 1     | 1     | 1   | $m_7 = S I_1 I_0$                       |

![ center | 350](https://imgs.search.brave.com/WaRs_TdVwRMbYj32KIDN6k3U0HQKzCZrK8HShl8vrtE/rs:fit:860:0:0/g:ce/aHR0cHM6Ly9jZG4u/c3BhcmtmdW4uY29t/L2Fzc2V0cy9sZWFy/bl90dXRvcmlhbHMv/Mi8xLzYvMzYtbXVs/dGlwbGV4ZXItc2No/ZW1hdGljLlBORw)

#### Demultiplexores

Un **demultiplexor** (DEMUX) es un circuito combinacional que tiene una entrada
de información de datos I y N entradas de control que sirven para seleccionar
una de las M salidas, por la que ha de salir el dato que presente en la entrada.
Siendo M = 2 N

• Esto se consigue aplicando a las entradas de control la combinación binaria
correspondiente a la salida que se desea selecciona r.

• Los demultiplexores y los decodificadores son similares y en la práctica se
usa un mismo circuito para realizar las dos funciones: decodificación de N a M y
demultiplexado 1 de M.

El demultiplexor, es un circuito combinacional que, aunque la función básica es
la que hemos explicado, puede utilizarse en muchos casos como decodificador y
adopta cualquiera de las funciones que un decodificador realiza.

Como vemos, el demultiplexor y el decodificador con Enable se realizan con el
mismo circuito.

#### Decodificadores

Un **decodificador** (DEC) es un circuito combinacional que convierte un código
binario de entrada A de N bits, en M líneas de salida Oi.

##### Ejemplo

DEC 2 a 4 → (Decodificador de 2 entradas y 4 salidas)

![ center | 400](https://imgs.search.brave.com/WAcuBpkuPmtyMyx97ChcJBvQcEQ5sUHL3_2yfMFC3kg/rs:fit:860:0:0/g:ce/aHR0cHM6Ly9hcmVh/dGVjbm9sb2dpYS5j/b20vZWxlY3Ryb25p/Y2EvaW1hZ2VuZXMv/ZGVjb2RpZmljYWRv/cjJ4NC5qcGc)

#### Codificadores.

Los codificadores son circuitos que codifican en forma binaria la información
que se le aplica a su entrada, teniendo en cuenta que la información de entrada
debe ser numérica o alfanumérica. Están compuestos por 2n entradas y n salidas.

En los codificadores, sólo una de las entradas puede estar activa. El código de
salida indica qué entrada es la que está activa. Para denominar a los
codificadores se puede emplear un sistema análogo al de los decodificadores, que
estudiaremos más adelante, refiriéndose a su número de entradas y de salidas;
así un decodificador que tuviera 4 entradas y 2 salidas sería un codificador
4:2.

Para evitar problemas cuando dos entradas del decodificador están activas se
emplean los llamados codificadores con prioridad o codificadores prioritarios.
En éstos cuando más de una entrada está activada será la de más peso la que
determinará el código de salida.

Otro problema que puede presentarse es que para distintos valores de las
entradas se tenga un mismo código de salida. Es lo que ocurre cuando no está
activa la entrada de habilitación (si la hay) o, en caso de estar habilitado el
codificador, no hay ninguna entrada binaria activa o lo está la menos
significativa. En todos estos casos el valor de todas las salidas es cero.

Los codificadores nos permiten “compactar” la información, generando un código
de salida a partir de la información de entrada.

Poniendo un ejemplo:

Las ecuaciones las obtenemos siguiendo el mismo método de siempre:

1. Obtener la tabla de verdad completa.

2. Aplicar el método de Karnaugh. Con ello obtendremos las ecuaciones más
   simplificadas para las salidas C1 y C0.

Al hacer la tabla de verdad, hay que tener en cuenta que muchas de las entradas
NO SE PUEDEN PRODUCIR. En las entradas de un decodificador, una y sólo una de
las entradas estará activa en cada momento. Utilizaremos esto para simplificar
las ecuaciones. Se ha utilizado una X para indicar que esa salida nunca se
producirá:

C1 y C0 siempre valen ’x’ excepto para 4 filas. Los mapas de Karnaugh que
obtenemos son:

as casillas que tienen el valor "x" podemos asignarles el valor que más nos
convenga, de forma que obtengamos la expresión más simplificada. Haremos las
agrupaciones más grandes posibles, en nuestro caso agrupaciones de 8, y
tomaremos las "x" como si valiesen "1", obteniendo las siguientes expresiones:

### Convertidores de código

Son circuitos combinacionales cuya función es cambiar los datos de un código
binario a otro, esto es así porque para determinadas operaciones de transmisión
y procesamiento de información son más eficaces unos códigos que otros. Se
suelen implementar mediante dispositivos lógicos programables.

Vamos a ver un ejemplo de un cambiador
de [código](http://www.juntadeandalucia.es/averroes/educacion_permanente/glosario/index.php/Codigo_Binario "http://www.juntadeandalucia.es/averroes/educacion_permanente/glosario/index.php/Codigo_Binario") de
BCD (8421) a binario exceso 3.

La tabla de verdad será:

![ center | 300](https://imgs.search.brave.com/qCoxlpkmPOmeKXRqVclGF6o5FtezKZ8UeyNk2CkRBPI/rs:fit:860:0:0/g:ce/aHR0cHM6Ly93d3cu/Z2Vla3Nmb3JnZWVr/cy5vcmcvd3AtY29u/dGVudC9xbC1jYWNo/ZS9xdWlja2xhdGV4/LmNvbS0wYzI1MzIz/YmEwNGYxYTJmMTcw/OTkyYzUyMmI1OGFl/MF9sMy5wbmc)

Las funciones canónicas serían:

![ center | 200](https://imgs.search.brave.com/_kbI7VN81fgY7aThJsOPvEGb8LHy0RKbLTULNKe5i0U/rs:fit:860:0:0/g:ce/aHR0cHM6Ly93d3cu/Z2Vla3Nmb3JnZWVr/cy5vcmcvd3AtY29u/dGVudC9xbC1jYWNo/ZS9xdWlja2xhdGV4/LmNvbS1hNjcyYThh/OGJjOGNmZTgwOGFj/NDM0YzA3MTZkNTA3/OF9sMy5wbmc)

Ahora deberíamos simplificar e implementar la función, pero en este caso es un
proceso largo que no vamos a hacer aquí y que la razón por la que estos
circuitos se implementan en circuitos combinacionales integrados

##### Características

- Tipo de Conversión:

  - Codificador: Convierte datos de un formato a un formato más compacto o a una
    representación específica (por ejemplo, de binario a BCD).
  - Decodificador: Realiza la operación inversa al codificador, convirtiendo
    datos de un formato específico a otro más general (por ejemplo, de BCD a
    binario).

- Número de Entradas y Salidas: Los codificadores y decodificadores pueden tener
  diferentes números de entradas y salidas, dependiendo de la aplicación
  específica.

- Complejidad de la Función de Conversión: Pueden ser simples, como un
  codificador binario de 4 a 2 líneas, o complejos, como un decodificador BCD a
  7 segmentos.

- Expansibilidad: Algunos codificadores y decodificadores pueden ser expandidos
  para manejar un mayor número de entradas o salidas.

- Señales de Control: Algunos codificadores y decodificadores pueden requerir
  señales de control adicionales para determinar su operación específica.

- Uso de Tablas de Verdad: Pueden ser diseñados a partir de tablas de verdad o
  mediante la utilización de combinaciones de puertas lógicas.

- Aplicaciones: Utilizados en una amplia gama de aplicaciones, incluyendo
  sistemas de comunicación, control de dispositivos, visualización de datos,
  etc.

- Compatibilidad del Sistema: Deben ser compatibles con el sistema al que están
  conectados, en términos de voltajes, niveles lógicos, y características
  eléctricas.

- Tamaño y Encapsulamiento:Los convertidores de código están disponibles en una
  variedad de tamaños y formas, desde dispositivos discretos hasta circuitos
  integrados complejos.

- Velocidad de Operación: Al igual que con otros circuitos lógicos
  combinacionales, la velocidad de operación puede ser una consideración
  importante en aplicaciones de alta velocidad.

- Consumo de Energía: La eficiencia energética puede ser crítica en aplicaciones
  de bajo consumo o alimentadas por batería.

- Inmunidad al Ruido y Estabilidad: Deben ser capaces de operar de manera
  confiable en presencia de ruido eléctrico y variaciones en las condiciones de
  alimentación.

#### Binario

Un codificador binario es un circuito lógico combinacional que toma un número de
entradas binarias y genera una salida codificada en forma binaria. El propósito
de un codificador es reducir la cantidad de líneas necesarias para representar
un conjunto de datos.

Un ejemplo común es el codificador binario de n a m líneas, que toma n entradas
y las codifica en una salida de m bits. A continuación se muestra un ejemplo de
un codificador binario de 4 a 2 líneas:

Entradas: D0 ​,D1​,D2​,D3​ (4 entradas) Salidas: Y0​,Y1​ (2 salidas)

![ center | 350](https://imgs.search.brave.com/bTQKVkvaDuUP_Y5deJSFGi7ASIDNXs2y9muUUuu5NQo/rs:fit:500:0:0/g:ce/aHR0cHM6Ly9hcmVh/dGVjbm9sb2dpYS5j/b20vZWxlY3Ryb25p/Y2EvaW1hZ2VuZXMv/ZGVjb2RpZmljYWRv/cjJ4NC5qcGc)

En este ejemplo, hay 16 combinaciones posibles de entradas (debido a 4 bits de
entrada), pero solo hay 4 combinaciones válidas que tienen una salida activa. El
resto se considera "no válidas" y se indican con un guión (-).

El diseño de un codificador binario se basa en la función de codificación
deseada. Puede ser un codificador de prioridad, donde solo se toma en cuenta la
entrada más significativa activa, o un codificador de activación, donde todas
las entradas activas se tienen en cuenta.

La representación de un codificador binario en términos de puertas lógicas
incluye puertas AND y OR, y puede variar en complejidad según el número de
entradas y salidas.

Estos codificadores son comúnmente utilizados en sistemas digitales para reducir
el número de líneas de datos y simplificar la comunicación y el procesamiento de
información.

#### BCD

Un codificador BCD (Binary-Coded Decimal) es un tipo específico de codificador
que toma como entrada un número en formato decimal y lo convierte en una
representación binaria de 4 bits. BCD es una forma de representar números
decimales utilizando combinaciones de cuatro bits binarios, lo que permite
representar números del 0 al 9 en cada dígito.

Un codificador BCD de 4 dígitos toma 4 dígitos decimales como entrada y los
convierte en una salida de 4 bits para cada dígito, totalizando 16 bits de
salida.

Por ejemplo, si las entradas son D3​D2​D1​D0​, entonces las salidas serían
0Y3​Y2​Y1​Y0​.

Tabla de Verdad de un Codificador BCD de 4 Dígitos:

En este ejemplo, solo las combinaciones de dígitos del 0 al 9 son válidas, y el
resto se consideran "no válidas" y se indican con un guion (-).

El codificador BCD es útil en aplicaciones donde se requiere la representación
de números decimales en un sistema digital. Por ejemplo, en pantallas de
visualización de siete segmentos donde cada dígito se representa usando
combinaciones de siete segmentos (LEDs). También se utiliza en sistemas de
control y en la interfaz entre sistemas digitales y dispositivos de
entrada/salida que utilizan representación decimal.

Este tipo de codificador es un componente esencial en muchos sistemas digitales
que trabajan con datos en formato decimal.

#### Codificador 7 segmentos

n codificador de 7 segmentos es un tipo de circuito lógico combinacional que
convierte un número en formato binario en una representación de 7 segmentos,
comúnmente utilizada para mostrar dígitos en pantallas o displays de siete
segmentos.

Un display de siete segmentos consiste en siete segmentos individuales
dispuestos en forma de "8", donde cada segmento puede encenderse o apagarse para
representar dígitos numéricos (0 al 9) y algunas letras (A a F para representar
números hexadecimales).

Los siete segmentos son identificados comúnmente como a, b, c, d, e, f, y g:

Cada uno de estos segmentos puede ser encendido o apagado, lo que permite
representar números y letras. Por ejemplo, para representar el número 0, se
necesitarían encender los segmentos a, b, c, d, e, f, pero no el g.

El codificador de 7 segmentos toma como entrada un número en formato binario de
4 bits (ya que puede representar números del 0 al 15) y genera las señales de
control necesarias para encender los segmentos correspondientes y representar el
dígito en el display de siete segmentos.

Por ejemplo, si las entradas son D3​D2​D1​D0​, entonces las salidas serían
abcdefg (indicando qué segmentos se deben encender para representar el dígito
correspondiente).

Tabla de Verdad de un Codificador de 7 Segmentos:

En este ejemplo, solo las combinaciones de dígitos del 0 al 9 son válidas, y el
resto se consideran "no válidas" y se indican con un guión (-).

El codificador de 7 segmentos es ampliamente utilizado en aplicaciones donde se
requiere mostrar números, como en relojes digitales, contadores, termómetros
digitales, entre otros dispositivos de visualización.

<div style="page-break-after: always;"></div>

## Half-Subtractor y Full-Subtractor

### Half-Substractor

Un Half-Subtractor toma dos bits de entrada, A y B, y tiene dos salidas,
Diferencia (Diff) y Acarreo (Borrow). Aquí tienes la tabla de verdad
correspondiente:

|  A  |  B  | Diferencia (Diff) | Acarreo (Borrow) |
| :-: | :-: | :---------------: | :--------------: |
|  0  |  0  |         0         |        0         |
|  0  |  1  |         1         |        1         |
|  1  |  0  |         1         |        0         |
|  1  |  1  |         0         |        0         |

Donde:

- **Diferencia (Diff)** = A XOR B
- **Acarreo (Borrow)** = A' \* B

![ center | 400](https://lh4.googleusercontent.com/nGZudomRRE1f2PPrCyFYlEX9C7zEeLNESvOz7ckGiUqHyHanuoVD0lnyY8gxTd-z9R40c5SLkISuHzgSK5_YH1U8CBQBHig3CvymVaD4oGKuaKXStII-KwjEV-qTapBkL6IsCg-_wmZsMO84BKAB4gA)

### Full-Subtractor

Un Full-Subtractor toma tres bits de entrada, A, B y Cin (Acarreo de Entrada), y
tiene dos salidas, Diferencia (Diff) y Acarreo (Borrow). Aquí tienes la tabla de
verdad correspondiente:

|  A  |  B  | Cin | Diferencia (Diff) | Acarreo (Borrow) |
| :-: | :-: | :-: | :---------------: | :--------------: |
|  0  |  0  |  0  |         0         |        0         |
|  0  |  0  |  1  |         1         |        1         |
|  0  |  1  |  0  |         1         |        1         |
|  0  |  1  |  1  |         0         |        1         |
|  1  |  0  |  0  |         1         |        0         |
|  1  |  0  |  1  |         0         |        0         |
|  1  |  1  |  0  |         0         |        1         |
|  1  |  1  |  1  |         1         |        1         |

Donde:

- **Diferencia (Diff)** = (A XOR B) XOR Cin
- **Acarreo (Borrow)** = (A' _ B) + (A XOR B _ Cin)

![ center | 550](https://lh4.googleusercontent.com/SGunWQfHuioYXyq1tC-wu6CHT9WjTCuMoG73JHEvWFX8jBV3ItiMJa4dtG_naM_B-wwQ6dDEdHqkMgEo6Re0pw1Q2A4HqGSE604PKKGTycH3FIfEwLnX78lSntTLsygUQVyn5PtK6QO2PDqgJOU8Rrs)

<div style="page-break-after: always;"></div>

## Decodificador Binario a Hexadecimal

**Variables de entrada:** A, B, C, D

**Variables de salida:** a, b, c, d, e, f, g

### Tabla de verdad

|  #  |  A  |  B  |  C  |  D  |     |  a  |  b  |  c  |  d  |  e  |  f  |  g  |
| :-: | :-: | :-: | :-: | :-: | --- | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  0  |  0  |     |  1  |  1  |  1  |  1  |  1  |  1  |  0  |
|  1  |  0  |  0  |  0  |  1  |     |  0  |  1  |  1  |  0  |  0  |  0  |  0  |
|  2  |  0  |  0  |  1  |  0  |     |  1  |  1  |  0  |  1  |  1  |  0  |  1  |
|  3  |  0  |  0  |  1  |  1  |     |  1  |  1  |  1  |  1  |  0  |  0  |  1  |
|  4  |  0  |  1  |  0  |  0  |     |  0  |  1  |  1  |  0  |  0  |  1  |  1  |
|  5  |  0  |  1  |  0  |  1  |     |  1  |  0  |  1  |  1  |  0  |  1  |  1  |
|  6  |  0  |  1  |  1  |  0  |     |  1  |  0  |  1  |  1  |  1  |  1  |  1  |
|  7  |  0  |  1  |  1  |  1  |     |  1  |  1  |  1  |  0  |  0  |  0  |  0  |
|  8  |  1  |  0  |  0  |  0  |     |  1  |  1  |  1  |  1  |  1  |  1  |  1  |
|  9  |  1  |  0  |  0  |  1  |     |  1  |  1  |  1  |  1  |  0  |  1  |  1  |
| 10  |  1  |  0  |  1  |  0  |     |  1  |  1  |  1  |  0  |  1  |  1  |  1  |
| 11  |  1  |  0  |  1  |  1  |     |  0  |  0  |  1  |  1  |  1  |  1  |  1  |
| 12  |  1  |  1  |  0  |  0  |     |  1  |  0  |  0  |  1  |  1  |  1  |  0  |
| 13  |  1  |  1  |  0  |  1  |     |  0  |  1  |  1  |  1  |  1  |  0  |  1  |
| 14  |  1  |  1  |  1  |  0  |     |  1  |  0  |  0  |  1  |  1  |  1  |  1  |
| 15  |  1  |  1  |  1  |  1  |     |  1  |  0  |  0  |  0  |  1  |  1  |  1  |

### Mapas de Karnough

![ | center](attachments/bin2hex-1.jpg)

$$a = (\overline{B} ⋅ \overline{D}) + (\overline{A} ⋅ C) + (\overline{A} ⋅ B ⋅ D) + (B ⋅ C) + (A ⋅ \overline{D}) + (A ⋅ \overline{B} ⋅ \overline{C})$$

![ | center](attachments/bin2hex-2.jpg)

$$b = (A ⋅ \overline{C} ⋅ D) + (\overline{B} ⋅ \overline{D}) + (\overline{A} ⋅ \overline{C} ⋅ \overline{D}) + (\overline{A} ⋅ C ⋅ D) + (\overline{A} ⋅ \overline{B})$$

![ | center](attachments/bin2hex-3.jpg)

$$c = (\overline{C} ⋅ D) + (\overline{A} ⋅ B) + (A ⋅ \overline{B}) + (\overline{A} ⋅ \overline{C}) + (\overline{A} ⋅ D)$$

![ | center](attachments/bin2hex-4.jpg)

$$d = (B ⋅ \overline{C} ⋅ D) + (\overline{B} ⋅ C ⋅ D) + (B ⋅ C ⋅ \overline{D}) + (A ⋅ \overline{C}) + (\overline{A} ⋅ \overline{B} ⋅ \overline{D})$$

![ | center](attachments/bin2hex-5.jpg)

$$e = (\overline{B} ⋅ \overline{D}) + (C ⋅ \overline{D}) + (A ⋅ C) + (A ⋅ B)$$

![ | center](attachments/bin2hex-6.jpg)

$$f = (\overline{C} ⋅ \overline{D}) + (B ⋅ \overline{D}) + (\overline{A} ⋅ B ⋅ \overline{C}) + (A ⋅ \overline{B}) + (A ⋅ C)$$

![ | center](attachments/bin2hex-7.jpg)

$$g = (\overline{B} ⋅ C) + (A ⋅ \overline{B}) + (A ⋅ D) + (C ⋅ \overline{D}) + (\overline{A} ⋅ B ⋅ \overline{C})$$

<div style="page-break-after: always;"></div>

## Referencias

- ElectrónicaOnline (s.f.) _Circuitos Lógicos Combinacionales_.
  https://electronicaonline.net/electronica-digital/circuitos-logicos-combinacionales/

- Ecured (s.f.). _Sumador medio_. https://www.ecured.cu/Sumador_medio

- Personales (s.f.) _Sumador digital_.
  https://personales.unican.es/manzanom/Planantiguo/EDigitalI/SumG2_09.pdf

- Gregorio Menezo (s.f.). _Decodificadores y multiplexores_
  https://personales.unican.es/manzanom/planantiguo/edigitali/decg9_09.pdf

- CienciaEsfera (s.f.) _3. Convertidores de código_.
  https://www.cienciasfera.com/materiales/tecnologia/tecno02/tema11/3_convertidores_de_cdigo.html
