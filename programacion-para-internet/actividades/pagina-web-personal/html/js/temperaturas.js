const btnTemp = document.getElementById("btn-temp");
const resTemp = document.getElementById("res-temp");
const unidadTemp = document.getElementById("unidad-temp");

/*
+ 'parseFloat(string)' 
* Extrae el número real que se encuentre al principio de un *string*
- Cuando encuentra un número, se detendrá en cuanto detecte una letra
- Cuando no encuentra un número devuelve 'NaN' (Not a Number)
- Acepta notación científica (p. ej.'1.23e-4' = 0.000123) 
*/

let temp;
let unidad;

function getTemp() {
	let symbol = " °";

	const inputTemp = parseFloat(document.getElementById("input-temp").value);
	const optTempIn = document.getElementById("opt-temp-in").value;
	const optTempOut = document.getElementById("opt-temp-out").value;

	if (optTempIn === optTempOut) {
		alert("Error: entrada y salida deben ser diferentes");
	} else {
		switch (optTempIn) {
			case "C":
				if (optTempOut === "F") {
					temp = (inputTemp * 9) / 5 + 32;
				} else {
					temp = inputTemp + 273.15; // C->K
				}
				break;

			case "F":
				if (optTempOut === "C") {
					temp = ((inputTemp - 32) * 5) / 9;
				} else {
					temp = (inputTemp * 9) / 5 + 273.5; // F->K
				}
				break;

			case "K":
				if (optTempOut === "C") {
					temp = inputTemp = 273.5;
				} else {
					temp = ((inputTemp - 273.15) * 9) / 5 + 32; // K->F
				}
				break;
		}
	}

	temp = parseFloat(temp.toFixed(5));

	if (optTempIn === "K") {
		symbol = "";
	}
	resTemp.innerHTML = temp + symbol + optTempOut ;
}

btnTemp.addEventListener("click", getTemp);
