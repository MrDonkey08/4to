LIBRARY IEEE;
USE IEEE. STD LOGIC 1164.ALL;
USE IEEE. STD LOGIC ARITH.ALL;
USE IEEE.STD LOGIC UNSIGNED.ALL;
ENTITY control IS
	PORT (
		reset : IN STD LOGIC;
		clk : IN STD LOGIC;
		irq : IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		rw : INOUT STD LOGIC;
		datain : IN STD LOGIC VECTOR (3 DOWNTO 0);
		pcontrol : INOUT STD LOGIC VECTOR (7 DOWNTO 0);
		re : IN STD LOGIC VECTOR (3 DOWNTO 0);
		pcout : IN STD LOGIC VECTOR (7 DOWNTO 0);
		cs : INOUT STD LOGIC VECTOR (4 DOWNTO 0));
END control;
ARCHITECTURE Behavioral OF control IS
	TYPE estados IS (d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17);
	SIGNAL edo presente, edo futuro : estados;
	SIGNAL f : std logic vector (7 DOWNTO 0);
BEGIN
	procesoA : PROCESS (edo presente, irq, reset)
	BEGIN
		IF reset = '1' THEN
			edo futuro <= d0;
			pcontrol <= "11111111";
			rw <= '0';
			cs <= "11110";
		ELSE
			CASE edo presente IS
				WHEN d0 =>
					IF irq - "10" THEN
						cs <= "11100";
						edo futuro <= d1;
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
						edo futuro <= dl;
					ELSIF irq = "01" THEN
						pcontrol <= "10000000";
						edo futuro <= di;
					ELSE
						ca = "11110";
						edo_futuro <= d3;
					END IF;
				WHEN d2 =>
					CE <= CS;
					edo futuro <= d5;
				WHEN d3 ->
					cE = "10110";
					rw <= '1';
					edo futuro <= d4;
				WHEN d4 ->
					EN <= '0';
					IF datain = "0000" THEN
						cs <- "00001";
						edo_futuro <= d2;
					ELSIF datain = "0001" THEN
						cs <= "00010";
						edo_futuro <= d5;
					ELSIF datain = "0010" THEN
						cs <= "00011";
						edo_futuroc = d5;
					ELSIF datain - "0011" THEN
						c8 <= "00100";
						edo futuro <= d5;
					ELSIF datain - "0100" THEN
						cs <- "00101";
						edo futuro <= d5;
					ELSIF datain - "0101" THEN
						cs <= "00110";
						edo futuro <= d5;
					ELSIF datain = "0110" THEN
						cs <= "11111";
						edo_futuro <- d6;
					ELSIF datain = "0111" THEN
						cs <= "11111";
						edo futuro <= d7;
					ELSIF datain = "1000" THEN
						cs <= "11111";
						edo futuro <= d8;
					ELSIF datain = "1001" THEN
						cs <- "00111";
						edo_futuro <- d9;
					ELSIF datain = "1010" THEN
						cs <- "11011";
						edo_futuro <= d0;
					ELSIF datain = "1011" THEN
						cs <= "11111";
						IF rc(0) = '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuroč = d0;
						END IF;
					ELSIF datain = "1100" THEN
						cs <= "11111";
						IF ro(2) = '1' THEN
							edo futuro <= d0;
						END IF;
					ELSIF datain = "1101" THEN
						cs <- "11111";
						IF rc(1) = '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuro <= d0;
						END IF;
					ELSIF datain = "1110" THEN
						@s <- "11111";
						IF rc(3) - '1' THEN
							edo_futuro <= d10;
						ELSE
							edo_futuro <- d;
						END IF;
					END IF;
				WHEN d5 =>
					cs <- "10101";
					edo futuro <= d11;
				WHEN d6 =>
					cs <- "10110";
					IW = '1';
					edo_futuro <= d12;
				WHEN d7 =>
					cs <= "10110";
					IN <= '1';
					edo_futuro <= d11;
				WHEN dB =>
					cE <- "10110";
					IW = 1';
					edo futuro <= d15;
				WHEN d9 =>
					cs <- "11000";
					edo futuro <= d10;
				WHEN d10 =>
					cs <= "10110";
					rw = '1';
					edo futuro <= d16;
				WHEN d11 ->
					ca <- "10001";
					EW <= '0';
					edo futuro <= d0;
				WHEN d12 ->
					cs <= "11111";
					IN <= '0';
					pcontrol(0) <- datain(0);
					pcontrol (1) <= datain(1);
					pcontrol(2) <= datain(2);
					pcontrol(3) <- datain(3);
					pcontrol(4) <- pcontro1(4);
					pcontrol (5) <- pcontrol(5);
					pcontrol(6) <= pcontrol(6);
					pcontrol(7) <= pcontrol (7);
					edo futuro <= d13;
				WHEN d13 =>
					Cs <= "10110";
					rw <= '1';
					edo_futuro <- d14;
				WHEN d14 =>
					c & <= "11010";
					Ew <= '0';
					pcontrol(0) <- pcontrol (0) :
					pcontrol (1) <= pcontrol (1);
					pcontrol(2) <= pcontrol (2);
					pcontrol (3) <= pcontrol (3);
					pcontrol(4) <= datain(0);
					pcontrol(5) <- datain(1);
					pcontrol(6) <= datain(2);
					pcontrol(7) <= datain(3);
					edo_futuro <= d0;
				WHEN d15 =>
					cs <= "10010";
					Ew - '0';
					edo_futuro <= d0;
				WHEN d16 =>
					cs <- "10000";
					f(0) <= datain(0);
					f(1) <= datain(1);
					f(2) <= datain(2);
					f(3) <= '0';
					£(4) <- '0';
					f(5) <= '0';
					f(6) <= '0';
					£(7) <- '0';
					IF datain(3) = '0' THEN
						pcontrok <- pcout + f;
						edo_futuro <= d17;
					ELSE
						pcontrol <- pcout - f;
						edo_futuro <= d17;
					END IF;
				WHEN d17 ->
					cs <- "11110";
					edo_ futuro <- d0;
			END CASE;
		END IF;
	END PROCESS procesoA;
	procesoB : PROCESS (clk, reset)
	BEGIN
		IF (clk' event AND clk = '1') THEN
			IF reset = '0' THEN
				edo_presente <= edo_ futuro;
			ELSE
				NULL;
			END IF;
		END IF;
	END PROCESS procesoB;
END Pshaviorali