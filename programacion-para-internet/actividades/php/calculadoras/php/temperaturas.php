<?php

$inputTemp = $_POST['temp'];
$optTempIn = $_POST['temp-in'];
$optTempOut = $_POST['temp-out'];
$resTemp = $_POST["res-temp"];

$temp;
$symbol;

function getTemp() {
    global $temp, $inputTemp, $optTempIn, $optTempOut, $resTemp, $symbol;

    $symbol = " °";

	if ($optTempIn === $optTempOut) {
		$temp = $inputTemp;
	} else {
		switch ($optTempIn) {
			case "C":
				if ($optTempOut === "F") {
					$temp = ($inputTemp * 9) / 5 + 32;
				} else if ($optTempOut === "K") {
					$temp = $inputTemp + 273.15; // C->K
				} else {
					$temp = ($inputTemp * 9) / 5 + 491.67;
				}
				break;

			case "F":
				if ($optTempOut === "C") {
					$temp = (($inputTemp - 32) * 5) / 9;
				} else if ($optTempOut === "K") {
					$temp = ($inputTemp * 9) / 5 + 273.5; // F->K
				} else {
					$temp = $inputTemp + 459.67;
				}
				break;

			case "K":
				if ($optTempOut === "C") {
					$temp = $inputTemp - 273.15;
				} else if ($optTempOut === "F") {
					$temp = (($inputTemp - 273.15) * 9) / 5 + 32; // K->F
				} else {
					$temp = ($inputTemp * 9) / 5;
				}
				break;

			case "Ra":
				if ($optTempOut === "C") {
					$temp = ($inputTemp - 491.67) * (5 / 9);
				} else if ($optTempOut === "F") {
					$temp = $inputTemp - 459.67;
				} else {
					$temp = ($inputTemp * 5) / 9;
				}
				break;
		}
	}

    $temp = round($temp, 5);

    if ($optTempOut == "K") {
        $symbol = " ";
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    getTemp();

	$resTemp = $temp . $symbol . $optTempOut;
}

?>
