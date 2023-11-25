function calcularepFcn() {
	diametro = parseFloat(document.querySelector("#diametro").value);
	longitud = parseFloat(document.querySelector("#Longitud").value);
	/* Materiales */
	material = document.querySelector("#Material").value;
	material = parseFloat(material);
	UTS = 0;
	Ys = 0;
	switch (material) {
		case 1:
			UTS = 415;
			Ys = 230;
			break;
		case 2:
			UTS = 450;
			Ys = 275;
			break;
		case 3:
			UTS = 485;
			Ys = 275;
			break;
		case 4:
			UTS = 415;
			Ys = 220;
			break;
		case 5:
			UTS = 485;
			Ys = 260;
			break;
	}

	/* Eficiencia de la junta */
	eficiencia = document.querySelector("#Eficiencia").value;
	eficiencia = parseFloat(eficiencia);
	eta = 0;
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

	/* Nivel */
	nivel = document.querySelector("#Nivel").value;
	nivel = parseFloat(nivel);
	rho = document.querySelector("#Densidad").value;
	rho = parseFloat(rho);

	document.querySelector("#EspesorCalculado").value = nivel;
}
