<?php
$conexion = mysqli_connect("localhost", "root", "", "appdatabase");

if (!$conexion) {
	echo 'No se pudo conectar a la Base de Datos';
} else{
	echo 'Conexión exitosa';
}