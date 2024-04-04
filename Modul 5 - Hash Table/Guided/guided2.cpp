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
