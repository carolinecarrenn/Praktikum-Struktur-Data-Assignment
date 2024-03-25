# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Caroline Carren (2311102174)</p>

## Dasar Teori

Linked list adalah salah satu struktur data yang terdiri dari sejumlah elemen data yang disusun secara berurutan. 
Setiap elemen dalam linked list disebut sebagai "node", dan setiap node memiliki dua komponen utama: data yang menyimpan nilai atau informasi, dan sebuah pointer (atau reference) yang menunjuk ke node berikutnya dalam urutan.

Ada dua jenis linked list utama yaitu single linked list dan double linked list.

1. Single Linked List
   
   ![Screenshot 2024-03-25 145540](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0655d2d5-a66b-4766-9ae2-51d00c4034ea)
   
   Single linked list adalah struktur data linear di mana setiap elemen disebut "node" terdiri dari dua bagian: data dan pointer yang menunjuk ke node berikutnya dalam urutan.
   Node terakhir dalam linked list menunjuk ke NULL, menandakan akhir dari linked list.
   Kelebihan:
   - Efisien untuk operasi penambahan dan penghapusan elemen di awal dan akhir linked list. Operasi ini memiliki kompleksitas waktu O(1) karena tidak perlu menggeser elemen lain.
   - Membutuhkan ruang penyimpanan yang lebih sedikit dibandingkan dengan array karena node-node hanya membutuhkan ruang untuk data dan pointer.
   Kekurangan:
   - Pencarian elemen yang spesifik membutuhkan waktu linier, dengan kompleksitas waktu O(n), karena pencarian harus dilakukan secara berurutan dari awal hingga akhir linked list.
   - Tidak mendukung akses acak langsung ke elemen, seperti pada array.[1]


2. Double Linked List

   ![Screenshot 2024-03-25 145939](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/cd755724-dd61-4a4b-9548-8e157717bbc1)

   Double linked list mirip dengan single linked list, tetapi setiap node memiliki dua pointer: satu yang menunjuk ke node sebelumnya dan satu lagi yang menunjuk ke node berikutnya dalam urutan.
   Hal ini memungkinkan pergerakan maju dan mundur dalam linked list.

   Kelebihan:
   - Sama dengan single linked list, double linked list juga efisien untuk operasi penambahan dan penghapusan elemen di awal dan akhir linked list dengan kompleksitas waktu O(1).
   - Dapat melakukan traversal maju dan mundur dalam linked list dengan mudah, karena setiap node memiliki pointer ke node sebelumnya dan berikutnya.
   Kekurangan:
   - Membutuhkan lebih banyak ruang penyimpanan dibandingkan dengan single linked list karena setiap node menyimpan dua pointer.
   - Memerlukan manajemen yang lebih kompleks dalam implementasinya, terutama saat menambah atau menghapus node.[1]

## Guided 

### 1. [Latihan Single Linked List]

```C++
/// Caroline Carren
/// 2311102174

#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
#### Deskripsi Program : 
Program ini merupakan implementasi dari sebuah single linked list non-circular, Fitur yang disediakan oleh program ini antara lain:

1. **Inisialisasi**: Program menginisialisasi sebuah linked list dengan membuat kepala (head) dan ekor (tail) yang awalnya menunjuk ke NULL.

2. **Penambahan Data**:
   - `insertDepan(int nilai)`: Menambahkan data baru ke depan linked list.
   - `insertBelakang(int nilai)`: Menambahkan data baru ke belakang linked list.
   - `insertTengah(int data, int posisi)`: Menambahkan data baru pada posisi tertentu dalam linked list.

3. **Penghapusan Data**:
   - `hapusDepan()`: Menghapus data dari depan linked list.
   - `hapusBelakang()`: Menghapus data dari belakang linked list.
   - `hapusTengah(int posisi)`: Menghapus data dari posisi tertentu dalam linked list.

4. **Perubahan Data**:
   - `ubahDepan(int data)`: Mengubah data pada posisi depan linked list.
   - `ubahBelakang(int data)`: Mengubah data pada posisi belakang linked list.
   - `ubahTengah(int data, int posisi)`: Mengubah data pada posisi tertentu dalam linked list.

5. **Pengecekan**:
   - `isEmpty()`: Memeriksa apakah linked list kosong.

6. **Fungsi Bantuan**:
   - `hitungList()`: Menghitung jumlah node dalam linked list.
   - `clearList()`: Menghapus semua data dari linked list.

7. **Tampilan**:
   - `tampil()`: Menampilkan seluruh data dalam linked list.

Program ini dapat digunakan untuk mengelola data dengan fleksibilitas penambahan, penghapusan, perubahan, dan penampilan data dalam struktur linked list. Pada `main()` function, dilakukan pengujian terhadap berbagai fungsi yang telah diimplementasikan dalam program ini.

### 2. [Latihan Double Linked List]

```C++
/// Caroline Carren
/// 2311102174

#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Deskripsi Program : 
Program ini merupakan implementasi dari Double Linked List, Double Linked List adalah struktur data linear di mana setiap node terdiri dari tiga bagian: data itu sendiri, pointer ke node sebelumnya (prev), dan pointer ke node berikutnya (next).

Deskripsi fitur-fitur utama dari program ini adalah sebagai berikut:

1. **Deklarasi Kelas `Node`**: Kelas `Node` mendefinisikan struktur dari sebuah node dalam Double Linked List. Setiap node memiliki sebuah integer `data`, serta pointer `prev` dan `next` yang menunjuk ke node sebelumnya dan node berikutnya.

2. **Deklarasi Kelas `DoubleLinkedList`**: Kelas `DoubleLinkedList` adalah tempat implementasi utama dari operasi-operasi yang terkait dengan Double Linked List. Ini mencakup operasi-operasi seperti penambahan, penghapusan, pembaruan, penghapusan semua data, dan penampilan data.

3. **Metode `push(int data)`**: Metode ini menambahkan sebuah node baru dengan data tertentu ke depan dari Double Linked List.

4. **Metode `pop()`**: Metode ini menghapus node pertama (dari depan) dari Double Linked List.

5. **Metode `update(int oldData, int newData)`**: Metode ini mencari node dengan data tertentu dalam Double Linked List dan mengganti data lama dengan data baru.

6. **Metode `deleteAll()`**: Metode ini menghapus semua node dalam Double Linked List.

7. **Metode `display()`**: Metode ini menampilkan semua data yang ada dalam Double Linked List.

8. **Fungsi `main()`**: Fungsi utama dari program yang memberikan menu kepada pengguna untuk memilih operasi yang ingin dilakukan pada Double Linked List. Pengguna dapat memilih untuk menambah data, menghapus data, memperbarui data, membersihkan semua data, menampilkan data, atau keluar dari program.

Program ini memungkinkan pengguna untuk berinteraksi dengan Double Linked List dengan melakukan berbagai operasi seperti penambahan, penghapusan, pembaruan, dan penampilan data, sesuai dengan pilihan yang mereka buat dari menu yang disediakan.


## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. ]

![Screenshot 2024-03-25 155450](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/397a3d0e-be4a-4929-bfa5-0590b79a4231)

```C++
/// Caroline Carren
/// 2311102174

#include <iostream>
#include <string>
using namespace std;

// Node untuk menyimpan data
struct Node {
    string name;
    int age;
    Node* next;
};

// Kelas LinkedList untuk menyimpan operasi-operasi terkait linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di awal linked list
    void insertFront(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data setelah node dengan nama tertentu
    void insertAfter(string name, int age, string afterName) {
        Node* current = head;
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data " << afterName << " tidak ditemukan." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk menambahkan data di akhir linked list
    void insertEnd(string name, int age) {
        if (head == nullptr) {
            insertFront(name, age);
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = nullptr;
        current->next = newNode;
    }

    // Fungsi untuk menghapus node dengan nama tertentu
    void deleteNode(string name) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data " << name << " tidak ditemukan." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    // Fungsi untuk mengubah data (ganti nama)
    void modifyNode(string oldName, string newName, int newAge) {
        Node* current = head;

        while (current != nullptr && current->name != oldName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data " << oldName << " tidak ditemukan." << endl;
            return;
        }

        current->name = newName;
        current->age = newAge;
    }

    // Fungsi untuk menampilkan isi linked list
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " " << current->age << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    int numData;
    cout << "Masukkan jumlah data: ";
    cin >> numData;

    // Mengambil input data dari pengguna dan menambahkannya ke linked list
    for (int i = 0; i < numData; ++i) {
        string name;
        int age;
        cout << "Masukkan nama: ";
        cin >> name;
        cout << "Masukkan usia: ";
        cin >> age;
        list.insertEnd(name, age);
    }

    cout << "Data awal:" << endl;
    list.displayList();
    cout << endl;

    string deleteName;
    cout << "Masukkan nama yang ingin dihapus: ";
    cin >> deleteName;
    list.deleteNode(deleteName);
    cout << "Setelah menghapus data:" << endl;
    list.displayList();
    cout << endl;

    string insertName, afterName;
    int insertAge;
    cout << "Masukkan nama yang ingin ditambahkan: ";
    cin >> insertName;
    cout << "Masukkan usia yang ingin ditambahkan: ";
    cin >> insertAge;
    cout << "Masukkan nama setelah data baru: ";
    cin >> afterName;
    list.insertAfter(insertName, insertAge, afterName);
    cout << "Setelah menambahkan data:" << endl;
    list.displayList();
    cout << endl;

    // Menambahkan data baru di awal linked list
    list.insertFront("Igor", 20);
    cout << "Setelah menambahkan Igor 20 di awal:" << endl;
    list.displayList();
    cout << endl;

    // Mengubah data Michael menjadi Reyn 18
    list.modifyNode("Michael", "Reyn", 18);
    cout << "Setelah mengubah Michael menjadi Reyn 18:" << endl;
    list.displayList();
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot (88)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/b52d0b7e-0d3e-45a4-8cf6-dc537a772fa1)
![Screenshot (89)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0ea7f58e-ec3c-4cf0-a8b7-d1342c96f4ac)

#### Deskripsi Program : 
Program ini merupakan implementasi dari sebuah linked list yang menyimpan data berupa nama dan usia seseorang. Berikut adalah deskripsi fitur-fitur utama dari program ini:

1. **Struktur `Node`**: Struktur ini digunakan untuk menyimpan data dalam linked list. Setiap `Node` memiliki dua variabel yaitu `name` (nama) dan `age` (usia), serta pointer `next` yang menunjuk ke `Node` selanjutnya.

2. **Kelas `LinkedList`**: Kelas ini digunakan untuk menyimpan operasi-operasi terkait dengan linked list. Beberapa operasi yang disediakan antara lain:

   - `insertFront(string name, int age)`: Menambahkan data di awal linked list.
   - `insertAfter(string name, int age, string afterName)`: Menambahkan data setelah node dengan nama tertentu.
   - `insertEnd(string name, int age)`: Menambahkan data di akhir linked list.
   - `deleteNode(string name)`: Menghapus node dengan nama tertentu.
   - `modifyNode(string oldName, string newName, int newAge)`: Mengubah data (mengganti nama).
   - `displayList()`: Menampilkan isi linked list.

3. **Fungsi `main()`**: Fungsi utama dari program yang memberikan interaksi kepada pengguna untuk memasukkan data, menghapus data, menambahkan data setelah data tertentu, menambahkan data di awal linked list, serta mengubah data. Program kemudian menampilkan isi linked list setelah setiap operasi dilakukan.

Pada awal program, pengguna diminta untuk memasukkan jumlah data yang ingin dimasukkan. Kemudian, program akan meminta pengguna untuk memasukkan nama dan usia untuk setiap data, dan akan menambahkannya ke linked list. Setelah itu, program akan melakukan beberapa operasi seperti menghapus data, menambahkan data baru setelah data tertentu, menambahkan data di awal linked list, dan mengubah data. Setiap kali setelah operasi dilakukan, program akan menampilkan isi linked list.

#### Full code Screenshot:
![Screenshot (91)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/e366cdf8-95fe-4c69-81a4-6aa888ee4dc7)
![Screenshot (92)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/41702c3a-5a9e-4da4-a907-215daa6968c9)
![Screenshot (93)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/3b5d4530-470e-4644-b8b5-f81315cad6cf)
![Screenshot (94)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/4d9c1564-41e1-4b21-a28e-922eff5daf90)
![Screenshot (95)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/eb467e81-f7b5-473a-9c8d-b9a6c060d960)
![Screenshot (96)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/36f75a28-8978-4818-889c-b68acf5093c5)

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]

![Screenshot 2024-03-25 160143](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/be5ca10d-a911-4647-8391-0e8ad59ee715)

```C++
/// Caroline Carren
/// 2311102174

#include <iostream>
using namespace std;

struct Node {
    string nama;
    double harga;
    Node* next;
    Node* prev;
};

// menampilkan menu
void tampilkanMenu() {
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;
}

// menampilkan data
void tampilkanData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " - " << temp->harga << endl;
        temp = temp->next;
    }
}

// tambah data
Node* tambahData(Node* head) {
    Node* newNode = new Node();
    cout << "Masukkan nama produk: ";
    cin >> newNode->nama;
    cout << "Masukkan harga: ";
    cin >> newNode->harga;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// hapus data
Node* hapusData(Node* head) {
    if (head == NULL) {return NULL;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        delete temp;
        return NULL;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    delete temp;
    return head;
}

// update data
Node* updateData(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Tampilkan semua data yang tersedia
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " - " << temp->harga << endl;
        temp = temp->next;
    }

    // Ambil input nama produk yang akan diupdate
    string namaLama;
    cout << "Masukkan nama produk yang akan diupdate: ";
    cin >> namaLama;

    // Cari node dengan nama yang sesuai
    temp = head;
    while (temp != NULL) {
        if (temp->nama == namaLama) {
            // Tampilkan daftar opsi untuk update
            cout << "Pilih opsi: " << endl;
            cout << "1. Update nama" << endl;
            cout << "2. Update harga" << endl;
            int pilihan;
            cin >> pilihan;

            // Update data berdasarkan pilihan
            switch (pilihan) {
                case 1:
                    cout << "Masukkan nama baru: ";
                    cin >> temp->nama;
                    break;
                case 2:
                    cout << "Masukkan harga baru: ";
                    cin >> temp->harga;
                    break;
                default:
                    cout << "Pilihan tidak valid" << endl;
                    break;
            }

            // Kembalikan node yang telah diupdate
            return head;
        }
        temp = temp->next;
    }

    // Jika tidak ditemukan produk dengan nama tersebut, tampilkan pesan
    cout << "Produk dengan nama " << namaLama << " tidak ditemukan" << endl;

    // Kembalikan node yang sama
    return head;
}

// tambah data urutan tertentu
Node* tambahDataUrutanTertentu(Node* head) {
    Node* newNode = new Node();
    cout << "Masukkan nama produk: ";
    cin >> newNode->nama;
    cout << "Masukkan harga: ";
    cin >> newNode->harga;
    Node* temp = head;
    int posisi;
    cout << "Masukkan posisi: ";
    cin >> posisi;
    if (posisi == 1) {
        newNode->next = temp;
        newNode->prev = NULL;
        temp->prev = newNode;
        return newNode;
    }
    for (int i = 0; i < posisi - 2; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        cout << "Posisi tidak valid" << endl;
delete newNode;
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// hapus data urutan tertentu
Node* hapusDataUrutanTertentu(Node* head, int posisi) {
    Node* temp = head;
    if (posisi == 1) {
        if (head->next != NULL) {
            head->next->prev = NULL;
        }
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return head;
    }
    for (int i = 0; i < posisi - 2; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        cout << "Posisi tidak valid" << endl;
        return head;
    }
    if (temp->next == NULL) {
        cout << "Posisi tidak valid" << endl;
        return head;
    }
    Node* hapus = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL) {
        temp->next->prev = temp;
    }
    delete hapus;
    return head;
}

// hapus seluruh data
Node* hapusSeluruhData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    int pilihan;
    while (true) {
        tampilkanMenu();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                head = tambahData(head);
                break;
            case 2:
                head = hapusData(head);
                break;
            case 3:
                head = updateData(head);
                break;
            case 4:
                head = tambahDataUrutanTertentu(head);
                break;
            case 5:
                int posisi;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                head = hapusDataUrutanTertentu(head, posisi);
                break;
            case 6:
                head = hapusSeluruhData(head);
                break;
            case 7:
                tampilkanData(head);
                break;
            case 8:
                exit(0);
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    }
    return 0;
}
```
#### Output:
![Screenshot (81)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/af947c58-5b28-4bbb-b4fa-676931c4cced)
![Screenshot (82)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/4c3dd35f-5ba7-44db-bf1e-0daa5a4ea225)
![Screenshot (83)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/dafb9960-891a-4639-a344-fb722973acd0)
![Screenshot (84)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/9fa02c19-c4c7-4b2a-82b8-9592e398989b)
![Screenshot (85)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/061c1c94-cd99-4581-b1e0-2d4ecf94ca59)
![Screenshot (86)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/ee54183d-7a47-4493-83dd-d995da60fa85)

#### Deskripsi Program : 
Program ini adalah sebuah aplikasi sederhana yang mengelola data produk pada sebuah toko skincare di Purwokerto. Berikut adalah deskripsi fitur-fitur utama dari program ini:

1. **Struktur Data `Node`**: Struktur ini digunakan untuk merepresentasikan sebuah produk skincare. Setiap `Node` memiliki dua data yaitu `nama` (nama produk) dan `harga` (harga produk), serta dua pointer yaitu `next` (pointer ke `Node` berikutnya) dan `prev` (pointer ke `Node` sebelumnya).

2. **Fungsi `tampilkanMenu()`**: Fungsi ini digunakan untuk menampilkan menu pilihan operasi kepada pengguna. Menu ini mencakup beberapa opsi seperti tambah data, hapus data, update data, dan lain-lain.

3. **Fungsi `tampilkanData(Node* head)`**: Fungsi ini digunakan untuk menampilkan semua data produk yang tersimpan dalam linked list. 

4. **Operasi `tambahData(Node* head)`**: Fungsi ini meminta pengguna untuk memasukkan data produk baru (nama dan harga), lalu menambahkannya ke akhir linked list.

5. **Operasi `hapusData(Node* head)`**: Fungsi ini menghapus data produk terakhir dari linked list.

6. **Operasi `updateData(Node* head)`**: Fungsi ini memungkinkan pengguna untuk memperbarui data produk yang sudah ada dalam linked list.

7. **Operasi `tambahDataUrutanTertentu(Node* head)`**: Fungsi ini memungkinkan pengguna untuk menambahkan data produk baru pada posisi tertentu dalam linked list.

8. **Operasi `hapusDataUrutanTertentu(Node* head, int posisi)`**: Fungsi ini memungkinkan pengguna untuk menghapus data produk pada posisi tertentu dalam linked list.

9. **Operasi `hapusSeluruhData(Node* head)`**: Fungsi ini menghapus semua data produk dari linked list.

10. **Fungsi `main()`**: Fungsi utama dari program ini. Program akan terus berjalan dan menampilkan menu pilihan operasi kepada pengguna. Pengguna dapat memilih operasi yang diinginkan, dan program akan menjalankan operasi sesuai dengan pilihan pengguna sampai pengguna memilih untuk keluar dari program.

Program ini memberikan fleksibilitas kepada pengguna untuk mengelola data produk skincare dengan berbagai operasi seperti tambah, hapus, update, dan lain-lain, menggunakan struktur data linked list.

#### Full code Screenshot:
![Screenshot (97)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/d9d7f3eb-225e-4f3b-9b00-4a71de8421c5)
![Screenshot (98)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f70255bd-ca41-42ab-8139-6734cff1019f)
![Screenshot (99)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/8f342a9a-7aec-4852-82d6-e1b04b26ac58)
![Screenshot (100)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/5d6ed3f8-4cd6-4e7f-9f66-894916fc4405)
![Screenshot (101)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/2c5f3307-1567-4de2-9e01-49244a142e5b)
![Screenshot (102)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/486b22b0-baa3-44f4-99d1-ae6e551015ef)
![Screenshot (103)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/79186929-d65f-4e5e-9b36-8296bc9b6b19)
![Screenshot (104)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/d6e506b7-93e5-4832-9590-e11bc6d2c2a1)


## Kesimpulan
**Kesimpulan:**
- Single linked list dan double linked list merupakan struktur data yang berguna dalam mengelola kumpulan data secara dinamis.
- Single linked list lebih sederhana dan membutuhkan lebih sedikit ruang memori karena hanya memiliki satu pointer untuk setiap node.
- Double linked list memberikan lebih banyak fleksibilitas karena setiap node memiliki dua pointer, memungkinkan traversal maju dan mundur.
- Pemilihan antara single dan double linked list tergantung pada kebutuhan spesifik aplikasi dan keseimbangan antara kinerja dan penggunaan memori.

## Referensi
[1] M. T. Goodrich, R. Tamassia, dan D. M. Mount, "Data Structures and Algorithms in C++," Wiley, 2011.
