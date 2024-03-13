# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Caroline Carren Aurelia R (2311102174)</p>

## Dasar Teori

Tipe data adalah konsep dasar dalam ilmu komputer yang menggambarkan jenis nilai yang dapat disimpan dan dioperasikan oleh suatu program komputer. Dalam konteks struktur data dan algoritma, pemahaman yang baik tentang tipe data sangat penting untuk merancang algoritma yang efisien dan efektif. Berikut adalah beberapa dasar teori tentang tipe data:[1]

Tipe Data Dasar:
- Integer: Menyimpan bilangan bulat. Misalnya, int pada banyak bahasa pemrograman.
- Float/Double: Menyimpan bilangan desimal. Misalnya, float atau double.
- Character: Menyimpan karakter. Misalnya, char.
  
Tipe Data Struktur:
- Array: Struktur data yang menyimpan elemen-elemen dengan tipe data yang sama, dan setiap elemen dapat diakses dengan menggunakan indeks.
- Struct/Record: Gabungan dari beberapa tipe data yang berbeda dalam satu struktur. Misalnya, dalam C, kita bisa mendefinisikan struct untuk menggabungkan beberapa variabel dengan tipe data yang berbeda.
- Union: Struktur data yang memungkinkan penyimpanan lebih dari satu tipe data dalam satu lokasi memori, tetapi hanya satu tipe data yang bisa diakses pada satu waktu.

Tipe Data Abstrak:
- Queue: Antrian data yang mengikuti prinsip FIFO (First In, First Out).
- Stack: Tumpukan data yang mengikuti prinsip LIFO (Last In, First Out).
- Linked List: Kumpulan elemen data yang terhubung melalui node-node, masing-masing memiliki dua bagian: data dan referensi/pointer ke node berikutnya.
- Tree: Struktur hirarkis dengan satu simpul sebagai simpul atas atau akar, dan simpul lainnya dibagi menjadi sub-pohon.
- Graph: Struktur data yang terdiri dari simpul-simpul yang terhubung oleh sisi-sisi, yang mewakili relasi antar elemen.


## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>

using namespace std;

//Main Program
int main ()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e.+,-,*,/
    cin >> op;
    //It allow user to enter the operands
    cin >> num1 >> num2;

    //Switch statement begins
    switch(op)
    {
        //If user enter +
        case '+' :
            cout << num1 + num2;
            break;
        //If user enter -
        case '-' :
            cout << num1 - num2;
            break;
        //If user enter *
        case '*' :
            cout << num1 * num2;
            break;
        //If user enter /
        case '/' :
            cout << num1 / num2;
            break;
        //If the operator is other than +,-,* or /,
        //error message will display
        default:
            cout << "Error operator is not correct";
    } //Switch statement ends
    return 0;

}
```

#### Deskripsi Program : Program ini merupakan kalkulator sederhana yang menerima input dari pengguna berupa operator matematika (+, -, *, atau /) dan dua bilangan (num1 dan num2). Program kemudian melakukan operasi matematika sesuai dengan operator yang dimasukkan dan menampilkan hasilnya.



### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>

//Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);

    return 0;
}

```
#### Deskripsi Program : Program ini menyajikan cara menggunakan struktur untuk mengorganisir data mahasiswa dan kemudian mencetak informasi mereka ke layar. Variabel struktur memungkinkan pengelompokan data terkait dalam satu unit, memudahkan pengelolaan dan akses ke data tersebut.


### 3. [Tipe Data Koleksi]

```C++
#include <iostream>

using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama:" << nilai[0] << endl;
    cout << "Isi array kedua:" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai [2] << endl;
    cout << "Isi array keempat :" << nilai [3] << endl;
    cout << "Isi array kelima:" << nilai[4] << endl;

    return 0;

}

```
#### Deskripsi Program : Program ini memberikan contoh penggunaan array untuk menyimpan dan mengakses sejumlah nilai integer. Array menyediakan cara yang efisien untuk mengelola sekumpulan data yang serupa.



## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>

using namespace std;

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

// Function to check if a number is even or odd
bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    // Variables
    char initial = 'C';
    int age = 18;
    double height = 1.75, circleRadius = 5.5;
    bool isStudent = true;

    // Display initial
    cout << "Initial: " << initial << endl;

    // Display age
    cout << "Age: " << age << endl;

    // Display height
    cout << "Height: " << height << endl;

    // Display circle area
    cout << "Circle area: " << calculateCircleArea(circleRadius) << endl;

    // Display if student or not
    if (isStudent) {
        cout << "Is a student" << endl;
    } else {
        cout << "Is not a student" << endl;
    }

    // Display if age is even or odd
    if (isEven(age)) {
        cout << "Age is even" << endl;
    } else {
        cout << "Age is odd" << endl;
    }

    return 0;
}
```
#### Deskripsi Program : 
Program ini merupakan contoh penggunaan tipe data primitif dalam bahasa pemrograman C++. Program ini melakukan beberapa hal:

a. Mendefinisikan Fungsi:
- calculateCircleArea: Menerima jari-jari lingkaran dan mengembalikan luas lingkaran dengan menggunakan nilai PI yang telah ditentukan.
- isEven: Menerima sebuah angka dan mengembalikan true jika angka tersebut genap, dan false jika ganjil.
  
b. Mendeklarasikan dan Menginisialisasi Variabel:
- initial: Sebuah karakter yang diset sebagai 'C'.
- age: Sebuah bilangan bulat yang diset sebagai 18.
- height: Sebuah bilangan pecahan yang diset sebagai 1.75.
- circleRadius: Sebuah bilangan pecahan yang diset sebagai 5.5.
- isStudent: Sebuah nilai boolean yang diset sebagai true.
  
c. Menampilkan Nilai Variabel:
- Menampilkan nilai variabel initial, age, height, dan hasil perhitungan luas lingkaran ke layar.
- Menampilkan pesan yang menunjukkan apakah seseorang adalah seorang mahasiswa (isStudent).
- Menampilkan pesan yang menunjukkan apakah umur (age) merupakan bilangan genap atau ganjil.

Kesimpulan dari materi tipe data primitif:

Program ini menggunakan tipe data primitif seperti char, int, dan double untuk menyimpan informasi seperti nama awal, usia, tinggi badan, dan jari-jari lingkaran.

a. Fungsi calculateCircleArea menggunakan tipe data primitif double untuk mengembalikan nilai luas lingkaran.

b. Fungsi isEven menggunakan tipe data primitif int untuk menentukan apakah sebuah angka genap atau ganjil.

c. Variabel isStudent menggunakan tipe data primitif bool untuk menyimpan status apakah seseorang mahasiswa atau tidak.

Dari program ini, dapat disimpulkan bahwa tipe data primitif sangat penting dalam pemrograman karena digunakan untuk menyimpan nilai-nilai dasar dan melakukan operasi matematika sederhana. Penggunaan tipe data primitif memungkinkan program untuk melakukan berbagai macam tugas, seperti menghitung luas lingkaran, mengecek apakah sebuah angka genap atau ganjil, dan lain sebagainya.


#### Output:![Screenshot (23)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f3853460-f60d-4284-a25d-e276938cc642)

#### Full code Screenshot:![Screenshot (24)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/12dc4d35-7ea8-46dd-a620-9af6d4808c58)![Screenshot (25)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/91993ceb-5fb1-43ae-bbbe-564f274bdfa5)

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]
```C++
#include <iostream>
#include <string>

using namespace std;

// Struct to represent an address
struct Address {
    string street;
    string city;
    string state;
    string zipCode;
};

// Class to represent a person
class Person {
public:
    // Member data
    string name;
    int age;
    Address address;

    // Member function to display information
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address.street << ", " << address.city << ", "
             << address.state << " " << address.zipCode << "\n";
    }
};

int main() {
    // Create a Person object
    Person person;

    // Set the member data of the Person object
    person.name = "Na Jae-min";
    person.age = 24;
    person.address.street = "423,Apgujjeong-ro, Gangnam-gu";
    person.address.city = "Seoul";
    person.address.state = "NJ";
    person.address.zipCode = "130700";

    // Call the method to display information
    person.displayInfo();

    return 0;
}
```
#### Jawaban :

Class: Dalam konteks pemrograman berorientasi objek, "class" adalah struktur data yang dapat mencakup data anggota (atribut) dan fungsi anggota (metode) yang bersifat terkait. Ini adalah sebuah template untuk membuat objek yang memiliki sifat dan perilaku yang sama. Dalam "Data Structures and Algorithm Analysis in C++", kelas-kelas mungkin digunakan untuk mewakili struktur data seperti list, tumpukan, antrian, dan sebagainya. Metode yang terkait dengan kelas-kelas ini mungkin menerapkan algoritma tertentu untuk berbagai operasi yang terkait dengan struktur data tersebut.[2]

Struct: "Struct" adalah struktur data sederhana yang terdiri dari satu atau lebih tipe data yang dikelompokkan bersama. Dalam C++, "struct" mirip dengan "class", namun perbedaannya terletak pada hak akses default. Secara default, anggota dari sebuah "struct" adalah publik, sedangkan dalam sebuah "class", anggota tersebut secara default adalah private. Dalam buku ini, "struct" mungkin digunakan untuk merepresentasikan struktur data yang lebih sederhana atau sebagai bagian dari implementasi dari struktur data yang lebih kompleks.[2]

Class:

Class adalah struktur data yang mendefinisikan sebuah tipe baru yang terdiri dari data dan fungsi-fungsi yang beroperasi pada data tersebut.
- Dalam sebuah class, data-dan-fungsi dapat dikelompokkan bersama untuk merepresentasikan sebuah objek atau konsep yang lebih kompleks.
- Class menyediakan cara untuk menerapkan konsep pemrograman berorientasi objek (OOP), yang menggabungkan data dan operasi pada data tersebut menjadi satu kesatuan yang disebut sebagai objek.
- Data dalam sebuah class biasanya dideklarasikan sebagai variabel-variabel anggota (member variables) dan fungsi-fungsi yang bekerja pada data tersebut disebut sebagai metode-metode (methods).
- Class memungkinkan untuk melakukan enkapsulasi, yaitu menyembunyikan rincian implementasi internal dari luar, sehingga hanya metode-metode yang dapat diakses dari luar.

Struct:

Struct adalah tipe data yang dapat menyimpan sekumpulan data dengan tipe-tipe yang berbeda dalam satu unit.
- Dalam struct, setiap anggota data disebut dengan nama field atau variabel, dan setiap field dapat memiliki tipe data yang berbeda.
- Secara umum, struct digunakan untuk mengelompokkan data terkait bersama-sama untuk mewakili sebuah konsep atau objek.
- Struct biasanya tidak memiliki metode-metode yang terkait langsung dengan data yang disimpan di dalamnya, meskipun beberapa bahasa pemrograman seperti C++ mengizinkan penambahan metode ke dalam struct.
- Pada dasarnya, struct adalah konstruksi yang lebih sederhana dibandingkan dengan class, tetapi dapat digunakan untuk tujuan yang serupa, terutama dalam bahasa pemrograman seperti C.
  
#### Output:![Screenshot (28)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/189e2506-590c-4725-b1cb-f5815342744f)

#### Deskripsi Program :  Program ini merupakan contoh implementasi dari konsep struktur (struct) dan class dalam bahasa pemrograman C++. 

- Deklarasi Struktur (Struct) Address:
Struktur Address digunakan untuk merepresentasikan alamat seseorang.
Struktur ini memiliki empat anggota: street, city, state, dan zipCode, yang semuanya bertipe string.

- Deklarasi Class Person:
Class Person digunakan untuk merepresentasikan individu.
Class ini memiliki beberapa anggota data, antara lain:
name: Untuk menyimpan nama orang.
age: Untuk menyimpan usia orang.
address: Objek dari struktur Address, untuk menyimpan alamat orang.
Class ini juga memiliki sebuah metode displayInfo() untuk menampilkan informasi tentang seseorang, termasuk nama, usia, dan alamatnya.
Fungsi main():

- Di dalam fungsi main(), sebuah objek person dari kelas Person dibuat.
Kemudian, data anggota dari objek tersebut diatur menggunakan operator titik (.) untuk mengakses anggota data dan objek struktur dalam objek person.
Terakhir, metode displayInfo() dipanggil untuk menampilkan informasi tentang orang tersebut di layar.

- Output:
Program akan mencetak informasi tentang orang yang direpresentasikan oleh objek person ke layar.
Program ini menunjukkan cara menggunakan struktur dan class dalam C++ untuk menyusun data dengan lebih terstruktur dan membentuk entitas yang lebih kompleks seperti orang dengan nama, usia, dan alamat. Ini memanfaatkan konsep enkapsulasi dan abstraksi untuk membuat representasi yang lebih bersih dan lebih mudah dipelihara.


#### Full code Screenshot:![Screenshot (26)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/009be6c4-2bea-4400-a170-c6fe6acabfd6) ![Screenshot (27)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/405354df-1df9-486d-b7f9-d1b9caf25bd0)

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map object with string as key and int as value
    map<string, int> employeeAges;

    // Add entries to the map
    employeeAges["Alice"] = 25;
    employeeAges["Bob"] = 30;
    employeeAges["Charlie"] = 28;

    // Display the ages of employees
    cout << "Alice's age: " << employeeAges["Alice"] << " years" << endl;
    cout << "Bob's age: " << employeeAges["Bob"] << " years" << endl;
    cout << "Charlie's age: " << employeeAges["Charlie"] << " years" << endl;

    // Use an iterator to print the entire map
    cout << "\nPrinting the entire map:\n";
    for (auto it = employeeAges.begin(); it != employeeAges.end(); ++it) {
        cout << "Name: " << it->first << ", Age: " << it->second << " years" << endl;
    }

    return 0;
}

```
#### Jawaban :

Perbedaan antara array dan map :

- Array:

Merupakan struktur data yang menyimpan elemen-elemen dengan tipe data yang sama dalam urutan terindeks.
Memiliki akses yang cepat ke elemen-elemen berdasarkan indeksnya.
Ukuran array biasanya tetap dan harus ditentukan saat deklarasi.
Pengaksesan elemen dalam array memiliki kompleksitas waktu O(1) karena dapat diakses secara langsung melalui indeksnya.[3]

- Map:

Merupakan struktur data yang memetakan kunci (key) ke nilai (value) yang terkait.
Dapat menyimpan data dengan tipe data yang berbeda untuk kunci dan nilai.
Ukuran map dapat berubah secara dinamis sesuai dengan penambahan atau penghapusan elemen.
Pengaksesan elemen dalam map biasanya memiliki kompleksitas waktu O(log n) atau O(1), tergantung pada implementasi, karena memerlukan pencarian berbasis kunci.
Dalam konteks algoritma dan struktur data, array sering digunakan untuk penyimpanan data yang sederhana dan memiliki akses yang cepat berdasarkan indeksnya. Sementara itu, map digunakan ketika diperlukan asosiasi antara kunci dan nilai, dan ketika pencarian atau pengaksesan data berdasarkan kunci menjadi penting.[3]



Perbedaan utama antara array dan map terletak pada cara data disimpan dan diakses, serta kemampuan dan kegunaan masing-masing struktur data. diantara lain yaitu :

a. Struktur Data:

- Array: Array adalah struktur data linear yang menyimpan kumpulan elemen dengan tipe data yang sama secara berurutan dalam memori. Setiap elemen diakses menggunakan indeks numerik yang berurutan, dimulai dari 0.
- Map: Map adalah struktur data asosiatif yang menyimpan kumpulan pasangan kunci-nilai (key-value pairs). Setiap elemen memiliki sebuah kunci yang unik dan terkait dengan sebuah nilai. Data dalam map tidak disimpan secara berurutan dalam memori.

b. Akses Data:

- Array: Akses ke elemen-elemen array dilakukan dengan menggunakan indeks numerik. Indeks ini mengidentifikasi posisi relatif dari setiap elemen dalam array.
- Map: Akses ke elemen-elemen map dilakukan dengan menggunakan kunci (key) yang unik. Kunci digunakan untuk mengidentifikasi nilai yang terkait.

c. Penambahan dan Penghapusan Elemen:

- Array: Untuk menambah atau menghapus elemen dalam array, seringkali memerlukan realokasi memori dan penggeseran elemen-elemen lainnya.
- Map: Penambahan dan penghapusan elemen dalam map biasanya lebih efisien karena tidak memerlukan realokasi memori atau penggeseran elemen lainnya.

d. Kemampuan Pencarian:

- Array: Pencarian dalam array dapat dilakukan dengan melakukan iterasi secara linear atau menggunakan algoritma pencarian yang lebih efisien jika array terurut.
- Map: Pencarian dalam map biasanya dilakukan secara lebih efisien dengan menggunakan struktur data internal yang disebut sebagai tabel hash atau pohon pencarian biner (binary search tree).

e. Kemampuan untuk Menangani Kunci Duplikat:

- Array: Dalam array, kunci tidak diperlukan karena akses dilakukan menggunakan indeks numerik. Oleh karena itu, konsep kunci duplikat tidak berlaku.
- Map: Map dapat menangani kunci duplikat dengan cara mengganti nilai yang terkait dengan kunci yang sama atau menggunakan struktur data yang mendukung kunci duplikat, seperti multimap.

f. Kompleksitas Waktu Operasi:

- Array: Operasi dasar seperti akses, penambahan, atau penghapusan pada array memiliki kompleksitas waktu O(1) untuk akses (jika indeks diketahui), namun O(n) untuk penambahan atau penghapusan (jika perlu realokasi memori).
- Map: Operasi dasar seperti akses, penambahan, atau penghapusan pada map memiliki kompleksitas waktu yang bergantung pada struktur data internal yang digunakan. Namun, dalam banyak kasus, map dapat memberikan kompleksitas waktu rata-rata O(1) untuk operasi dasar ini.

#### Output: ![Screenshot (29)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/552035c0-7278-4fcf-b969-ea9463a6bfb6)

#### Deskripsi Program : Program ini merupakan contoh penggunaan struktur data map dalam bahasa pemrograman C++. 

- Penggunaan Library:
Program menggunakan beberapa library standar C++, yaitu <iostream> untuk input-output standar, <map> untuk struktur data map, dan <string> untuk menggunakan tipe data string.

- Deklarasi dan Penggunaan Map:
Sebuah objek map bernama employeeAges dideklarasikan dengan menggunakan map<string, int>. Ini berarti bahwa map memiliki string sebagai kunci (key) dan int sebagai nilai (value).
Beberapa entri ditambahkan ke dalam map menggunakan operator indeks ([]). Ini mengaitkan nama karyawan dengan usia mereka.

- Menampilkan Usia Karyawan:
Usia setiap karyawan kemudian ditampilkan ke layar menggunakan cout. Penggunaan operator[] pada map memungkinkan kita untuk mengakses nilai berdasarkan kuncinya.

- Menampilkan Seluruh Map Menggunakan Iterator:
Sebuah iterator (it) digunakan untuk mengakses setiap elemen dalam map.
Sebuah loop for digunakan untuk mengiterasi melalui setiap elemen dalam map, dari awal (begin()) hingga akhir (end()).
Dalam setiap iterasi, nama karyawan dan usianya ditampilkan ke layar.

- Output:
Program akan mencetak usia setiap karyawan ke layar, kemudian mencetak seluruh map yang berisi nama karyawan dan usia mereka.
Program ini menunjukkan bagaimana struktur data map dapat digunakan untuk mengaitkan kunci dengan nilai dan bagaimana mengakses dan mengiterasi melalui entri-entri dalam map menggunakan iterator. 

#### Full code Screenshot: ![Screenshot (30)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1a1c914e-86c5-4208-924c-25e0edb0d2e3)

## Kesimpulan :
Kesimpulan yang dapat saya ambil dari pembelajaran ini yaitu :

- Struktur Data Mengorganisasikan Data:
Struktur data membantu kita mengatur data dengan baik sehingga logika program menjadi lebih terstruktur. Dengan demikian, program menjadi lebih mudah dipahami dan dipelihara.

- Memahami Pengertian dan Langkah-langkah Pembuatan Program:
Melalui pembelajaran struktur data, kita belajar tentang pengertian struktur data, langkah-langkah pembuatan program, dan berbagai tipe data yang dapat digunakan dalam pemrograman.

- Pemilihan Struktur Data yang Tepat:
Pemilihan struktur data yang tepat dalam pemrograman sangat penting. Struktur data yang sesuai akan menghasilkan algoritma yang jelas dan tepat, sehingga membuat program menjadi lebih sederhana dan efisien.

- Peran Array dalam Struktur Data:
Array adalah salah satu jenis struktur data yang sederhana, yang membantu dalam penyimpanan data dalam urutan tertentu di lokasi memori komputer. Penggunaan array secara tepat dapat meningkatkan efisiensi program.

Dengan memahami konsep struktur data dan mengaplikasikannya dengan baik, maka dapat menghasilkan algoritma yang efektif dan program yang lebih baik secara keseluruhan. 

## Referensi
[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," The MIT Press, 2009.

[2] Weiss, M. A., "Data Structures and Algorithm Analysis in C++," The Institute of Electrical and Electronics Engineers (IEEE), 2014.

[3] Mehlhorn, K. dan Sanders, P., "Algorithms and Data Structures: The Basic Toolbox," The Institute of Electrical and Electronics Engineers (IEEE), 2008.
