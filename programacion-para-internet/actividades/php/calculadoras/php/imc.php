<?php

// Entrada
$peso = $_POST['peso'];
$altura = $_POST['altura'];

// Salida
$imc = $_POST['imc'];
$comp = $_POST['composicion-corporal'];
$estado;

function getImc($peso, $altura) {
    global $imc, $comp;

    $altura = $altura / 100;

    $imc = $peso / ($altura ** 2);
    $imc = round($imc, 5);

    getComp();
	
    return array("imc" => $imc, "comp" => $comp);
}

function getComp() {
    global $imc, $comp, $estado;

    if ($imc >= 40) {
        $estado = "malo";
        $comp = "Obesidad tipo 3 (> 40)";
    } else if ($imc >= 35) {
        $estado = "malo";
        $comp = "Obesidad tipo 2 (35 - 40)";
    } else if ($imc >= 30) {
        $estado = "medio-malo";
        $comp = "Obesidad tipo 1 (30 - 34)";
    } else if ($imc >= 25) {
        $estado = "medio-bueno";
        $comp = "Sobrepeso (25 - 29)";
    } else if ($imc >= 18.5) {
        $estado = "bueno";
        $comp = "Normal (18.5 - 24)";
    } else if ($imc >= 17) {
        $estado = "medio-bueno";
        $comp = "Delgadez leve (17 - 18.4)";
    } else if ($imc >= 16) {
        $estado = "medio-malo";
        $comp = "Delgadez media (16 - 16.9)";
    } else {
        $estado = "malo";
        $comp = "Delgadez severa (> 16)";
    }
}

if ($_SERVER['REQUEST_METHOD'] === "POST") {
    $result = getImc($peso, $altura);

    $imc_result = $result['imc'];
    $comp_result = $result['comp'];
}

?>