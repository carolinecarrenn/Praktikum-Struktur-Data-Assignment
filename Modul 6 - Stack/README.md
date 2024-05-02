# <h1 align="center">Laporan Praktikum Modul Stack </h1>
<p align="center">Caroline Carren Aurelia R</p>
<p align="center">2311102174</p>
<p align="center">IF 11 E</p>

## Tujuan Praktikum 
1. Mampu memahami konsep stack pada struktur data dan algoritma
2. Mampu mengimplementasikan operasi-operasi pada stack
3. Mampu memecahkan permasalahan dengan solusi stack

## Dasar Teori

![stack](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/dcffbdd8-02a5-4755-839a-0b564ce20012)

Stack adalah struktur data yang bersifat linier dan mengikuti prinsip Last In First Out (LIFO). 
Artinya, elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan.
Operasi dasar pada stack meliputi push (menambahkan elemen ke stack) dan pop (mengeluarkan elemen dari stack).[1]

Stack biasanya digunakan dalam penyelesaian masalah rekursif, pelacakan pemanggilan fungsi dalam program, dan dalam evaluasi ekspresi matematika.[1]

Implementasi stack dapat dilakukan menggunakan array atau linked list. Dalam implementasi menggunakan array, kita harus memperhatikan overflow ketika stack penuh. 
Sedangkan dalam implementasi menggunakan linked list, kita perlu memperhatikan alokasi dan dealokasi memori untuk setiap elemen stack.[1]

### Operasi Dasar Pada Stack
1. Create
   
   Operasi untuk membuat sebuah stack kosong. [1]
   
   ```C++
   struct Stack {
   int top;
   float data[n];
   } tumpukan;
   ```
   
3. initStack
   
   Operasi untuk menginisialisasikan nilai awal stack (stack kosong) [1]
   
   ```C++
   bool initStack(){
   Tumpukan.top = -1
   }
   ```
4. isEmpty
   
   Operasi untuk memeriksa apakah suatu stack masih kosong.. Stack kosong ditandai dengan nilai Top kurang dari nol (-1) [1]
   
   ```C++
   int isEmpty(){
    if (Tumpukan.top == -1)
   return 1; //true
   else
   return 0; //false
   }
   ```
5. isFull
   
   Operasi untuk memeriksa apakah stack yang ada sudah penuh. Stack akan mengindikasikan penuh jika puncak stack (top) terletak tepat di bawah jumlah maksimum (MAX) yang dapat ditampung stack.[1]
   
   ```C++
   int isFull(){
    if (Tumpukan.top == MAX-1) return 1; //true
   return 0; //false else
   }
   ```
6. Push (insert)
   
   Operasi untuk menambahkan satu elemen ke dalam stack dan tidak dapat dilakukan jika stack dalam keadaan penuh[1]
   
   ```C++
   void push (int data){
   if (isEmpty() == 1){
   Tumpukan.top++;
   Tumpukan.data[Tumpukan.top] = Data;
   }
   else if (isFull() == 0){
   Tumpukan.top++;
   Tumpukan.data[Tumpukan.top] = Data;
   } else{
      cout << "Stack sudah penuh!";
   }
   }
   ```
7. Pop

   Operasi untuk mengambil atau menghapus data teratas (top) dari stack.[1]
   
   ```C++
   void pop() {
   if (isEmpty() == 0){ myStack.top--;
   cout << " Data teratas terambil" << endl;
   } else{
   cout << " Stack masih kosong!" << endl;
   }
   }
   ```
8. Clear
   
   Operasi untuk menghapus atau mengosongkan seluruh data stack. Jika Top bernilai -1 maka stack dianggap kosong.[1]
   
   ```C++
   void clear() {
    top = -1;
   }
   ```
9. Display
   
   Operasi untuk menampilkan seluruh data stack.[1]
   
   ```C++
   void display(){
   if (isEmpty() == 0){
   for (int i=Tumpukan.top; i>=0; i--) {
   cout << Tumpukan.data[i] << endl;
   }
   } else{
    cout << "Stack masih kosong!" << endl;
   }
   }
   ```
   
## Guided 

### 1. [Implementasi Stack]

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull() {
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return (top == 0);
}

// Fungsi untuk menambahkan data ke dalam stack
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

// Fungsi untuk menghapus data dari stack
void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = ' ';
        top--;
    }
}

// Fungsi untuk melihat data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang dapat dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data dalam stack
int countStack() {
    return top;
}

// Fungsi untuk mengubah data pada posisi tertentu dalam stack
void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

// Fungsi untuk menghapus semua data dalam stack
void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

// Fungsi untuk mencetak semua data dalam stack
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang di cetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    // Memasukkan beberapa data ke dalam stack
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Mencetak semua data dalam stack
    cetakArrayBuku();

    cout << "\n" << endl;
    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    // Melihat data pada posisi ke-2 dalam stack
    peekArrayBuku(2);

    // Menghapus data dari stack
    popArrayBuku();

    // Menghitung jumlah data dalam stack
    cout << "banyaknya data = " << countStack() << endl;

    // Mengubah data pada posisi ke-2 dalam stack
    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n" << endl;

    // Menghapus semua data dalam stack
    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus : " << top << endl;

    // Mencetak semua data dalam stack setelah dihapus
    cetakArrayBuku();

    return 0;
}
```
#### Output :
![Screenshot 2024-05-02 154702](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/02b080d8-18ff-4a1e-b064-cf6d5f792aeb)

#### Deskripsi Program : 
Program ini adalah implementasi sederhana dari struktur data stack menggunakan array dalam bahasa pemrograman C++. 
Stack adalah struktur data yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dihapus.

Program ini memiliki beberapa fungsi dasar untuk mengelola stack:

1. `isFull()`: Fungsi untuk mengecek apakah stack sudah penuh.
2. `isEmpty()`: Fungsi untuk mengecek apakah stack kosong.
3. `pushArrayBuku(string data)`: Fungsi untuk menambahkan data ke dalam stack.
4. `popArrayBuku()`: Fungsi untuk menghapus data dari stack.
5. `peekArrayBuku(int posisi)`: Fungsi untuk melihat data pada posisi tertentu dalam stack.
6. `countStack()`: Fungsi untuk menghitung jumlah data dalam stack.
7. `chargeArrayBuku(int posisi, string data)`: Fungsi untuk mengubah data pada posisi tertentu dalam stack.
8. `destroyArrayBuku()`: Fungsi untuk menghapus semua data dalam stack.
9. `cetakArrayBuku()`: Fungsi untuk mencetak semua data dalam stack.

Pada bagian `main()`, program melakukan beberapa operasi pada stack yang telah dibuat, seperti memasukkan data, mencetak data, mengubah data, menghapus data, dan lain-lain. 
Setiap operasi ini mengilustrasikan penggunaan fungsi-fungsi yang telah didefinisikan sebelumnya untuk mengelola stack.

### Full code Screenshot:
![carbon](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/57b819ca-d146-4d1c-baa4-684cc409561d)


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    Stack() {
        head = NULL;  // Menginisialisasi head dengan NULL
        tail = NULL;  // Menginisialisasi tail dengan NULL
        size = 0;     // Menginisialisasi size dengan 0
    }

    void push(char a) {
        node* tmp = new node;  // Membuat node baru
        tmp->data = a;          // Mengisi data node dengan karakter a
        tmp->next = NULL;       // Mengatur pointer next node menjadi NULL
        if (size == 0) {        // Jika stack kosong
            head = tmp;         // Atur head dan tail menjadi node baru
            tail = tmp;
            tail->prev = NULL;  // Mengatur pointer prev node menjadi NULL
        } else {                // Jika stack tidak kosong
            tail->next = tmp;   // Sambungkan node baru ke node terakhir
            tmp->prev = tail;   // Mengatur pointer prev node baru ke node terakhir
            tail = tmp;         // Atur tail menjadi node baru
        }
        size++;  // Menambahkan ukuran stack
    }

    char pop() {
        char data;  // Variabel untuk menyimpan data node yang akan dihapus
        if (head == tail) {  // Jika stack hanya memiliki satu elemen
            data = tail->data;  // Mengambil data dari node terakhir
            delete head;        // Menghapus node terakhir
            head = NULL;        // Mengatur head dan tail menjadi NULL
            tail = NULL;
            size--;             // Mengurangi ukuran stack
        } else {                // Jika stack memiliki lebih dari satu elemen
            node* tmp = tail;   // Mengambil node terakhir sebagai tmp
            tail = tail->prev;  // Mengatur tail menjadi node sebelumnya
            tail->next = NULL;  // Mengatur pointer next node menjadi NULL
            data = tmp->data;   // Mengambil data dari node yang dihapus
            delete tmp;         // Menghapus node yang dihapus
            size--;             // Mengurangi ukuran stack
        }
        return data;  // Mengembalikan data dari node yang dihapus
    }

private:
    struct node {
        char data;   // Menyimpan karakter
        node* next;  // Pointer ke node berikutnya
        node* prev;  // Pointer ke node sebelumnya
    };

    node* head;  // Pointer ke node pertama dalam stack
    node* tail;  // Pointer ke node terakhir dalam stack
    int size;    // Jumlah node dalam stack
};

int main() {
    Stack s;                     // Membuat objek Stack
    string sentence;             // Variabel untuk menyimpan kalimat
    bool isPalindrome = true;    // Variabel untuk menentukan apakah kalimat merupakan palindrom

    cout << "Masukkan kalimat: ";  // Menampilkan pesan kepada pengguna
    getline(cin, sentence);        // Mengambil input kalimat dari pengguna

    for (char c : sentence) {    // Untuk setiap karakter dalam kalimat
        s.push(c);               // Memasukkan karakter ke dalam stack
    }

    for (char c : sentence) {    // Untuk setiap karakter dalam kalimat
        if (s.pop() != c) {      // Jika karakter yang di-pop dari stack tidak sama dengan karakter dari kalimat
            isPalindrome = false;  // Set isPalindrome menjadi false
            break;                // Keluar dari loop
        }
    }

    if (isPalindrome) {          // Jika isPalindrome masih true
        cout << "Kalimat tersebut adalah palindrom." << endl;  // Menampilkan pesan bahwa kalimat adalah palindrom
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;  // Menampilkan pesan bahwa kalimat bukan palindrom
    }

    return 0;
}

```

### Output:
#### Contoh Kata Palindrom :
![Screenshot 2024-05-02 154723](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/60397a0d-a0e6-49b8-8e7d-dab72a7dbd16)

#### Contoh Kata Bukan Palindrom :
![Screenshot 2024-05-02 154733](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/687b9194-5c1c-4842-9415-729cfbac3958)

### Deskripsi Program : 
Program ini adalah implementasi dari struktur data stack menggunakan linked list dalam bahasa pemrograman C++. 
Program ini bertujuan untuk mengecek apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak.

Kelas `Stack` memiliki atribut private berupa node yang berisi data karakter, pointer ke node berikutnya (`next`), dan pointer ke node sebelumnya (`prev`). Kelas ini memiliki beberapa fungsi, antara lain:

- Konstruktor `Stack()`: Untuk menginisialisasi stack dengan mengatur `head` dan `tail` menjadi `NULL`, serta `size` menjadi 0.
- `push(char a)`: Untuk menambahkan karakter `a` ke dalam stack. Jika stack kosong, maka `head` dan `tail` akan menunjuk ke node baru. Jika tidak, maka node baru akan ditambahkan sebagai `tail`.
- `pop()`: Untuk menghapus dan mengembalikan karakter dari stack. Jika stack hanya memiliki satu elemen, maka `head` dan `tail` akan diatur menjadi `NULL`. Jika tidak, maka `tail` akan diubah menjadi node sebelumnya.
- `isPalindrome()`: Untuk mengecek apakah sebuah kalimat merupakan palindrom atau tidak. Program menggunakan stack untuk menyimpan karakter-karakter kalimat, kemudian membandingkan setiap karakter dari awal dan akhir kalimat. Jika karakternya sama untuk setiap pasangan, maka kalimat tersebut merupakan palindrom.

Pada `main()`, program akan meminta pengguna memasukkan sebuah kalimat. Setiap karakter dari kalimat tersebut akan dimasukkan ke dalam stack. 
Setelah itu, program akan membandingkan setiap karakter dari awal dan akhir kalimat dengan menghapus karakter dari stack. 
Jika semua karakter cocok, maka program akan mencetak bahwa kalimat tersebut adalah palindrom. 
Jika tidak, maka program akan mencetak bahwa kalimat tersebut bukan palindrom.

### Full code Screenshot:
![carbon (1)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/99a41421-74f0-4f2e-84ee-b51c76e5a1f8)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk melakukan pembalikan kalimat menggunakan stack
string balikKalimat(string kalimat) {
    stack<char> tumpukan; // Menggunakan stack dari library <stack>

    // Memasukkan karakter kalimat ke dalam tumpukan
    for (char c : kalimat) {
        tumpukan.push(c);
    }

    string terbalik = ""; // Variabel untuk menyimpan kalimat yang sudah dibalik

    // Mengambil karakter dari tumpukan dan membentuk kalimat yang sudah dibalik
    while (!tumpukan.empty()) {
        terbalik += tumpukan.top();
        tumpukan.pop();
    }

    return terbalik; // Mengembalikan kalimat yang sudah dibalik
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat); // Meminta pengguna untuk memasukkan kalimat

    string terbalik = balikKalimat(kalimat); // Memanggil fungsi untuk melakukan pembalikan kalimat
    cout << "Kalimat yang sudah dibalik: " << terbalik << endl;

    return 0;
}
```
### Output:
![Screenshot 2024-05-02 154754](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/443c5a7a-63b7-470c-8fbe-59a3d2212dd2)

### Deskripsi Program : 
Program ini adalah implementasi sederhana dari pembalikan kalimat menggunakan stack dalam bahasa pemrograman C++. 
Program ini memanfaatkan struktur data stack dari library `<stack>` untuk melakukan pembalikan.

Pada `main()`, program meminta pengguna untuk memasukkan sebuah kalimat. 
Kemudian, program memanggil fungsi `balikKalimat()` untuk membalikkan kalimat yang dimasukkan pengguna. 
Fungsi `balikKalimat()` bekerja dengan cara memasukkan setiap karakter kalimat ke dalam stack, lalu mengambil karakter-karakter tersebut dari stack untuk membentuk kalimat yang sudah dibalik.

Setelah proses pembalikan selesai, program akan mencetak kalimat yang sudah dibalik ke layar.

### Full code Screenshot:
![carbon (2)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/fe560309-d7e3-4a72-95f0-158534cc7f6f)

## Kesimpulan
Kesimpulan yang dapat di ambil yaitu : 
- Konsep Stack: Stack adalah struktur data yang mengikuti prinsip Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dihapus.
- Operasi Stack: Operasi dasar pada stack meliputi push (menambahkan elemen ke dalam stack), pop (menghapus elemen dari stack), dan peek (melihat elemen teratas tanpa menghapusnya).
- Implementasi Stack: Stack dapat diimplementasikan menggunakan array atau linked list. Pemilihan implementasi tergantung pada kebutuhan dan kompleksitas operasi yang akan dilakukan.
- Aplikasi Stack: Stack digunakan dalam berbagai aplikasi, seperti dalam proses parsing ekspresi matematika, evaluasi ekspresi postfix, penanganan fungsi rekursif, manajemen pemanggilan fungsi (call stack), dan lain-lain.
- Keuntungan Stack: Penggunaan stack memungkinkan penanganan data secara efisien dalam beberapa kasus, seperti penanganan fungsi rekursif, undo/redo dalam aplikasi, dan sebagainya.
- Pentingnya Pemahaman Konsep: Pemahaman konsep dasar stack sangat penting dalam pengembangan perangkat lunak karena banyak algoritma dan struktur data lain yang bergantung pada konsep LIFO yang dimiliki oleh stack.

## Referensi
[1] Adam Drozdek, "Data Structures and Algorithms in C++," 2nd ed. Boston, MA: Cengage Learning, 2012.
