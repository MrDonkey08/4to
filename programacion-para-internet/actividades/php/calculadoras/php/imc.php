<?php

// Entrada
$peso = $_POST['peso'];
$altura = $_POST['altura'];

// Salida
$imc = $_POST['imc'];
$comp = $_POST['composicion-corporal'];

function getImc($peso, $altura)
{
	global $imc, $comp;

	$altura = $altura / 100;

	$imc = $peso / ($altura ** 2);
	$imc = round($imc, 5);

	$comp = getComp(); 

	return array("imc" => $imc, "comp" => $comp);
}

function getComp()
{
	global $imc, $comp;

	if ($imc >= 40) {
		$comp = "Obesidad tipo 3 (> 40)";
	} else if ($imc >= 35) {
		$comp = "Obesidad tipo 2 (35 - 40)";
	} else if ($imc >= 30) {
		$comp = "Obesidad tipo 1 (30 - 34)";
	} else if ($imc >= 25) {
		$comp = "Sobrepeso (25 - 29)";
	} else if ($imc >= 18.5) {
		$comp = "Normal (18.5 - 24)";
	} else if ($imc >= 17) {
		$comp = "Delgadez leve (17 - 18.4)";
	} else if ($imc >= 16) {
		$comp = "Delgadez media (16 - 16.9)";
	} else {
		$comp = "Delgadez severa (> 16)";
	}

	return $comp;
}

if ($_SERVER['REQUEST_METHOD'] === "POST") {
	$result = getImc($peso, $altura);

	$imc_result = $result['imc'];
	$comp_result = $result['comp'];
}

?>