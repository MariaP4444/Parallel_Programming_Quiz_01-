#include <iostream>
#include <cstdlib>
#include <ctime>
#include <pthread.h>

using namespace std;

// Variables globales para contar los puntos dentro del círculo y controlar la cantidad de puntos por hilo
int totalInsideCircle = 0;
int pointsPerThread;
pthread_mutex_t mutex;

// Función para generar un número aleatorio en el rango [-1,1]
double randomDouble() {
    return (double)rand() / RAND_MAX * 2.0 - 1.0;
}

// Función que ejecutará cada hilo para contar puntos dentro del círculo
void* countPoints(void* arg) {
    int localCount = 0;
    for (int i = 0; i < pointsPerThread; i++) {
        double x = randomDouble();
        double y = randomDouble();
        if (x * x + y * y <= 1) {
            localCount++;
        }
    }
    pthread_mutex_lock(&mutex);
    totalInsideCircle += localCount;
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

// Función para calcular pi usando el método de Monte Carlo con hilos
double calculatePi(int N, int numThreads) {
    pthread_t threads[numThreads];
    pointsPerThread = N / numThreads;
    totalInsideCircle = 0;
    pthread_mutex_init(&mutex, nullptr);
    
    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], nullptr, countPoints, nullptr);
    }
    
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], nullptr);
    }
    
    pthread_mutex_destroy(&mutex);
    return 4.0 * totalInsideCircle / N;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Error: número incorrecto de parámetros. Se esperaba 2 parámetros: <num_puntos> <num_hilos>." << endl;
        return 1;
    }
    
    int N = atoi(argv[1]);
    int numThreads = atoi(argv[2]);
    if (N <= 0 || numThreads <= 0) {
        cout << "Error: El número de puntos y de hilos deben ser enteros positivos." << endl;
        return 1;
    }
    
    srand(time(0)); // Inicializar semilla aleatoria
    double piApprox = calculatePi(N, numThreads);
    
    cout << "Aproximación de Pi: " << piApprox << endl;
    
    return 0;
}

