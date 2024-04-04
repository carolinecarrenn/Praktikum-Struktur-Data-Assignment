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
