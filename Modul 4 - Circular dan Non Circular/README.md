# <h1 align="center">Laporan Praktikum Modul Linked List Circular and Non Circular</h1>
<p align="center">Caroline Carren Aurelia R</p>
<p align="center">2311102174</p>
<p align="center">IF 11 E</p>

## Dasar Teori

Linked list adalah struktur data linear di mana setiap elemen disebut node, dan setiap node terdiri dari dua bagian: data dan pointer yang menunjuk ke node berikutnya dalam urutan. 
Ada dua jenis utama linked list: linked list linear (non-circular) dan linked list circular.[1]

1. **Linked List Linear (Non Circular)** :
  
   Linked list non-circular adalah struktur data linier di mana setiap elemen atau node terhubung dengan node berikutnya dalam urutan tertentu.
   Dalam linked list non-circular, setiap node memiliki dua bagian utama: data yang berisi nilai aktual dan pointer yang menunjuk ke node berikutnya dalam linked list.[1]

   Operasi Dasar:
   - Insertion: Menambahkan elemen baru ke linked list di posisi tertentu, seperti di awal, akhir, atau setelah node tertentu.
   - Deletion: Menghapus elemen tertentu dari linked list.
   - Traversal: Mengunjungi setiap node dalam linked list, biasanya dimulai dari awal hingga akhir.[1]
   
   Kelebihan Linked List Non-Circular:
   - Fleksibilitas dalam penambahan dan penghapusan elemen, terutama di tengah-tengah linked list.
   - Ruang memori yang efisien karena node-node hanya membutuhkan ruang tambahan untuk pointer.[1]
   
   Kekurangan Linked List Non-Circular:
   - Memerlukan pencarian linier untuk mengakses elemen tertentu, tidak seperti array yang dapat diakses secara langsung dengan indeks.[1]

   Contoh program non circular :
   ![carbon (4)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/887c4eaa-e365-41e0-9333-eb1306bd26a8)



 2. **Linked List Circular**
   
    Linked list circular adalah variasi dari linked list di mana node terakhir dalam linked list mengarah kembali ke node pertama, membentuk lingkaran atau siklus.
    Ini berarti tidak ada elemen yang memiliki pointer yang menunjuk ke nilai null.[1]

    Operasi Dasar:
    - Operasi pada linked list circular mirip dengan operasi pada linked list non-circular. Namun, traversal perlu memperhatikan kondisi terminasi agar tidak jatuh ke dalam loop tak terbatas.
    
    Kelebihan Linked List Circular:
    - Tidak memerlukan pengecekan pointer null saat melakukan traversal atau operasi lainnya
    - Cocok untuk implementasi struktur data berulang seperti buffer lingkaran atau antrian siklus.
    
    Kekurangan Linked List Circular:
    - Memerlukan perhatian khusus dalam implementasi untuk mencegah deadlock atau loop tak terbatas.
    - Pemeliharaan tambahan diperlukan untuk memastikan bahwa tidak ada siklus yang rusak atau tidak valid.[1]
  
    Contoh program circular :
    ![carbon (5)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/c2c7b192-16f7-4328-b4cd-7c90e3b597ae)




## Guided 

### 1. [Linked List Non Circular]

```C++
/// Caroline Carren
/// 2311102174


#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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
#### Output :
![Screenshot (161)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/322ed550-fd29-4c9c-91e1-216d21c61166)

#### Deskripsi Program : 
Pada awal program, terdapat deklarasi struct Node yang merepresentasikan sebuah simpul atau node dalam linked list. 
Setiap node memiliki dua bagian, yaitu data yang merupakan nilai yang disimpan dalam simpul dan next yang merupakan pointer ke simpul selanjutnya dalam linked list.
Terdapat beberapa fungsi untuk melakukan operasi pada linked list:
- init(): Menginisialisasi pointer head dan tail menjadi NULL untuk menandakan bahwa linked list masih kosong.
- isEmpty(): Memeriksa apakah linked list kosong atau tidak.
- insertDepan(int nilai): Menambahkan elemen baru di depan linked list.
- insertBelakang(int nilai): Menambahkan elemen baru di belakang linked list.
- hitungList(): Menghitung jumlah elemen dalam linked list.
- insertTengah(int data, int posisi): Menambahkan elemen baru pada posisi tertentu di tengah linked list.
- hapusDepan(): Menghapus elemen pertama dari linked list.
- hapusBelakang(): Menghapus elemen terakhir dari linked list.
- hapusTengah(int posisi): Menghapus elemen pada posisi tertentu di tengah linked list.
- ubahDepan(int data): Mengubah nilai elemen pertama dari linked list.
- ubahTengah(int data, int posisi): Mengubah nilai elemen pada posisi tertentu di tengah linked list.
- ubahBelakang(int data): Mengubah nilai elemen terakhir dari linked list.
- clearList(): Menghapus semua elemen dari linked list.
- tampil(): Menampilkan isi dari linked list.
Pada fungsi main(), terdapat contoh penggunaan operasi-operasi di atas untuk mengatur dan mengakses linked list.
Beberapa operasi yang dilakukan antara lain: penambahan elemen, penghapusan elemen, pengubahan nilai elemen, dan penampilan isi linked list setelah operasi-operasi tersebut dilakukan.

Program ini menyediakan beberapa fungsi dasar untuk mengelola linked list seperti menambahkan, menghapus, mengubah, serta menampilkan elemen-elemen dalam linked list.


### 2. [Latihan Linked List Circular]

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
#### Output :
![Screenshot (162)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f99427e1-24a8-4d69-bd2a-5172106b8675)

#### Deskripsi Program : 
Program ini adalah implementasi dari single linked list dengan sifat circular menggunakan bahasa pemrograman C++. 

Single linked list circular adalah struktur data linear di mana setiap elemen disambungkan dengan elemen berikutnya dalam sebuah loop, sehingga elemen terakhir mengarah kembali ke elemen pertama.

Pada awal program, terdapat deklarasi struct Node yang merepresentasikan sebuah simpul atau node dalam linked list. 

Setiap node memiliki dua bagian, yaitu data yang merupakan nilai yang disimpan dalam simpul dan next yang merupakan pointer ke simpul selanjutnya dalam linked list.

Terdapat beberapa variabel global yang digunakan dalam program :
- head: Pointer ke simpul pertama dalam linked list.
- tail: Pointer ke simpul terakhir dalam linked list.
- baru: Pointer untuk menunjuk ke simpul baru yang akan dibuat.
- bantu: Pointer untuk melakukan traversing dalam linked list.
- hapus: Pointer untuk menghapus simpul dari linked list.

Terdapat beberapa fungsi untuk melakukan operasi pada linked list:
- Pada fungsi init(), dilakukan inisialisasi pointer head dan tail menjadi NULL, menandakan bahwa linked list masih kosong.
- Fungsi isEmpty() digunakan untuk memeriksa apakah linked list kosong atau tidak.
- Fungsi buatNode(string data) digunakan untuk membuat simpul baru dengan nilai data tertentu.
- Fungsi hitungList() digunakan untuk menghitung jumlah elemen dalam linked list.
- insertDepan(string data): Menambahkan elemen baru di depan linked list.
- insertBelakang(string data): Menambahkan elemen baru di belakang linked list.
- insertTengah(string data, int posisi): Menambahkan elemen baru pada posisi tertentu di tengah linked list.
- hapusDepan(): Menghapus elemen pertama dari linked list.
- hapusBelakang(): Menghapus elemen terakhir dari linked list.
- hapusTengah(int posisi): Menghapus elemen pada posisi tertentu di tengah linked list.
- clearList(): Menghapus semua elemen dari linked list.
- tampil(): Menampilkan isi dari linked list.
- Fungsi main() merupakan tempat di mana operasi-operasi pada linked list dijalankan untuk mengatur dan mengakses linked list.


Beberapa operasi yang dilakukan antara lain: 
penambahan elemen di depan, di belakang, di tengah, penghapusan elemen di depan, di belakang, di tengah, serta penampilan isi linked list setelah operasi-operasi tersebut dilakukan.

Program ini menyediakan berbagai fungsi dasar untuk mengelola linked list dengan sifat circular, seperti penambahan, penghapusan, serta penampilan isi linked list.


## Unguided 

### [Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. ]
![Screenshot (130)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0c53ede6-f1a4-460b-aebb-e5c4f84b219f)

![Screenshot (131)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/bf7c2b76-d596-43f7-baeb-05c60d13bb64)

![Screenshot (132)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/dc38b094-21d8-455b-8ff2-9001ffa5fdf8)

![Screenshot (133)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/11cfb5b9-f910-49d5-88ba-8f95abaf3769)

![Screenshot (134)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7b2b165b-ef47-426a-a2a7-69c51fe7c746)



```C++
/// Nama  : CAROLINE CARREN
/// Nim   : 2311102174
/// Kelas : IF 11 E

#include <iostream>
using namespace std;

/// deklarasi node struct
struct Node
{
    int nim;
    string nama;
    Node *next;
};

Node *head;
Node *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

/// pengecekan
bool isEmpty()
{
    return (head == NULL);
}

/// tambah depan
void TambahDepan(string nama, int nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    if (isEmpty())
    {
        head = baru;
        tail = baru;
        baru->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

/// tambah belakang
void TambahBelakang(string nama, int nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    if (isEmpty())
    {
        head = baru;
        tail = baru;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

/// hapus belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (!isEmpty())
    {
        hapus = tail;
        bantu = head;

        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }

        tail = bantu;
        tail->next = head;

        delete hapus;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

/// tampilkan
void tampilkan()
{
    Node *bantu = head;
    int nomor = 1;

    if (!isEmpty())
    {
        cout << "No." << "\t" << "Nama Mahasiswa" << "\t" << "NIM Mahasiswa" << endl;
        do
        {
            cout << nomor++ << "\t" << bantu->nama << "\t" << bantu->nim << endl;
            bantu = bantu->next;
        } while (bantu != head);
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

/// hitung
int hitung()
{
    Node *bantu = head;
    int jumlah = 0;

    if (!isEmpty())
    {
        do
        {
            jumlah++;
            bantu = bantu->next;
        } while (bantu != head);
    }
    return jumlah;
}

/// tambah tengah
void TambahTengah(string nama, int nim, int posisi)
{
    if (posisi < 1 || posisi > hitung() + 1)
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        TambahDepan(nama, nim);
    }
    else if (posisi == hitung() + 1)
    {
        TambahBelakang(nama, nim);
    }
    else
    {
        Node *baru = new Node;
        baru->nama = nama;
        baru->nim = nim;

        Node *bantu = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

/// hapus depan
void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        head = head->next;
        tail->next = head;
        delete hapus;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

/// hapus tengah
void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitung())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        hapusDepan();
    }
    else if (posisi == hitung())
    {
        hapusBelakang();
    }
    else
    {
        Node *bantu = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            bantu = bantu->next;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

/// hapus list
void hapusList()
{
    while (!isEmpty())
    {
        hapusDepan();
    }
    cout << "List berhasil terhapus!" << endl;
}

void ubahDepan(string nama, int nim)
{
    if (!isEmpty())
    {
        head->nama = nama;
        head->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

/// ubah belakang
void ubahBelakang(string nama, int nim)
{
    if (!isEmpty())
    {
        tail->nama = nama;
        tail->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

/// ubah tengah
void ubahTengah(string nama, int nim, int posisi)
{
    if (posisi < 1 || posisi > hitung())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        ubahDepan(nama, nim);
    }
    else if (posisi == hitung())
    {
        ubahBelakang(nama, nim);
    }
    else
    {
        Node *bantu = head;
        for (int i = 1; i < posisi; i++)
        {
            bantu = bantu->next;
        }
        bantu->nama = nama;
        bantu->nim = nim;
    }
}

int main()
{
    int pilihOperasi, nim, posisi;
    string nama;
    menu:
    cout << "Program Circular Linked List" << endl;
    cout << "============================" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Hapus Depan" << endl;
    cout << "5. Hapus Belakang" << endl;
    cout << "6. Hapus Tengah" << endl;
    cout << "7. Ubah Depan" << endl;
    cout << "8. Ubah Belakang" << endl;
    cout << "9. Ubah Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. Tampilkan" << endl;
    cout << "0. KELUAR" << endl;
    cout << "Pilih Operasi : ";
    cin >> pilihOperasi;

    switch (pilihOperasi)
    {
    case 1:
        cout << "-Tambah Depan-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        TambahDepan(nama, nim);
        cout << "Data " << nama << " berhasil ditambahkan!" << endl;
        goto menu;
        break;

    case 2:
        cout << "-Tambah Belakang-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        TambahBelakang(nama, nim);
        cout << "Data " << nama << " berhasil ditambahkan!" << endl;
        goto menu;
        break;

    case 3:
        cout << "-Tambah Tengah-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        cout << "Masukan Posisi : ";
        cin >> posisi;
        TambahTengah(nama, nim, posisi);
        cout << "Data " << nama << " berhasil ditambahkan pada posisi " << posisi << "!" << endl;
        goto menu;
        break;

    case 4:
        cout << "-Hapus Depan-" << endl;
        hapusDepan();
        cout << "Data Depan berhasil dihapus!" << endl;
        goto menu;
        break;

    case 5:
        cout << "-Hapus Belakang-" << endl;
        hapusBelakang();
        cout << "Data Belakang berhasil dihapus!" << endl;
        goto menu;
        break;

    case 6:
        cout << "-Hapus Tengah-" << endl;
        cout << "Masukan Posisi : ";
        cin >> posisi;
        hapusTengah(posisi);
        cout << "Data pada posisi " << posisi << " berhasil dihapus!" << endl;
        goto menu;
        break;

    case 7:
        cout << "-Ubah Depan-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        ubahDepan(nama, nim);
        cout << "Data Depan berhasil diubah!" << endl;
        goto menu;
        break;

    case 8:
        cout << "-Ubah Belakang-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        ubahBelakang(nama, nim);
        cout << "Data Belakang berhasil diubah!" << endl;
        goto menu;
        break;

    case 9:
        cout << "-Ubah Tengah-" << endl;
        cout << "Masukan Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM : ";
        cin >> nim;
        cout << "Masukan Posisi : ";
        cin >> posisi;
        ubahTengah(nama, nim, posisi);
        cout << "Data pada posisi " << posisi << " berhasil diubah!" << endl;
        goto menu;
        break;

    case 10:
        cout << "-Hapus List-" << endl;
        hapusList();
        goto menu;
        break;

    case 11:
        cout << "-Data Mahasiswa-" << endl;
        tampilkan();
        goto menu;
        break;

    case 0:
        cout << "Keluar" << endl;
        cout << "Terima kasih" << endl;
        cout << "Keluar dari sistem" << endl;
        break;
    }
}

```

#### Output:
Input data Jawad dengan menu tambah depan :
![Screenshot (136)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/19573253-8bf1-46ec-b54d-9aa496bc5234)

Input data Carren dengan tambah tengah :
![Screenshot (137)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/a0e52127-0f4b-44a1-921c-93bad31b64df)

Input data Farrel dengan tambah belakang :
![Screenshot (138)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7207feb5-72e7-4a69-be8a-dc3b8eebd2d2)

Input data Wati dengan tambah tengah :
![Screenshot (140)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1f4d41ba-167d-4934-aaff-0033e80a176e)

Menghapus data Denis :
![Screenshot (142)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7562c318-4098-403a-b55b-0a97349235ae)

Input data Owi dengan tambah depan :
![Screenshot (144)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/aa45e328-7089-4fe6-a3c6-9c50783eb78e)

Input data David dengan tambah belakang :
![Screenshot (153)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f68e9d9d-c58f-47f7-8e08-0766be457398)

Mengubah data Udin menjadi Idin :
![Screenshot (145)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/16f6965f-2671-403a-9ac6-7a0dd00a52b5)

Mengubah data David menjadi Lucy :
![Screenshot (147)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/cb009a1a-9824-4f5f-a28a-132bf509f4b6)

Menghapus data awal :
![Screenshot (147)2](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/40014eaf-c04b-42c0-9723-bdfb99d0908b)

Mengubah data awal menjadi Bagas :
![Screenshot (149)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/e2d33312-e331-4812-b245-14094bfd8ac2)

Menghapus data terakhir :
![Screenshot (150)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/49c73f92-7cff-4bc2-9ca2-78ac85232429)

Tampilan semua data yang telah di input :
![Screenshot (156)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/9b8c25f8-87b4-459b-889e-8ea7075f7b7b)

Menu keluar :
![Screenshot (152)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/c9537a70-239a-4254-9542-1c454031e440)

#### Deskripsi Program : 
Program ini adalah sebuah implementasi dari Circular Linked List dalam bahasa C++. Circular Linked List adalah struktur data berbasis linked list di mana setiap elemen dalam list terhubung dengan elemen berikutnya dan elemen terakhir terhubung kembali ke elemen pertama, membentuk suatu lingkaran. Program ini memungkinkan pengguna untuk melakukan beberapa operasi dasar pada Circular Linked List, seperti menambahkan elemen di depan, belakang, atau di tengah, menghapus elemen dari depan, belakang, atau tengah, mengubah nilai elemen di depan, belakang, atau tengah, menghitung jumlah elemen dalam list, dan menampilkan seluruh elemen dalam list.

Struktur data yang digunakan dalam program ini adalah sebuah struktur `Node` yang memiliki dua variabel: `nim` untuk menyimpan Nomor Induk Mahasiswa dan `nama` untuk menyimpan nama mahasiswa. Struktur `Node` ini juga memiliki pointer `next` yang menunjukkan ke Node selanjutnya dalam list.

Program dimulai dengan pendefinisian fungsi-fungsi dasar seperti `init()` untuk menginisialisasi list, `isEmpty()` untuk memeriksa apakah list kosong, dan fungsi-fungsi lainnya seperti `TambahDepan()`, `TambahBelakang()`, `hapusDepan()`, `hapusBelakang()`, `tampilkan()`, dan lain-lain.

Di dalam fungsi `main()`, program menampilkan menu operasi yang tersedia kepada pengguna dan meminta masukan operasi yang diinginkan. Setelah operasi dipilih, program akan menjalankan fungsi yang sesuai dan kembali ke menu utama sampai pengguna memilih untuk keluar dari program.

Program ini merupakan implementasi sederhana dari Circular Linked List yang memungkinkan pengguna untuk menyimpan nama dan nim mahasiswa dan dapat memanipulasi data.

#### Full code Screenshot:
![carbon (6)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/ee61f144-e9ec-4dfd-a394-de59f4e27fe2)





## Kesimpulan

- Circular Linked List:

  Circular Linked List adalah jenis struktur data berantai di mana node terakhir menunjuk kembali ke node pertama, membentuk sebuah lingkaran.
  Keuntungan dari Circular Linked List adalah kemampuannya untuk memiliki akses ke node pertama dan terakhir dengan efisien tanpa harus melakukan traversal dari awal.
  Penerapan Circular Linked List cocok untuk implementasi struktur data yang memerlukan iterasi siklik atau penanganan sirkular, seperti manajemen memori dalam sistem operasi atau penjadwalan siklik dalam
  sistem real-time.

- Non-Circular Linked List:

  Non-Circular Linked List adalah struktur data berantai di mana node terakhir menunjuk ke null, sehingga tidak membentuk lingkaran.
  Pada Non-Circular Linked List, traversal dari awal ke akhir harus dilakukan secara eksplisit untuk mencapai node terakhir.
  Non-Circular Linked List biasanya lebih sederhana dalam implementasi dan manajemen daripada Circular Linked List, tetapi kurang efisien dalam beberapa operasi, terutama jika akses ke node terakhir sering
  diperlukan.

- Penambahan dan Penghapusan Elemen:

  Kedua jenis linked list ini memerlukan algoritma khusus untuk menambahkan dan menghapus elemen di depan, belakang, atau di tengah linked list.
  Pada Circular Linked List, perhatian khusus perlu diberikan untuk mengatur ulang pointer tail saat menambah atau menghapus elemen, karena node terakhir harus tetap menunjuk kembali ke node pertama.

- Iterasi dan Akses Data:

  Iterasi melalui elemen-elemen linked list dapat dilakukan dengan loop, baik menggunakan pendekatan while atau for, tergantung pada preferensi atau kebutuhan implementasi.
  Akses data pada elemen linked list harus memperhatikan pengecekan kekosongan linked list dan perlunya melakukan traversal dari awal untuk mengakses elemen tertentu.

## Referensi
[1] Drozdek, A. (2012). Data Structures and Algorithms in C++. (Edisi ke-4). Cengage Learning.
