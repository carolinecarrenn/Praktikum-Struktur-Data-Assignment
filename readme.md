# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">caroline carren</p>

## Dasar Teori

Tipe data adalah konsep dasar dalam ilmu komputer yang menggambarkan jenis nilai yang dapat disimpan dan dioperasikan oleh suatu program komputer. Dalam konteks struktur data dan algoritma, pemahaman yang baik tentang tipe data sangat penting untuk merancang algoritma yang efisien dan efektif. Berikut adalah beberapa dasar teori tentang tipe data:

Tipe Data Dasar:

Integer: Menyimpan bilangan bulat. Misalnya, int pada banyak bahasa pemrograman.
Float/Double: Menyimpan bilangan desimal. Misalnya, float atau double.
Character: Menyimpan karakter. Misalnya, char.
Tipe Data Struktur:

Array: Struktur data yang menyimpan elemen-elemen dengan tipe data yang sama, dan setiap elemen dapat diakses dengan menggunakan indeks.
Struct/Record: Gabungan dari beberapa tipe data yang berbeda dalam satu struktur. Misalnya, dalam C, kita bisa mendefinisikan struct untuk menggabungkan beberapa variabel dengan tipe data yang berbeda.
Union: Struktur data yang memungkinkan penyimpanan lebih dari satu tipe data dalam satu lokasi memori, tetapi hanya satu tipe data yang bisa diakses pada satu waktu.
Tipe Data Abstrak:

Queue: Antrian data yang mengikuti prinsip FIFO (First In, First Out).
Stack: Tumpukan data yang mengikuti prinsip LIFO (Last In, First Out).
Linked List: Kumpulan elemen data yang terhubung melalui node-node, masing-masing memiliki dua bagian: data dan referensi/pointer ke node berikutnya.
Tree: Struktur hirarkis dengan satu simpul sebagai simpul atas atau akar, dan simpul lainnya dibagi menjadi sub-pohon.
Graph: Struktur data yang terdiri dari simpul-simpul yang terhubung oleh sisi-sisi, yang mewakili relasi antar elemen.


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
Program ini merupakan kalkulator sederhana yang menerima input dari pengguna berupa operator matematika (+, -, *, atau /) dan dua bilangan (num1 dan num2). 
Program kemudian melakukan operasi matematika sesuai dengan operator yang dimasukkan dan menampilkan hasilnya.
