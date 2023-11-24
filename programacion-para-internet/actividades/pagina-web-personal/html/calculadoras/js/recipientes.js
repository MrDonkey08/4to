// Variables de Entrada

const presion = document.getElementById("presion");
const diametro = document.getElementById("diametro");
const material = document.getElementById("material");
const longitud = document.getElementById("longitud");
const eficiencia = document.getElementById("eficiencia");
const densidad = document.getElementById("densidad");
const nivel = document.getElementById("nivel");

// Variables de Salida

const espesorTapasComercial = document.getElementById("espesor-tapas-comercial");
const espesorCuerpoComercial = document.getElementById("espesor-cuerpo-comercial");
const espesorTapasCalculado = document.getElementById("espesor-tapas-calculado");
const espesorCuerpoCalculado = document.getElementById("espesor-cuerpo-calculado");
const pesoVacio = document.getElementById("peso-vacio");
const pesoLleno = document.getElementById("peso-lleno");

// Botones

const btnRecipientes = document.getElementById("btn-recipientes");

// Variables

let UTS = Ys = S = tComercialBody = eta = tCalTapas = tCalCuerpo = vThicknessBody = vThicknessTapa = tComercialTapa = vTapas = vCuerpo = vTotal = vCuerpoLiquido = vTapasLiquido = pLiquido = vTLiquido = 0;

function calcularRecipiente() {
	switch (parseFloat(material.value)) {
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

	// Esfuerzo permisible
	S = Math.min(UTS / 3.5, (Ys * 2) / 3);

	switch (parseFloat(eficiencia.value)) {
		case 1: eta = 1; break;
		case 2: eta = 0.85; break;
		case 3: eta = 0.75; break;
	}

	tCalTapas = (presion.value * diametro.value) / (2 * eta * S - 0.2 * presion.value);
	tCalCuerpo = (presion.value * (diametro.value / 2)) / (eta * S - 0.6 * presion.value);

	tCalTapas = tCalTapas / 0.0254;
	tCalCuerpo = tCalCuerpo / 0.0254;

	vThicknessBody = parseFloat(espesorCuerpoComercial.value);

	switch (vThicknessBody) {
		case 1: tComercialBody = 1 / 8; break;
		case 2: tComercialBody = 1 / 4; break;
		case 3: tComercialBody = 3 / 8; break;
		case 4: tComercialBody = 5 / 8; break;
		case 5: tComercialBody = 3 / 4; break;
		case 6: tComercialBody = 7 / 8; break;
		case 7: tComercialBody = 1; break;
		case 8: tComercialBody = 1 + 1 / 4; break;
		case 9: tComercialBody = 1 + 1 / 2; break;
		case 10: tComercialBody = 1 + 3 / 4; break;
		case 11: tComercialBody = 2; break;
	}

	// Espesor comercial de las tapas

	vThicknessTapa = parseFloat(espesorTapasComercial.value);

	switch (vThicknessTapa) {
		case 1: tComercialTapa = 1 / 8; break;
		case 2: tComercialTapa = 1 / 4; break;
		case 3: tComercialTapa = 3 / 8; break;
		case 4: tComercialTapa = 5 / 8; break;
		case 5: tComercialTapa = 3 / 4; break;
		case 6: tComercialTapa = 7 / 8; break;
		case 7: tComercialTapa = 1; break;
		case 8: tComercialTapa = 1 + 1 / 4; break;
		case 9: tComercialTapa = 1 + 1 / 2; break;
		case 10: tComercialTapa = 1 + 3 / 4; break;
		case 11: tComercialTapa = 2; break;
	}

	if (tComercialBody < tCalCuerpo) {
		espesorCuerpoCalculado.style.backgroundColor = "rgb(255,199,206)";
		espesorCuerpoCalculado.style.color = "rgb(156,0,6)";
	} else {
		espesorCuerpoCalculado.style.backgroundColor = "rgb(198,239,206)";
		espesorCuerpoCalculado.style.color = "rgb(0,97,0)";
	}

	if (tComercialTapa < tCalTapas) {
		espesorTapasCalculado.style.backgroundColor = "rgb(255,199,206)";
		espesorTapasCalculado.style.color = "rgb(156,0,6)";
	} else {
		espesorTapasCalculado.style.backgroundColor = "rgb(198,239,206)";
		espesorTapasCalculado.style.color = "rgb(0,97,0)";
	}

	diametro1 = parseFloat(diametro.value);
	longitud1 = parseFloat(longitud.value);

	vTapas = (Math.PI / 12) * (Math.pow(diametro1 + 2 * tComercialTapa * 0.0254, 3) - Math.pow(diametro1, 3));
	vCuerpo = ((Math.PI * longitud1) / 4) * (Math.pow(diametro1 + 2 * tComercialBody * 0.0254, 2) - Math.pow(diametro1, 2));

	vTotal = vTapas + vCuerpo;
	pesoVacio.value = (7800 * vTotal).toFixed(0);

	espesorTapasCalculado.value = tCalTapas.toFixed(4);
	espesorCuerpoCalculado.value = tCalCuerpo.toFixed(4);

	// Calcular volumen y peso del líquido
	
	vTapasLiquido = (Math.PI / 12) * Math.pow(diametro1, 3);
	vCuerpoLiquido = ((Math.PI * longitud1) / 4) * Math.pow(diametro1, 2);
	vTLiquido = vTapasLiquido + vCuerpoLiquido;

	pLiquido = densidad.value * vTLiquido;
	pesoLleno.value = (parseFloat(pesoVacio.value) + pLiquido).toFixed(0);
}

btnRecipientes.addEventListener("click", calcularRecipiente);