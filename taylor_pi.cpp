#include <iostream>

using namespace std;


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
    
    double piApprox = calculatePi(upperBound);
    cout << "Aproximación de π con " << upperBound << " iteraciones: " << piApprox << endl;
    
    return 0;
}

