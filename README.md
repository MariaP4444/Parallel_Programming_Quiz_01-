# Cálculo de π: Métodos Secuenciales y Paralelos  

Este proyecto implementa el cálculo del número π utilizando diferentes métodos y comparando su rendimiento en ejecución secuencial y paralela.  

## Archivos  

- `taylorpi.cpp`: Implementación secuencial usando la serie de Taylor.  
- `montepi.cpp`: Implementación secuencial del método de Monte Carlo.  
- `carlospi.cpp`: Implementación paralela del método de Monte Carlo con `pthreads`.  

## Instrucciones de Ejecución  

### Compilación  

Para compilar los programas, usa `g++` con la opción `-pthread` para la versión paralela:  

```bash
g++ -o taylorpi taylorpi.cpp -O2
g++ -o montepi montepi.cpp -O2
g++ -o carlospi carlospi.cpp -O2 -pthread

## Ejecución  

```bash
./taylorpi <num_iteraciones>
./montepi <num_lanzamientos>
./carlospi <num_lanzamientos> <num_hilos>

## Ejemplo de ejecución
./taylorpi 1000000
./montepi 1000000
./carlospi 1000000 32

## Análisis de Rendimiento  

Se comparó el rendimiento del método de Monte Carlo en versiones secuencial (`montepi.cpp`) y paralela (`carlospi.cpp`).  

Las tablas muestran los tiempos de CPU y errores relativos para diferentes configuraciones de lanzamientos y cantidad de hilos.  

### Comparación de `carlospi.cpp` con Diferentes Cantidades de Hilos  

| TOSSES   | THREADS = 16 | THREADS = 32 | THREADS = 51 | THREADS = 74 |
|----------|-------------|-------------|-------------|-------------|
| **500000** | CPU: 1.34999  | CPU: 1.25337  | CPU: 1.19913  | CPU: 1.2382  |
|          | REAL: 0       | REAL: 1       | REAL: 0       | REAL: 0       |
|          | ERROR: 0.005047 | ERROR: 0.00123 | ERROR: 0.00140 | ERROR: 0.004416 |
| **1000000** | CPU: 2.67988  | CPU: 2.69562  | CPU: 2.7086  | CPU: 2.5714  |
|          | REAL: 1       | REAL: 0       | REAL: 1       | REAL: 1       |
|          | ERROR: 0.002915 | ERROR: 0.00133 | ERROR: 0.00137 | ERROR: 0.002652 |

### Resultados de `montepi.cpp` (secuencial)  

| TOSSES   | CPU Time | Real Time | Error |
|----------|---------|----------|-------|
| **5000**    | 0.003929  | 0  | 0.0184073 |
| **10000**   | 0.003986  | 0  | 0.00199265 |
| **500000**  | 0.158018  | 0  | 0.00163265 |
| **1000000** | 0.318885  | 0  | 0.000423346 |

## Observaciones  

- A medida que aumentan los lanzamientos (`tosses`), la precisión del cálculo mejora en ambos métodos.  
- La versión paralela (`carlospi.cpp`) reduce el tiempo de CPU significativamente en comparación con la versión secuencial.  
- Hay un punto óptimo en la cantidad de hilos: más hilos no siempre garantizan mayor eficiencia debido a la sobrecarga de sincronización.  

## Video de Explicación  

Puedes ver el video explicativo del proyecto en el siguiente enlace:  
[Video Explicativo](https://javerianacaliedu-my.sharepoint.com/:v:/g/personal/jnblandonm_javerianacali_edu_co/EeQiaRmcAFBKujZmYuCU6N0BbzdmzKRgI-d0mElLI81brg?nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUZvckJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0NvcHkifX0&e=H8XhIM)
