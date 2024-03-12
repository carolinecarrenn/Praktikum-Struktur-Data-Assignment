# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Caroline Carren</p>

## Dasar Teori

Tipe data adalah konsep dasar dalam ilmu komputer yang menggambarkan jenis nilai yang dapat disimpan dan dioperasikan oleh suatu program komputer. Dalam konteks struktur data dan algoritma, pemahaman yang baik tentang tipe data sangat penting untuk merancang algoritma yang efisien dan efektif. Berikut adalah beberapa dasar teori tentang tipe data:

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
Deskripsi Program : Program ini merupakan kalkulator sederhana yang menerima input dari pengguna berupa operator matematika (+, -, *, atau /) dan dua bilangan (num1 dan num2). 
Program kemudian melakukan operasi matematika sesuai dengan operator yang dimasukkan dan menampilkan hasilnya.
```

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
Deskripsi Program : Program ini menyajikan cara menggunakan struktur untuk mengorganisir data mahasiswa dan kemudian mencetak informasi mereka ke layar. Variabel struktur memungkinkan pengelompokan data terkait dalam satu unit, memudahkan pengelolaan dan akses ke data tersebut.

```
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
Deskripsi Program : Program ini memberikan contoh penggunaan array untuk menyimpan dan mengakses sejumlah nilai integer. Array menyediakan cara yang efisien untuk mengelola sekumpulan data yang serupa.

```

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
#### Output:

#### Full code Screenshot:

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
#### Output:

#### Full code Screenshot:

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
#### Output:

#### Full code Screenshot:

## Kesimpulan

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). "Introduction to Algorithms." The MIT Press.

