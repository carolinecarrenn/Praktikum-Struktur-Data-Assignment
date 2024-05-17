# <h1 align="center">Laporan Praktikum Modul Algoritma Searching </h1>
<p align="center">2311102174 - Caroline Carren Aurelia R</p>
<p align="center">IF 11 E</p>

## Table of Contents
1. [Tujuan Praktikum](#tujuan-praktikum)
2. [Dasar Teori](#dasar-teori)
3. [Guided](#guided)
4. [Unguided](#unguided)
5. [Kesimpulan](#kesimpulan)
6. [Referensi](#referensi)

## Tujuan Praktikum 
1. Mahasiswa dapat memahami Konsep Algoritma Searching
2. Mahasiswa diharapkan dapat memahami konsep dasar dari berbagai algoritma pencarian seperti pencarian sekuensial, pencarian biner, dan mungkin juga algoritma pencarian lainnya seperti interpolation search atau exponential search.
3. Mahasiswa dapat mengimplementasikan algoritma pencarian dalam bahasa pemrograman C++
4. Mahasiswa diharapkan dapat menganalisis kinerja berbagai algoritma pencarian dalam berbagai skenario, seperti pada data yang terurut, tidak terurut, atau data dengan ukuran yang berbeda-beda.
5. Mahasiswa diharapkan dapat memahami kelebihan dan kekurangan masing-masing algoritma pencarian serta kapan algoritma tertentu lebih efisien digunakan daripada yang lain.
6. Mahasiswa untuk menerapkan konsep struktur data yang relevan dengan algoritma pencarian, seperti array, linked list, atau tree, tergantung pada algoritma yang dipelajari.

## Dasar Teori

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/4bd90343-6d61-4064-8155-1b7769685832)

Algoritma pencarian (searching) adalah algoritma yang digunakan untuk mencari suatu nilai tertentu dalam kumpulan data. 
Tujuan utama dari algoritma pencarian adalah untuk menentukan apakah suatu nilai tertentu ada di dalam kumpulan data, dan jika ada, di mana posisi atau berapa jumlah kemunculannya.

Beberapa algoritma pencarian yang umum digunakan meliputi:

### Sequential Search (Pencarian Sekuensial)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/cc54cf72-d610-4e23-ac9d-143503965024)

Sequential Search, juga dikenal sebagai Linear Search, adalah salah satu metode sederhana untuk mencari sebuah elemen dalam sebuah kumpulan data. 
Algoritma ini memeriksa setiap elemen satu per satu dalam kumpulan data hingga nilai yang dicari ditemukan atau sampai seluruh kumpulan data telah diperiksa. 
Ini adalah metode pencarian yang paling mudah dipahami, tetapi mungkin tidak efisien untuk kumpulan data yang sangat besar.[1]

Langkah-langkah Sequential Search:

1. Mulai dari elemen pertama dalam kumpulan data.
2. Bandingkan elemen saat ini dengan nilai yang dicari.
3. Jika nilai elemen saat ini sama dengan nilai yang dicari, kembalikan indeks elemen tersebut.
4. Jika tidak, lanjutkan ke elemen berikutnya.
5. Ulangi langkah 2-4 hingga menemukan nilai yang dicari atau sampai seluruh kumpulan data telah diperiksa.[1]

Kelebihan dan Kekurangan Sequential Search:

- Kelebihan: Sederhana dan mudah diimplementasikan.
- Kekurangan: Tidak efisien untuk kumpulan data yang sangat besar karena memerlukan waktu linier tergantung pada jumlah elemen dalam kumpulan data.[1]

Contoh program Sequential Search :
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <vector>
using namespace std;

int sequentialSearch(vector<int> arr, int x) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Nilai ditemukan, kembalikan indeks
        }
    }
    return -1; // Nilai tidak ditemukan
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 3;
    int result = sequentialSearch(arr, x);
    if (result != -1) {
        cout << "Nilai ditemukan di indeks: " << result << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }
    return 0;
}
```
Output program : 
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/02140d86-acf1-48fd-8c3e-136e6d7cd27c)

### Binary Search (Pencarian Biner)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/33eae694-77b8-48c3-80d5-7ab9207dcf45)

Binary Search adalah algoritma pencarian yang digunakan pada kumpulan data yang terurut secara berurutan. 
Proses pencarian dimulai dengan membandingkan nilai yang dicari dengan elemen tengah kumpulan data. 
Jika nilai yang dicari sama dengan elemen tengah, pencarian selesai. 
Jika tidak, algoritma akan memilih setengah kumpulan data berdasarkan hasil perbandingan sebelumnya, dan melanjutkan pencarian pada setengah tersebut.[2]

Langkah-langkah Binary Search:

1. Urutkan kumpulan data secara berurutan.
2. Tentukan elemen tengah kumpulan data.
3. Bandingkan nilai yang dicari dengan elemen tengah.
4. Jika nilai yang dicari sama dengan elemen tengah, pencarian selesai.
5. Jika nilai yang dicari kurang dari elemen tengah, lanjutkan pencarian pada setengah kumpulan data bagian kiri dari elemen tengah.
6. Jika nilai yang dicari lebih besar dari elemen tengah, lanjutkan pencarian pada setengah kumpulan data bagian kanan dari elemen tengah.
7. Ulangi langkah 2-6 hingga nilai yang dicari ditemukan atau sampai setengah kumpulan data hanya memiliki satu elemen.[2]

Kelebihan dan Kekurangan Binary Search:

- Kelebihan: Sangat efisien untuk kumpulan data yang besar karena setiap langkah mengurangi setengah kumpulan data yang akan diperiksa.
- Kekurangan: Hanya dapat digunakan pada kumpulan data yang sudah terurut.[2]

Contoh program Sequential Search :
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid; // Nilai ditemukan, kembalikan indeks
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Nilai tidak ditemukan
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 3;
    int result = binarySearch(arr, x);
    if (result != -1) {
        cout << "Nilai ditemukan di indeks: " << result << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }
    return 0;
}
```

Output Program :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/14e7bb56-3503-4c3b-8cb6-fc511349b63b)

### Hashing

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/713f2400-e374-4288-8e92-1cc706819586)

Hashing adalah teknik yang digunakan untuk mengonversi nilai yang dicari menjadi indeks dalam tabel hash. 
Tabel hash adalah struktur data yang menggunakan fungsi hash untuk menghasilkan indeks atau alamat tempat nilai disimpan. 
Hashing efisien dalam melakukan pencarian karena dapat langsung mengarahkan kita ke lokasi di mana nilai tersebut seharusnya berada.[3]

Proses Hashing:
- Fungsi Hash: Fungsi hash digunakan untuk mengonversi nilai yang dicari menjadi indeks dalam tabel hash. Fungsi ini mengambil nilai sebagai input dan mengembalikan indeks dalam tabel hash.
- Penyimpanan: Nilai yang dicari disimpan pada indeks yang dihasilkan oleh fungsi hash.[3]

Pencarian Nilai dengan Hashing:
- Fungsi Hash: Terapkan fungsi hash pada nilai yang dicari untuk mendapatkan indeks.
- Akses Tabel Hash: Akses tabel hash pada indeks yang dihasilkan oleh fungsi hash untuk mencari nilai.[3]

Kelebihan dan Kekurangan Hashing:
- Kelebihan: Pencarian sangat cepat karena langsung mengarahkan kita ke lokasi nilai yang dicari.
- Kekurangan: Kemungkinan terjadinya tabrakan hash (hash collision), di mana dua nilai yang berbeda menghasilkan indeks yang sama.[3]

Contoh program Hashing :
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Membuat tabel hash untuk menyimpan nama dan umur
    unordered_map<string, int> hashTable;

    // Menambahkan data ke dalam tabel hash
    hashTable["Jaehyun"] = 25;
    hashTable["Wooseok"] = 30;
    hashTable["Wonwoo"] = 23;

    // Mencari nilai dalam tabel hash
    string name = "Wonwoo";
    if (hashTable.find(name) != hashTable.end()) {
        cout << name << "'s age is " << hashTable[name] << " years." << endl;
    } else {
        cout << "Data for " << name << " not found." << endl;
    }

    return 0;
}
```
Output Program :
![Screenshot 2024-05-17 181405](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/27223d89-3f8d-4af6-a85e-4ff37eb5067e)

### Interpolation Search (Pencarian Interpolasi)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/892edf81-e48e-49c9-8924-25892103e79c)

Pencarian Interpolasi adalah sebuah algoritma pencarian yang digunakan pada kumpulan data yang terurut dan memiliki distribusi yang merata. 
Algoritma ini mencoba memperkirakan posisi nilai yang dicari berdasarkan nilai maksimum dan minimum dalam kumpulan data. 
Dengan asumsi bahwa data terdistribusi secara merata, algoritma ini cenderung lebih cepat daripada Binary Search, terutama jika data memiliki distribusi yang merata.[4]

Langkah-langkah Interpolation Search:

1. Hitung perkiraan posisi nilai yang dicari berdasarkan nilai maksimum dan minimum dalam kumpulan data serta distribusi data.
2. Bandingkan nilai yang dicari dengan nilai di posisi perkiraan.
3. Jika nilai yang dicari sama dengan nilai di posisi perkiraan, pencarian selesai.
4. Jika nilai yang dicari kurang dari nilai di posisi perkiraan, lanjutkan pencarian di setengah kumpulan data bagian kiri dari posisi perkiraan.
5. Jika nilai yang dicari lebih besar dari nilai di posisi perkiraan, lanjutkan pencarian di setengah kumpulan data bagian kanan dari posisi perkiraan.
6. Ulangi langkah 2-5 hingga nilai yang dicari ditemukan atau sampai setengah kumpulan data hanya memiliki satu elemen.[4]

Kelebihan dan Kekurangan Interpolation Search:
- Kelebihan: Lebih cepat daripada Binary Search untuk kumpulan data yang terdistribusi secara merata.
- Kekurangan: Tidak efisien untuk kumpulan data yang tidak terdistribusi secara merata, dapat menjadi lambat atau bahkan tidak stabil dalam beberapa kasus.[4]

Contoh program Interpolation Search :
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int> arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Interpolasi untuk memperkirakan posisi nilai x
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) {
            return pos; // Nilai ditemukan, kembalikan indeks
        } else if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1; // Nilai tidak ditemukan
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int x = 30;
    int result = interpolationSearch(arr, x);
    if (result != -1) {
        cout << "Nilai ditemukan di indeks: " << result << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }
    return 0;
}
```

Output Program :

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/53a19385-13a1-4b6f-9169-be60331f7f73)

### Exponential Search (Pencarian Eksponensial)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/8758b007-bfd1-46d7-b915-146e39eaf52a)

Exponential Search adalah algoritma pencarian yang digunakan pada kumpulan data yang terurut. 
Proses pencarian dimulai dengan mencari rentang yang mengandung nilai yang dicari, kemudian melakukan pencarian biner dalam rentang tersebut. 
Algoritma ini berguna terutama saat kita tidak tahu ukuran kumpulan data sebelumnya.[1]

Langkah-langkah Exponential Search:
1. Tentukan rentang awal yang berukuran 1 (indeks awal dan akhir sama).
2. Perbesar rentang dengan menggandakan ukuran rentang hingga nilai pada indeks akhir kurang dari atau sama dengan nilai yang dicari.
3. Lakukan pencarian biner dalam rentang yang diperbesar untuk menemukan nilai yang dicari.[1]

Kelebihan dan Kekurangan Exponential Search:
- Kelebihan: Efisien saat ukuran kumpulan data tidak diketahui sebelumnya.
- Kekurangan: Memerlukan lebih banyak perbandingan daripada Binary Search jika nilai yang dicari berada di dekat ujung kumpulan data.[1]

Contoh program Exponential Search :
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; // Nilai ditemukan, kembalikan indeks
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Nilai tidak ditemukan
}

int exponentialSearch(vector<int> arr, int x) {
    int n = arr.size();
    if (arr[0] == x) {
        return 0; // Nilai ditemukan di indeks 0
    }
    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = exponentialSearch(arr, x);
    if (result != -1) {
        cout << "Nilai ditemukan di indeks: " << result << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }
    return 0;
}
```

Output Program :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/41fa629d-bbfd-48c6-ad1d-5d3da80fb7c4)

## Guided 

### 1. [Pencarian nilai dalam sebuah array menggunakan metode pencarian sekuensial]

```C++
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
```
#### Output :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/ae0c449d-6571-4d8f-ad31-acd437245533)

#### Deskripsi Program : 
Program ini adalah contoh program yang melakukan pencarian nilai dalam sebuah array menggunakan metode pencarian sekuensial. 

Berikut adalah deskripsi dari program tersebut:
- Program dimulai dengan mendeklarasikan variabel-variabel yang akan digunakan, seperti n yang merupakan ukuran array, data yang merupakan array yang berisi data, cari yang merupakan nilai yang akan dicari dalam array, ketemu yang merupakan boolean untuk menandai apakah nilai ditemukan, dan i yang digunakan sebagai variabel iterasi.
- Kemudian, program melakukan pencarian nilai cari dalam array data menggunakan perulangan for. Jika nilai ditemukan, variabel ketemu akan diubah menjadi true dan perulangan akan dihentikan dengan menggunakan break.
- Setelah itu, program mencetak judul program dan isi array data.
- Program kemudian memeriksa apakah nilai cari ditemukan. Jika ditemukan, program akan mencetak indeks nilai yang ditemukan. Jika tidak ditemukan, program akan mencetak pesan bahwa nilai tidak ditemukan.
- Akhirnya, program mengembalikan nilai 0 ke sistem operasi, menandakan bahwa program telah berakhir dengan sukses.
  
### Full code Screenshot:
![carbon (3)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/4bec1ab1-b896-4300-a952-283fe252b4cd)

### 2. [Implementasi algoritma binary search untuk mencari nilai dalam array yang telah diurutkan menggunakan algoritma selection sort]

```C++
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
```
#### Output :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/4656ba60-1892-46aa-adb8-3f9ca9f19a6f)

#### Deskripsi Program : 
Program ini merupakan contoh algoritma binary search untuk mencari nilai dalam array yang telah diurutkan menggunakan algoritma selection sort. 

Berikut adalah deskripsi dari program tersebut:
- Program dimulai dengan mendeklarasikan array dataArray yang berisi 7 elemen bilangan bulat dan variabel cari untuk menyimpan data yang akan dicari.
- Kemudian, program mendefinisikan fungsi `selection_sort()` untuk mengurutkan array dataArray menggunakan algoritma selection sort. Algoritma ini bekerja dengan mencari nilai minimum dalam array dan menukarnya dengan elemen pertama, kemudian mencari nilai minimum dalam sisa array dan menukarnya dengan elemen kedua, dan seterusnya hingga array terurut.
- Program juga mendefinisikan fungsi `binarysearch()` untuk melakukan pencarian data dalam array yang telah diurutkan menggunakan algoritma binary search. Algoritma ini bekerja dengan membagi array menjadi dua bagian dan memeriksa apakah nilai yang dicari berada di bagian kiri atau kanan dari titik tengah array. Pencarian dilakukan secara rekursif hingga nilai ditemukan atau array habis.
- Di dalam fungsi `main()`, program mencetak judul "BINARY SEARCH" dan menampilkan data awal dari array dataArray. Kemudian, program meminta pengguna untuk memasukkan nilai yang ingin dicari (cari).
- Selanjutnya, program mengurutkan array dataArray menggunakan fungsi `selection_sort()` dan menampilkan data setelah diurutkan.
- Terakhir, program melakukan pencarian nilai yang dimasukkan pengguna menggunakan algoritma binary search dengan memanggil fungsi `binarysearch()` dan menampilkan hasil pencarian.
- Program menggunakan `_getche()` untuk menunggu input karakter dari pengguna sebelum program keluar.

### Full code Screenshot:
![carbon (4)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/ebcbb0e9-4e32-4862-b6ae-6c486a5519e3)

### 3. [Pencarian nilai dalam array menggunakan pendekatan linear search]

```C++
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
```

#### Output :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/bdd25808-5ca9-47fd-b060-6f8703cefb1d)

#### Deskripsi Program : 
Program ini merupakan contoh sederhana dari pencarian nilai dalam array menggunakan pendekatan linear search. 

Berikut adalah deskripsi dari program tersebut:
1. Program dimulai dengan mendeklarasikan dan menginisialisasi array arr dengan 10 elemen bilangan bulat dan variabel cari yang berisi nilai yang ingin dicari dalam array.
2. Selanjutnya, program mendeklarasikan variabel i sebagai indeks untuk iterasi, panjangArray untuk menyimpan panjang array, dan ketemu sebagai flag untuk menandai apakah data ditemukan atau tidak.
3. Program kemudian menggunakan perulangan for untuk iterasi melalui seluruh elemen array. Jika nilai pada indeks tertentu sama dengan nilai yang dicari (cari), maka variabel ketemu diubah menjadi true dan perulangan dihentikan dengan menggunakan break.
4. Setelah perulangan selesai, program menampilkan hasil pencarian. Jika nilai ditemukan, program akan mencetak indeks tempat nilai ditemukan dan panjang array. Jika nilai tidak ditemukan, program akan mencetak pesan bahwa elemen tidak ditemukan.
5. Akhirnya, program mengembalikan nilai 0, menandakan bahwa program telah berhasil dijalankan.

### Full code Screenshot:
![carbon (6)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/a413d092-e186-4219-8b10-ac170e2de934)

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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
```

### Output:

#### Contoh kata yang di temukan di indeks ke :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/90983058-abc0-48a2-99de-0fa65fb3eb9a)

#### Contoh kata yang tidak di temukan di indeks ke :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/fd6e1b26-157e-4d8e-bdce-7904fe5f7875)

### Deskripsi Program : 
Program ini merupakan implementasi pencarian biner (binary search) pada string. 

Berikut adalah penjelasan mengenai program tersebut:
1. Program dimulai dengan mendefinisikan fungsi `binarySearch` yang menerima dua parameter:
   string str yang merupakan string yang akan dicari dan karakter x yang merupakan karakter target yang ingin dicari dalam string.
2. Fungsi binarySearch melakukan pencarian biner pada string str untuk mencari karakter x. Pencarian dimulai dengan menginisialisasi indeks rendah (low) dengan 0 dan indeks tinggi (high) dengan panjang string dikurangi 1.
3. Selama indeks rendah kurang dari atau sama dengan indeks tinggi, fungsi menghitung indeks tengah (mid) dengan menggunakan rumus mid = low + (high - low) / 2.
4. Jika karakter pada indeks tengah adalah karakter target (str[mid] == x), maka fungsi mengembalikan indeks tengah tersebut.
5. Jika karakter pada indeks tengah lebih kecil dari karakter target (str[mid] < x), maka fungsi memperbarui indeks rendah menjadi mid + 1.
6. Jika karakter pada indeks tengah lebih besar dari karakter target (str[mid] > x), maka fungsi memperbarui indeks tinggi menjadi mid - 1.
7. Jika karakter target tidak ditemukan setelah seluruh string str diperiksa, fungsi mengembalikan nilai -1.
8. Pada fungsi main, program meminta pengguna untuk memasukkan string str dan karakter target x.
9. Kemudian, program memanggil fungsi `binarySearch` dengan parameter string str dan karakter x, dan menyimpan hasilnya dalam variabel result.
10. Jika karakter target ditemukan dalam string, program mencetak indeks dimana karakter ditemukan. Jika tidak ditemukan, program mencetak pesan bahwa karakter tidak ditemukan.
11. Program mengembalikan nilai 0, menandakan bahwa program telah berhasil dijalankan.

Program ini merupakan contoh sederhana dari penggunaan pencarian biner pada string untuk mencari sebuah karakter dalam string.

### Full code Screenshot:
![carbon (7)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/5f541364-cb19-4a7b-b1b7-4e6161e81967)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <cstring> // Untuk fungsi strlen dan strcpy

using namespace std;

void countAndDisplayVowels(const char* sentence) {
    int vowelCount = 0;
    int length = strlen(sentence);
    cout << "Analisis kalimat:\n";
    for (int i = 0; i < length; i++) {
        char lowerCh = tolower(sentence[i]);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            vowelCount++;
            cout << sentence[i] << " adalah vokal\n";
        } else if (isalpha(lowerCh)) {
            cout << sentence[i] << " adalah konsonan\n";
        } else {
            cout << sentence[i] << " bukan huruf\n";
        }
    }
    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;
}

int main() {
    char sentence[1000];
    cout << "Masukkan sebuah kalimat: ";
    cin.getline(sentence, 1000);

    countAndDisplayVowels(sentence);

    return 0;
}
```

### Output:
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7e756af4-7712-4819-9cb9-b70cad29ca55)

### Deskripsi Program : 
Program ini merupakan contoh program yang menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. 

Berikut adalah penjelasan mengenai program tersebut:
1. Program dimulai dengan mendefinisikan fungsi `countAndDisplayVowels` yang menerima parameter sentence yang merupakan array karakter yang berisi kalimat yang akan dianalisis.
2. Di dalam fungsi countAndDisplayVowels, program menginisialisasi `vowelCount` untuk menyimpan jumlah huruf vokal dalam kalimat, dan length untuk menyimpan panjang kalimat menggunakan fungsi strlen dari <cstring>.
3. Selanjutnya, program melakukan iterasi melalui setiap karakter dalam kalimat. Untuk setiap karakter, program mengubahnya menjadi huruf kecil menggunakan tolower untuk memudahkan perbandingan.
   Jika karakter tersebut merupakan huruf vokal ('a', 'e', 'i', 'o', 'u'), program akan meningkatkan nilai `vowelCount` dan mencetak bahwa karakter tersebut adalah vokal. Jika karakter tersebut adalah huruf konsonan, program akan mencetak bahwa karakter tersebut adalah konsonan. Jika karakter tersebut bukan huruf, program akan mencetak bahwa karakter tersebut bukan huruf.
4. Setelah selesai melakukan iterasi, program akan mencetak jumlah huruf vokal yang ditemukan dalam kalimat.
5. Pada fungsi main, program meminta pengguna untuk memasukkan sebuah kalimat menggunakan cin.getline dan menyimpannya dalam array sentence.
6. Kemudian, program memanggil fungsi `countAndDisplayVowels` dengan parameter sentence.
7. Program mengembalikan nilai 0, menandakan bahwa program telah berhasil dijalankan.

Program ini merupakan contoh penggunaan array karakter, fungsi string dari <cstring>, dan operasi-operasi pada karakter dalam bahasa pemrograman C++.

### Full code Screenshot:
![carbon (8)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/c031d46c-3736-47d7-a9c3-f225e3f4ec89)


### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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
```

### Output:
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/2f980a9c-e93e-4de4-8e07-cb43aced61af)

### Deskripsi Program : 
Program ini merupakan contoh implementasi pencarian sekuensial (sequential search). 
Program mencari jumlah kemunculan suatu nilai target dalam array. 

Berikut adalah penjelasan mengenai program tersebut:
1. Fungsi sequentialSearch digunakan untuk melakukan pencarian sekuensial dalam `array data[]`. Fungsi ini menerima tiga parameter: array data[], ukuran array size, dan nilai target yang akan dicari. Fungsi ini mengembalikan jumlah kemunculan nilai target dalam array.
2. Di dalam fungsi sequentialSearch, program menggunakan perulangan `for` untuk iterasi melalui setiap elemen `array data[]`. Jika nilai pada indeks i sama dengan target, maka count (yang menghitung jumlah kemunculan) akan diincrement.
3. Setelah selesai melakukan iterasi, fungsi `sequentialSearch` mengembalikan nilai count, yang merupakan jumlah kemunculan nilai target dalam array.
4. Pada fungsi main, program mendeklarasikan `array data[]` dengan nilai-nilai tertentu, menghitung ukuran array, dan menentukan nilai target yang akan dicari.
5. Program memanggil fungsi `sequentialSearch` dengan parameter `array data[]`, ukuran array, dan nilai target, dan menyimpan hasilnya dalam variabel jumlahKemunculan.
6. Program kemudian menampilkan jumlah kemunculan nilai target dalam array menggunakan cout.
7. Akhirnya, program mengembalikan nilai 0, menandakan bahwa program telah berhasil dijalankan.

Program ini merupakan contoh sederhana dari pencarian sekuensial dalam array 

### Full code Screenshot:
![carbon (9)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/d5ffc629-52d7-460a-929b-7ba6e8b0ba09)

## Kesimpulan
Kesimpulan dari melakukan praktikum dengan algoritma searching adalah :

1. Pemahaman Algoritma Pencarian :
   
   Praktikum ini memberikan pemahaman yang lebih baik tentang berbagai algoritma pencarian seperti pencarian sekuensial dan pencarian biner.
   Algoritma pencarian sangat penting dalam pemrosesan data karena membantu menemukan elemen tertentu dalam kumpulan data.
   
2. Penggunaan Fungsi-fungsi Pencarian :
   
   Praktikum ini mengajarkan penggunaan fungsi-fungsi pencarian seperti sequentialSearch dan binarySearch, serta bagaimana mengimplementasikannya.
   
3. Pentingnya Analisis Kasus Terburuk :
   
   Dalam algoritma pencarian, penting untuk mempertimbangkan analisis kasus terburuk, terutama ketika menggunakan algoritma pencarian sekuensial pada kumpulan data besar yang dapat mempengaruhi kinerja program secara keseluruhan.
  
4. Penggunaan Variabel dan Logika :
   
   Praktikum ini juga mengajarkan penggunaan variabel, logika perulangan, dan logika kondisional untuk mengimplementasikan algoritma pencarian dengan benar.

5. Pentingnya Pengujian dan Debugging :
   
   Dalam memahami dan mengimplementasikan algoritma pencarian, pengujian dan debugging adalah langkah penting untuk memastikan bahwa program berjalan dengan benar dan memberikan hasil yang diinginkan.

## Referensi
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, MA, USA: MIT Press, 2009.

[2] R. Sedgewick and K. Wayne, Algorithms, 4th ed. Boston, MA, USA: Addison-Wesley, 2011.

[3] A. Levitin, Introduction to the Design and Analysis of Algorithms, 3rd ed. Boston, MA, USA: Pearson, 2012.

[4] M. A. Weiss, Data Structures and Algorithm Analysis in C++, 4th ed. Boston, MA, USA: Pearson, 2014.


