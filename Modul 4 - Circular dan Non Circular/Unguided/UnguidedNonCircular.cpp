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
