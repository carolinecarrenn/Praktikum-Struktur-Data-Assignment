# <h1 align="center">Laporan Praktikum Modul Linked List Circular and Non Circular</h1>
<p align="center">Caroline Carren (2311102174)</p>

## Dasar Teori

Linked list adalah struktur data linear di mana setiap elemen disebut node, dan setiap node terdiri dari dua bagian: data dan pointer yang menunjuk ke node berikutnya dalam urutan. 
Ada dua jenis utama linked list: linked list linear (non-circular) dan linked list circular.[1]

1. **Linked List Linear (Non Circular)** :
  
   Linked list non-circular adalah struktur data linier di mana setiap elemen atau node terhubung dengan node berikutnya dalam urutan tertentu.
   Dalam linked list non-circular, setiap node memiliki dua bagian utama: data yang berisi nilai aktual dan pointer yang menunjuk ke node berikutnya dalam linked list.[1]

   Operasi Dasar:
   - Insertion: Menambahkan elemen baru ke linked list di posisi tertentu, seperti di awal, akhir, atau setelah node tertentu.
   - Deletion: Menghapus elemen tertentu dari linked list.
   - Traversal: Mengunjungi setiap node dalam linked list, biasanya dimulai dari awal hingga akhir.
   
   Kelebihan Linked List Non-Circular:
   - Fleksibilitas dalam penambahan dan penghapusan elemen, terutama di tengah-tengah linked list.
   - Ruang memori yang efisien karena node-node hanya membutuhkan ruang tambahan untuk pointer.
   
   Kekurangan Linked List Non-Circular:
   - Memerlukan pencarian linier untuk mengakses elemen tertentu, tidak seperti array yang dapat diakses secara langsung dengan indeks.[1]

   Contoh program non circular :
```C++
#include <iostream>

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display()
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.display();
    return 0;
}  
```

2.  **Linked List Circular**
   
    Linked list circular adalah variasi dari linked list di mana node terakhir dalam linked list mengarah kembali ke node pertama, membentuk lingkaran atau siklus.
    Ini berarti tidak ada elemen yang memiliki pointer yang menunjuk ke nilai null.

    Operasi Dasar:
    - Operasi pada linked list circular mirip dengan operasi pada linked list non-circular. Namun, traversal perlu memperhatikan kondisi terminasi agar tidak jatuh ke dalam loop tak terbatas.
    
    Kelebihan Linked List Circular:
    - Tidak memerlukan pengecekan pointer null saat melakukan traversal atau operasi lainnya
    - Cocok untuk implementasi struktur data berulang seperti buffer lingkaran atau antrian siklus.
    
    Kekurangan Linked List Circular:
    - Memerlukan perhatian khusus dalam implementasi untuk mencegah deadlock atau loop tak terbatas.
    - Pemeliharaan tambahan diperlukan untuk memastikan bahwa tidak ada siklus yang rusak atau tidak valid.
  
    Contoh program circular :
```C++
#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;
public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void add_node(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display()
    {
        Node *temp = head;
        if (head == NULL)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        do
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        std::cout << " " << std::endl;
    }
};

int main()
{
    CircularLinkedList list;
    list.add_node(1);
    list.add_node(2);
    list.add_node(3);
    list.display();
    return 0;
}
```


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

### 1. [Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. ]

#### Program Non Circular Linked List

```C++
/// CAROLINE CARREN
/// 2311102174

#include <iostream>
using namespace std;

// Deklarasi struct node
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

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void TambahDepan(string nama, int nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    } else 
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void TambahBelakang(string nama, int nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung List
int hitung(){
    Node *count;
    count = head;
    int jumlah = 0;
    while (count != NULL){
        jumlah++;
        count = count->next;
    }
    return jumlah;
}

// Tambah Tengah
void TambahTengah(string nama, int nim, int posisi)
{
    if (posisi < 1 || posisi > hitung ()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->nama = nama;
        baru->nim = nim;

        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1 ) {
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
    Node *del;
    if (isEmpty() == false) {
        if (head->next != NULL) {
            del = head;
            head = head->next;
            delete del;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (isEmpty() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu = nullptr;
    Node *hapus = nullptr;
    Node *sebelum = nullptr;

    if (posisi < 1 || posisi > hitung()) {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor < posisi) {
            if (nomor == posisi - 1) {
                sebelum = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }

        if (nomor == posisi) {
            hapus = bantu;
        }

        bantu = bantu->next;
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(string nama, int nim)
{
    if (isEmpty() == 0) {
        head->nama = nama;
        head->nim = nim;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(string nama, int nim, int posisi) {
    Node *bantu;
    if (isEmpty() == 0) {
        if (posisi < 1 || posisi > hitung()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->nama = nama;
            bantu->nim = nim;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(string nama, int nim) {
    if (isEmpty() == 0) {
        tail->nama = nama;
        tail->nim = nim;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void hapusList() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampilkan() {
    Node *bantu;
    bantu = head;
    if (isEmpty() == false) {
        int u = 1;
        cout << "No." << "\t" << "Nama Mahasiswa" << "\t" << "NIM Mahasiswa" << endl;
        while (bantu != NULL) {
            cout << u++ << "\t" << bantu->nama << "\t" << "\t" << bantu->nim << endl;
            bantu = bantu->next;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}





int main() {
    int pilihOperasi, nim, posisi;
    string nama;
    menu:
    cout << "Program Single Linked List Non-Circular" << endl;
    cout << "=======================================" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. Tampilkan" << endl;
    cout << "0. KELUAR" << endl;
    cout << "Pilih Operasi : ";
    cin >> pilihOperasi;

    switch (pilihOperasi) {
    case 1:
        cout << "-Tambah Depan-" << endl;
        cout << endl;
        cout << "Masukan Nama :";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukan NIM :";
        cin.ignore();
        cin >> nim;
        TambahDepan(nama, nim);
        cout << "Data " << nama << " berhasil diinput!" << endl;
        
        goto menu;
        
        break;

    case 2:
        cout << "Tambah Belakang" << endl;
        cout << endl;
        int jml;
        cout << "Masukan jumlah data yang diinputkan: ";
        cin >> jml;
        for (int u = 1; u <= jml; u++) {
            cout << "Masukan Nama :";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan NIM :";
            cin >> nim;
            TambahBelakang(nama, nim);
        }

        goto menu;
        
        break;

    case 3:
    cout << "-Tambah Tengah-" << endl;
    cout << endl;
    cout << "Masukan Nama : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukan NIM : ";
    cin >> nim;
    cout << "Masukan Posisi : ";
    cin >> posisi;
    TambahTengah(nama, nim, posisi);
    cout << "Data " << nama << " berhasil diinput!" << endl;
    
    goto menu;
    
    break;
    
    case 4:
    cout << "-Ubah Depan-" << endl;
    cout << endl;
    cout << "Masukan Nama : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukan NIM : ";
    cin >> nim;
    ubahDepan(nama, nim);

    goto menu;

    break;
    
    case 5:
    cout << "-Ubah Belakang-" << endl;
    cout << endl;
    cout << "Masukan Nama lama : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukan NIM lama : ";
    cin >> nim;
    ubahBelakang(nama, nim);
    
    goto menu;
    
    break;

case 6:
    cout << "-Ubah Tengah-" << endl;
    cout << endl;
    cout << "Masukan Nama: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukan NIM : ";
    cin >> nim;
    cout << "Posisi : ";
    cin >> posisi;
    ubahTengah(nama, nim, posisi);
    
    goto menu;
    
    break;

    case 7:
    cout << "Hapus Depan" << endl;
    hapusDepan();
    cout << "Data Depan berhasil terhapus!" << endl;
    
    goto menu;
    
    break;

case 8:
    cout << "Hapus Belakang" << endl;
    hapusBelakang();
    cout << "Data Belakang berhasil terhapus!" << endl;
    
    goto menu;
    
    break;

case 9:
    cout << "Hapus Tengah" << endl;
    cout << "Masukan Posisi : ";
    cin >> posisi;
    hapusTengah(posisi);
    cout << "Data Tengah berhasil terhapus!" << endl;
    
    goto menu;
    
    break;

case 10:
    hapusList();
    
    goto menu;
    
    break;

case 11:
    cout << "Tampilkan" << endl;
    tampilkan();
    
    goto menu;
    
    break;

case 0:
    cout << "Keluar" << endl;
    cout << "Terima kasih" << endl;
    cout << "keluar dari sistem" << endl;
    exit(0);
    break;

   
    }
}
```
#### Output:


#### Deskripsi Program : 
Program ini merupakan implementasi dari Single Linked List Non-Circular menggunakan bahasa pemrograman C++. 
Single Linked List adalah struktur data berantai di mana setiap node memiliki pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk ke null. 
Program ini memiliki fungsi-fungsi dasar untuk manipulasi linked list, seperti penambahan (tambah depan, tambah belakang, tambah tengah), penghapusan (hapus depan, hapus belakang, hapus tengah), pengubahan (ubah depan, ubah belakang, ubah tengah), dan penampilan (tampilkan).

#### Full code Screenshot:
![carbon](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/e885a44b-6f01-449b-ac6b-5dd81f98f878)


#### Program Circular Linked List


```C++
/// CAROLINE CARREN
/// 2311102174

#include <iostream>
using namespace std;

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

bool isEmpty()
{
    return (head == NULL);
}

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
        cout << "-Tampilkan-" << endl;
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


#### Deskripsi Program : 
Program ini merupakan implementasi dari Circular Linked List menggunakan bahasa pemrograman C++. 
Circular Linked List adalah struktur data berantai di mana setiap node terhubung ke node berikutnya dan node terakhir terhubung kembali ke node pertama.
Program ini menggunakan konsep menu-driven, di mana pengguna diminta untuk memilih operasi yang ingin dilakukan pada linked list melalui angka yang sesuai dengan menu. 
Setelah operasi selesai dilakukan, pengguna akan kembali ke menu utama kecuali jika pengguna memilih untuk keluar dari program dengan memilih angka 0. 
Program ini menggunakan konsep loop menggunakan label menu: dan goto menu untuk kembali ke menu utama setelah operasi selesai dilakukan.
#### Full code Screenshot:
![carbon (1)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/fc51b39d-0e7f-41b7-a849-8fa74bba44e6)


## Kesimpulan

Circular Linked List:

Circular Linked List adalah jenis struktur data berantai di mana node terakhir menunjuk kembali ke node pertama, membentuk sebuah lingkaran.
Keuntungan dari Circular Linked List adalah kemampuannya untuk memiliki akses ke node pertama dan terakhir dengan efisien tanpa harus melakukan traversal dari awal.
Penerapan Circular Linked List cocok untuk implementasi struktur data yang memerlukan iterasi siklik atau penanganan sirkular, seperti manajemen memori dalam sistem operasi atau penjadwalan siklik dalam sistem real-time.

Non-Circular Linked List:

Non-Circular Linked List adalah struktur data berantai di mana node terakhir menunjuk ke null, sehingga tidak membentuk lingkaran.
Pada Non-Circular Linked List, traversal dari awal ke akhir harus dilakukan secara eksplisit untuk mencapai node terakhir.

Non-Circular Linked List biasanya lebih sederhana dalam implementasi dan manajemen daripada Circular Linked List, tetapi kurang efisien dalam beberapa operasi, terutama jika akses ke node terakhir sering diperlukan.
Penambahan dan Penghapusan Elemen:

Kedua jenis linked list ini memerlukan algoritma khusus untuk menambahkan dan menghapus elemen di depan, belakang, atau di tengah linked list.
Pada Circular Linked List, perhatian khusus perlu diberikan untuk mengatur ulang pointer tail saat menambah atau menghapus elemen, karena node terakhir harus tetap menunjuk kembali ke node pertama.
Iterasi dan Akses Data:

Iterasi melalui elemen-elemen linked list dapat dilakukan dengan loop, baik menggunakan pendekatan while atau for, tergantung pada preferensi atau kebutuhan implementasi.
Akses data pada elemen linked list harus memperhatikan pengecekan kekosongan linked list dan perlunya melakukan traversal dari awal untuk mengakses elemen tertentu.

## Referensi
[1] Drozdek, A. (2012). Data Structures and Algorithms in C++. (Edisi ke-4). Cengage Learning.
