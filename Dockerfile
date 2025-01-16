# Usa la imagen base oficial con GCC y G++
FROM gcc:latest

# Crea un directorio de trabajo dentro del contenedor
WORKDIR /app

# Copia tu código fuente al contenedor
COPY main.cpp /app

# Copia todos los archivos .h al contenedor

COPY *.h .

# Compila el programa
RUN g++ main.cpp -o proyecto

# Especifica el comando por defecto para ejecutar el programa
CMD ["./proyecto"]