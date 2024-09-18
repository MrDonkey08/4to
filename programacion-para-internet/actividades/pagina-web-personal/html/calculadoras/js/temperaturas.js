const btnTemp = document.getElementById("btn-temp")
const resTemp = document.getElementById("res-temp")
const unidadTemp = document.getElementById("unidad-temp")

/*
+ 'parseFloat(string)' 
* Extrae el número real que se encuentre al principio de un *string*
- Cuando encuentra un número, se detendrá en cuanto detecte una letra
- Cuando no encuentra un número devuelve 'NaN' (Not a Number)
- Acepta notación científica (p. ej.'1.23e-4' = 0.000123) 
- Descarta los ceros finales redundantes (p.ej: 12.4300000 -> 12.43)
*/

let temp
let unidad

function getTemp() {
  let symbol = " °"

  const inputTemp = parseFloat(document.getElementById("input-temp").value)
  const optTempIn = document.getElementById("opt-temp-in").value
  const optTempOut = document.getElementById("opt-temp-out").value

  if (optTempIn === optTempOut) {
    temp = inputTemp
  } else {
    switch (optTempIn) {
      case "C":
        if (optTempOut === "F") {
          temp = (inputTemp * 9) / 5 + 32
        } else if (optTempOut === "K") {
          temp = inputTemp + 273.15 // C->K
        } else {
          temp = (inputTemp * 9) / 5 + 491.67
        }
        break

      case "F":
        if (optTempOut === "C") {
          temp = ((inputTemp - 32) * 5) / 9
        } else if (optTempOut === "K") {
          temp = (inputTemp * 9) / 5 + 273.5 // F->K
        } else {
          temp = inputTemp + 459.67
        }
        break

      case "K":
        if (optTempOut === "C") {
          temp = inputTemp - 273.15
        } else if (optTempOut === "F") {
          temp = ((inputTemp - 273.15) * 9) / 5 + 32 // K->F
        } else {
          temp = (inputTemp * 9) / 5
        }
        break

      case "Ra":
        if (optTempOut === "C") {
          temp = (inputTemp - 491.67) * (5 / 9)
        } else if (optTempOut === "F") {
          temp = inputTemp - 459.67
        } else {
          temp = (inputTemp * 5) / 9
        }
        break
    }
  }

  temp = parseFloat(temp.toFixed(5))

  if (optTempOut == "K") {
    symbol = " "
  }
  resTemp.innerHTML = temp + symbol + optTempOut
}

btnTemp.addEventListener("click", getTemp)
