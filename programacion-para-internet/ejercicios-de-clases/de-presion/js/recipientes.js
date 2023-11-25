function calcularpFcn() {
	presion = document.querySelector("#presion").value;
	diametro = document.querySelector("#diametro").value;
	longitud = document.querySelector("#longitud").value;
	densidad = document.querySelector("#densidad").value;
	nivel = document.querySelector("#nivel").value;

	eficiencia = document.querySelector("#eficiencia").value;
	eficiencia = parseFloat(eficiencia);
	switch (eficiencia) {
		case 1:
			eta = 1;
			break;
		case 2:
			eta = 0.85;
			break;
		case 3:
			eta = 0.75;
			break;
	}

	document.querySelector("#espesortapascalculado").value = densidad;
}
