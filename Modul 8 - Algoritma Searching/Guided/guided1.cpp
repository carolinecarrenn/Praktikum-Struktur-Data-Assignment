/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

// Fungsi utama tempat program dimulai
int main() {
    int n = 10; // Deklarasikan variabel integer n dan inisialisasikan ke 10
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Deklarasikan array data dengan ukuran n dan inisialisasikan dengan nilai-nilai
    int cari = 10; // Deklarasikan variabel integer cari dan inisialisasikan ke 10
    bool ketemu = false; // Deklarasikan variabel boolean ketemu dan inisialisasikan ke false
    int i; // Deklarasikan variabel integer i tanpa inisialisasi

    // Algoritma Pencarian Sekuensial
    // Lakukan iterasi dari 0 hingga n-1 (termasuk) menggunakan perulangan for
    for (i = 0; i < n; i++) {
        // Periksa apakah nilai data[i] sama dengan cari
        if (data[i] == cari) {
            ketemu = true; // Tetapkan true ke variabel ketemu jika nilai ditemukan
            break; // Hentikan eksekusi perulangan for
        }
    }

    // Cetak judul program dan array data
    cout << "\tProgram Pencarian Sekuensial Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Periksa apakah nilai ditemukan
    if (ketemu) {
        // Cetak indeks nilai yang ditemukan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke - " << i << endl;
    } else {
        // Cetak pesan jika nilai tidak ditemukan
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0; // Hentikan eksekusi fungsi utama dan kembalikan 0 ke sistem operasi
}