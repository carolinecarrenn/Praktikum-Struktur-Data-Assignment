# <h1 align="center">Laporan Praktikum Modul Graph and Tree </h1>
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
1. Mahasiswa diharapkan mampu memahami graph dan tree
2. Mahasiswa diharapkan mampu mengimplementasikan graph dan tree pada pemrograman
   
## Dasar Teori

### Graph (Graf)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0df30c62-2443-4e11-a5fa-7b6a343f9fc9)

#### Definisi:

Sebuah graph adalah kumpulan dari simpul-simpul (vertices) yang terhubung oleh sisi-sisi (edges). 
Graph dapat digunakan untuk merepresentasikan berbagai jenis relasi antara objek.[1]

#### Jenis-jenis Graph:

- Directed Graph (Digraph):

  Setiap sisi memiliki arah tertentu.
  
  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/16180107-b73d-4201-9cc9-fa3a01744dcb)

  
- Undirected Graph:
  
  Sisi-sisi tidak memiliki arah.
  
  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/0ef82ecf-3885-46d1-8a60-86e67fe1cce9)

  
- Weighted Graph:
  
  Setiap sisi memiliki bobot (weight) yang mengindikasikan biaya atau jarak antara dua simpul.
  
  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/d95138c2-53d3-4ff3-9f35-c58b834b21e8)

- Acyclic Graph:
  
  Graph yang tidak memiliki siklus.
  
  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/3bb78664-b8ba-466b-96fa-6f65a68a5a12)

  
- Cyclic Graph:

  Graph yang memiliki setidaknya satu siklus.

  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/95cb33e1-6c83-4de1-ac2b-ff5c7144b73e)

  
- Representasi Graph:

  Graph dapat direpresentasikan menggunakan matriks adjasensi, daftar adjasensi, atau representasi lainnya tergantung pada kebutuhan spesifik algoritma yang digunakan.[1]

  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/fc918932-bf74-41b5-a3fa-8ef18202e5ea)

#### Karakteristik Graph :
Graph memiliki beberapa karakteristik sebagai berikut:

- Jarak maksimum dari sebuah simpul ke semua simpul lainnya dianggap sebagai eksentrisitas dari simpul tersebut.
- Titik yang memiliki eksentrisitas minimum dianggap sebagai titik pusat dari graph.
- Nilai eksentrisitas minimum dari semua simpul dianggap sebagai jari-jari dari graph terhubung.

#### Fungsi dan Kegunaan Graph :
Fungsi dan kegunaan graph di antaranya:

- Graph digunakan untuk merepresentasikan aliran komputasi.
- Digunakan dalam pemodelan grafik.
- Graph dipakai pada sistem operasi untuk alokasi sumber daya.
- Google maps menggunakan graph untuk menemukan rute terpendek.
- Graph digunakan dalam sistem penerbangan untuk optimasi rute yang efektif.
- Pada state-transition diagram, graph digunakan untuk mewakili state dan transisinya.
- Di sirkuit, graph dapat digunakan untuk mewakili titik sirkuit sebagai node dan kabel sebagai edge.
- Graph digunakan dalam memecahkan teka-teki dengan hanya satu solusi, seperti labirin.
- Graph digunakan dalam jaringan komputer untuk aplikasi Peer to peer (P2P).
- Umumnya graph dalam bentuk DAG (Directed acyclic graph) digunakan sebagai alternatif blockchain untuk cryptocurrency. Misalnya crypto seperti IOTA

#### Kelebihan Graph : 
Keunggulan dari struktur data graph adalah :

- Dengan menggunakan graph kita dapat dengan mudah menemukan jalur terpendek dan tetangga dari node
- Graph digunakan untuk mengimplementasikan algoritma seperti DFS dan BFS.
- Graph membantu dalam mengatur data.
- Karena strukturnya yang non-linier, membantu dalam memahami masalah yang kompleks dan visualisasinya.

#### Kekurangan Graph :
Adapun kekurangan dari struktur data graph di antaranya

- Graph menggunakan banyak pointer yang bisa rumit untuk ditangani.
- Memiliki kompleksitas memori yang besar.
- Jika graph direpresentasikan dengan adjacency matrix maka edge tidak memungkinkan untuk sejajar dan operasi perkalian graph juga sulit dilakukan.
  

### Tree (Pohon)

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/2895ae89-e3b4-4d80-97c6-699b360ce85c)

Sebuah tree adalah jenis khusus dari graph yang tidak memiliki siklus. Dengan kata lain, setiap dua simpul dalam pohon terhubung oleh tepat satu jalur.[1]

#### Struktur Pohon: 

Pohon terdiri dari simpul-simpul yang terhubung oleh tepat satu jalur. 
Sebuah simpul khusus disebut sebagai akar (root), dan setiap simpul memiliki tepat satu simpul yang disebut sebagai induk (parent), kecuali akar. 
Simpul-simpul lainnya dibagi menjadi anak-anak (children) dari simpul induk tersebut.

#### Istilah-istilah pada Tree :

- Create :
  
  Membentuk binary tree baru yang masih kosong.
  
- Clear :

  Mengosongkan binary tree yang sudah ada.

- Empty :

  Function untuk memeriksa apakah binary tree masih kosong.

- Insert :

  Memasukkan sebuah node ke dalam tree. Ada tiga pilihan insert: sebagai root, left child, atau right child. Khusus insert sebagai root, tree harus dalam keadaan kosong.

- Find :

  Mencari root, parent, left child, atau right child dari suatu node. (Tree tak boleh kosong).

- Update :

  Mengubah isi dari node yang ditunjuk oleh pointer current. (Tree tidak boleh kosong)

- Retrieve :

  Mengetahui isi dari node yang ditunjuk pointer current. (Tree tidak boleh kosong)

- DeleteSub :

  Menghapus sebuah subtree (node beserta seluruh descendantnya) yang ditunjuk current. Tree tak boleh kosong. Setelah itu pointer current akan berpindah ke parent dari node yang dihapus.

- Characteristic :

  Mengetahui karakteristik dari suatu tree, yakni : size, height, serta average lengthnya. Tree tidak boleh kosong.

- Traverse :

  Mengunjungi seluruh node-node pada tree, masing-masing sekali. Hasilnya adalah urutan informasi secara linier yang tersimpan dalam tree. Adatiga cara traverse : Pre Order, In Order, dan Post Order.

  Langkah-Langkahnya Traverse :
  - PreOrder :
    Cetak isi node yang dikunjungi, kunjungi Left Child, kunjungi Right Child.
  - InOrder :
    Kunjungi Left Child, Cetak isi node yang dikunjungi, kunjungi Right Child.
  - PostOrder :
    Kunjungi Left Child, Kunjungi Right Child, cetak isi node yang dikunjungi.


#### Jenis-jenis Tree :

- Binary Tree :

  Setiap simpul memiliki paling banyak dua anak.
  
  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7c9d3a86-72e7-4f8f-a94c-ef758e433d9e)
  
- Binary Search Tree (BST) :
  
  Sebuah binary tree di mana setiap simpul memiliki nilai yang lebih besar daripada semua simpul di subpohon kiri dan lebih kecil daripada semua simpul di subpohon kanan.

  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/6269902a-983c-4880-90ab-1068aa13b85d)
  
- Balanced Tree :

  Sebuah pohon di mana tinggi subpohon kiri dan kanan dari setiap simpul tidak boleh berbeda lebih dari satu.

  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/ef61150d-b153-4163-81ed-81690ef0e381)
  
- Representasi Tree :

  Pohon dapat direpresentasikan menggunakan struktur data seperti struktur node, matriks adjasensi jika diperlukan, atau dalam bentuk representasi lain yang sesuai dengan algoritma yang digunakan.

  ![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/3fb8f824-af57-489e-b8bd-fd4c867eac01)

#### Karakteristik Tree :
Adapun karakteristik dari struktur data tree adalah sebagai berikut:

- Penjelahan data (traversing) pada tree dilakukan oleh algoritma Depth First Search dan Breadth First Search
- Tidak ada loop dan circuit
- Tidak memiliki self-loop
- Disusun dalam model hierarki

#### Fungsi dan Kegunaan Tree :
Berikut adalah fungsi dan kegunaan dari struktur data tree

- Dalam kehidupan nyata, struktur data tree membantu dalam pengembangan game.
- Membantu pengindeksan pada database.
- Decision Tree adalah tools yang biasanya digunakan dalam analisis keputusan. Metode ini memiliki struktur seperti diagram alur yang membantu untuk memahami data.
- Domain Name Server juga menggunakan struktur data tree.
- Kasus penggunaan tree yang paling umum adalah situs jejaring sosial, seperti Facebook, Instagram, Twitter, dll.


#### Keunggulan Strukur Data Tree :
Berikut adalah beberapa keunggulan atau kelebihan dari tree:

- Memungkinan subtree untuk dipindahkan dengan usaha yang minim.
- Mencerminkan hubungan data secara struktural.
- Menawarkan operasi pencarian dan penyisipan yang efisien.
- Tree sangat baik digunakan untuk membuat hierarki data.

## Guided 

### 1. [Program Graph]
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <iomanip>
using namespace std;

// Array yang berisi nama-nama simpul
string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "Tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

// Matriks yang merepresentasikan bobot antara simpul-simpul
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

// Fungsi untuk menampilkan graf
void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

// Fungsi utama
int main() {
    tampilGraph(); // Memanggil fungsi untuk menampilkan graf
    return 0;
}
```

#### Output :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/2d1fe998-6a3e-4bea-9ab4-d140cfece056)

#### Deskripsi Program : 
Program ini adalah sebuah program yang mengimplementasikan representasi graf menggunakan matriks berbobot. 
Program ini menyediakan data tentang simpul-simpul (node) dan bobot-bobot (weight) antar simpul-simpul tersebut.

- Array `simpul` menyimpan nama-nama simpul dalam graf, yang dalam konteks ini adalah nama-nama kota.
- Matriks `busur` merepresentasikan bobot antara simpul-simpul. Indeks baris dan kolom dari matriks ini menunjukkan simpul asal dan simpul tujuan, sedangkan nilai di dalamnya menunjukkan bobot dari sambungan (edge) antara simpul-simpul tersebut.
- Fungsi `tampilGraph()` digunakan untuk menampilkan representasi graf ke layar. Ini mencetak nama-nama simpul beserta sambungan (edge) dan bobotnya.
- Dalam `main()`:
  1. Dipanggil `tampilGraph()` untuk menampilkan representasi graf.

Program ini menciptakan representasi graf berbobot yang dapat digunakan untuk memodelkan jaringan perjalanan antar kota, misalnya, dengan menghitung rute terpendek atau biaya perjalanan antar kota.

### Full code Screenshot :
![carbon](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/23755f1e-f592-4803-9580-1efeb059f12e)


### 2. [Program Tree]
```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

// Pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

// Fungsi pembuatan node baru
Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Fungsi untuk membuat node baru sebagai root
void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Fungsi untuk menyisipkan node baru sebagai child kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah memiliki child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk menyisipkan node baru sebagai child kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah memiliki child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk mengubah data sebuah node
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Fungsi untuk menampilkan data sebuah node
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Fungsi untuk menemukan dan menampilkan informasi tentang sebuah node
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Fungsi penelusuran (Traversal)
// PreOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// InOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// PostOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Fungsi untuk menghapus seluruh tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Fungsi untuk menghapus subtree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghapus tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghitung ukuran tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Fungsi untuk menghitung tinggi level tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            return max(heightKiri, heightKanan) + 1;
        }
    }
}

// Fungsi untuk menampilkan karakteristik tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}
```

#### Output :
![Screenshot 2024-05-28 184029](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/7cbdb321-8e90-4ff6-87ed-65ee4d734d0c)
![Screenshot 2024-05-28 184047](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/34cc1f30-206d-40fe-9156-03fc202a9d90)


#### Deskripsi Program : 
Program ini adalah implementasi dari struktur data Pohon (Tree). Pohon ini merupakan pohon biner, di mana setiap node memiliki maksimal dua anak, yaitu kiri dan kanan.

Berikut adalah beberapa fungsi utama dalam program ini:

1. `init()`: Menginisialisasi pohon dengan menetapkan root menjadi NULL.
2. `isEmpty()`: Memeriksa apakah pohon kosong atau tidak.
3. `newPohon(char data)`: Membuat node baru dengan data tertentu.
4. `buatNode(char data)`: Membuat node baru dan menetapkannya sebagai root jika pohon kosong.
5. `insertLeft(char data, Pohon *node)`: Menyisipkan node baru sebagai anak kiri dari node tertentu.
6. `insertRight(char data, Pohon *node)`: Menyisipkan node baru sebagai anak kanan dari node tertentu.
7. `update(char data, Pohon *node)`: Mengubah data dari suatu node.
8. `retrieve(Pohon *node)`: Menampilkan data dari suatu node.
9. `find(Pohon *node)`: Menampilkan informasi tentang suatu node, seperti data, root, parent, sibling, dan anak-anaknya.
10. `preOrder(Pohon *node)`, `inOrder(Pohon *node)`, `postOrder(Pohon *node)`: Melakukan penelusuran pre-order, in-order, dan post-order pada pohon.
11. `deleteTree(Pohon *node)`: Menghapus seluruh pohon.
12. `deleteSub(Pohon *node)`: Menghapus subtree yang dimulai dari suatu node.
13. `clear()`: Menghapus seluruh pohon.
14. `size(Pohon *node)`: Menghitung jumlah node dalam pohon.
15. `height(Pohon *node)`: Menghitung tinggi pohon.
16. `characteristic()`: Menampilkan karakteristik pohon, seperti ukuran (size), tinggi (height), dan rata-rata jumlah node per tingkat.

Dalam `main()`:

- Inisialisasi pohon dilakukan menggunakan `init()` dan membuat node root 'A' dengan `buatNode('A')`.
- Beberapa node tambahan ditambahkan ke pohon menggunakan `insertLeft()` dan `insertRight()`.
- Beberapa operasi dilakukan, seperti mengubah data suatu node, menampilkan informasi tentang suatu node, melakukan penelusuran pada pohon, menghitung karakteristik pohon, dan menghapus subtree.
- Hasil operasi seperti pre-order traversal, in-order traversal, dan post-order traversal ditampilkan.
- Akhirnya, karakteristik pohon setelah penghapusan subtree juga ditampilkan.
  
### Full code Screenshot :
![carbon (1)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1579a264-2d98-48a3-aae9-f49b2a800cb3)

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
dengan output sebagai berikut : 
       
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/66b30df8-e9a9-460e-be39-44d0d11ff610)

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int caroline_2311102174;
int main() {
  int jumlah_simpul;
  cout << "Silakan masukan jumlah simpul : ";
  cin >> jumlah_simpul;

  vector<string> nama_simpul(jumlah_simpul);
  cout << "Silakan masukan nama simpul" << endl;
  for (int i = 0; i < jumlah_simpul; i++) {
    cout << "Simpul " << i + 1 << " ";
    cin >> nama_simpul[i];
  }

  vector<vector<int>> bobot_antar_simpul(jumlah_simpul, vector<int>(jumlah_simpul, 0));
  cout << "Silakan masukkan bobot antar simpul" << endl;
  for (int i = 0; i < jumlah_simpul; i++) {
    for (int j = 0; j < jumlah_simpul; j++) {
      cout << nama_simpul[i] << " --> " << nama_simpul[j] << " = ";
      cin >> bobot_antar_simpul[i][j];
    }
  }

  cout << "Simpul\t";
  for (int i = 0; i < jumlah_simpul; i++) {
    cout << nama_simpul[i] << "\t";
  }
  cout << endl;

  for (int i = 0; i < jumlah_simpul; i++) {
    cout << nama_simpul[i] << "\t";
    for (int j = 0; j < jumlah_simpul; j++) {
      cout << bobot_antar_simpul[i][j] << "\t";
    }
    cout << endl;
  }

  return 0;
}
```

### Output:

![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1b840bdc-6615-4f19-86ba-c38076e0ab28)

### Deskripsi Program : 
Program ini adalah sebuah program yang memungkinkan pengguna untuk memasukkan jumlah simpul (node) dalam graf, nama-nama simpul, dan bobot antar simpul tersebut. 
Program kemudian menampilkan matriks berbobot yang merepresentasikan hubungan antar simpul.

Berikut adalah deskripsi dari program tersebut:

1. Pengguna diminta untuk memasukkan jumlah simpul dalam graf.
2. Array `nama_simpul` digunakan untuk menyimpan nama-nama simpul yang dimasukkan oleh pengguna.
3. Matriks `bobot_antar_simpul` digunakan untuk menyimpan bobot antar simpul yang dimasukkan oleh pengguna.
4. Pengguna diminta untuk memasukkan bobot antar setiap pasangan simpul.
5. Program menampilkan matriks berbobot yang merepresentasikan hubungan antar simpul. Setiap baris dan kolom menunjukkan simpul-simpul yang dimasukkan pengguna, dan nilai di dalamnya menunjukkan bobot antar simpul-simpul tersebut.

Program ini memberikan kemampuan bagi pengguna untuk dengan mudah memasukkan data tentang graf berbobot, yang dapat digunakan dalam berbagai aplikasi, seperti perencanaan rute atau jaringan transportasi.

### Full code Screenshot:
![carbon (2)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1ed6de55-3447-4c15-a26c-b64617d69951)

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
using namespace std;

int caroline_2311102174;

// Deklarasi Struktur Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // Pointer
};

// Pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

// Pengecekan apakah pohon kosong
bool isEmpty() {
    return root == NULL;
}

// Fungsi untuk membuat node baru
Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Fungsi untuk menambahkan node sebagai root
void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Fungsi untuk menambahkan node anak kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk menambahkan node anak kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk pembaruan data node
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Fungsi untuk pengambilan data node
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Fungsi untuk mencari node
Pohon *find(char data) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        Pohon *current = root;
        while (current != NULL) {
            if (current->data == data) {
                return current;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return NULL;
    }
}

// Fungsi untuk menampilkan node child dari node yang diinputkan
void showChild(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            if (node->left)
                cout << "Child kiri: " << node->left->data << endl;
            if (node->right)
                cout << "Child kanan: " << node->right->data << endl;
        }
    }
}

// Fungsi untuk menampilkan node descendant dari node yang diinputkan
void showDescendant(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            if (node->left) {
                cout << "Descendant kiri: ";
                showDescendant(node->left);
            }
            if (node->right) {
                cout << "Descendant kanan: ";
                showDescendant(node->right);
            }
            if (!node->left && !node->right)
                cout << node->data << " ";
        }
    }
}

// Fungsi utama
int main() {
    int pilih;
    char dataChar, parentChar;
    Pohon *node, *parent;

    // Inisialisasi pohon
    init();

    do {
        system("cls");
        cout << "1. Buat Root" << endl;
        cout << "2. Tambah Node" << endl;
        cout << "3. Update Node" << endl;
        cout << "4. Retrieve Data Node" << endl;
        cout << "5. Cari Node" << endl;
        cout << "6. Tampilkan Child Node" << endl;
        cout << "7. Tampilkan Descendant Node" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> dataChar;
                buatNode(dataChar);
                break;
            case 2:
                cout << "Masukkan data node: ";
                cin >> dataChar;
                cout << "Masukkan data parent: ";
                cin >> parentChar;
                parent = find(parentChar);
                if (parent != NULL) {
                    char childPosition;
                    cout << "Masukkan posisi child (kiri/l/kanan/r): ";
                    cin >> childPosition;
                    if (childPosition == 'l')
                        insertLeft(dataChar, parent);
                    else if (childPosition == 'r')
                        insertRight(dataChar, parent);
                    else
                        cout << "Posisi child tidak valid!" << endl;
                } else {
                    cout << "Parent tidak ditemukan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> dataChar;
                node = find(dataChar);
                if (node != NULL) {
                    char newData;
                    cout << "Masukkan data baru: ";
                    cin >> newData;
                    update(newData, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "Masukkan data node yang ingin diretrieve: ";
                cin >> dataChar;
                node = find(dataChar);
                if (node != NULL) {
                    retrieve(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> dataChar;
                node = find(dataChar);
                if (node != NULL) {
                    cout << "Node ditemukan!" << endl;
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 6:
                cout << "Masukkan data node yang ingin ditampilkan childnya: ";
                cin >> dataChar;
                node = find(dataChar);
                if (node != NULL) {
                    showChild(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 7:
                cout << "Masukkan data node yang ingin ditampilkan descendantnya: ";
                cin >> dataChar;
                node = find(dataChar);
                if (node != NULL) {
                    cout << "Descendant dari node " << dataChar << " adalah: ";
                    showDescendant(node);
                    cout << endl;
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 8:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        system("pause");
    } while (pilih != 8);

    return 0;
}
```

### Output:
#### Contoh Buat Root :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/6028dcd1-754b-4f41-acf8-722fa516128f)

#### Contoh Tambah Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/50d01b14-d8cc-4c43-beba-6bef7ffd931b)
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/88e19c2b-e98d-463b-b381-41eef9f0ecb7)

#### Contoh Update Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/269c978f-7742-42a9-9e2a-75b2fd9c5e1f)

#### Contoh Retrieve Data Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/72861d2b-22d7-4cfb-887c-2e8e10bef867)

#### Contoh Cari Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1441c71e-c7fc-4a24-bef5-49908a9a3582)

#### Contoh Tampilkan Child Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/8f2ef27d-eff5-4fe6-94d9-9d776c750d2f)

#### Contoh Tampilkan Descendant Node :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/26f0714b-f81c-43c7-a72c-2b5c432d49da)

#### Contoh Keluar :
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/28816a69-1317-4f35-a2d7-93a8de6975a9)

### Deskripsi Program : 
Program ini adalah implementasi dari sebuah struktur data Pohon (Tree). Pohon ini merupakan pohon biner pencarian (Binary Search Tree atau BST), yang memiliki sifat bahwa setiap node memiliki nilai yang lebih kecil dari nilai node yang berada di sebelah kanannya, dan lebih besar dari nilai node yang berada di sebelah kirinya.

Berikut adalah deskripsi dari program tersebut :
1. `init()`: Menginisialisasi pohon dengan menetapkan root menjadi NULL.
2. `isEmpty()`: Memeriksa apakah pohon kosong atau tidak.
3. `newPohon(char data)`: Membuat node baru dengan data tertentu.
4. `buatNode(char data)`: Membuat node baru dan menetapkannya sebagai root jika pohon kosong.
5. `insertLeft(char data, Pohon *node)`: Menyisipkan node baru sebagai anak kiri dari node tertentu.
6. `insertRight(char data, Pohon *node)`: Menyisipkan node baru sebagai anak kanan dari node tertentu.
7. `update(char data, Pohon *node)`: Mengubah data dari suatu node.
8. `retrieve(Pohon *node)`: Menampilkan data dari suatu node.
9. `find(char data)`: Mencari node dengan data tertentu dalam pohon.
10. `showChild(Pohon *node)`: Menampilkan node anak dari suatu node.
11. `showDescendant(Pohon *node)`: Menampilkan semua turunan dari suatu node.

Dalam `main()`:

- Terdapat sebuah loop `do-while` yang memberikan menu interaktif kepada pengguna untuk melakukan berbagai operasi pada pohon.
- Pengguna dapat melakukan operasi seperti membuat root, menambahkan node, mengubah data node, mencari node, menampilkan anak dan turunan dari suatu node, serta keluar dari program.

Program ini memberikan fleksibilitas kepada pengguna untuk memanipulasi dan mengeksplorasi struktur pohon secara interaktif.

### Full code Screenshot:
![carbon (3)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/2f8708b0-21d5-4039-8561-9af98aebe003)

## Kesimpulan
Berikut adalah kesimpulan dari praktikum yang telah dilakukan :

1. Pentingnya Representasi Data :
   Pada praktikum graph dan tree menekankan pentingnya cara kita menyimpan informasi tentang hubungan antara entitas. Ini memungkinkan kita untuk melakukan operasi pada data dengan lebih mudah dan efisien.

2. Penggunaan Struktur Data :
   Graph dan tree adalah alat yang berguna dalam pemrograman. Mereka membantu kita memecahkan masalah seperti perutean, analisis jaringan, dan pencarian data dengan lebih baik.

3. Algoritma dan Operasi :
   Pada praktikum ini memperkenalkan beberapa algoritma dan operasi yang umum digunakan, seperti pencarian, penelusuran, penambahan, penghapusan, dan pembaruan data. Memahami algoritma ini membantu dalam mengoptimalkan kinerja aplikasi.

4. Pemodelan Masalah :
   Graph dan tree dapat digunakan untuk memodelkan berbagai masalah dalam kehidupan nyata, seperti jaringan transportasi atau struktur hirarkis. Ini membantu dalam mencari solusi yang optimal untuk masalah-masalah tersebut.

5. Kompleksitas dan Kinerja :
   Memahami kompleksitas operasi pada graph dan tree penting untuk memilih representasi yang sesuai dan mengoptimalkan kinerja aplikasi. Praktikum ini membantu dalam memahami kapan kita harus menggunakan struktur data tertentu dan bagaimana cara mengatasi masalah kinerja.

## Referensi
[1]  T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, MA, USA: MIT Press, 2009.
