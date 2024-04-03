/// CAROLINE CARREN
/// 2311102174

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
