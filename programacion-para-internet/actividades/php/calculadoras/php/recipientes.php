<?php

// Variables de Entrada

$presion = $_POST["presion"];
$diametro = $_POST["diametro"];
$material = $_POST["material"];
$longitud = $_POST["longitud"];
$eficiencia = $_POST["eficiencia"];
$densidad = $_POST["densidad"];
$nivel = $_POST["nivel"];

// Variables de Salida

$espesorTapasComercial = $_POST["espesor-tapas-comercial"];
$espesorCuerpoComercial = $_POST["espesor-cuerpo-comercial"];
$espesorTapasCalculado = $_POST["espesor-tapas-calculado"];
$espesorCuerpoCalculado = $_POST["espesor-cuerpo-calculado"];
$pesoVacio = $_POST["peso-vacio"];
$pesoLleno = $_POST["peso-lleno"];

// Botones

$btnRecipientes = $_POST["btn-recipientes"];

// Variables

$UTS = $Ys = $S = $tComercialBody = $eta = $tCalTapas = $tCalCuerpo = $vThicknessBody = $vThicknessTapa = $tComercialTapa = $vTapas = $vCuerpo = $vTotal = $vCuerpoLiquido = $vTapasLiquido = $pLiquido = $vTLiquido = 0;

$status = "";

function calcularRecipiente() {
	global $presion, $diametro, $material,  $longitud, $eficiencia, $densidad, $nivel;
	global $espesorCuerpoComercial, $espesorTapasComercial, $espesorCuerpoCalculado, $espesorTapasCalculado, $pesoVacio, $pesoLleno;
	global $UTS, $Ys, $S, $tComercialBody, $eta, $tCalTapas, $tCalCuerpo, $vThicknessBody, $vThicknessTapa, $tComercialTapa, $vTapas, $vCuerpo, $vTotal, $vCuerpoLiquido, $vTapasLiquido, $pLiquido, $vTLiquido;
	global $status;

	switch (floatval($material)) {
		case 1:
			$UTS = 415;
			$Ys = 230;
			break;
		case 2:
			$UTS = 450;
			$Ys = 275;
			break;
		case 3:
			$UTS = 485;
			$Ys = 275;
			break;
		case 4:
			$UTS = 415;
			$Ys = 220;
			break;
		case 5:
			$UTS = 485;
			$Ys = 260;
			break;
	}

	// Esfuerzo permisible
	$S = min($UTS / 3.5, ($Ys * 2) / 3);

	switch (floatval($eficiencia)) {
		case 1: $eta = 1; break;
		case 2: $eta = 0.85; break;
		case 3: $eta = 0.75; break;
	}

	$tCalTapas = ($presion * $diametro) / (2 * $eta * $S - 0.2 * $presion);
	$tCalCuerpo = ($presion * ($diametro / 2)) / ($eta * $S - 0.6 * $presion);

	$tCalTapas = $tCalTapas / 0.0254;
	$tCalCuerpo = $tCalCuerpo / 0.0254;

	$vThicknessBody = floatval($espesorCuerpoComercial);

	switch ($vThicknessBody) {
		case 1: $tComercialBody = 1 / 8; break;
		case 2: $tComercialBody = 1 / 4; break;
		case 3: $tComercialBody = 3 / 8; break;
		case 4: $tComercialBody = 5 / 8; break;
		case 5: $tComercialBody = 3 / 4; break;
		case 6: $tComercialBody = 7 / 8; break;
		case 7: $tComercialBody = 1; break;
		case 8: $tComercialBody = 1 + 1 / 4; break;
		case 9: $tComercialBody = 1 + 1 / 2; break;
		case 10: $tComercialBody = 1 + 3 / 4; break;
		case 11: $tComercialBody = 2; break;
	}

	// Espesor comercial de las tapas

	$vThicknessTapa = floatval($espesorTapasComercial);

	switch ($vThicknessTapa) {
		case 1: $tComercialTapa = 1 / 8; break;
		case 2: $tComercialTapa = 1 / 4; break;
		case 3: $tComercialTapa = 3 / 8; break;
		case 4: $tComercialTapa = 5 / 8; break;
		case 5: $tComercialTapa = 3 / 4; break;
		case 6: $tComercialTapa = 7 / 8; break;
		case 7: $tComercialTapa = 1; break;
		case 8: $tComercialTapa = 1 + 1 / 4; break;
		case 9: $tComercialTapa = 1 + 1 / 2; break;
		case 10: $tComercialTapa = 1 + 3 / 4; break;
		case 11: $tComercialTapa = 2; break;
	}

	if ($tComercialBody < $tCalCuerpo) {
		$status = "warning";
	} else {
		$status = "good";
	}

	if ($tComercialTapa < $tCalTapas) {
		$status = "warning";
	} else {
		$status = "good";
	}

	$vTapas = (M_PI / 12) * (pow($diametro + 2 * $tComercialTapa * 0.0254, 3) - pow($diametro, 3));
	$vCuerpo = ((M_PI * $longitud) / 4) * (pow($diametro + 2 * $tComercialBody * 0.0254, 2) - pow($diametro, 2));

	$vTotal = $vTapas + $vCuerpo;
	$pesoVacio = (7800 * $vTotal);

	$espesorTapasCalculado = $tCalTapas;
	$espesorCuerpoCalculado = $tCalCuerpo;

	// Calcular volumen y peso del líquido

	$vTapasLiquido = (M_PI / 12) * pow($diametro, 3);
	$vCuerpoLiquido = ((M_PI * $longitud) / 4) * pow($diametro, 2);
	$vTLiquido = $vTapasLiquido + $vCuerpoLiquido;

	$pLiquido = $densidad * $vTLiquido;
	$pesoLleno = ($pesoVacio + $pLiquido);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	calcularRecipiente();

	$espesorTapasCalculado = round($espesorTapasCalculado, 4);
	$espesorCuerpoCalculado = round ($espesorCuerpoCalculado, 4);
	$pesoVacio = round ($pesoVacio);
	$pesoLleno = round ($pesoLleno);
}

?>