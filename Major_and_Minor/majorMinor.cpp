#include <iostream>
using namespace std;

// Protótipos das funções
int Major(int a[], int size);
int Minor(int a[], int size);

int main() {
    int array[10] = {0, 1, 4, 3, 4, 5, 56, 6, 7, 17};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Major elemet " << Major(array, size) << endl;
    cout << "Minot elemet " << Minor(array, size) << endl;

    return 0;
}

int Major(int a[], int size) {
    int major = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] > major) {
            major = a[i];
        }
    }
    return major;
}

int Minor(int a[], int size) {
    int minor = a[0];
    for(int i = 1; i < size; i++) {
        if(a[i] < minor) {
            minor = a[i];
        }
    }
    return minor;
}