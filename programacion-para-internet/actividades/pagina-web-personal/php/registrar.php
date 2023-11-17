<?php
include 'conexion.php';

$nombre = $_POST["nombre"];
$apellido = $_POST["apellido"];
$tel = $_POST["telefono"];
$correo = $_POST["e-mail"];
$mensaje = $_POST["mensaje"];

// Validar datos

if (empty($nombre) || empty($apellido) || empty($tel) || empty($correo) || empty($mensaje)) {
    echo '<script>
            alert("Por favor, completa todos los campos");
            window.history.go(-1);
        </script>';
    mysqli_close($conexion);
    exit;
}

// Insertar campos

$insertar = "INSERT INTO tblcontact(nombre, apellido, telefono, correo, mensaje) VALUES
('$nombre', '$apellido', '$tel', '$correo', '$mensaje')";

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