#include <iostream>
#include <pthread.h>
#include <random>
#include <atomic>
#include <vector>

using namespace std;

atomic<int> count_in_circle(0);
int total_tosses;
int tosses_thread;

void* monte_carlo(void* arg){
	random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dis(-1.0, 1.0);

        int tosses = tosses_thread;

        for(int i = 0; i < tosses; ++i){
                double x = dis(gen);
		double y = dis(gen);
 
 		if(x * x + y * y <= 1.0){
			count_in_circle++;
		}
       	}
	
	pthread_exit(nullptr);
}

int main(int argc, char* argv[]){
	if(argc != 3){
		cerr << "Uso: " << argv[0] << " <hilos> <lanzamientos>" << endl;
        	return 1;
	}
	
	int num_threads = stoi(argv[1]);
        total_tosses = stoi(argv[2]);
	tosses_thread = total_tosses / num_threads;
        vector<pthread_t> threads(num_threads);

	for(int i = 0; i < num_threads; ++i){
		pthread_create(&threads[i], nullptr, monte_carlo, nullptr);
	}

        for (int i = 0; i < num_threads; ++i){
		pthread_join(threads[i], nullptr);
	}

        double pi = 4.0 * count_in_circle / total_tosses;
        cout << "Estimación de π: " << pi << endl;

        return 0;
}
