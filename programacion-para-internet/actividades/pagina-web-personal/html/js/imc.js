// Entrada

const inputPeso = document.getElementById("input-peso");
const inputAltura = document.getElementById("input-altura");
const btnIMC = document.getElementById("btn-imc");

// Salida

const inputIMC = document.getElementById("input-imc");
const inputComp = document.getElementById("input-composicion-corporal");

let IMC;
let comp;

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
}

function getComp() {
	if (IMC >= 40) {
		comp = "Obesidad tipo 3 (> 40)";
	} else if (IMC >= 35) {
		comp = "Obesidad tipo 2 (35 - 40)";
	} else if (IMC >= 30) {
		comp = "Obesidad tipo 1 (30 - 34)";
	} else if (IMC >= 25) {
		comp = "Sobrepeso (25 - 29)";
	} else if (IMC >= 18.5) {
		comp = "Normal (18.5 - 24)";
	} else if (IMC >= 17) {
		comp = "Delgadez leve (17 - 18.4)";
	} else if (IMC >= 16) {
		comp = "Delgadez media (16 - 16.9)";
	} else {
		comp = "Delgadez severa (> 16)";
	}

	return comp;
}

btnIMC.addEventListener("click", getIMC);
