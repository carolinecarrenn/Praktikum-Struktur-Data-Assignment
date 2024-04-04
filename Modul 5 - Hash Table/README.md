# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Caroline Carren Aurelia R</p>
<p align="center">2311102174</p>
<p align="center">IF 11 E</p>

## Tujuan Praktikum 
1. Mahasiswa mampu menjelaskan definisi dan konsep dari Hash Code
2. Mahasiswa mampu menerapkan Hash Code kedalam pemrograman
   
## Dasar Teori
![image](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/dc38d27e-70fe-4fb1-9632-05bac21bd83f)

1. Pengertian Hash Table

   Hash table adalah struktur data yang memetakan kunci (key) ke nilai (value) dengan menggunakan fungsi hash.
   Fungsi hash mengubah kunci menjadi indeks dalam tabel, di mana nilai yang terkait disimpan.
   Hash table memungkinkan akses data yang cepat dan efisien berdasarkan kuncinya.[1]
  
2. Cara Kerja Hash Table

   a. Fungsi Hash:
   
   Sebuah fungsi hash menerima kunci dan menghasilkan nilai integer yang disebut hash code. Hash code ini digunakan sebagai indeks dalam tabel hash.

   b. Penyimpanan Data:
   
   Nilai yang terkait dengan kunci disimpan di lokasi tabel yang dihitung berdasarkan hash code.

   c. Pengambilan Data:
   
   Untuk mengambil nilai dari hash table, fungsi hash digunakan untuk menghitung indeks tabel. Nilai yang disimpan di indeks tersebut kemudian dikembalikan.[1]

3. Keuntungan dan Kekurangan Hash Table

   a. Keuntungan:
   - Akses data yang cepat dan efisien
   - Membutuhkan sedikit memori
   - Mudah diimplementasikan

   b. Kekurangan:
   - Bentrokan (collision) dapat terjadi ketika dua kunci berbeda menghasilkan hash code yang sama
   - Membutuhkan fungsi hash yang dirancang dengan baik[2]

4. Implementasi Hash Table dalam C++

   Hash table dapat diimplementasikan dalam C++ menggunakan berbagai cara, seperti:
   - Array:

     Sebuah array dapat digunakan untuk menyimpan data di mana indeksnya dihitung berdasarkan hash code.
     
   - Linked list:
     
     Linked list dapat digunakan untuk menangani bentrokan.
     
   - STL map:
     
     STL map dalam C++ menyediakan implementasi hash table yang sudah jadi.[2]

### Contoh program
```C++
#include <iostream>
#include <list>
#include <string>

using namespace std;

static const int hashGroups = 10;

class HashTable {
private:
    // Kelas HashNode untuk merepresentasikan node dalam tabel hash
    class HashNode {
    public:
        string key; // Kunci
        string value; // Nilai

        // Konstruktor untuk menginisialisasi HashNode dengan kunci dan nilai
        HashNode(string k, string v) : key(k), value(v) {}
    };

    // Array dari list untuk menampung bucket-bucket tabel hash
    list<HashNode> table[hashGroups];

    // Fungsi hash untuk menghasilkan indeks dari kunci
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % hashGroups;
    }

public:
    // Fungsi untuk menambahkan elemen baru ke tabel hash
    void put(string key, string value) {
        int hash = hashFunction(key);
        for (HashNode &node : table[hash]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        // Jika tidak ada node dengan kunci yang sama, tambahkan ke bucket
        table[hash].emplace_back(key, value);
    }

    // Fungsi untuk mendapatkan nilai dari kunci yang diberikan
    string get(string key) {
        int hash = hashFunction(key);
        for (HashNode &node : table[hash]) {
            if (node.key == key) {
                return node.value;
            }
        }
        // Jika tidak ditemukan, kembalikan string kosong
        return "";
    }

    // Fungsi untuk menghapus elemen dengan kunci yang diberikan
    void remove(string key) {
        int hash = hashFunction(key);
        for (auto it = table[hash].begin(); it != table[hash].end(); ++it) {
            if (it->key == key) {
                // Hapus node dari bucket
                table[hash].erase(it);
                return;
            }
        }
    }
};

int main() {
    // Membuat objek tabel hash
    HashTable hashTable;

    // Menambahkan data ke tabel hash
    hashTable.put("firstName", "Jaehyun");
    hashTable.put("lastName", "Jung");

    // Mengambil dan menampilkan nilai dari kunci yang diberikan
    cout << hashTable.get("firstName") << endl;
    cout << hashTable.get("lastName") << endl;

    // Menghapus data dengan kunci yang diberikan
    hashTable.remove("firstName");

    // Menampilkan nilai setelah penghapusan
    cout << hashTable.get("firstName") << endl;

    return 0;
}

```
### Output :
![Screenshot (163)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/295fbf75-a1b5-4744-8cb1-369f0756893c)

### Deskripsi program :
- Program dimulai dengan mengimpor pustaka standar dan menggunakan deklarasi namespace untuk std.
- Konstanta hashGroups ditetapkan ke nilai 10 sebagai jumlah grup hash.
- Dideklarasikan kelas HashTable yang berisi kelas bersarang HashNode dan beberapa fungsi untuk manipulasi tabel hash.
- HashNode adalah kelas yang merepresentasikan node dalam tabel hash. Ini memiliki dua atribut: key untuk menyimpan kunci dan value untuk menyimpan nilai.
- Dalam kelas HashTable, terdapat array dari list (table) untuk menampung bucket-bucket tabel hash. Ukuran array sesuai dengan jumlah grup hash.
- hashFunction adalah fungsi untuk menghasilkan indeks dari kunci yang diberikan.
- Fungsi put digunakan untuk menambahkan elemen baru ke tabel hash. Jika kunci sudah ada, nilai yang sesuai diperbarui.
- Fungsi get digunakan untuk mendapatkan nilai dari kunci yang diberikan. Jika kunci tidak ditemukan, fungsi ini mengembalikan string kosong.
- Fungsi remove digunakan untuk menghapus elemen dengan kunci yang diberikan.
- Fungsi main adalah fungsi utama program yang membuat objek tabel hash, menambahkan, mengambil, dan menghapus data, serta menampilkan hasilnya.


## Guided 

### 1. [Implementasi Hash Table]

```C++
/// Nama  : Caroline Carren
/// Nim   : 2311102174
/// Kelas : IF 11 E

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
	return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node {
	int key;
	int value;
	Node* next;
	Node(int key, int value) : key(key), value(value),
	next(nullptr) {
	}
};

// Class hash table
class HashTable {
	private:
	Node** table;
	public:
	HashTable() {
		table = new Node*[MAX_SIZE]();
	}
	~HashTable() {
		for (int i = 0; i < MAX_SIZE; i++) {
			Node* current = table[i];
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
		delete[] table;
	}

	// Insertion
	void insert(int key, int value) {
		int index = hash_func(key);
		Node* current = table[index];
		while (current != nullptr) {
			if (current->key == key) {
				current->value = value;
				return;
			}
			current = current->next;
		}
		Node* node = new Node(key, value);
		node->next = table[index];
		table[index] = node;
	}

	// Searching
	int get(int key) {
		int index = hash_func(key);
		Node* current = table[index];
		while (current != nullptr) {
			if (current->key == key) {
				return current->value;
			}
			current = current->next;
		}
		return -1;
	}

	// Deletion
	void remove(int key) {
		int index = hash_func(key);
		Node* current = table[index];
		Node* prev = nullptr;
		while (current != nullptr) {
			if (current->key == key) {
				if (prev == nullptr) {
					table[index] = current->next;
				} else {
					prev->next = current->next;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}
	}
	// Traversal
	void traverse() {
		for (int i = 0; i < MAX_SIZE; i++) {
			Node* current = table[i];
			while (current != nullptr) {
				cout << current->key << ": " << current->value
				<< endl;
				current = current->next;
			}
		}
	}
}
;
int main() {
	HashTable ht;
	// Insertion
	ht.insert(1, 10);
	ht.insert(2, 20);
	ht.insert(3, 30);
	// Searching
	cout << "Get key 1: " << ht.get(1) << endl;
	cout << "Get key 4: " << ht.get(4) << endl;
	// Deletion
	ht.remove(4);
	// Traversal
	ht.traverse();
	return 0;
}
```

#### Output :
![Screenshot (164)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f67b4f0d-8dc0-48db-8e73-3c2a86fb95f1)

#### Deskripsi Program : 
Program di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. 
Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. 
Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array.

### 2. [Sistem Penyimpanan dan Pencarian Nama dan Nomor Telepon Menggunakan Tabel Hash]

```C++
/// Nama  : Caroline Carren
/// Nim   : 2311102174
/// Kelas : IF 11 E

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ukuran tabel hash
const int TABLE_SIZE = 11;

// Variabel untuk menyimpan nama
string name; 
// Variabel untuk menyimpan nomor telepon
string phone_number; 

// Kelas HashNode untuk merepresentasikan node dalam tabel hash
class HashNode {
public:
    string name;
    string phone_number;

    // Konstruktor untuk HashNode
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Kelas HashMap untuk implementasi tabel hash
class HashMap {
private:
    // Array dari vektor yang merepresentasikan tabel hash
    vector<HashNode*> table[TABLE_SIZE]; 
public:
    // Fungsi hashFunc untuk menghasilkan nilai hash dari kunci (nama)
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            // Menjumlahkan nilai ASCII dari setiap karakter kunci
            hash_val += c; 
        }
        // Mengembalikan hasil modulo dari ukuran tabel untuk mendapatkan indeks
        return hash_val % TABLE_SIZE; 
    }

    // Fungsi insert untuk memasukkan pasangan nama dan nomor telepon ke dalam tabel hash
    void insert(string name, string phone_number) {
        // Menghitung nilai hash dari nama
        int hash_val = hashFunc(name); 
        // Iterasi melalui vektor node pada indeks hash yang sesuai
        for (auto node : table[hash_val]) { 
            // Jika nama sudah ada dalam tabel
            if (node->name == name) { 
                // Update nomor telepon
                node->phone_number = phone_number; 
                return;
            }
        }
        // Tambahkan node baru ke vektor
        table[hash_val].push_back(new HashNode(name, phone_number)); 
    }

    // Fungsi remove untuk menghapus entri berdasarkan nama dari tabel hash
    void remove(string name) {
        // Menghitung nilai hash dari nama
        int hash_val = hashFunc(name); 
        // Iterasi melalui vektor node pada indeks hash yang sesuai
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) { 
            // Jika nama ditemukan
            if ((*it)->name == name) { 
                // Hapus node
                table[hash_val].erase(it); 
                return;
            }
        }
    }

    // Fungsi searchByName untuk mencari nomor telepon berdasarkan nama dari tabel hash
    string searchByName(string name) {
        // Menghitung nilai hash dari nama
        int hash_val = hashFunc(name); 
        // Iterasi melalui vektor node pada indeks hash yang sesuai
        for (auto node : table[hash_val]) { 
            // Jika nama ditemukan
            if (node->name == name) { 
                 // Mengembalikan nomor telepon yang sesuai
                return node->phone_number;
            }
        }
        // Mengembalikan string kosong jika nama tidak ditemukan
        return ""; 
    }

    // Fungsi print untuk menampilkan seluruh isi tabel hash
    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map; // Membuat objek HashMap

    // Menambahkan beberapa entri ke tabel hash
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencetak nomor telepon dari beberapa nama yang dicari
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    // Menghapus salah satu entri
    employee_map.remove("Mistah");

    // Mencetak nomor telepon setelah entri dihapus
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    // Mencetak isi keseluruhan tabel hash
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}

```

#### Output :
![Screenshot (165)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/df49c738-6595-467a-8fb3-51a201a0a05d)


#### Deskripsi Program : 
Program di atas, class HashNode merepresentasikan setiap node dalam hash table, yang terdiri dari nama dan nomor telepon karyawan. 
Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. 
Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. 
Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan.

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. 
#### Dengan ketentuan :
#### a. Setiap mahasiswa memiliki NIM dan nilai.
#### b. Program memiliki tampilan pilihan menu berisi poin C.
#### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


```C++
/// Nama  : Caroline Carren
/// Nim   : 2311102174
/// Kelas : IF 11 E

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Struktur Mahasiswa untuk merepresentasikan data mahasiswa.
struct Mahasiswa {
    string nim;
    string nama;
    int nilai;
    Mahasiswa(string n, string na, int v) : nim(n), nama(na), nilai(v) {}
};

// Kelas HashTable untuk menyimpan data mahasiswa menggunakan hash table.
class HashTable {
private:
    // Ukuran hash table
    int size;  
    // Vector untuk menyimpan bucket-bucket data mahasiswa
    vector<vector<Mahasiswa>> table;  

public:
    // Konstruktor untuk menginisialisasi hash table dengan ukuran tertentu.
    HashTable(int s) : size(s), table(s) {}

    // Fungsi hashFunction untuk menghasilkan nilai hash dari NIM mahasiswa.
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    // Fungsi addData untuk menambahkan data mahasiswa ke dalam hash table.
    void addData(Mahasiswa mhs) {
        // Menghitung indeks bucket untuk NIM mahasiswa
        int index = hashFunction(mhs.nim);  
        // Menambahkan data mahasiswa ke dalam bucket yang sesuai
        table[index].push_back(mhs);  
    }

    // Fungsi removeData untuk menghapus data mahasiswa dari hash table berdasarkan NIM.
    bool removeData(string nim) {
         // Menghitung indeks bucket untuk NIM mahasiswa yang akan dihapus
        int index = hashFunction(nim); 
        for (size_t i = 0; i < table[index].size(); ++i) {
            // Jika NIM mahasiswa ditemukan
            if (table[index][i].nim == nim) {  
                // Menghapus mahasiswa dari bucket
                table[index].erase(table[index].begin() + i);  
                // Mengembalikan true sebagai tanda bahwa data berhasil dihapus
                return true;  
            }
        }
        // Mengembalikan false jika NIM mahasiswa tidak ditemukan
        return false;  
    }

    // Fungsi searchByNIM untuk mencari data mahasiswa berdasarkan NIM.
    Mahasiswa* searchByNIM(string nim) {
        // Menghitung indeks bucket untuk NIM mahasiswa yang ingin dicari
        int index = hashFunction(nim);  
        for (Mahasiswa &mhs : table[index]) {
            if (mhs.nim == nim) {
                // Mengembalikan alamat dari objek Mahasiswa jika NIM ditemukan
                return &mhs;  
            }
        }
        // Mengembalikan nullptr jika NIM mahasiswa tidak ditemukan
        return nullptr;  
    }

    // Fungsi searchByValueRange untuk mencari data mahasiswa berdasarkan rentang nilai (80-90).
    vector<Mahasiswa> searchByValueRange(int minVal, int maxVal) {
         // Vector untuk menyimpan data mahasiswa yang memenuhi rentang nilai
        vector<Mahasiswa> result; 
        for (vector<Mahasiswa> &bucket : table) {
            for (Mahasiswa &mhs : bucket) {
                if (mhs.nilai >= minVal && mhs.nilai <= maxVal) {
                    // Menambahkan mahasiswa ke dalam vector jika memenuhi rentang nilai
                    result.push_back(mhs);  
                }
            }
        }
        // Mengembalikan vector yang berisi data mahasiswa dalam rentang nilai tertentu
        return result;  
    }

    // Fungsi displayAllData untuk menampilkan seluruh data mahasiswa.
    void displayAllData() {
        cout << "===============================================\n";
        cout << "Seluruh Data Mahasiswa:\n";
        for (const vector<Mahasiswa> &bucket : table) {
            for (const Mahasiswa &mhs : bucket) {
                cout << "-----------------------------------------------\n";
                cout << "NIM   : " << mhs.nim << "\n";
                cout << "Nama  : " << mhs.nama << "\n";
                cout << "Nilai : " << mhs.nilai << "\n";
            }
        }
        cout << "===============================================\n";
    }
};

// Fungsi displayMenu untuk menampilkan pilihan menu ke layar.
void displayMenu() {
    cout << "===============================================\n";
    cout << "          Manajemen Data Mahasiswa\n";
    cout << "===============================================\n";
    cout << "Menu:\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data mahasiswa berdasarkan NIM\n";
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)\n";
    cout << "5. Tampilkan seluruh data mahasiswa\n";
    cout << "6. Keluar\n";
    cout << "===============================================\n";
}

int main() {
     // Ukuran hash table
    int size = 10; 
    // Membuat objek hash table dengan ukuran tertentu
    HashTable hashTable(size);  

    // Variabel untuk menyimpan pilihan menu pengguna
    int choice;  
    while (true) {
        // Menampilkan menu
        displayMenu();  
        cout << "Masukkan pilihan: ";
        // Membaca pilihan pengguna dari input
        cin >> choice;  

        switch (choice) {
            // Opsi untuk menambahkan data mahasiswa
            case 1: {  
                string nim, nama;
                int nilai;
                cout << "===============================================\n";
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                Mahasiswa mhs(nim, nama, nilai);
                hashTable.addData(mhs);
                cout << "===============================================\n";
                cout << "Data mahasiswa berhasil ditambahkan.\n";
                break;
            }
            // Opsi untuk menghapus data mahasiswa
            case 2: {  
                string nim;
                cout << "===============================================\n";
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                if (hashTable.removeData(nim)) {
                    cout << "Data mahasiswa dengan NIM " << nim << " telah dihapus.\n";
                } else {
                    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
                }
                break;
            }
            // Opsi untuk mencari data mahasiswa berdasarkan NIM
            case 3: {  
                string nim;
                cout << "===============================================\n";
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                Mahasiswa *mhs = hashTable.searchByNIM(nim);
                if (mhs != nullptr) {
                    cout << "===============================================\n";
                    cout << "Data mahasiswa ditemukan:\n";
                    cout << "NIM   : " << mhs->nim << "\n";
                    cout << "Nama  : " << mhs->nama << "\n";
                    cout << "Nilai : " << mhs->nilai << "\n";
                } else {
                    cout << "===============================================\n";
                    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
                }
                break;
            }
            // Opsi untuk mencari data mahasiswa berdasarkan rentang nilai (80-90)
            case 4: {  
                cout << "===============================================\n";
                cout << "Data mahasiswa dengan rentang nilai (80-90):\n";
                vector<Mahasiswa> result = hashTable.searchByValueRange(80, 90);
                if (!result.empty()) {
                    for (Mahasiswa &mhs : result) {
                        cout << "-----------------------------------------------\n";
                        cout << "NIM   : " << mhs.nim << "\n";
                        cout << "Nama  : " << mhs.nama << "\n";
                        cout << "Nilai : " << mhs.nilai << "\n";
                    }
                } else {
                    cout << "-----------------------------------------------\n";
                    cout << "Tidak ada data mahasiswa dengan rentang nilai (80-90).\n";
                }
                break;
            }
            // Opsi untuk menampilkan seluruh data mahasiswa
            case 5: {  
                hashTable.displayAllData();
                break;
            }
            // Opsi untuk keluar dari program
            case 6: {  
                cout << "===============================================\n";
                cout << "Terima kasih atas penggunaan program!\n";
                return 0;
            }
            // Menampilkan pesan jika pilihan tidak valid
            default:  
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
        }
    }

    return 0;
}

```

### Output:

#### Menambahkan data mahasiswa
![Screenshot (166)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/806e200b-2577-4778-a95b-be5aeacfc7e5)

#### Menampilkan seluruh data yang telah di input
![Screenshot (167)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1012e80f-6afc-4ace-97eb-b099dc5a8cbe)

#### Menghapus data mahasiswa berdasarkan inputan NIM (taeri)
![Screenshot (168)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/27f85fa1-f552-49b4-9190-681d45ded10c)

#### Tampilan setelah nama mahasiswa (taeri) di hapus
![Screenshot (169)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/260c67ae-a3cb-4ed5-a295-ff245a48cdf7)

#### Menambahkan data baru 
![Screenshot (170)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/1665117d-850b-482f-aa84-271e3a06240a)
![Screenshot (176)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/c39b4429-cd99-4a74-bc16-7f406d14296c)

#### Mencari nama dengan NIM
![Screenshot (172)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/12602dd9-1e52-4894-bdd0-2b730c86fae4)

#### Mencari data mahasiswa berdasarkan nilai dengan rentang nilai 80-90
![Screenshot (173)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/f3b4898a-8322-484b-aa3e-f6d0197cefb0)

#### Menampilkan seluruh data 
![Screenshot (174)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/54474304-0df2-4cd2-927f-c9ac44db4d85)

#### Tampilan akhir program
![Screenshot (175)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/292841f3-95d1-4014-8a90-a66e30bb41ae)

### Deskripsi Program : 
Program di atas digunakan untuk manajemen data mahasiswa, yang memungkinkan pengguna untuk menambahkan, menghapus, mencari, dan menampilkan data mahasiswa berdasarkan NIM atau rentang nilai tertentu.

Struktur data yang digunakan dalam program ini adalah:

- Struktur Mahasiswa (struct Mahasiswa):

  Merupakan representasi data mahasiswa dengan atribut NIM, nama, dan nilai.
  
- Kelas HashTable (class HashTable):

  Mengimplementasikan hash table untuk menyimpan data mahasiswa.

  Menyediakan fungsi-fungsi untuk menambah, menghapus, mencari, dan menampilkan data mahasiswa.

  Menggunakan vektor (vector) untuk menyimpan bucket-bucket data mahasiswa.

  Memiliki fungsi hash untuk menghasilkan nilai hash dari NIM mahasiswa.
  
- Fungsi displayMenu():

  Menampilkan pilihan menu ke layar untuk interaksi dengan pengguna.
  
- Fungsi main():

  Berisi logika program utama yang menggunakan objek HashTable untuk melakukan manajemen data mahasiswa.
  
  Terdapat loop untuk memproses pilihan menu yang dimasukkan pengguna.

- Operasi yang dapat dilakukan dalam program ini antara lain:

  Menambahkan data mahasiswa.
  
  Menghapus data mahasiswa berdasarkan NIM.
  
  Mencari data mahasiswa berdasarkan NIM.
  
  Mencari data mahasiswa berdasarkan rentang nilai tertentu.
  
  Menampilkan seluruh data mahasiswa.
  
Selain itu, program juga menyediakan fungsi-fungsi bantuan seperti fungsi hash untuk menghasilkan nilai hash dari NIM mahasiswa dan fungsi untuk menampilkan menu.


### Full code Screenshot:
![carbon (7)](https://github.com/carolinecarrenn/Praktikum-Struktur-Data-Assignment/assets/161668868/177bfd5a-22d1-4250-8388-d16743a174d6)


## Kesimpulan

Kesimpulan yang dapat di ambil yaitu : 

1. Efisiensi Pencarian dan Penyisipan:
   Hash table merupakan struktur data yang efisien untuk operasi pencarian dan penyisipan.
   
   Dengan menggunakan fungsi hash, elemen-elemen disimpan di lokasi yang dihitung berdasarkan kunci mereka, yang memungkinkan pencarian dengan kompleksitas waktu O(1) dalam kasus terbaik.

2. Penanganan Tabrakan (Collision Handling):
   
   Dalam implementasi hash table, tabrakan dapat terjadi ketika dua kunci di-hash ke lokasi yang sama.

   Penanganan tabrakan adalah aspek penting dalam hash table, dan ada beberapa metode yang digunakan untuk menangani tabrakan, seperti chaining (penyimpanan elemen-elemen yang bertabrakan dalam bentuk daftar terkait) dan probing (mencari lokasi alternatif untuk penyimpanan elemen).

3. Penggunaan Fungsi Hash yang Efektif:
   
   Kualitas fungsi hash sangat penting dalam kinerja hash table.

   Fungsi hash yang baik seharusnya mendistribusikan kunci secara merata di seluruh ruang hash, sehingga mengurangi kemungkinan terjadinya tabrakan dan memaksimalkan efisiensi pencarian.

4. Penggunaan dalam Berbagai Aplikasi:

   Hash table digunakan dalam berbagai aplikasi seperti basis data, kamus, caching, dan banyak lagi.

   Keunggulan utamanya adalah kecepatan pencarian dan penyisipan yang konstan, membuatnya ideal untuk situasi di mana waktu eksekusi kritis.

5. Pertimbangan Desain:

   Saat merancang atau menggunakan hash table, penting untuk mempertimbangkan faktor-faktor seperti ukuran tabel, fungsi hash yang dipilih, dan metode penanganan tabrakan.

   Pilihan-pilihan ini akan memengaruhi kinerja dan efisiensi dari struktur data hash table tersebut.

## Referensi

[1] Adam Drozdek, "Data Structures and Algorithms in C++," 2nd ed. Boston, MA: Cengage Learning, 2012.

[2] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," 3rd ed. Cambridge, MA: The MIT Press, 2009.
