/// Nama  : Caroline Carren
/// Nim   : 2311102174
/// Kelas : IF 11 E

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
