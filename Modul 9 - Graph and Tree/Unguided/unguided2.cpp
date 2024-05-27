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

