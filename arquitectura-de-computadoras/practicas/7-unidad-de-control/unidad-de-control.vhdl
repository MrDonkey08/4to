LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY control IS
	PORT (
		reset : IN STD_LOGIC;
		clk : IN STD_LOGIC;
		irq : IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		rw : INOUT STD_LOGIC;
		datain : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		pcontrol : INOUT STD_LOGIC_VECTOR (7 DOWNTO 0);
		rc : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		pcout : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
		cs : INOUT STD_LOGIC_VECTOR (4 DOWNTO 0));
END control;

ARCHITECTURE Behavioral OF control IS
	TYPE estados IS (d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17);
	SIGNAL edo_presente, edo_futuro : estados;
	SIGNAL f : STD_LOGIC_VECTOR (7 DOWNTO 0);
BEGIN
	procesoA : PROCESS (edo_presente, irq, reset)
	BEGIN
		IF reset = '1' THEN
			edo_futuro <= d0;
			pcontrol <= "11111111";
			rw <= '0';
			cs <= "11110";
		ELSE
			CASE edo_presente IS
				WHEN d0 =>
					IF irq - "10" THEN
						cs <= "11100";
						edo_futuro <= d1;
					ELSIF irq = "01" THEN
						cs <= "11100";
						edo_futuro <= d1;
					ELSE
						cs <= "11111";
						edo_futuro <= d3;
					END IF;
				WHEN d1 =>
					IF irq - "10" THEN
						pcontrol <= "01000000";
						edo_futuro <= dl;
					ELSIF irq = "01" THEN
						pcontrol <= "10000000";
						edo_futuro <= di;
					ELSE
						cs = "11110";
						edo_futuro <= d3;
					END IF;
				WHEN d2 =>
					cs <= cs;
					edo_futuro <= d5;
				WHEN d3 =>
					cs = "10110";
					rw <= '1';
					edo_futuro <= d4;
				WHEN d4 =>
					rw <= '0';
					IF datain = "0000" THEN
						cs <= "00001";
						edo_futuro <= d2;
					ELSIF datain = "0001" THEN
						cs <= "00010";
						edo_futuro <= d5;
					ELSIF datain = "0010" THEN
						cs <= "00011";
						edo_futuro = d5;
					ELSIF datain - "0011" THEN
						cs <= "00100";
						edo_futuro <= d5;
					ELSIF datain - "0100" THEN
						cs <= "00101";
						edo_futuro <= d5;
					ELSIF datain - "0101" THEN
						cs <= "00110";
						edo_futuro <= d5;
					ELSIF datain = "0110" THEN
						cs <= "11111";
						edo_futuro <= d6;
					ELSIF datain = "0111" THEN
						cs <= "11111";
						edo_futuro <= d7;
					ELSIF datain = "1000" THEN
						cs <= "11111";
						edo_futuro <= d8;
					ELSIF datain = "1001" THEN
						cs <= "00111";
						edo_futuro <= d9;
					ELSIF datain = "1010" THEN
						cs <= "11011";
						edo_futuro <= d0;
					ELSIF datain = "1011" THEN
						cs <= "11111";
						IF rc(0) = '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuro = d0;
						END IF;
					ELSIF datain = "1100" THEN
						cs <= "11111";
						IF rc(2) = '1' THEN
							edo_futuro <= d0;
						END IF;
					ELSIF datain = "1101" THEN
						cs <= "11111";
						IF rc(1) = '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuro <= d0;
						END IF;
					ELSIF datain = "1110" THEN
						@s <= "11111";
						IF rc(3) - '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuro <= d0;
						END IF;
					END IF;
				WHEN d5 =>
					cs <= "10101";
					edo_futuro <= d11;
				WHEN d6 =>
					cs <= "10110";
					rw = '1';
					edo_futuro <= d12;
				WHEN d7 =>
					cs <= "10110";
					rw <= '1';
					edo_futuro <= d11;
				WHEN dB =>
					cs <= "10110";
					rw = 1';
					edo_futuro <= d15;
				WHEN d9 =>
					cs <= "11000";
					edo_futuro <= d10;
				WHEN d10 =>
					cs <= "10110";
					rw = '1';
					edo_futuro <= d16;
				WHEN d11 =>
					cs <= "10001";
					rw <= '0';
					edo_futuro <= d0;
				WHEN d12 =>
					cs <= "11111";
					rw <= '0';
					pcontrol(0) <= datain(0);
					pcontrol(1) <= datain(1);
					pcontrol(2) <= datain(2);
					pcontrol(3) <= datain(3);
					pcontrol(4) <= pcontro1(4);
					pcontrol(5) <= pcontrol(5);
					pcontrol(6) <= pcontrol(6);
					pcontrol(7) <= pcontrol(7);
					edo_futuro <= d13;
				WHEN d13 =>
					cs <= "10110";
					rw <= '1';
					edo_futuro <= d14;
				WHEN d14 =>
					c & <= "11010";
					rw <= '0';
					pcontrol(0) <= pcontrol(0) :
					pcontrol(1) <= pcontrol(1);
					pcontrol(2) <= pcontrol(2);
					pcontrol(3) <= pcontrol(3);
					pcontrol(4) <= datain(0);
					pcontrol(5) <= datain(1);
					pcontrol(6) <= datain(2);
					pcontrol(7) <= datain(3);
					edo_futuro <= d0;
				WHEN d15 =>
					cs <= "10010";
					rw - '0';
					edo_futuro <= d0;
				WHEN d16 =>
					cs <= "10000";
					f(0) <= datain(0);
					f(1) <= datain(1);
					f(2) <= datain(2);
					f(3) <= '0';
					£(4) <= '0';
					f(5) <= '0';
					f(6) <= '0';
					£(7) <= '0';
					IF datain(3) = '0' THEN
						pcontrol <= pcout + f;
						edo_futuro <= d17;
					ELSE
						pcontrol <= pcout - f;
						edo_futuro <= d17;
					END IF;
				WHEN d17 =>
					cs <= "11110";
					edo_futuro <= d0;
			END CASE;
		END IF;
	END PROCESS procesoA;
	procesoB : PROCESS (clk, reset)
	BEGIN
		IF (clk' event AND clk = '1') THEN
			IF reset = '0' THEN
				edo_presente <= edo_futuro;
			ELSE
				NULL;
			END IF;
		END IF;
	END PROCESS procesoB;
END Behavioral;