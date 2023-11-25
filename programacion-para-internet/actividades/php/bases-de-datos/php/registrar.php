<?php
include 'conexion.php';

$nombre = $_POST["nombre"];
$apellido = $_POST["apellido"];
$correo = $_POST["correo"];

// Insertar campos

$insertar = "INSERT INTO tblinfo(nombre, apellido, correo) VALUES
('$nombre', '$apellido', '$correo')";

$verificar_correo = mysqli_query($conexion, "SELECT * FROM tblinfo 
WHERE correo = '$correo'");

if (mysqli_num_rows($verificar_correo) > 0) {
	echo '<script>
			alert("El correo ya existe");
			window.history.go(-1);
		</script>';
	exit;
}

// Ejecutar consulta

$resultado = mysqli_query($conexion, $insertar);

if (!$resultado) {
	echo '<script>
			alert("Error de registro");
			window.history.go(-1);
		</script>';
	exit;
} else {
	echo '<script>
			alert("Registro efectuado");
			window.history.go(-1);
		</script>';
	exit;
}

// Cerrar consultas

//mysqli_close($conexion);
?>