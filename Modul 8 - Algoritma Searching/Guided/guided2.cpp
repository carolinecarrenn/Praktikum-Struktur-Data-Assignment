/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>    
#include <conio.h>     
#include <iomanip>     

using namespace std;   

// Deklarasi dan inisialisasi array dataArray dengan 7 elemen
int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; 
int cari; // Deklarasi variabel cari untuk menyimpan data yang akan dicari

// Fungsi untuk melakukan sorting dengan algoritma selection sort
void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        // Menukar nilai dataArray[i] dengan dataArray[min]
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

// Fungsi untuk melakukan pencarian data dengan algoritma binary search
void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false; // Flag untuk menandai apakah data ditemukan atau tidak
    awal = 0;
    akhir = 6; // Indeks terakhir dari array
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari) {
            b_flag = true; // Data ditemukan
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1; // Pencarian di bagian kanan
        } else {
            akhir = tengah - 1; // Pencarian di bagian kiri
        }
    }
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Menampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari; // Menerima input data yang ingin dicari dari pengguna
    cout << "\nData diurutkan: ";
    // Mengurutkan data dengan selection sort
    selection_sort();
    // Menampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    // Melakukan pencarian binary search
    binarysearch();
    _getche(); // Menunggu input karakter dari pengguna sebelum program keluar
    return 0;
}
