# <h1 align="center">Laporan Praktikum Modul Queue </h1>
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
1. Mahasiswa dapat memahami Konsep Antrian
2. Mahasiswa dapat mengimplementasikan Antrian
3. Mahasiswa dapat memahami Operasi Antrian
4. Mahasiswa dapat mengoptimalkan Penggunaan Memori

## Dasar Teori
   ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/542949fa-86f2-4b76-a061-5ed687fb6d30)

   Queue adalah struktur data yang mengikuti prinsip "First In, First Out" (FIFO), yang berarti elemen pertama yang dimasukkan ke dalam antrian adalah yang pertama keluar.[1]
   
### Operasi Dasar Pada Queue
- `enqueue(item)`: Menambahkan item ke dalam antrian.
- `dequeue()`: Menghapus item dari antrian dan mengembalikan nilainya.
- `peek()`: Mengembalikan nilai item yang paling depan tanpa menghapusnya.
- `isEmpty()`: Memeriksa apakah antrian kosong.
- `isFull()`: Memeriksa apakah antrian penuh (pada implementasi yang menggunakan ukuran terbatas).[1]

### Implementasi Queue:

- Array-based:
  
Menggunakan array untuk menyimpan elemen-elemen queue. Perlu memperhatikan penyesuaian indeks saat enqueue dan dequeue untuk memastikan FIFO.

- Linked List-based:
  
Menggunakan linked list untuk menyimpan elemen-elemen queue. Enqueue dilakukan pada ujung belakang linked list, dan dequeue dilakukan pada ujung depan linked list.

- Queue Kosong dan Penuh:
  
Queue dikatakan kosong jika tidak ada elemen di dalamnya.

Queue dikatakan penuh jika tidak ada tempat kosong untuk menambahkan elemen baru (pada implementasi menggunakan array dengan ukuran tetap).[1]

### Aplikasi Queue:

- Antrian dalam pemrosesan data (misalnya, penjadwalan CPU).
- Antrian dalam simulasi (misalnya, simulasi antrian di bank).
- Penanganan request (misalnya, antrian pesan pada aplikasi komunikasi).
- Buffering dalam komunikasi data.[1]

## Guided 

### 1. [Implementasi Queue]
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosongqueueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```
#### Output :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/87f3b75d-fae3-4105-a6a7-a9864998f2a6)

#### Deskripsi Program : 
Program ini adalah implementasi sederhana dari struktur data antrian (queue) menggunakan array. 
Program ini memiliki fungsi-fungsi dasar untuk mengelola antrian, yaitu:

- `isFull()`: Untuk mengecek apakah antrian sudah penuh atau belum.
- `isEmpty()`: Untuk mengecek apakah antrian kosong atau tidak.
- `enqueueAntrian(string data)`: Untuk menambahkan data ke dalam antrian. Jika antrian penuh, akan ditampilkan pesan "Antrian penuh".
- `dequeueAntrian()`: Untuk mengeluarkan data dari antrian. Jika antrian kosong, akan ditampilkan pesan "Antrian kosong".
- `countQueue()`: Untuk menghitung jumlah data dalam antrian.
- `clearQueue()`: Untuk menghapus semua data dalam antrian.
- `viewQueue()`: Untuk menampilkan data dalam antrian.

Pada `main()`, program melakukan beberapa operasi pada antrian, yaitu:

- Menambahkan data "Andi" dan "Maya" ke dalam antrian.
- Menampilkan isi antrian dan jumlah antrian.
- Mengeluarkan satu data dari antrian.
- Menampilkan isi antrian dan jumlah antrian setelah pengeluaran.
- Menghapus semua data dalam antrian.
- Menampilkan isi antrian dan jumlah antrian setelah penghapusan.
  
Dengan demikian, program ini dapat digunakan untuk simulasi antrian sederhana dengan batasan jumlah maksimal antrian.

### Full code Screenshot:
![carbon](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/be398612-acb6-43d4-960f-fecf5f3dce1a)


## Unguided 

### 1. . Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data dan pointer ke Node selanjutnya
struct Node {
    string data;
    Node* next;
};

// Kelas Queue untuk mengimplementasikan antrian menggunakan linked list
class Queue {
private:
    Node* front; // Penanda elemen depan antrian
    Node* back; // Penanda elemen belakang antrian
    int size; // Jumlah elemen dalam antrian

public:
    // Konstruktor untuk inisialisasi antrian kosong
    Queue() : front(nullptr), back(nullptr), size(0) {}

    // Memeriksa apakah antrian kosong
    bool isEmpty() {
        return size == 0;
    }

    // Memeriksa apakah antrian penuh (sudah mencapai ukuran maksimum)
    bool isFull() {
        return size == 5; // Maksimal ukuran antrian
    }

    // Menambahkan elemen baru ke belakang antrian
    void enqueue(string data) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }

        Node* newNode = new Node(); // Membuat node baru
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) { // Jika antrian kosong, elemen baru menjadi front dan back
            front = newNode;
            back = newNode;
        } else { // Jika tidak, elemen baru ditambahkan ke belakang dan back diperbarui
            back->next = newNode;
            back = newNode;
        }

        size++; // Menambah jumlah elemen dalam antrian
    }

    // Menghapus elemen dari depan antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front; // Simpan elemen depan yang akan dihapus
        front = front->next; // Geser penanda front ke elemen berikutnya
        delete temp; // Hapus elemen yang disimpan
        size--; // Kurangi jumlah elemen dalam antrian

        if (isEmpty()) { // Jika setelah penghapusan antrian kosong, update back menjadi nullptr
            back = nullptr;
        }
    }

    // Menghitung jumlah elemen dalam antrian
    int count() {
        return size;
    }

    // Menghapus semua elemen dalam antrian
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Menampilkan elemen-elemen dalam antrian beserta nomor urutnya
    void view() {
        cout << "Data antrian teller:" << endl;
        Node* temp = front;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". " << temp->data << endl;
            temp = temp->next;
            i++;
        }
    }
};

// Fungsi main untuk menguji implementasi antrian
int main() {
    Queue queue;

    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    queue.dequeue();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    queue.clear();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    return 0;
}
```

### Output:
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/fac49477-29a0-404d-9c02-3a1784882c1e)

### Deskripsi Program : 
Program ini merupakan implementasi antrian (queue) menggunakan linked list. Berikut adalah deskripsi singkat dari setiap bagian program tersebut:

- Struct `Node` digunakan untuk merepresentasikan elemen dalam linked list, dengan atribut `data` untuk menyimpan data dan `next` untuk menyimpan pointer ke node selanjutnya.
- Kelas `Queue` digunakan untuk mengimplementasikan struktur data antrian. Atribut `front` dan `back` digunakan untuk menunjukkan elemen depan dan belakang antrian, sedangkan `size` menyimpan jumlah elemen dalam antrian.
- Konstruktor `Queue()` digunakan untuk inisialisasi antrian kosong.
- Metode `isEmpty()` dan `isFull()` digunakan untuk memeriksa apakah antrian kosong atau penuh.
- Metode `enqueue(string data)` digunakan untuk menambahkan elemen baru ke belakang antrian.
- Metode `dequeue()` digunakan untuk menghapus elemen dari depan antrian.
- Metode `count()` digunakan untuk menghitung jumlah elemen dalam antrian.
- Metode `clear()` digunakan untuk menghapus semua elemen dalam antrian.
- Metode `view()` digunakan untuk menampilkan elemen-elemen dalam antrian beserta nomor urutnya.

Di dalam fungsi `main()`, program melakukan beberapa operasi pada antrian:
- Menambahkan data "Andi" dan "Maya" ke dalam antrian.
- Menampilkan isi antrian dan jumlah antrian.
- Menghapus satu data dari antrian.
- Menampilkan isi antrian dan jumlah antrian setelah penghapusan.
- Menghapus semua data dalam antrian.
- Menampilkan isi antrian dan jumlah antrian setelah penghapusan semua elemen.

### Full code Screenshot:
![carbon (1)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/91baf4ae-5122-49d3-b4c3-b4aa5164c095)

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data mahasiswa
struct Node {
    string namaMahasiswa;
    string nimMahasiswa;
    Node* next;
};

// Kelas Queue untuk mengimplementasikan antrian menggunakan linked list
class Queue {
private:
    Node* front; // Penanda elemen depan antrian
    Node* back; // Penanda elemen belakang antrian
    int size; // Jumlah elemen dalam antrian

public:
    // Konstruktor untuk inisialisasi antrian kosong
    Queue() : front(nullptr), back(nullptr), size(0) {}

    // Memeriksa apakah antrian kosong
    bool isEmpty() {
        return size == 0;
    }

    // Memeriksa apakah antrian penuh (sudah mencapai ukuran maksimum)
    bool isFull() {
        return size == 5; // Maksimal ukuran antrian
    }

    // Menambahkan elemen baru ke belakang antrian
    void enqueue(string nama, string nim) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }

        Node* newNode = new Node(); // Membuat node baru
        newNode->namaMahasiswa = nama; // Mengisi data nama mahasiswa
        newNode->nimMahasiswa = nim; // Mengisi data NIM mahasiswa
        newNode->next = nullptr;

        if (isEmpty()) { // Jika antrian kosong, elemen baru menjadi front dan back
            front = newNode;
            back = newNode;
        } else { // Jika tidak, elemen baru ditambahkan ke belakang dan back diperbarui
            back->next = newNode;
            back = newNode;
        }

        size++; // Menambah jumlah elemen dalam antrian
    }

    // Menghapus elemen dari depan antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front; // Simpan elemen depan yang akan dihapus
        front = front->next; // Geser penanda front ke elemen berikutnya
        delete temp; // Hapus elemen yang disimpan
        size--; // Kurangi jumlah elemen dalam antrian

        if (isEmpty()) { // Jika setelah penghapusan antrian kosong, update back menjadi nullptr
            back = nullptr;
        }
    }

    // Mengembalikan jumlah elemen dalam antrian
    int count() {
        return size;
    }

    // Menghapus semua elemen dalam antrian
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Menampilkan elemen-elemen dalam antrian beserta nama dan NIM mahasiswa masing-masing
    void view() {
        cout << "Data antrian mahasiswa:" << endl;
        Node* temp = front;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". Nama: " << temp->namaMahasiswa << ", NIM: " << temp->nimMahasiswa << endl;
            temp = temp->next;
            i++;
        }
    }
};

// Fungsi main untuk menguji implementasi antrian
int main() {
    Queue queue;

    // Menambahkan elemen ke antrian
    queue.enqueue("Andi", "123456");
    queue.enqueue("Maya", "789012");

    // Menampilkan antrian
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    // Menghapus elemen dari antrian
    queue.dequeue();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    // Menghapus semua elemen dari antrian
    queue.clear();
    queue.view();
    cout << "Jumlah antrian = " << queue.count() << endl;

    return 0;
}
```

### Output:
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/a9ef84a6-0c75-4a59-9033-cfdce9a4e704)


### Deskripsi Program : 
Program ini merupakan implementasi antrian (queue) menggunakan linked list. 
Program ini memiliki struktur data `Node` untuk menyimpan data mahasiswa (nama dan NIM) dan kelas `Queue` untuk mengimplementasikan antrian.

Pada kelas `Queue`, terdapat atribut `front` dan `back` yang menunjukkan elemen depan dan belakang antrian serta `size` yang menyimpan jumlah elemen dalam antrian. 
Terdapat juga konstruktor untuk inisialisasi antrian kosong, metode untuk memeriksa apakah antrian kosong atau penuh, serta metode untuk menambahkan, menghapus, menghitung jumlah, menghapus semua, dan menampilkan elemen-elemen dalam antrian.

Di dalam fungsi `main()`, program melakukan beberapa operasi pada antrian:
- Menambahkan data mahasiswa "Andi" dengan NIM "123456" dan "Maya" dengan NIM "789012" ke dalam antrian.
- Menampilkan isi antrian beserta nama dan NIM mahasiswa masing-masing.
- Menghapus satu data mahasiswa dari antrian.
- Menampilkan isi antrian setelah penghapusan dan jumlah antrian.
- Menghapus semua data mahasiswa dari antrian.
- Menampilkan isi antrian setelah penghapusan semua elemen dan jumlah antrian.

### Full code Screenshot:
![carbon (2)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/56896a72-1bcb-4846-8628-f9397bbb84a6)


## Kesimpulan
Kesimpulan dari melakukan praktikum dengan struktur data antrian (queue) adalah:

1. **Penggunaan Praktis**:

   Antrian sangat berguna dalam situasi di mana kita perlu mengelola data atau tugas secara berurutan, seperti dalam simulasi antrian pelanggan di kasir atau pengolahan pesan yang masuk.

2. **Implementasi dengan Linked List**:
  
   Implementasi antrian dengan menggunakan linked list memungkinkan penambahan dan penghapusan elemen dengan efisien, karena tidak perlu menggeser seluruh elemen seperti pada array.

4. **Pentingnya Pengecekan Kapasitas**:
  
   Penting untuk selalu memeriksa apakah antrian penuh sebelum menambahkan elemen baru, serta memeriksa apakah antrian kosong sebelum menghapus elemen.

5. **Fleksibilitas**:

   Struktur data antrian memiliki fleksibilitas yang baik dalam menangani berbagai situasi di mana urutan atau waktu kedatangan data penting.

6. **Penggunaan di Berbagai Bidang**:

   Konsep antrian tidak hanya berguna dalam pemrograman komputer, tetapi juga dapat diterapkan dalam berbagai bidang lain seperti manajemen, logistik, dan lainnya.
   
## Referensi
[1] Goodrich, M.T., Tamassia, R., dan Goldwasser, M.H., "Data Structures and Algorithms in Java," John Wiley & Sons, Inc., 2014.
