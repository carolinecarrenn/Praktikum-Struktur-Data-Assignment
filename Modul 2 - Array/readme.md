# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Caroline Carren (2311102174)</p>

## Dasar Teori

- Pengertian Array:
  
Array merupakan struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama yang disimpan secara berurutan dalam memori.
Setiap elemen dalam array memiliki indeks yang menentukan posisi atau lokasinya dalam array.

- Deklarasi Array:
  
Array dideklarasikan dengan menentukan tipe data elemen dan ukuran array.
Contoh: int array[10]; mendeklarasikan sebuah array integer dengan 10 elemen.

- Akses Elemen Array:
  
Elemen array dapat diakses dengan menggunakan indeksnya.
Indeks array dimulai dari 0 hingga ukuran array dikurangi 1.
Contoh: array[0], array[1], ..., array[9] untuk array dengan ukuran 10.

- Inisialisasi Array:
  
Array dapat diinisialisasi saat deklarasi atau setelah deklarasi dengan memberikan nilai pada setiap elemennya (inisialisasi satu per satu, inisialisasi dengan daftar nilai, atau inisialisasi menggunakan tanda kurung kurawal.)

- Operasi Dasar pada Array:
  
Menyimpan dan mengambil nilai dari elemen array.
Melakukan iterasi melalui elemen-elemen array.
Memanipulasi elemen array seperti menambah, menghapus, atau mengubah nilai.

- Keterbatasan Array:
  
Ukuran array biasanya tetap setelah dideklarasikan.
Memori untuk array dialokasikan secara statis, sehingga ukurannya tidak bisa diubah saat runtime.
Penggunaan memori statis dapat menjadi masalah jika ukuran array terlalu besar atau tidak diketahui sebelumnya.

- Multidimensional Array:
  
Array dapat memiliki lebih dari satu dimensi, yang disebut sebagai array multidimensi(array dua dimensi (matriks) dan array tiga dimensi)
Contoh: int matrix[3][3]; mendeklarasikan matriks 3x3.


## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int z = 0; z < 3; z++)
                {
                    cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
    cin >> arr[x][y][z];
    }
    }
    cout << endl;
    }

    // Output Array
    for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int z = 0; z < 3; z++)
                {
                    cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
    }
    }
    }

    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int z = 0; z < 3; z++)
                {
                    cout << arr[x][y][z] << ends;
    }
    cout << endl;
    }
    cout << endl;
    }
}
```
#### Deskripsi Program :
- Program dimulai dengan mendeklarasikan array tiga dimensi arr dengan ukuran 2x3x3, yang berarti array tersebut memiliki 2 matriks 3x3.
- Selanjutnya, program menggunakan tiga perulangan bersarang untuk meminta pengguna memasukkan nilai untuk setiap elemen array. Perulangan pertama mengontrol indeks x (matriks luar), perulangan kedua mengontrol indeks y (baris dalam matriks), dan perulangan ketiga mengontrol indeks z (kolom dalam matriks).
- Setelah pengguna memasukkan nilai untuk setiap elemen array, program menggunakan perulangan bersarang lagi untuk mencetak nilai dari setiap elemen array yang telah dimasukkan. Ini memberikan tampilan yang menyertakan informasi indeks (x, y, z) dari setiap elemen array.
- Terakhir, program mencetak kembali nilai elemen array tanpa memberikan informasi mengenai indeksnya. Ini memberikan tampilan array secara berturut-turut tanpa memperhatikan matriks atau baris/kolom.

Tujuan utama program ini adalah memberikan pengguna kemampuan untuk memasukkan nilai ke dalam array tiga dimensi dan kemudian mencetak nilai-nilai tersebut dengan dua format tampilan yang berbeda: satu dengan indeks (x, y, z) dan yang lainnya tanpa informasi indeks.


### 2. [Program Mencari Nilai Maksimal pada Array]

```C++
#include <iostream>
using namespace std;

int main (){
    int maks, a, i = 1, lokasi;
    cout << "Masukan panjang array : ";
    cin >> a;
    int array [a];
    cout << "Masukkan " << a <<" angka\n";
    for (i = 0; i < a ; ++i) 
    {
        cout << "Array ke- " << (i) << " : ";
        cin >> array [i];
    }
    maks = array [0];
    for (i = 0; i < a; i++)
    {
        if (array [i] > maks)
        {
        
        maks = array [i];
        lokasi = i;
    }
}
cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}

```
#### Deskripsi Program :
- Program meminta pengguna untuk memasukkan panjang array yang diinginkan.
- Setelah pengguna memasukkan panjang array, program mendeklarasikan array dengan ukuran sesuai input pengguna.
- Program kemudian meminta pengguna untuk memasukkan nilai-nilai array sebanyak panjang array yang telah ditentukan. Nilai-nilai tersebut dimasukkan ke dalam array menggunakan perulangan for.
- Program menginisialisasi variabel maks dengan nilai dari elemen pertama array.
- Program kemudian melakukan iterasi melalui seluruh elemen array menggunakan perulangan for, dimulai dari indeks 0 hingga panjang array dikurangi 1.
- Di dalam perulangan, program membandingkan setiap elemen array dengan nilai maksimum yang saat ini disimpan dalam variabel maks. Jika sebuah elemen array lebih besar dari nilai maksimum yang disimpan saat ini, maka nilai maksimum diupdate dengan nilai elemen tersebut, dan lokasi indeksnya disimpan dalam variabel lokasi.
- Setelah perulangan selesai, program mencetak nilai maksimum yang ditemukan beserta lokasi indeksnya di dalam array.

Tujuan utama dari program ini adalah untuk mencari nilai maksimum dalam array yang diinputkan oleh pengguna dan untuk mencetak nilai maksimum tersebut beserta lokasi indeksnya dalam array.



## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]
![Screenshot (51)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/5be87ee7-dea3-4db7-9050-512b0d86ba81)


```C++
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
```
#### Output:
![Screenshot (39)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/5243fb41-d15d-47f4-94a0-6b61a98043e7)

#### Deskripsi Program :
- Program dimulai dengan mendeklarasikan array integer dengan nama array yang memiliki panjang 10.
- Pengguna diminta untuk memasukkan 10 nilai integer secara berurutan ke dalam array menggunakan perulangan for.
- Setelah semua nilai dimasukkan, program mencari nilai genap dan ganjil dalam array tersebut menggunakan dua perulangan for terpisah.
- Dalam setiap perulangan for, setiap elemen array diperiksa apakah nilainya genap atau ganjil dengan menggunakan operasi modulus (%).
- Jika nilai tersebut genap (sisa bagi dengan 2 adalah 0), maka nilai tersebut ditambahkan ke dalam string genap.
- Jika nilai tersebut ganjil (sisa bagi dengan 2 bukan 0), maka nilai tersebut ditambahkan ke dalam string ganjil.
- Setelah semua nilai diperiksa, program mencetak nilai-nilai genap dan ganjil yang telah ditemukan. Mereka dicetak sebagai string, dengan nilai-nilai dipisahkan oleh koma dan spasi.
- Sebelum mencetak, program memastikan untuk menghilangkan koma dan spasi ekstra di akhir string menggunakan substr().

Tujuan utama dari program ini adalah untuk memungkinkan pengguna memasukkan nilai-nilai ke dalam array, dan kemudian mencari dan mencetak nilai-nilai genap dan ganjil yang ada dalam array tersebut.


#### Full code Screenshot:
![Screenshot (44)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/c3b5a7bb-7f06-40f8-ba6f-12a6ca9e367a)
![Screenshot (45)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/db556281-f1a8-4d45-aee3-0f8ffada2de0)


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++

#include <stdio.h>

int main() {
    // Deklarasi variable
    int x, y, z;
    // Input ukuran array 3D
    printf("Masukkan ukuran array 3D (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    // Deklarasi array 3D
    int arr[x][y][z];

    // Mengambil input dan menampilkan array 3D
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("Masukkan nilai untuk arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\nArray 3D adalah:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    // Kembali ke titik awal
    return 0;
}

```
#### Output:
![Screenshot (40)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1e051794-9d45-481f-869b-563f1a91db6a)
![Screenshot (41)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0590cac1-9e60-447f-a115-3ca22711e96d)

#### Deskripsi Program : 
- Program dimulai dengan mendeklarasikan tiga variabel integer x, y, dan z, yang akan digunakan untuk menyimpan ukuran array 3 dimensi.
- Pengguna diminta untuk memasukkan ukuran array 3 dimensi melalui input yang diminta menggunakan printf dan scanf.
- Setelah ukuran array ditentukan, array tiga dimensi arr dideklarasikan dengan menggunakan nilai-nilai yang dimasukkan oleh pengguna.
- Kemudian, program menggunakan tiga perulangan bersarang untuk mengambil input untuk setiap elemen dalam array 3 dimensi tersebut dari pengguna menggunakan printf dan scanf.
- Perulangan tersebut mengatur indeks untuk masing-masing dimensi array dan berjalan sebanyak ukuran yang dimasukkan oleh pengguna.
- Setelah semua nilai dimasukkan, program mencetak kembali array 3 dimensi yang telah diisi menggunakan tiga perulangan bersarang lagi.
- Program kemudian mengembalikan nilai 0 sebagai indikasi bahwa program telah selesai dijalankan dengan sukses.

Tujuan utama dari program ini adalah untuk memungkinkan pengguna untuk membuat, mengisi, dan menampilkan array 3 dimensi sesuai dengan ukuran yang dimasukkan.

#### Full code Screenshot:
![Screenshot (46)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0e814937-f846-49e3-8171-744787e88bd3)
![Screenshot (47)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/17768aba-f53b-44aa-91bb-0712561746a4)


### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++

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

```
#### Output:
![Screenshot (43)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/207239ea-e82b-41ad-b86f-2d54a2301e67)

#### Deskripsi Program :
- Program dimulai dengan mendefinisikan empat fungsi, masing-masing bertugas untuk mengelola array dan menghitung statistik sederhana seperti nilai maksimum, minimum, dan rata-rata.
- Dalam fungsi main, sebuah array integer dengan nama arr dan ukuran maksimum 100 dideklarasikan.
- Fungsi input_array dipanggil untuk meminta pengguna memasukkan nilai-nilai array. Pengguna diminta untuk memasukkan ukuran array dan nilai-nilai elemen array.
- Setelah pengguna memasukkan nilai-nilai, fungsi input_array mengembalikan ukuran array yang diisi.
- Array yang diisi kemudian dicetak.
- Fungsi find_max, find_min, dan find_avg dipanggil untuk mencari nilai maksimum, minimum, dan rata-rata dari array yang telah diisi.
- Hasil dari setiap fungsi tersebut kemudian dicetak.

Tujuan utama dari program ini adalah untuk memungkinkan pengguna memasukkan nilai-nilai ke dalam array, dan kemudian mencari dan mencetak nilai maksimum, minimum, dan rata-rata dari nilai-nilai tersebut.

#### Full code Screenshot:
![Screenshot (48)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/d9ff359d-7672-4e53-a0f8-2afbf7c75f6b)
![Screenshot (49)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/03eea357-0e1f-435e-a1b7-ba3740318f57)
![Screenshot (50)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/bd927b39-0fbf-43fa-8b14-73daee00c7f4)

## Kesimpulan
Kesimpulan yang dapat saya ambil dari pembelajaran ini yaitu :
- Dalam dasar pemrograman array merupakan salah satu struktur data dasar dalam pemrograman.

  Memahami konsep dan penggunaan array sangat penting bagi seorang pemrogram karena banyak masalah yang dapat diselesaikan dengan menggunakan array.
  
- Optimalitas
  
  Array dapat digunakan untuk menyimpan dan mengakses sekumpulan data dengan efisien. Akses ke elemen-elemen array bisa dilakukan secara langsung dengan menggunakan indeks, yang membuatnya lebih efisien daripada menggunakan variabel terpisah untuk setiap data.

- Pengelolaan Data
  
  Array memungkinkan pengelolaan data yang terstruktur. Dengan array, kita dapat menyimpan data dalam urutan tertentu dan mengaksesnya dengan mudah menggunakan indeks.
  
- Manipulasi Data
  
  Array memungkinkan manipulasi data dengan berbagai cara, seperti mengurutkan elemen-elemen array, mencari nilai tertentu, atau mengubah nilai-nilai dalam array.
  
- Kompleksitas Algoritma
  
  Memahami array membantu dalam menganalisis kompleksitas algoritma. Misalnya, dalam mencari atau mengakses elemen array, kita dapat mengidentifikasi kompleksitas waktu yang terlibat dalam operasi tersebut, yang penting untuk mengevaluasi kinerja algoritma secara keseluruhan.

- Penggunaan dalam Berbagai Konteks
  
  Array digunakan dalam berbagai konteks pemrograman, termasuk dalam implementasi struktur data lain seperti stack, queue, dan matriks.
  
- Pentingnya Pemahaman Konsep
  
  Penting untuk memahami konsep-konsep yang berkaitan dengan array, seperti indeks array, alokasi memori, dan pengelolaan array dinamis. Hal ini membantu dalam menghindari kesalahan pemrograman yang umum terkait dengan penggunaan array.

## Referensi

[1] M. A. Weiss, "Data Structures and Algorithm Analysis in C++," Addison-Wesley, Boston, MA, USA, 2014.

[2] S. B. Lippman, J. Lajoie, and B. E. Moo, "C++ Primer," 5th ed., Addison-Wesley, Boston, MA, USA, 2012.
