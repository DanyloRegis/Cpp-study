#include <iostream>
#include <pthread.h>
using namespace std;

const int SIZE = 1000000;
long counter = 0;

// Variáveis para Peterson's Solution
bool flag[2] = {false, false};
int turn = 0;

void* increment_counter(void* arg) {
    int thread_id = *(int*)arg;
    int other = 1 - thread_id;
    
    for (int i = 0; i < SIZE/2; i++) {
        flag[thread_id] = true;
        turn = other;
        
        while (flag[other] && turn == other) {
            // Busy wait
        }
        
        // Seção crítica
        counter++;
        
        flag[thread_id] = false;
    }
    return NULL;
}

int main() {
    pthread_t threads[2];
    int ids[2] = {0, 1};
    
    pthread_create(&threads[0], NULL, increment_counter, &ids[0]);
    pthread_create(&threads[1], NULL, increment_counter, &ids[1]);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    cout << "Counter: " << counter << " (esperado: " << SIZE << ")" << endl;
    
    return 0;
}