/// Caroline Carren
/// 2311102174

#include <iostream>
#include <string>
using namespace std;

// Node untuk menyimpan data
struct Node {
    string name;
    int age;
    Node* next;
};

// Kelas LinkedList untuk menyimpan operasi-operasi terkait linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di awal linked list
    void insertFront(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data setelah node dengan nama tertentu
    void insertAfter(string name, int age, string afterName) {
        Node* current = head;
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data " << afterName << " tidak ditemukan." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk menambahkan data di akhir linked list
    void insertEnd(string name, int age) {
        if (head == nullptr) {
            insertFront(name, age);
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = nullptr;
        current->next = newNode;
    }

    // Fungsi untuk menghapus node dengan nama tertentu
    void deleteNode(string name) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data " << name << " tidak ditemukan." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    // Fungsi untuk mengubah data (ganti nama)
    void modifyNode(string oldName, string newName, int newAge) {
        Node* current = head;

        while (current != nullptr && current->name != oldName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data " << oldName << " tidak ditemukan." << endl;
            return;
        }

        current->name = newName;
        current->age = newAge;
    }

    // Fungsi untuk menampilkan isi linked list
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " " << current->age << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    int numData;
    cout << "Masukkan jumlah data: ";
    cin >> numData;

    // Mengambil input data dari pengguna dan menambahkannya ke linked list
    for (int i = 0; i < numData; ++i) {
        string name;
        int age;
        cout << "Masukkan nama: ";
        cin >> name;
        cout << "Masukkan usia: ";
        cin >> age;
        list.insertEnd(name, age);
    }

    cout << "Data awal:" << endl;
    list.displayList();
    cout << endl;

    string deleteName;
    cout << "Masukkan nama yang ingin dihapus: ";
    cin >> deleteName;
    list.deleteNode(deleteName);
    cout << "Setelah menghapus data:" << endl;
    list.displayList();
    cout << endl;

    string insertName, afterName;
    int insertAge;
    cout << "Masukkan nama yang ingin ditambahkan: ";
    cin >> insertName;
    cout << "Masukkan usia yang ingin ditambahkan: ";
    cin >> insertAge;
    cout << "Masukkan nama setelah data baru: ";
    cin >> afterName;
    list.insertAfter(insertName, insertAge, afterName);
    cout << "Setelah menambahkan data:" << endl;
    list.displayList();
    cout << endl;

    // Menambahkan data baru di awal linked list
    list.insertFront("Igor", 20);
    cout << "Setelah menambahkan Igor 20 di awal:" << endl;
    list.displayList();
    cout << endl;

    // Mengubah data Michael menjadi Reyn 18
    list.modifyNode("Michael", "Reyn", 18);
    cout << "Setelah mengubah Michael menjadi Reyn 18:" << endl;
    list.displayList();
    cout << endl;

    return 0;
}
