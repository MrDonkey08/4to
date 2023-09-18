# Practica 1 - Programacion GAL22V10 en winCULP

## Marcador

### Tabla de verdad

|  #  |  E  | $A_0$ | $A_1$ | $B_0$ | $B_1$ |  S  |  A  |  B  |  C  |  D  |  E  |  F  |  G  |
|:---:|:---:|:-----:|:-----:|:-----:|:-----:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 16  |  1  |   0   |   0   |   0   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 17  |  1  |   0   |   0   |   0   |   1   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 18  |  1  |   0   |   0   |   1   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 19  |  1  |   0   |   0   |   1   |   1   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 20  |  1  |   0   |   1   |   0   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 21  |  1  |   0   |   1   |   0   |   1   |  E  |  1  |  0  |  0  |  1  |  1  |  1  |  1  |
| 22  |  1  |   0   |   1   |   1   |   0   |     |  0  |  0  |  1  |  1  |  1  |  1  |  1  |
| 23  |  1  |   0   |   1   |   1   |   1   |  A  |  1  |  1  |  1  |  0  |  1  |  1  |  1  |
| 24  |  1  |   1   |   0   |   0   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 25  |  1  |   1   |   0   |   0   |   1   |     |  0  |  0  |  1  |  0  |  1  |  1  |  1  |
| 26  |  1  |   1   |   0   |   1   |   0   |  E  |  1  |  0  |  0  |  1  |  1  |  1  |  1  |
| 27  |  1  |   1   |   0   |   1   |   1   |  B  |  0  |  0  |  1  |  1  |  1  |  1  |  1  |
| 28  |  1  |   1   |   1   |   0   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
| 29  |  1  |   1   |   1   |   0   |   1   |  B  |  0  |  0  |  1  |  1  |  1  |  1  |  1  |
| 30  |  1  |   1   |   1   |   1   |   0   |  A  |  1  |  1  |  1  |  0  |  1  |  1  |  1  |
| 31  |  1  |   1   |   1   |   1   |   1   |  E  |  1  |  0  |  0  |  1  |  1  |  1  |  1  |

#### Mapas de Karnaugh

![A | center](../../simulaciones/2-contador-sincrono-7seg/attachments/a.jpg)

$$A = (E A_0 B_0 \overline{B_1})+(E \overline{A_0} A_1 B_1)+(E A_0 A_1 B_0)$$

![B | center](attachments/1-B.jpg)

$$B = (E A_0 A_1 B_0 \overline{B_1}) + (E \overline{A_0} A_1 B_0 B_1)$$

![C | center](attachments/1-C.jpg)

$$C = (E A_1 B_0 \overline{B_1})+(E A_0 \overline{B_0} B_1)+(E A_0 \overline{A_1} B_1)+(E \overline{A_0} A_1 B_0)$$

![D | center](attachments/1-D.jpg)

$$D = (E A_1 \overline{B_0} B_1)+(E \overline{A_0} A_1 B_0 \overline{B_1})+(E A_0 \overline{A_1} B_0)+(E A_0 A_1 B_1)$$

![E | center](attachments/1-E.jpg)

$$E = F = G = (E A_1 B_1)+(E A_1 B_0)+(E A_0 B_1)+(E A_0 B_0)$$

## Jugadas

### Tabla de verdad

|  #  | $A_0$ | $A_1$ |     |  A  |  B  |  C  |  D  |  E  |  F  | G   |
| :-: | :---: | :---: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | --- |
|  5  |   0   |   0   |     |  0  |  0  |  0  |  0  |  0  |  0  | 0   |
|  6  |   0   |   1   |     |  0  |  0  |  1  |  1  |  1  |  0  | 1   |
|  7  |   1   |   0   |     |  1  |  1  |  1  |  1  |  1  |  1  | 0   |
|  8  |   1   |   1   |     |  0  |  1  |  1  |  0  |  1  |  1  | 1   |

### Simplificación con Álgebra de Boole

$$\begin{array}{l}
A = EA_0 \overline{A_1} \\
B = E(A_0 \overline{A_1} + A_1 A_0) = EA_0 \\
C = B + C = E(A_0 + \overline{A_0} A_1) = EA_0 + EA_1\\
D = E(\overline{A_0} A_1 + A_0 \overline{A_1}) = E(A_0 \oplus A_1) \\
\text{E} = C = EA_0 + EA_1 \\
F = EA_0 \\
G = E A_1
\end{array}$$

