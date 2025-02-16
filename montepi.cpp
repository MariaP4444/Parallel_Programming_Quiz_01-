#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Función para generar un número aleatorio en el rango [-1,1]
double randomDouble() {
	return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

// Función para calcular pi usando el método de Monte Carlo
double calculatePi(int N) {
	int countInsideCircle = 0;
	for (int i = 0; i < N; i++) {
		double x = randomDouble();
		double y = randomDouble();

                // Si el punto cae dentro del círculo
                if (x * x + y * y <= 1) {
			countInsideCircle++;
		}
	}
	return 4.0 * countInsideCircle / N;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Error: número incorrecto de parámetros. Se esperaba 1 parámetro." << endl;
		return 1;
	}

	int N = atoi(argv[1]);
	if (N <= 0) {
		cout << "Error: El número de puntos debe ser un entero positivo." << endl;
		return 1;
	}

	srand(time(0)); // Inicializar semilla aleatoria
	
	// Medir tiempo inicial de CPU y wall-clock time
	clock_t startCPU = clock();
	time_t startWall = time(nullptr);
        
	double piApprox = calculatePi(N);
	
	// Medir tiempo final de CPU y wall-clock time
	clock_t endCPU = clock();
	time_t endWall = time(nullptr);
	
	// Calcular tiempos
	double cpuTime = static_cast<double>(endCPU - startCPU) / CLOCKS_PER_SEC;
	double wallTime = difftime(endWall, startWall);

	// Calcular el error
	double error = fabs(M_PI - piApprox);

	cout << "Aproximación de Pi: " << piApprox << endl;
	cout << "Tiempo de CPU: " << cpuTime << " segundos" << endl;
	cout << "Tiempo real (wall-clock time): " << wallTime << " segundos" << endl;
	cout << "Error: " << error << endl;
	
	return 0;
}
