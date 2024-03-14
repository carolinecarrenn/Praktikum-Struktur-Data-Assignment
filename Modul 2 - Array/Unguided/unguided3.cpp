#include <iostream>
using namespace std;

// Deklarasi fungsi 'input_array'
int input_array(int arr[]) {
    int size;
    cout << "Masukkan ukuran array: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Masukkan elemen " << i+1 << ": ";
        cin >> arr[i];
    }
    return size;
}

// Deklarasi fungsi 'find_max'
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Deklarasi fungsi 'find_min'
int find_min(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Deklarasi fungsi 'find_avg'
double find_avg(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Deklarasi fungsi main
int main() {
    int arr[100];
    int size = input_array(arr);
    cout << "\nArray yang dimasukkan: ";
    for (int i = 0; i < size; i++) {
        cout<< arr[i] << " ";
    }
    cout << "\n\nNilai maksimum adalah: " << find_max(arr, size);
    cout << "\nNilai minimum adalah: " << find_min(arr, size);
    cout << "\nNilai rata-rata adalah: " << find_avg(arr, size);
    return 0;
}