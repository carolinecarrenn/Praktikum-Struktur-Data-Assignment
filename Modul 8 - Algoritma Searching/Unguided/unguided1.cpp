/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

// Fungsi untuk melakukan pencarian biner pada string
int binarySearch(string str, char x) {
    // Inisialisasi indeks rendah dan tinggi
    int low = 0;
    int high = str.length() - 1;
    int mid;

    // Lanjutkan pencarian saat indeks rendah kurang dari atau sama dengan indeks tinggi
    while (low <= high) {
        // Hitung indeks tengah
        mid = low + (high - low) / 2;

        // Jika karakter pada indeks tengah adalah karakter target
        if (str[mid] == x) {
            // Kembalikan indeks tengah
            return mid;
        }

        // Jika karakter pada indeks tengah lebih kecil dari karakter target
        if (str[mid] < x) {
            // Set indeks rendah ke indeks tengah plus satu
            low = mid + 1;
        }

        // Jika karakter pada indeks tengah lebih besar dari karakter target
        else {
            // Set indeks tinggi ke indeks tengah minus satu
            high = mid - 1;
        }
    }

    // Jika karakter target tidak ditemukan, kembalikan -1
    return -1;
}

int main() {
    string str;
    char x;

    // Tampilkan pesan untuk memasukkan string
    cout << "Masukkan string: ";
    cin >> str;

    // Tampilkan pesan untuk memasukkan karakter yang akan dicari
    cout << "Masukkan karakter yang akan dicari: ";
    cin >> x;

    // Panggil fungsi binarySearch dan simpan hasilnya
    int result = binarySearch(str, x);

    // Jika karakter target ditemukan
    if (result!= -1) {
        // Tampilkan indeks karakter target
        cout << "Karakter ditemukan pada indeks " << result;
    }

    // Jika karakter target tidak ditemukan
    else {
        // Tampilkan pesan bahwa karakter tidak ditemukan
        cout << "Karakter tidak ditemukan dalam string";
    }

    return 0;
}