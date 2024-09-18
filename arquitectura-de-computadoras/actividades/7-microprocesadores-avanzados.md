# Microprocesadores Avanzados

## Introducción

La microarquitectura de una CPU moderna es una pieza clave en el funcionamiento
eficiente de los sistemas informáticos. En su implementación, sigue un conjunto
de etapas denominado CPU's pipeline, que incluye Fetch, Decode, Execute y Write
Back. Estas etapas permiten que las instrucciones de un programa se ejecuten de
manera secuencial y eficiente, pero surgen desafíos, como el manejo de
instrucciones de ramificación (branches) y la optimización del rendimiento.

La especulación en la ejecución de branches se ha convertido en una estrategia
importante para evitar la pérdida de recursos al anticipar decisiones sobre qué
instrucciones descartar o ejecutar. La introducción de algoritmos basados en
inteligencia artificial ha mejorado significativamente la predicción de
branches, minimizando el tiempo de espera y optimizando el rendimiento global de
la CPU.

Además, conceptos como SuperScalar Execution y Out of Order Execution han
transformado la ejecución de instrucciones al permitir paralelismo y
reorganización de tareas, contribuyendo así a un rendimiento más eficiente.

En el ámbito de la clasificación de Flynn, se exploran diferentes arquitecturas
de computadoras. Desde las tradicionales Single Instruction Single Data (SISD)
hasta las modernas Multiple Instruction Multiple Data (MIMD), cada clasificación
tiene sus ventajas y desventajas, adecuándose a distintos usos y requisitos de
rendimiento.

La introducción de hardware multi-threading aborda desafíos comunes que afectan
el rendimiento de la CPU, como pérdidas en las cachés de datos e instrucciones,
bloqueos por dependencia de datos y bloqueos de unidades funcionales.
Estrategias como Coarse-Grained Multi-Threading y Fine-Grained Multi-Threading
buscan optimizar el rendimiento al cambiar dinámicamente entre hilos en caso de
bloqueos, aumentando así el rendimiento global del sistema.

La conexión de multiprocesadores presenta distintos enfoques, desde el uso de un
solo bus compartido hasta la implementación de redes de comunicación. Cada
enfoque tiene sus ventajas y desventajas, siendo la elección entre simplicidad y
rendimiento una consideración crucial en el diseño de sistemas informáticos,
desde sistemas embebidos hasta supercomputadoras.

En conjunto, estos componentes y conceptos de la microarquitectura de una CPU
moderna demuestran la complejidad y la sofisticación involucradas en el diseño
de sistemas informáticos eficientes y de alto rendimiento.

<div style="page-break-after: always;"></div>

## Desarrollo

### Componentes de la microarquitectura de una CPU moderna

La **microarquitectura** de una CPU es una implementación de un ISA (Instruction
Set Arquitecture). Este está compuesto de 4 etapas conocidas como _CPU's
pipeline_:

1. **Fetch:** Consiste en obtener las instrucciones del programa desde la
   memoria
2. **Decode:** Consiste en decodificar o, dicho de otra manera, traducir las
   instrucciones conseguidas a operaciones nativas
3. **Execute:** Consiste en ejecutar las instrucciones previamente
   decodificadas, utilizando operaciones aritméticas o lógicas.
4. **Write Back:** Por último, es necesario guardar los resultados del programa,
   en ocasiones localmente en registros y en otras ocasiones en memoria

El CPU's pipeline es sincrono, es decir, cada pipeline es controlado por un
reloj y cada dato va de una etapa del pipeline a la siguiente

#### Especulación

Al ejecutar un programa, como se menciono anteriormente, en la fase de execute
se ejecutan las instrucciones decodificadas, algunas de estas intrucciones son
catalogadas como _branch_. Estas instrucciones representan un punto de decisión,
en el que se decide seguir con las instrucciones o, caso contrario, desechar
ciertas instrucciones, redirigirse a otras instrucciones para tomar un camino
diferente

El problema en esta fase es que, se desperdician recursos al decodificar
instrucciones que serán desechadas. Si bien, podemos esperar a que se decida si
tomar el _branch_ para decodificar o no las instrucciones asociadas a este, esto
conllevaría a un retraso de tiempo.

Actualmente se ha desarrollado una algoritmo para impulsar la toma de deciciones
de los _branches_, este consiste en un módulo que utiliza inteligencia
artificial, este trata de predecir si los branches se deben de desechar o no, si
acierta, seguirá con su flujo de trabajo, si falla recibirá retroalimentación,
lo cual ayudará a conseguir una mejor predicción de los siguientes branches

#### SuperScalar Execution

En una CPU existen multiples ALU's algunas de ellas con diferentes diferentes
capacidades (operaciones). La existencia de múltiples ALU's permite dividir las
instrucciones para ser paralelamente

#### Out of Order

El flujo normal de ejecución de las instrucciones es de manera secuencial, sin
embargo, para conseguir el mayor aprovechamiento de los recursos para un mejor
rendimiento no es la mejor opción. Por lo tanto, es necesario implementar un
flujo diferente de trabajo, tal como la ejeución "fuera del orden"

La ejecución "fuera del orden" consiste en pausar aquellos procesos que
necesitan del cálculo de un operando para aprovechar el tiempo y trabajar en
aquellos que están listos. Una vez que los operandos necesarios para la
instrucción están listos, proceden a continuar el flujo para su uso

### Clasificación de Flynn

La taxonomía de Flynn es una clasificación de arquitecturas de computadora ,
propuesta por Michael J. Flynn en 1966. El sistema de clasificación se ha
estancado y se ha utilizado como herramienta en el diseño de procesadores
modernos y sus funcionalidades. Desde el surgimiento de las unidades de
procesamiento central de multiprocesamiento (CPU), un contexto de
multiprogramación ha evolucionado como una extensión del sistema de
clasificación.

#### Single Instruction Single Data (SISD)

Esta clasificación se refiere a las computadoras tradicionales y secuenciales en
las cuales una instrución a la vez se ejecuta sobre un único dato cada ciclo de
reloj.

Los datos en cuestión se almacenan en una única memoria en la cual se usan
técnicas como la segmentación para evitar errores de fragmentación interna.

##### Ventajas

- Barato
- Bajo consumo de energía

##### Desventajas

- Velocidad limitada por ser _single core_

##### Usos

- Microcontroladores
- Antiguos mainframes

#### Single Instruction Multiple Data (SIMD)

Esta arquitectura representa la ejecución de una misma instrucción sobre un
conjunto de datos. La misma es comúnmente vista en ciclos de programación que
ejecutan una misma instrucción una y otra vez sobre datos de un arreglo o
conjunto de datos. En la arquitectura SIMD estos datos son procesados por
múltiples CPU que ejecutan la misma instrucción sobre una parte del conjunto o
arreglo, cada uno, hasta llegar a procesar la totalidad de los mismos.

##### Ventajas

- Muy eficiente donde se necesita realizar la misma instrucción en grandes
  cantidades de datos

##### Desventajas

- Limitado a aplicaciones especificas

##### Usos

- GPU's
- Procesamiento cientifíco

#### Multiple Instruction Single Data(MISD)

Arquitectura que se refiere a múltiples instrucciones ejecutándose sobre un
único dato. Comúnmente se considera esta arquitectura poco práctica ya que en
tiempo de ejecución la efectividad del paralelismo requiere un múltiple flujo de
datos y, además, el acceso concurrente a un mismo dato en memoria puede
ocasionar que un CPU tenga que esperar a que el recurso(dato) esté disponible
para poder acceder a él.

##### Ventajas

- Util cuando es necesario la detección de fallos en tiempo real.

##### Desventajas

- Aplicaciones muy limitadas y, por lo tanto, no disponible comercialmente

##### Usos

- Sistemas de vuelo de transbordador espacial

#### Multiple Instruction Multiple Data (MIMD)

Esta arquitectura representa a un conjunto de instrucciones que se ejecutan
sobre un conjunto múltiple de datos. La misma es muy usada hoy en día para
explotar el paralelismo ya sea con memoria distribuida y memoria compartida o
híbridos como los clústers de computadoras.

##### Ventajas

- Gran cantidad de situaciones en donde el _multitasking_ es requerido

##### Desventajas

- Arquitectura mucho más compleja y, por ende, más costosa

##### Usos

- Computadoras modernas, laptops y teléfonos inteligentes.

### Hardware Multi-threading

Cuando una computadora es ejecutada, hay mucho eventos que pueden provocar que
los recursos del hardware del CPU no puedan ser utilzados completamente cada
ciclo del CPU, tal como:

- **Pérdida en la cache de datos:** Los datos solicitados requieren ser cargados
  desde memoria fuera del CPU. La CPU debe de esperar a que la información
  llegue de la memoria remota
- **Pérdida en la cache de instrucciones:** La siguiente instrucción del
  programa debe ser buscada de memoria fuera del CPU. De nuevo, la CPU debe
  esperar a que la siguiente instrucción llegue de la memoria remota
- **Bloqueo por dependencia de datos:** La siguiente instrucción no puede ser
  ejecutada dabido a que depende de un operando que no ha sido calculado
- **Bloqueo de unidad funcional:** La siguiente instrucción no puede ser
  ejecutada aún debido a que el resurso de hardware está ocupado.

Cuando una parte del programa (conocida como hilo) se bloquea por uno de estos
eventos, los recursos de hardware podrían utilizarse potencialmente para otro
hilo de ejecución. Al cambiar a un segundo hilo cuando el primero está
bloqueado, se puede aumentar el rendimiento global del sistema. La idea de
acelerar la ejecución agregada de todos los hilos del sistema se conoce como
"Throughput Computing". Esto contrasta con la aceleración de la ejecución de un
único hilo (o ejecución de un único hilo).

Si se replica toda una CPU para ejecutar un segundo hilo, la técnica se conoce
como multiprocesamiento.

Si sólo se replica una parte de la CPU para ejecutar un segundo hilo, la técnica
se denomina multihilo.

Compartir los recursos de hardware entre varios subprocesos supone una evidente
ventaja económica en comparación con el multiprocesamiento completo. Otra
ventaja potencial es que varios subprocesos pueden trabajar con los mismos
datos. Al compartir las mismas cachés de datos, varios subprocesos consiguen una
mejor utilización de estas cachés y una mejor sincronización de los datos
compartidos.

#### Coarse-Grained Multi-Threading

El tipo más simple de multi-threading se conoce como **Coarse-Grained
Multi-Threading**. Para este tipo, un hilo se ejecuta hasta que es bloqueado por
un evento que crea un bloqueo de larga latencia (normalmente un fallo de caché).
Este bloqueo de larga latencia debe ser identificado y comprobado por el
programador y, a continuación, el procesador se cambia mediante programación
para ejecutar otro subproceso.

#### Fine-Grained Multi-Threading

Un tipo más sofisticado de multihilo se conoce como **Fine-Grained
Multi-Threading**. En este tipo, la CPU comprueba en cada ciclo si el subproceso
actual está atascado o no. Si se estanca, un planificador de hardware cambiará
la ejecución a otro hilo que esté listo para ejecutarse. Dado que el hardware
comprueba cada ciclo en busca de bloqueos, se pueden tratar todos los tipos de
bloqueos, incluso los de un solo ciclo.

#### Simultaneous Multi-threading

El tipo más sofisticado de multihilo se aplica a los procesadores
superescalares. Superescalar significa que el procesador puede ejecutar
múltiples instrucciones en cada ciclo de CPU.

El **Multi-threading simultáneo** es aquel en el que cada una de estas
instrucciones que se emiten juntas puede ser del mismo hilo o cada una puede ser
de hilos diferentes. El programador de hilos del hardware elegirá las
instrucciones más apropiadas para maximizar la utilización de los canales de
ejecución.

#### MIPS Multi-threading

El primer procesadorprocesador multihilo de MIPS fue el MIPS32 34K, que salió al
mercado en 2005. El 34K implementaba el multihilo de grano fino (el tipo más
moderno que no tiene que cambiar ciegamente de hilo en cada ciclo), con un
programador de hilos de hardware dentro de la CPU que elige el hilo más
apropiado para ejecutarse en cada ciclo de la CPU.

Todos los procesadores multihilo posteriores de MIPS también han implementado el
multihilo de grano fino. Esto incluye el sistema de multiprocesamiento simétrico
1004K y la familia interAptiv de CPU multinúcleo multihilo, que ofrece un mayor
rendimiento multinúcleo y funciones añadidas como ECC de caché de datos,
direccionamiento virtual ampliado (EVA), FPU multihilo, DSP ASE actualizado y
otras funciones.

### Procesador Vectorial

Un procesador vectorial es un diseño de CPU capaz de ejecutar operaciones
matemáticas sobre múltiples datos de forma simultánea, en contraste con los
procesadores escalares, capaces de manejar sólo un dato cada vez.

A diferencia de un procesador escalar, un vectorial puede decodificar
intstrucciones cuyos operandos son vectores completos. La conversión de un
rprograma correspondiente a un procesador escalar a otro vectorial se llama
**vectorización**

hardware multithreading,

### Conexión de multiprocesadores

#### Por un solo bus

En este enfoque, todos los procesadores comparten un solo bus para la
comunicación de datos y control. El bus actúa como un canal de comunicación
centralizado al que todos los procesadores están conectados.

Este destaca debido a su sencillez, es decir, es simple y fácil de implementar,
además, suele ser más barata respecto al hardware. Por otra parte, uno de sus
principales problemas es el famoso cuello de botellas, esto ocasionado por el
ancho de banda del bus.

Se encuentra en sistemas más pequeños, como sistemas embebidos o sistemas de
propósito específico, donde no se requiere un alto rendimiento y la simplicidad
es crucial.

#### Por una red

En lugar de compartir un bus, cada procesador está conectado a una red de
comunicación. La topología de la red puede variar, desde topologías de árbol
hasta topologías de malla o toro.

Una de sus principales ventajas es su escalabilidad. Este permite una mayor
escalibilidad al añadir más procesadores sin los cuellos de bottelas de un solo
bus. Sin embargo, uno de sus grandes desventajas es que es más compleja y
costosa respecto a la de un solo bus.

Este enfoque se utiliza comúnmente en sistemas de alto rendimiento, como
clústeres de servidores y supercomputadoras, donde la escalabilidad y el
rendimiento son cruciales.

<div style="page-break-after: always;"></div>

## Conclusión

En conclusión, la exploración de los componentes de la microarquitectura de una
CPU moderna revela la complejidad y la sofisticación necesarias para alcanzar un
rendimiento óptimo en los sistemas informáticos actuales. Desde el diseño del
pipeline de la CPU hasta la implementación de estrategias avanzadas como la
especulación en la ejecución de branches, la ejecución fuera de orden y la
ejecución superscalar, se busca constantemente mejorar la eficiencia y
aprovechar al máximo los recursos disponibles.

La clasificación de Flynn proporciona un marco para entender las diferentes
arquitecturas de computadoras, desde las tradicionales hasta las más avanzadas,
adaptándose a diversas necesidades y aplicaciones. Cada clasificación presenta
ventajas y desventajas, y la elección de la arquitectura adecuada depende de los
requisitos específicos de rendimiento y funcionalidad.

La introducción del hardware multi-threading aborda desafíos inherentes a la
ejecución de programas, como bloqueos en la caché y dependencias de datos.
Estrategias como el multithreading grueso y fino buscan optimizar el rendimiento
al cambiar dinámicamente entre hilos, mejorando así la utilización de los
recursos y el rendimiento global del sistema.

En cuanto a la conexión de multiprocesadores, la elección entre un solo bus
compartido y una red de comunicación depende de consideraciones como la
escalabilidad, la complejidad y el rendimiento. Cada enfoque tiene sus ventajas
y desventajas, y la decisión se basa en las necesidades específicas de la
aplicación, desde sistemas embebidos hasta supercomputadoras.

En resumen, la evolución constante de la microarquitectura de las CPUs refleja
la búsqueda continua de soluciones innovadoras para mejorar la eficiencia y el
rendimiento de los sistemas informáticos. La intersección de la inteligencia
artificial, el paralelismo y la optimización de recursos juega un papel crucial
en la creación de procesadores más potentes y capaces de satisfacer las demandas
cada vez mayores de la computación moderna.

<div style="page-break-after: always;"></div>

## Referencias

- Intel Technology. (abril 8, 2021). _Architecture All Access: Modern CPU
  Architecture Part 2 – Microarchitecture Deep Dive_. Consultado el 29 de
  noviembre de 2023 de https://www.youtube.com/watch?v=o_WXTRS2qTY

- Learn Learn Scratch Tutorials (s.f.). _SISD,SIMD,MISD,MIMD_. Consultado el 29
  de noviembre de 2023 de https://learnlearn.uk/alevelcs/sisd-simd-misd-mimd/

- EcuRed. (s.f.). _Taxonomía de Flynn_. Consultado el 29 de noviembre de 2023 de
  https://www.ecured.cu/Taxonom%C3%ADa_de_Flynn

- Hmong (s.f.). _Taxonomía de Flynn_. Consultado el 29 de noviembre de 2023 de
  https://hmong.es/wiki/Flynn's_taxonomy#title

- Lau D. (s.f.). _Hardware Multi-threading: a Primer_. Consultado el 29 de
  noviembre de 2023 de
  https://www.chipestimate.com/Hardware-Multi-threading-a-Primer/Imagination-Technologies/Technical-Article/2016/12/27

- Departamento de Informática - Universidad de Valladolid. (). _PROCESADORES
  VECTORIALES_. Consultado el 29 de noviembre de 2023 de
  https://www.infor.uva.es/~bastida/Arquitecturas%20Avanzadas/Vectoriales.pdf
