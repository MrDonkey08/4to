# Actividad 2: Algebra de boole

**Nombre:** Alan Yahir Juárez Rubio

**Instrucciones:** Resuelve cada uno de los ejercicios propuestas, recuerda
incluir el procedimiento del cual obtuviste tus respuestas, e identificar
claramente el resultado.

1.  Quiere controlarse 2 bombas $B_1$ y $B_2$ haciendo uso de _un circuito
    lógico combinacional de control_ que funcionará en función de las siguientes
    premisas:

![Esquema de bombas | center ](attachments/1-bombas-esquema.jpg)

- Cuando el agua se encuentra entre los sensores $c$ y $d$ funcionar la bomba 1
  salvo que su temperatura ($T_1$) supere un límite prefijado en cuyo caso se
  detendrá y entrará en funcionamiento la bomba 2. Dicho límite de temperatura
  vendrá indicado por la activación del sensor $T_1$.

- Si el nivel de agua se encuentra por debajo de $c$, se activaran ambas bombas

- Si hay fallo en los sensores de nivel y se activara $d$ sin activarse $c$,
  ambas bombas se detendrán.

- Los sensores de temperatura $T_1$ y $T_2$ harán que la bomba respectiva se
  pare si se activa su sensor.

> Realiza el diseño del circuito antes descrito, halla:

1.  Tabla de verdad del circuito de control

2.  Expresión algebraica que represente a las funciones en su primera y/o
    segunda forma canónica.

3.  Simplifica las funciones haciendo uso de algebra de boole

4.  Implementa el circuito lógico para el circuito de control (Diagrama Lógico)

<div style="page-break-after: always;"></div>

## Circuito lógico combinacional de control

### 1. Tabla de verdad

|  m  |  c  | $d$ | $T_1$ | $T_2$ |     | $B_1$ | $B_2$ |
| :-: | :-: | :-: | :---: | :---: | --- | :---: | :---: |
|  0  |  0  |  0  |   0   |   0   |     |   0   |   0   |
|  1  |  0  |  0  |   0   |   1   |     |   0   |   0   |
|  2  |  0  |  0  |   1   |   0   |     |   0   |   0   |
|  3  |  0  |  0  |   1   |   1   |     |   0   |   0   |
|  4  |  0  |  1  |   0   |   0   |     |   0   |   0   |
|  5  |  0  |  1  |   0   |   1   |     |   0   |   0   |
|  6  |  0  |  1  |   1   |   0   |     |   0   |   0   |
|  7  |  0  |  1  |   1   |   1   |     |   0   |   0   |
|  8  |  1  |  0  |   0   |   0   |     |   1   |   0   |
|  9  |  1  |  0  |   0   |   1   |     |   1   |   0   |
| 10  |  1  |  0  |   1   |   0   |     |   0   |   1   |
| 11  |  1  |  0  |   1   |   1   |     |   0   |   0   |
| 12  |  1  |  1  |   0   |   0   |     |   1   |   1   |
| 13  |  1  |  1  |   0   |   1   |     |   1   |   0   |
| 14  |  1  |  1  |   1   |   0   |     |   0   |   1   |
| 15  |  1  |  1  |   1   |   1   |     |   0   |   0   |

### 2. Expresión Canónica

<!-- \sum _{m \in \{8, 9, 12, 13\}} -->

$$
\displaylines{ B_1 = \sum_m(8, 9, 12, 13)
= (c \cdot \overline{d} \cdot \overline{T_1} \cdot \overline{T_2})
+ (c \cdot \overline{d} \cdot \overline{T_1} \cdot T_2 )
+ (c \cdot d \cdot \overline{T_1} \cdot \overline{T_2})
+ (c \cdot d \cdot \overline{T_1} \cdot T_2)
}
$$

$$
\displaylines{ B_2 = \sum_m(10, 12, 14)
= (c \cdot \overline{d} \cdot T_1 \cdot T_2)
+ (c \cdot d \cdot \overline{T_1} \cdot \overline{T_2})
+ (c \cdot d \cdot T_1 \cdot \overline{T_2})
}
$$

### 3. Simplificación con Boole

$$
\displaylines{ B_1
= c \cdot \overline{d} \cdot \overline{T_1} \cdot (\overline{T_2} + T_2)
+ c \cdot d \cdot \overline{T_1} \cdot (\overline{T_2} + T_2) \\

= c \cdot \overline{d} \cdot \overline{T_1} + c \cdot d \cdot \overline{T_1} \\

}
$$

$$
\displaylines{ B_2
= (c \cdot \overline{d} \cdot T_1 \cdot T_2)
+ (c \cdot d \cdot \overline{T_1} \cdot \overline{T_2})
+ (c \cdot d \cdot T_1 \cdot \overline{T_2}) \\
= c \cdot \overline{d} \cdot T_1 \cdot (T_2 + \overline{T_2})
+ c \cdot d \cdot \overline{T_1} \cdot (\overline{T_2} + T_2) \\

= c \cdot \overline{d} \cdot T_1 + c \cdot d \cdot \overline{T_1} \cdot T_2 \\

= c \cdot T_1 \cdot (\overline{d} + d) + c \cdot d \cdot \overline{T_1} \cdot T_2 \\

= c \cdot T_1 + c \cdot T_2 \cdot \overline{T_1}

}
$$

<div style="page-break-after: always;"></div>

### 4. Diagrama

![ | center](attachments/1-circuito-lógico.jpg)

<div style="page-break-after: always;"></div>
 
1.  Obtener la expresión booleana de los siguientes circuitos lógicos combinacionales y describir su comportamiento por medio de su tabla de verdad.


<ol type="a">
	<li></li>
</ol>

![Circuito lógico |  center | 494](attachments/2-circuito-lógico-a.jpg)

$$F_0 =(W + (Z \oplus X)) \oplus (\overline{Y} + (Z \oplus X))$$

$$F_1 = \overline{(W + (\overline{Y} + (Z \oplus X)) \oplus \overline{(Z + \overline{X})}} $$

$$F_2 = Z \oplus ((Z \oplus X) + ((Z) \oplus (W * \overline{Y})))$$

<ol start="2" type="a">
	<li></li>
</ol>

![Circuito lógico b | center](attachments/3-circuito-lógico-b.jpg)

$$
\displaylines{
(A * \overline{C} + A * \overline{D})
+ \overline{D} * (\overline{B} * C)
}
$$

1.  Realiza el circuito lógico del siguiente conjunto de expresiones.
    1.  $\mathbf{F}\left( \mathbf{a,b,c} \right)\mathbf{=}\overline{\mathbf{a +}\overline{\mathbf{b}}\left( \mathbf{a}\overline{\mathbf{c}} \right)}\mathbf{+}\overline{\mathbf{b}}\mathbf{c}$
    2.  $F\left( a,b,c_{1} \right) = ab + c_{1}(a \oplus b)$
    3.  $F(a,b,c,d,e) = \overline{(ab} + cd)\left( \overline{e + b}c \right) + (ab \oplus ce)$

![ | center](attachments/4-circuito-lógico.jpg)

![ | center](attachments/5-circuito-lógico.jpg)

![ | center](attachments/6-circuito-lógico.jpg)

1.  Simplifique las siguientes expresiones utilizando algebra de Boole, describa
    cada una de las reglas aplicadas para su reducción.
    1.  $F(a,b,c) = \overline{a\overline{b}\left( a \oplus \overline{c} \right)} + \overline{b}c(a + c) + \overline{a\overline{b}}(b + ad)$
            $$\displaylines{

            \overline{a \overline{b}(a \oplus \overline{c})} + bc(\overline{a+c}) + a \overline{b} + \overline{(b+ad)} \\
            \overline{a \overline{b}(a \oplus \overline{c})} + bc(\overline{a+c}) + (\overline{b} + \overline{b}d) \\
            \overline{a \overline{b}(a \oplus \overline{c})} + bc(\overline{a+c}) + (\overline{b} + \overline{b}) \\
            0 + (bc\overline{a}\overline{c}) + \overline{b}
            bc\overline{a} + b
            }
        $$
        $$
    2.  $F(a,b,c,d) ab + cd(\overline{a \oplus b)} + ca\overline{\overline{(dc + b)}}$
    $$
    \displaylines{
     ab + cd(\overline{a \oplus b)} + ca(dc + b) \\
    ab + cd(\overline{a \oplus b)} + cad + cb \\
    ab + cd(\overline{a \oplus b)} + cb \\
    ab + cd(a \oplus b) + cb \\
    ab + cda + cdb + cb \\
    ab + cd + cb \\
    ab + c \
     }
    $$
    4. $F(a,b,c,d,e) \left( \overline{(aeb} + bcd \right)\left( \overline{e + b}c \right)) + (ab + de)$

$$
\displaylines{
\left( \overline{ae} + \overline{b} + bcd \right)\left( \overline{e}c \right)) + (ab + de) \\
\left( \overline{a} + \overline{e} + \overline{b} + bcd \right)\left( \overline{e}c \right)) + (ab + de) \\
\left( \overline{a} + \overline{e} + \overline{b} + bcd \right)\left( \overline{e} + \overline{c} \right) + (ab + de) \\
\left( \overline{a} + \overline{e} + \overline{b} \right)\left( \overline{e} + \overline{c} \right) + ab\left(1 + d\right) + de \\
\left( \overline{a} + \overline{b} \right)\left( \overline{c} \right) + ab + abd + de \\
\overline{a}c + \overline{b}c + ab + de \
}
$$

1. Simplifica las funciones utilizando el método de mapas de karnaugh. Realiza
   el procedimiento de forma clara y legible, resalta la expresión obtenida una
   vez realizada la simplificación.

   1. f(a,b,c,d,e)=∑m(2,4,6,3,5,12,17,21,10,31,28)

   ![1-Karnaugh.jpg | center](attachments/1-karnaugh.jpg)
   $$(a*b*c*d*e)+(a*¬\ c*d*¬\ e)+(¬\ a*b*¬\ c*¬\ d*e)+(¬\ a*¬\ b*¬\ c*d)+(b*c*¬\ d*¬\ e)+(a*¬\ b*¬\ d*e)+(¬\ a*¬\ b*c*¬\ e)+(¬\ a*¬\ b*c*¬\ d)$$

   2. f(a,b,c,d)=∏M(12,13,14,2,8,4,6)

   ![ | center](attachments/2-karnaugh.jpg)
   $$(¬\ a*c*¬\ d)+(b*¬\ d)+(a*¬\ c*¬\ d)+(a*b*¬\ c)$$

   3. f(a,b,c)=∑m(1,2,7,6,5)

   ![ | center](attachments/3-karnaugh.jpg) $$(b*¬\ c)+(¬\ b*c)+(a*b)$$

   3. f(a,b,c,d)=∏M(3,4,2,1,12,14,15,6)

   ![ | center](attachments/4-karnaugh.jpg)
   $$(¬\ a*¬\ b*d)+(a*b*c)+(b*¬\ d)+(¬\ a*¬\ b*c)$$
