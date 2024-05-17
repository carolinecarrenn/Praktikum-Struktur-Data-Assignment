/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>    

using namespace std;   

// Deklarasi dan inisialisasi array dengan 10 elemen
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
int cari = 8;          // Data yang ingin dicari
int i;                 // Indeks untuk iterasi
// Menghitung panjang array
int panjangArray = sizeof(arr) / sizeof(arr[0]); 
bool ketemu = false;   // Flag untuk menandai apakah data ditemukan atau tidak

int main() {
    // Loop untuk mencari data di dalam array
    for (i = 0; i < panjangArray; i++) {
        if (arr[i] == cari) {
            ketemu = true; // Data ditemukan
            break;         // Keluar dari loop
        }
    }

    // Menampilkan hasil pencarian
    if (ketemu) {
        cout << "Panjang array: " << panjangArray << endl;
        cout << cari << " terdapat pada indeks ke-" << i << endl;
    } else {
        cout << "Element tidak ditemukan" << endl;
    }

    return 0; // Mengembalikan nilai 0 yang menandakan program telah berhasil dijalankan
}
