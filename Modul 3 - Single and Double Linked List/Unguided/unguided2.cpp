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

void tampilkanData(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " - " << temp->harga << endl;
        temp = temp->next;
    }
}

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