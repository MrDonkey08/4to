<!DOCTYPE html>
<html lang="es">
	<head>
		<meta charset="UTF-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />

		<link rel="stylesheet" href="./css/normalize.css" />
		<link rel="stylesheet" href="./css/standard.css" />
		<link rel="stylesheet" href="./css/styles.css" />

		<title>Calculadoras</title>
	</head>

	<body>
		<a class="mi-titulo" href="./../../index.html">
			<h1>Alan Yahir Juárez Rubio <span>Ingeniero en Computación</span></h1>
		</a>

		<section id="recipientes-a-presion" class="bloque">
			<h2>Recipientes a Presión</h2>

			<h3>Datos de Entrada</h3>
			<fieldset>
				<legend>Variables de Entrada</legend>
				<div class="campos">
					<div class="campo">
						<label for="presion">Presión interna:</label>
						<input placeholder="MPa" type="number" id="presion-interna" />
					</div>
					<div class="campo">
						<label for="diametro">Diámetro:</label>
						<input placeholder="metros" type="number" id="diametro" />
					</div>
					<div class="campo">
						<label for="material">Material:</label>
						<select id="material">
							<option value="1">SA-283 gr D</option>
							<option value="2">SA-662 gr B</option>
							<option value="3">SA-537</option>
							<option value="4">SA-515 gr 60</option>
							<option value="5">SA-516 gr 70</option>
						</select>
					</div>
					<div class="campo">
						<label for="longitud">Longitud:</label>
						<input placeholder="metros" type="number" id="longitud" />
					</div>
					<div class="campo">
						<label for="eficiencia">Eficiencia de la junta:</label>
						<select id="eficiencia">
							<option value="1">Radiografiado completo (100%)</option>
							<option value="2">Radiografiado parcial (85%)</option>
							<option value="3">Sin Radiografiado (75%)</option>
						</select>
					</div>
					<div class="campo">
						<label for="densidad">ρ del líquido:</label>
						<input placeholder="kg/m³" type="number" id="densidad" />
					</div>
					<div class="campo">
						<label for="nivel">Nivel:</label>
						<input placeholder="metros" type="number" id="nivel" />
					</div>
				</div>
				<button>Calcular</button>
			</fieldset>

			<h3>Datos de Salida</h3>
			<fieldset>
				<legend>Variables de salida</legend>
				<div class="campos">
					<div class="campo">
						<label for="espesor">Espesor de las tapas calculado:</label>
						<input disabled type="number" id="espesor" />
					</div>
					<div class="campo">
						<label for="espesor-tapas">Espesor comercial de las tapas:</label>
						<select id="espesor-tapas">
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
						<label for="presion">Espesor del cuerpo calculado:</label>
						<input disabled type="number" id="presion" />
					</div>
					<div class="campo">
						<label for="espesor-cuerpo">Espesor comercial del cuerpo:</label>
						<select id="espesor-cuerpo">
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
						<label for="nivel-1">Peso del equipo vacio:</label>
						<input disabled type="number" id="nivel-1" />
					</div>
					<div class="campo">
						<label for="nivel-2">Peso del equipo lleno:</label>
						<input disabled type="number" id="nivel-2" />
					</div>
				</div>
			</fieldset>
		</section>

		<section id="calculo-imc" class="bloque">
			<h2>Calculadora de IMC (Índice de Masa Corporal)</h2>

			<h3>Datos de Entrada</h3>

			<?php if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['imc-submit'])) {
				require './php/imc.php';
			} ?>

			<form method="post" action="">
				<fieldset>
					<legend>Variables de Entrada</legend>
					<div class="campos">
						<div class="campo" id="peso">
							<label for="input-peso">Peso:</label>
							<input type="number" id="input-peso" name="peso" placeholder="kg" value="<?php echo $peso ?>"
								step="0.1" required />
						</div>
						<div class="campo" id="altura">
							<label for="input-altura">Altura:</label>
							<input type="number" id="input-altura" name="altura" placeholder="cm"
								value="<?php echo $altura; ?>" required />
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
							<input type="number" id="input-imc" name="imc" placeholder="IMC" value="<?php echo $imc; ?>"
								readonly />
						</div>
						<div class="campo" id="composicion-corporal">
							<label for="input-composicion-corporal">Composicion corporal:</label>
							<input type="text" id="input-composicion-corporal" name="composicion-corporal"
								placeholder="Composicion Corporal" value="<?php echo $comp; ?>" readonly />
						</div>
					</div>
				</fieldset>
			</form>
		</section>

		<section id="conversor-temp" class="bloque">
			<h2>Conversor de Temperaturas</h2>

			<?php if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['temp-submit'])) {
				require './php/temperaturas.php';
			} ?>

			<form method="post" action="">
				<fieldset>
					<legend>Variables de Entrada</legend>
					<div class="campos-2">
						<div class="campo" id="temp">
							<label for="input-temp">Temperatura:</label>
							<input type="number" id="input-temp" name="temp" placeholder="Temperatura"
								value="<?php echo ($inputTemp) ?>" />
						</div>
						<div class="campo" id="temp-in">
							<label for="opt-temp-in">Entrada</label>
							<select id="opt-temp-in" name="temp-in">
								<option value="C">°C</option>
								<option value="F">°F</option>
								<option value="K">K</option>
							</select>
						</div>
						<div class="campo" id="temp-out">
							<label for="opt-temp-out">Salida</label>
							<select id="opt-temp-out" name="temp-out">
								<option value="C">°C</option>
								<option value="F">°F</option>
								<option value="K">K</option>
							</select>
						</div>
					</div>
					<div class="res-contenedor">
						<span class="res" id="res-temp" name="res-temp">
							<?php echo ($resTemp); ?>
						</span>
					</div>
					<button id="btn-temp" type="submit" name="temp-submit">Calcular</button>
				</fieldset>
			</form>
		</section>
	</body>
</html>