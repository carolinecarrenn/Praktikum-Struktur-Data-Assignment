#include <iostream>
#include <string>
using namespace std;

int main() {
    // Deklarasi Array
    int array[10];
    cout << "Data Array: ";
    // Input data ke array
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    // Mencari nomor genap
    string genap = "";
    cout << "\nNomor Genap: ";
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 == 0) {
            genap += to_string(array[i]) + ", ";
        }
    }
    cout << genap.substr(0, genap.length() - 2) << endl;

    // Mencari nomor ganjil
    string ganjil = "";
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 != 0) {
            ganjil += to_string(array[i]) + ", ";
        }
    }
    cout << ganjil.substr(0, ganjil.length() - 2) << endl;

    return 0;
}