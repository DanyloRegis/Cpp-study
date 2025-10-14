#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr_size;
    cout << "Enter the size of the array: ";
    cin >> arr_size;

    int *arr = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        arr[i] = i * 2;
    }

    for (int i = 0; i < arr_size; i++) {
        cout << "[" << i << "] " << arr[i] << " ";
    }

    delete[] arr; // free allocated memory
    return 0;
}
