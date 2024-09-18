# Práctica Base de Datos

```sql
CREATE DATABASE appdatabase;
```

```sql
USE appdatabase;
```

```sql
CREATE TABLE tblinfo(id INT(11) AUTO_INCREMENT, nombre VARCHAR(50) NOT NULL, apellido VARCHAR(50) NOT NULL, correo VARCHAR(50) NOT NULL, PRIMARY KEY(id));
```

```sql
DESCRIBE tblinfo;
```

```sql
SELECT * FROM tblinfo;
```
