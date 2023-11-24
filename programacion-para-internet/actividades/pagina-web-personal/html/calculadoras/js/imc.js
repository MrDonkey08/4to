// Entrada

const inputPeso = document.getElementById("input-peso");
const inputAltura = document.getElementById("input-altura");
const btnIMC = document.getElementById("btn-imc");

// Salida

const inputIMC = document.getElementById("input-imc");
const inputComp = document.getElementById("input-composicion-corporal");

let IMC;
let comp;
let estado;

function getIMC() {
	const altura = inputAltura.value / 100;
	const peso = inputPeso.value;

	IMC = peso / altura ** 2;
	IMC = parseFloat(IMC.toFixed(5));

	/*
	+ Notación de potencia: a^n
	* Sea a y n dos números reales, entonces:
	& a ** n'' (implementado a partir de ECMAScript 2016)
	& Math.pow (a, n) (Para mayor compatibilidad)
	*/

	inputIMC.value = IMC;
	inputComp.value = getComp();
	colorEstado();
}

function getComp() {
	/* Status
		- 4 = severo -> rojo
		- 3 = alto -> naranja
		- 2 = medio -> amarillo
		- 1 = normal - > verde
	 */

	if (IMC >= 40) {
		estado = 4;
		comp = "Obesidad tipo 3 (> 40)";
	} else if (IMC >= 35) {
		estado = 4;
		comp = "Obesidad tipo 2 (35 - 40)";
	} else if (IMC >= 30) {
		estado = 3;
		comp = "Obesidad tipo 1 (30 - 34)";
	} else if (IMC >= 25) {
		estado = 2;
		comp = "Sobrepeso (25 - 29)";
	} else if (IMC >= 18.5) {
		estado = 1;
		comp = "Normal (18.5 - 24)";
	} else if (IMC >= 17) {
		estado = 2;
		comp = "Delgadez leve (17 - 18.4)";
	} else if (IMC >= 16) {
		estado = 3;
		comp = "Delgadez media (16 - 16.9)";
	} else {
		estado = 4;
		comp = "Delgadez severa (> 16)";
	}

	return comp;
}

function colorEstado() {
	switch (estado) {
		case 1: // verde
			inputIMC.style.color = inputComp.style.color = "#006100";
			inputIMC.style.backgroundColor = inputComp.style.backgroundColor = "#C6EDCE";
			break;
		case 2: // amarillo
			inputIMC.style.color = inputComp.style.color = "#E7B10A";
			inputIMC.style.backgroundColor = inputComp.style.backgroundColor = "#FFFEC4";
			break;
		case 3: // naranja
			inputIMC.style.color = inputComp.style.color = "#F94C10";
			inputIMC.style.backgroundColor = inputComp.style.backgroundColor = "#EFD595";
			break;
		case 4: // rojo
			inputIMC.style.color = inputComp.style.color = "#9C0006";
			inputIMC.style.backgroundColor = inputComp.style.backgroundColor = "#FFC7CE";
			break;
	}
}

btnIMC.addEventListener("click", getIMC);
