<!DOCTYPE html>
<html lang="es">
	<head>
		<meta charset="UTF-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />

		<link rel="stylesheet" href="./css/normalize.css" />
		<link rel="stylesheet" href="./css/standard.css" />

		<?php
			if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['recipiente-submit'])) {
				require './php/recipientes.php';
			} elseif ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['imc-submit'])) {
				require './php/imc.php';
			} elseif ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['temp-submit'])) {
				require './php/temperaturas.php';
			}
		?>

		<title>Calculadoras</title>
	</head>

	<body>
		<h1>Alan Yahir Juárez Rubio <span>Ingeniero en Computación</span></h1>

		<section id="recipientes-a-presion" class="bloque">
			<h2>Recipientes a Presión</h2>

			<h3>Datos de Entrada</h3>

			<form method="post">
				<fieldset>
					<legend>Variables de Entrada</legend>
					<div class="campos">
						<div class="campo">
							<label for="presion">Presión interna:</label>
							<input required placeholder="MPa" type="number" id="presion" name="presion" value="<?php echo $presion; ?>" step="0.000001" />
						</div>
						<div class="campo">
							<label for="diametro">Diámetro:</label>
							<input required placeholder="metros" type="number" id="diametro" name="diametro" value="<?php echo $diametro; ?>" step="0.000001" />
						</div>
						<div class="campo">
							<label for="material">Material:</label>
							<select id="material" name="material">
								<option value="1">SA-283 gr D</option>
								<option value="2">SA-662 gr B</option>
								<option value="3">SA-537</option>
								<option value="4">SA-515 gr 60</option>
								<option value="5">SA-516 gr 70</option>
							</select>
						</div>
						<div class="campo">
							<label for="longitud">Longitud:</label>
							<input required placeholder="metros" type="number" id="longitud" name="longitud" value="<?php echo $longitud; ?>" step="0.000001" />
						</div>
						<div class="campo">
							<label for="eficiencia">Eficiencia de la junta:</label>
							<select id="eficiencia" name=" eficiencia">
								<option value="1">Radiografiado completo (100%)</option>
								<option value="2">Radiografiado parcial (85%)</option>
								<option value="3">Sin Radiografiado (75%)</option>
							</select>
						</div>
						<div class="campo">
							<label for="densidad">ρ del líquido:</label>
							<input required placeholder="kg/m³" type="number" id="densidad" name="densidad" value="<?php echo $densidad; ?>" step="0.000001" />
						</div>
						<div class="campo">
							<label for="nivel">Nivel:</label>
							<input required placeholder="metros" type="number" id="nivel" name="nivel" value="<?php echo $nivel; ?>" step="0.000001" />
						</div>
					</div>
					<button id="btn-temp" type="submit" name="recipiente-submit">Calcular</button>
				</fieldset>

				<h3>Datos de Salida</h3>
				<fieldset>
					<legend>Variables de salida</legend>
					<div class="campos">
						<div class="campo">
							<label for="espesor-tapas-calculado">Espesor de las tapas calculado:</label>
							<input readonly type="number" class="<?php echo $status ?>" id="espesor-tapas-calculado" name="espesor-tapas-calculado" value="<?php echo $espesorTapasCalculado; ?>" />
						</div>
						<div class="campo">
							<label for="espesor-tapas-comercial">Espesor comercial de las tapas:</label>
							<select id="espesor-tapas-comercial" name="espesor-tapas-comercial" value="<?php echo $espesorTapasComercial; ?>">
								<option value="1">1/8 de pulgada</option>
								<option value="2">1/4 de pulgada</option>
								<option value="3">1/3 de pulgada</option>
								<option value="4">3/8 de pulgada</option>
								<option value="5">1/2 de pulgada</option>
								<option value="6">5/8 de pulgada</option>
								<option value="7">3/4 de pulgada</option>
								<option value="8">7/8 de pulgada</option>
								<option value="9">1 de pulgada</option>
								<option value="10">1 1/4 de pulgada</option>
								<option value="11">1 3/8 de pulgada</option>
								<option value="12">1 1/2 de pulgada</option>
								<option value="13">1 5/8 de pulgada</option>
								<option value="14">1 3/4 de pulgada</option>
								<option value="15">2 de pulgada</option>
							</select>
						</div>
						<div class="campo">
							<label for="espesor-cuerpo-calculado">Espesor del cuerpo calculado:</label>
							<input readonly type="number" class="<?php echo $status ?>" id="espesor-cuerpo-calculado" name="espesor-cuerpo-calculado" value="<?php echo $espesorCuerpoCalculado; ?>" />
						</div>
						<div class="campo">
							<label for="espesor-cuerpo-comercial">Espesor comercial del cuerpo:</label>
							<select id="espesor-cuerpo-comercial" name="espesor-cuerpo-comercial">
								<option value="1">1/8 de pulgada</option>
								<option value="2">1/4 de pulgada</option>
								<option value="3">1/3 de pulgada</option>
								<option value="4">3/8 de pulgada</option>
								<option value="5">1/2 de pulgada</option>
								<option value="6">5/8 de pulgada</option>
								<option value="7">3/4 de pulgada</option>
								<option value="8">7/8 de pulgada</option>
								<option value="9">1 de pulgada</option>
								<option value="10">1 1/4 de pulgada</option>
								<option value="11">1 3/8 de pulgada</option>
								<option value="12">1 1/2 de pulgada</option>
								<option value="13">1 5/8 de pulgada</option>
								<option value="14">1 3/4 de pulgada</option>
								<option value="15">2 de pulgada</option>
							</select>
						</div>
						<div class="campo">
							<label for="peso-vacio">Peso del equipo vacio:</label>
							<input readonly type="number" id="peso-vacio" name="peso-vacio" value="<?php echo $pesoVacio; ?>" />
						</div>
						<div class="campo">
							<label for="peso-lleno">Peso del equipo lleno:</label>
							<input readonly type="number" id="peso-lleno" name="peso-lleno" value="<?php echo $pesoLleno; ?>" />
						</div>
					</div>
				</fieldset>
			</form>
		</section>

		<section id="calculo-imc" class="bloque">
			<h2>Calculadora de IMC (Índice de Masa Corporal)</h2>

			<h3>Datos de Entrada</h3>

			<form method="post">
				<fieldset>
					<legend>Variables de Entrada</legend>
					<div class="campos">
						<div class="campo" id="peso">
							<label for="input-peso">Peso:</label>
							<input required type="number" id="input-peso" name="peso" placeholder="kg" value="<?php echo $peso; ?>" step="0.0001" />
						</div>
						<div class="campo" id="altura">
							<label for="input-altura">Altura:</label>
							<input required type="number" id="input-altura" name="altura" placeholder="cm" value="<?php echo $altura; ?>" step="0.1" />
						</div>
					</div>
					<button id="btn-imc" type="submit" name="imc-submit">Calcular</button>
				</fieldset>

				<h3>Datos de Salida</h3>
				<fieldset>
					<legend>Variables de Salida</legend>
					<div class="campos">
						<div class="campo" id="imc">
							<label for="input-imc">IMC:</label>
							<input readonly type="number" id="input-imc" class="<?php echo $estado ?>" name="imc" placeholder="IMC" value="<?php echo $imc; ?>" />
						</div>
						<div class="campo" id="composicion-corporal">
							<label for="input-composicion-corporal">Composicion corporal:</label>
							<input readonly type="text" id="input-composicion-corporal" class="<?php echo $estado ?>" name="composicion-corporal" placeholder="Composicion Corporal" value="<?php echo $comp; ?>" />
						</div>
					</div>
				</fieldset>
			</form>
		</section>

		<section id="conversor-temp" class="bloque">
			<h2>Conversor de Temperaturas</h2>

			<form method="post">
				<fieldset>
					<legend>Variables de Entrada</legend>
					<div class="campos-2">
						<div class="campo" id="temp">
							<label for="input-temp">Temperatura:</label>
							<input required type="number" id="input-temp" name="temp" placeholder="Temperatura" value="<?php echo $inputTemp; ?>" step="0.00001" />
						</div>
						<div class="campo" id="temp-in">
							<label for="opt-temp-in">Entrada</label>
							<select id="opt-temp-in" name="temp-in">
								<option value="C">°C</option>
								<option value="F">°F</option>
								<option value="K">K</option>
								<option value="Ra">°Ra</option>
							</select>
						</div>
						<div class="campo" id="temp-out">
							<label for="opt-temp-out">Salida</label>
							<select id="opt-temp-out" name="temp-out">
								<option value="C">°C</option>
								<option value="F">°F</option>
								<option value="K">K</option>
								<option value="Ra">°Ra</option>
							</select>
						</div>
					</div>
					<div class="res-contenedor">
						<span class="res" id="res-temp" name="res-temp">
							<?php echo $resTemp; ?>
						</span>
					</div>
					<button id="btn-temp" type="submit" name="temp-submit">Calcular</button>
				</fieldset>
			</form>
		</section>
	</body>
</html>