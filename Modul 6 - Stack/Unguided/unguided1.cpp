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
