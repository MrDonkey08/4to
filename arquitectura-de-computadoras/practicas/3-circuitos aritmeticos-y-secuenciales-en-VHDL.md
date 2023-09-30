<div style="page-break-after: always;"></div>


# Práctica 3: Circuitos aritméticos y secuenciales en VHDL

## Sumador de 4 bits

### Diagrama a bloques

![ | center | 400](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/FA-4bits-bloques.png)

### Análisis Lógico

|  A  |  B  | Ci  | Co  |  S  |
|:---:|:---:|:---:|:---:|:---:|
|  0  |  0  |  0  |  0  |  0  |
|  0  |  0  |  1  |  0  |  1  |
|  0  |  1  |  0  |  0  |  1  |
|  0  |  1  |  1  |  1  |  0  |
|  1  |  0  |  0  |  0  |  1  |
|  1  |  0  |  1  |  1  |  0  |
|  1  |  1  |  0  |  1  |  0  |
|  1  |  1  |  1  |  1  |  1  |



![ | center | 400](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/FA-4bits-logico.png)

### Código VHDL

```VHDL
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ContadorGray3Bits is
    Port (
        Clock, Reset : in STD_LOGIC;
        GrayCode : out STD_LOGIC_VECTOR(2 downto 0)
    );
end ContadorGray3Bits;

architecture Behavioral of ContadorGray3Bits is
    signal contador : STD_LOGIC_VECTOR(2 downto 0) := "000";
begin
    process(Clock, Reset)
    begin
        if Reset = '1' then
            contador <= "000";
        elsif rising_edge(Clock) then
            if contador = "111" then
                contador <= "000";
            else
                contador <= contador + 1;
            end if;
        end if;
    end process;

    GrayCode(2) <= contador(2) xor contador(1);
    GrayCode(1) <= contador(1) xor contador(0);
    GrayCode(0) <= contador(0);
end Behavioral;
```

### Cronograma

![ | center ](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/FA-cronograma-1.png)

![ | center ](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/FA-cronograma-2.png)


<div style="page-break-after: always;"></div>

## Contador de 3 bits Gray

### Diagrama a bloques

![ | center | 400](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/contador-3bits-2-gray-bloques.png)

### Análisis Lógico

 | $Q_2$ | $Q_1$ | $Q_0$ | $\overline{Q_2}$ | $\overline{Q_1}$ | $\overline{Q_0}$ |
 |:-----:|:-----:|:-----:|:----------------:|:----------------:|:----------------:|
 |   0   |   0   |   0   |        0         |        0         |        1         |
 |   0   |   0   |   1   |        0         |        1         |        1         |
 |   0   |   1   |   1   |        0         |        1         |        0         |
 |   0   |   1   |   0   |        1         |        1         |        0         |
 |   1   |   1   |   0   |        1         |        1         |        1         |
 |   1   |   1   |   1   |        1         |        0         |        1         |
 |   1   |   0   |   1   |        1         |        0         |        0         |
 |   1   |   0   |   0   |        0         |        0         |        0         |

![ | center | 400](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/contador-3bits-2-gray-logico.png)

### Código VHDL

```VHDL
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ContadorGray3Bits is
    Port (
        Clock, Reset : in STD_LOGIC;
        GrayCode : out STD_LOGIC_VECTOR(2 downto 0)
    );
end ContadorGray3Bits;

architecture Behavioral of ContadorGray3Bits is
    signal contador : STD_LOGIC_VECTOR(2 downto 0) := "000";
begin
    process(Clock, Reset)
    begin
        if Reset = '1' then
            contador <= "000";
        elsif rising_edge(Clock) then
            if contador = "111" then
                contador <= "000";
            else
                contador <= contador + 1;
            end if;
        end if;
    end process;

    GrayCode(2) <= contador(2) xor contador(1);
    GrayCode(1) <= contador(1) xor contador(0);
    GrayCode(0) <= contador(0);
end Behavioral;
```

### Cronograma

![ | center ](3-circuitos-aritmeticos-y-secuenciales-en-vhdl/attachments/contador-3bits-2-gray-cronograma.png)