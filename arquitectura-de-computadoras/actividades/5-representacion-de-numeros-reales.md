# Representación de números reales

## a) Cambio de base números reales

Realiza el cambio de base de los numeros reales a binario, emplea el método visto en clase (Representa el valor decimal, con un maximo de 15 bits)

1. 15.35

**Parte entera:** 15

| N / 2 | Residuo |
|:-----:|:-------:|
|  15   |    1    |
|   7   |    1    |
|   3   |    1    |
|   1   |    1    |

**Parte fraccional:** 0.35

|  #  | Parte entera | N * 2 |
|:---:|:------------:|:-----:|
|  1  |      -       |  .35  |
|  2  |      0       |  .7   |
|  3  |      1       |  .4   |
|  4  |      0       |  .8   |
|  5  |      1       |  .6   |
|  6  |      1       |  .2   |
|  7  |      0       |  .4   |
|  8  |      0       |  .8   |
|  9  |      1       |  .6   |
| 10  |      1       |  .2   |
| 11  |      0       |  .4   |
| 12  |      0       |  .8   |
| 13  |      1       |  .6   |
| 14  |      1       |  .2   |
| 15  |      0       |  .4   |


15.35 = 1111.010110011001100110

2. 3456.23

**Parte entera:** 3456

| N / 2 | Residuo |
|:-----:|:-------:|
| 3456  |    0    |
| 1728  |    0    |
|  864  |    0    |
|  432  |    0    |
|  216  |    0    |
|  108  |    0    |
|  54   |    0    |
|  27   |    1    |
|  13   |    1    |
|   6   |    0    |
|   3   |    1    |
|   1   |    1    | 

**Parte fraccional:** 0.23

|  #  | Parte entera | N * 2 |
|:---:|:------------:|:-----:|
|  1  |      -       |  .23  |
|  2  |      0       |  .46  |
|  3  |      0       |  .92  |
|  4  |      1       |  .84  |
|  5  |      1       |  .68  |
|  6  |      1       |  .36  |
|  7  |      0       |  .72  |
|  8  |      1       |  .44  |
|  9  |      0       |  .88  |
| 10  |      1       |  .76  |
| 11  |      1       |  .52  |
| 12  |      1       |  .04  |
| 13  |      0       |  .08  |
| 14  |      0       |  .16  |
| 15  |      0       |  .32  |

3456.23 = 110110000000.00111010111000

3. 17.094

**Parte entera:** 17

| N / 2 | Residuo |
|:-----:|:-------:|
|  17   |    1    |
|   8   |    0    |
|   4   |    0    |
|   2   |    0    |
|   1   |    1    | 

**Parte fraccional:** 0.094

|  #  | Parte entera | N * 2 |
|:---:|:------------:|:-----:|
|  1  |      -       | 0.094 |
|  2  |      0       | .188  |
|  3  |      0       | .376  |
|  4  |      0       | .752  |
|  5  |      1       | .504  |
|  6  |      1       | .008  |
|  7  |      0       | .016  |
|  8  |      0       | .032  |
|  9  |      0       | .064  |
| 10  |      0       | .128  |
| 11  |      0       | .256  |
| 12  |      0       | .512  |
| 13  |      1       | .024  |
| 14  |      0       | .048  |
| 15  |      0       | .096  |

17.23 = 10001.00011000000100

4. 5634.93751

**Parte entera:** 5634

| N / 2 | Residuo |
|:-----:|:-------:|
| 5634  |    0    |
| 2817  |    1    |
| 1408  |    0    |
|  704  |    0    |
|  352  |    0    |
|  176  |    0    |
|  88   |    0    |
|  44   |    0    |
|  22   |    0    |
|  11   |    1    |
|   5   |    1    |
|   2   |    0    |
|   1   |    1    |

**Parte fraccional:** 0.93751

|  #  | Parte entera | N * 2  |
|:---:|:------------:|:------:|
|  1  |      -       | .93751 |
|  2  |      1       | .87502 |
|  3  |      1       | .75004 |
|  4  |      1       | .50008 |
|  5  |      1       | .00016 |
|  6  |      0       | .00032 |
|  7  |      0       | .00064 |
|  8  |      0       | .00128 |
|  9  |      0       | .00256 |
| 10  |      0       | .00512 |
| 11  |      0       | .01024 |
| 12  |      0       | .02048 |
| 13  |      0       | .04096 |
| 14  |      0       | .08192 |
| 15  |      0       | .16384 |

5. 783.003412

**Parte entera:** 783

| N / 2 | Residuo |
|:-----:|:-------:|
|  783  |    1    |
|  391  |    1    |
|  195  |    1    |
|  97   |    1    |
|  48   |    0    |
|  24   |    0    |
|  12   |    0    |
|   6   |    0    |
|   3   |    1    |
|   1   |    1    |

**Parte fraccional:** 0.003412

|  #  | Parte entera |  N * 2  |
|:---:|:------------:|:-------:|
|  1  |      -       | .003412 |
|  2  |      0       | .006824 |
|  3  |      0       | .013648 |
|  4  |      0       | .027296 |
|  5  |      0       | .054592 |
|  6  |      0       | .109184 |
|  7  |      0       | .218368 |
|  8  |      0       | .436736 |
|  9  |      0       | .873472 |
| 10  |      1        | .746944 |
| 11  |      1        | .493888 |
| 12  |      0        | .987776 |
| 13  |      1        | .975552 |
| 14  |      1        | .951104 |
| 15  |      1        | .902208 |

783.003412 = 111000011.00000000110111

<div style="page-break-after: always;"></div>

## b) Representacion de numeros reales (IEEE 754)

Calcula la representacion de los numeros reales propuestos en punto o coma flotante definido por el estandat IEEE 754 en su formato de 32 bits.

1. -25.365
2. 2056.345
3. 176.27432
4. 3.45
5. -598.4501

Por supuesto, aquí está el procedimiento sin la columna "Fracción" y sin listas desordenadas:

1. -25.365

| Número     | Exceso a 127  | Exponente | Mantisa   | Binario Completo    |
|------------|---------------|-----------|-----------|---------------------|
| -25.365    | 25.365        | 32        | 10010111000000000000000  | 1 10000011 10010111000000000000000   |

2. 2056.345

| Número     | Exceso a 127  | Exponente | Mantisa   | Binario Completo    |
|------------|---------------|-----------|-----------|---------------------|
| 2056.345   | 2056.345      | 139       | 10110110001110110100000  | 0 10001011 10110110001110110100000   |

3. 176.27432

| Número     | Exceso a 127  | Exponente | Mantisa   | Binario Completo    |
|------------|---------------|-----------|-----------|---------------------|
| 176.27432  | 176.27432    | 135       | 10110001100101100000000  | 0 10000111 10110001100101100000000   |

4. 3.45

| Número     | Exceso a 127  | Exponente | Mantisa   | Binario Completo    |
|------------|---------------|-----------|-----------|---------------------|
| 3.45       | 3.45          | 128       | 10010000000000000000000  | 0 10000000 10010000000000000000000   |

5. -598.4501

| Número     | Exceso a 127  | Exponente | Mantisa   | Binario Completo    |
|------------|---------------|-----------|-----------|---------------------|
| -598.4501  | 598.4501      | 140       | 10011101111010010000000  | 1 10001100 10011101111010010000000   |

---

<div style="page-break-after: always;"></div>

## c) Representacion de numeros reales (IEEE 754) casos especiales

1. Convertir el número C19E0000 en formato IEEE 754 en su equivalente decimal:

   El número en formato IEEE 754 de 32 bits C19E0000 en hexadecimal se puede convertir al equivalente decimal siguiendo el estándar IEEE 754:

   - Signo: El bit más significativo (el primer dígito "C" en hexadecimal) es 1, lo que indica un número negativo.
   - Exponente: Los siguientes 8 bits (19) en binario son 00011001, que en decimal es 25.
   - Mantisa: Los últimos 23 bits (E00000) se pueden convertir a fracción. Aquí, el valor de la mantisa es 1.0 en notación binaria.

   El número en notación científica binaria sería: -1.0 × 2^25.

   Ahora, podemos calcular el valor decimal:
   - Signo: Negativo
   - Exponente: 25
   - Mantisa: 1.0

   El valor decimal es -2^25, que es igual a -33,554,432.

2. Representación del 0 en la representación de punto flotante (±0 en IEEE 754):

   En el estándar IEEE 754, existen dos representaciones del 0: +0 y -0. La diferencia entre ellos radica en el bit de signo (el bit más significativo). Si el bit de signo es 0, se trata de +0, y si el bit de signo es 1, se trata de -0. Ambos tienen el mismo valor absoluto (cero) y se utilizan para mantener información sobre el signo de resultados en operaciones específicas, como la división.

3. Casos especiales en IEEE 754:

   El estándar IEEE 754 define varios casos especiales para manejar situaciones excepcionales en aritmética de punto flotante. Algunos de los casos especiales son:
   - NaN (Not-a-Number): Representa resultados indefinidos, como 0 dividido por 0 o la raíz cuadrada de un número negativo.
   - +Inf y -Inf (Infinity): Representan el infinito positivo y negativo, respectivamente, que pueden ocurrir en operaciones como 1/0 o logaritmo de 0.
   - Denormalizados (Subnormales): Representan números muy pequeños que están por debajo del rango normalizado. Estos números se utilizan para mejorar la precisión en el rango subnormal.

4. Política de redondeo en IEEE 754 y su uso:

   La política de redondeo en IEEE 754 define cómo se redondean los resultados de las operaciones aritméticas cuando el resultado no puede representarse exactamente en el formato de punto flotante. Las políticas de redondeo comunes incluyen el redondeo hacia el número más cercano (round to nearest), redondeo hacia cero (round towards zero), redondeo hacia arriba (round up), y redondeo hacia abajo (round down).

   Se utiliza para manejar la pérdida de precisión en cálculos de punto flotante y para garantizar que los resultados se ajusten a las reglas de redondeo definidas. Esto es esencial en aplicaciones científicas y de ingeniería donde la precisión es crítica. La elección de la política de redondeo puede afectar la calidad de los resultados en cálculos numéricos.