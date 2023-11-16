<?php
include 'conexion.php';

$nombre = $_POST["nombre"];
$apellido = $_POST["apellido"];
$correo = $_POST["e-mail"];
$mensaje = $_POST["mensaje"];

// Validar datos

if (empty($nombre) || empty($apellido) || empty($correo) || empty($mensaje)) {
    echo '<script>
            alert("Por favor, completa todos los campos");
            window.history.go(-1);
        </script>';
    mysqli_close($conexion);
    exit;
}

// Insertar campos

$insertar = "INSERT INTO tblcontact(nombre, apellido, correo, mensaje) VALUES
('$nombre', '$apellido', '$correo', '$mensaje')";

$verificar_correo = mysqli_query($conexion, "SELECT * FROM tblcontact 
WHERE correo = '$correo'");

// Verificar existencia de correo

if (mysqli_num_rows($verificar_correo) > 0) {
	echo '<script>
			alert("El correo ya existe");
			window.history.go(-1);
		</script>';
	mysqli_close($conexion);
	exit;
}

// Ejecutar consulta

$resultado = mysqli_query($conexion, $insertar);

if (!$resultado) {
	echo '<script>
			alert("Error de registro");
			window.history.go(-1);
		</script>';
} else {
	echo '<script>
			alert("Registro efectuado");
			window.history.go(-1);
		</script>';
}

mysqli_close($conexion);
exit;

?>