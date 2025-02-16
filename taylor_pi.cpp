#include <iostream>
#include <ctime>

using namespace std;

//Programa que calcula al valor aproximado de pi con el metodo de taylor.
double calculatePi(int upperBound) {
	double pi = 0.0;
	    
	for (int n = 0; n < upperBound; ++n) {
		int sign = (n % 2 == 0) ? 1 : -1; 
			pi += sign * (1.0 / (2 * n + 1));
	}
        
	return pi * 4;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Error: número incorrecto de parámetros. Se esperaba 1 parámetro." << endl;
		return 1;
	}

	int upperBound = atoi(argv[1]);
	if (upperBound <= 0) {
		cout << "Error: el número de iteraciones debe ser un entero positivo." << endl;
		return 1;
	}

	// Medir tiempo inicial de CPU y wall-clock time
	clock_t startCPU = clock();
	time_t startWall = time(nullptr);

	double piApprox = calculatePi(upperBound);

	// Medir tiempo final de CPU y wall-clock time
	clock_t endCPU = clock();
	time_t endWall = time(nullptr);

	// Calcular tiempos
	double cpuTime = static_cast<double>(endCPU - startCPU) / CLOCKS_PER_SEC;
	double wallTime = difftime(endWall, startWall);

	cout << "Aproximación de π con " << upperBound << " iteraciones: " << piApprox << endl;
	cout << "Tiempo de CPU: " << cpuTime << " segundos" << endl;
	cout << "Tiempo real (wall-clock time): " << wallTime << " segundos" << endl;

	return 0;
}
