# Servicio Web

## Qué es un servicio web

Un **servicio web** es un tipo de software basado en texto diseñado para operar
en Internet. Este sistema facilita la transmisión de solicitudes y respuestas
entre diferentes servidores o aplicaciones, independientemente de las
diferencias en los lenguajes de programación utilizados o las plataformas de
ejecución.

En otras palabras, un servicio web posibilita la **comunicación entre máquinas y
el intercambio de datos entre aplicaciones a través de Internet.**

## Características

Algunas características destacadas de los servicios web incluyen:

- Utiliza un formato basado en texto.
- Favorece la interoperabilidad y el uso de múltiples plataformas.
- Ofrece servicios integrados.
- Tiene un alcance global.
- Es fácil de usar y acceder.
- Facilita el intercambio de mensajes SOAP (Protocolo de Acceso a Objetos
  Simples).
- La interfaz se describe mediante WSDL (Lenguaje de Descripción de Servicios
  Web).
- Se basa en el formato HTTP (Protocolo de Transferencia de Hipertexto).

## Funcionamiento

En la operativa de un **servicio web**, el proveedor envía un archivo WSDL que
describe el servicio al intermediario de servicios. Este intermediario utiliza
el archivo para comprender las funciones ejecutables en el servidor a través del
servicio web.

Luego, el solicitante se comunica con el intermediario para identificar al
proveedor y, así, enviar una solicitud SOAP en forma de mensaje HTTP al
servidor. Posteriormente, el servicio web interpreta la solicitud, el proveedor
valida la petición y el servicio envía los datos de respuesta en formato XML,
utilizando nuevamente SOAP y HTTP.

Finalmente, el XML enviado por el proveedor se valida una vez más con un archivo
XSD para su interpretación por parte del solicitante, dejando la información
lista para su procesamiento.

## Arquitectura

- **Descripción de Servicios**: Los servicios web se autodescriben,
  proporcionando información sobre las operaciones que admiten y cómo activarlas
  mediante el lenguaje de descripción de servicios web (**WSDL**).
- **Descubrimiento de Servicios**: Centraliza los servicios web en un registro
  común y proporciona funcionalidades para publicar y buscar servicios. **UDDI**
  es el encargado del Descubrimiento de Servicios.
- **Invocación de Servicios**: Implica el intercambio de mensajes entre el
  cliente y el servidor, donde **SOAP** especifica el formato de los mensajes.
- **Transporte**: Todos los mensajes se transmiten, generalmente a través de
  HTTP (Protocolo de Transferencia de Hipertexto), aunque se pueden emplear
  otros protocolos.

## Ventajas y Desventajas

### Ventajas

La principal ventaja de los servicios web radica en su independencia de
plataforma, permitiendo la comunicación entre clientes y servidores con pocos
requisitos en común. Para lograr esto, la tecnología de servicios web se apoya
en **formatos estandarizados** interpretados por todos los sistemas.

### Desventajas

Sin embargo, una desventaja se encuentra en el formato XML, que tiende a generar
**paquetes de datos grandes**, potencialmente causando problemas en conexiones
de red lentas. Otra opción para conectar sistemas a través de Internet son las
API web, que, aunque generalmente más rápidas, imponen especificaciones más
rigurosas, limitando la interoperabilidad entre cliente y servidor.

<div style="page-break-after: always;"></div>

## Referencias

- Carranza, A. (noviembre 12, 2021). _¿Qué es un web service? ¡Intercambia datos
  de un sistema a otro en segundos!_. Consultado el 25 de noviembre de 2023 de
  https://www.crehana.com/blog/transformacion-digital/que-es-web-service/

- Varela V. (abril 01, 2022). _Web Service: qué es y cómo funciona_. Consultado
  el 25 de noviembre de 2023 de
  https://www.prodigia.com.mx/blog/espacio-prodigio-1/web-service-que-es-y-como-funciona-81

- Digital Guide Ionos. (julio 20, 2021). _Web services: servicios de máquina a
  máquina_. Consultado el 25 de noviembre de 2023 de
  https://www.ionos.mx/digitalguide/paginas-web/desarrollo-web/web-services/

- Lázaro D. (s.f.). _Introducción a los Web Services_. Consultado el 25 de
  noviembre de 2023 de https://diego.com.es/introduccion-a-los-web-services
