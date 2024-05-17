/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>  

using namespace std;  

// Fungsi untuk melakukan pencarian sekuensial dan mengembalikan jumlah kemunculan target dalam array
int sequentialSearch(int data[], int size, int target) {
    int count = 0;  // Inisialisasi variabel count untuk menghitung jumlah kemunculan target
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            count++;  // Increment count jika nilai pada index i sama dengan target
        }
    }
    return count;  // Mengembalikan jumlah kemunculan target dalam array
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};  // Deklarasi array data
    int size = sizeof(data) / sizeof(data[0]);      // Menghitung ukuran array data
    int target = 4;                                 // Nilai yang akan dicari dalam array data

    // Memanggil fungsi sequentialSearch untuk mencari jumlah kemunculan target dalam array data
    int jumlahKemunculan = sequentialSearch(data, size, target);

    // Menampilkan hasil pencarian jumlah kemunculan target
    cout << "Jumlah kemunculan angka " << target << " pada data tersebut adalah: " << jumlahKemunculan << endl;

    return 0;  // Mengembalikan nilai 0 yang menandakan program berakhir dengan sukses
}
