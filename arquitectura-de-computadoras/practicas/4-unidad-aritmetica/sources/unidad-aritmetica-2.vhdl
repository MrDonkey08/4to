library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ALU4Bits is
    Port (
        CLK: in STD_LOGIC;
        A : in STD_LOGIC_VECTOR(3 downto 0);
        B : in STD_LOGIC_VECTOR(3 downto 0);
        CS : in STD_LOGIC_VECTOR(4 downto 0);
        operacion: out STD_LOGIC_VECTOR(3 downto 0);
        rc: out STD_LOGIC_VECTOR(3 downto 0)
    );
end ALU4Bits;

architecture Behavioral of ALU4Bits is
    signal C1 : STD_LOGIC_VECTOR(1 downto 0);
    variable Cout : STD_LOGIC;
begin
    process(CLK)
    begin
        if rising_edge(CLK) then
            case CS is
                when "00000" =>
                    operacion <= (A + B);
                when "00001" =>
                    operacion <= (A - B);
                    if A >= B then
                        Cout := '0';
                        C1(0) <= '0';
                    else
                        Cout := '1';
                        C1(0) <= '1';
                    end if;
                when "00010" =>
                    operacion <= (A and B);
                    Cout := '0';
                    C1(0) <= '0';
                when "00011" =>
                    operacion <= (A or B);
                    Cout := '0';
                    C1(0) <= '0';
                when "00100" =>
                    operacion <= (not A);
                    Cout := '0';
                    C1(0) <= '0';
                when "00101" =>
                    operacion <= (A xor B);
                    Cout := '0';
                    C1(0) <= '0';
                when "00110" =>
                    operacion <= (A and "1111");  -- Cambié "11111" a "1111"
                    Cout := '0';
                    C1(0) <= '0';
                when others =>
                    null;
            end case;
        end if;
    end process;

    rc(0) <= Cout;
    rc(1) <= Cout;
    rc(2) <= not (operacion(3) or operacion(2) or operacion(1));
    rc(3) <= Cout xor C1(0);
end Behavioral;
