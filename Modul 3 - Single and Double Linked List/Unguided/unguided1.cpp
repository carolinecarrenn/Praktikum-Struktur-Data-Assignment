/// Caroline Carren
/// 2311102174

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int age;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertFront(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

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

    // Insert initial data
    list.insertFront("John", 19);
    list.insertEnd("Jane", 20);
    list.insertEnd("Michael", 18);
    list.insertEnd("Yusuke", 19);
    list.insertEnd("Akechi", 20);
    list.insertEnd("Hoshino", 18);
    list.insertEnd("Karin", 18);

    cout << "Data awal:" << endl;
    list.displayList();
    cout << endl;

    // Hapus Akechi
    list.deleteNode("Akechi");
    cout << "Setelah menghapus Akechi:" << endl;
    list.displayList();
    cout << endl;

    // Menambahkan Futaba 18 di antara John dan Jane
    list.insertAfter("Futaba", 18, "John");
    cout << "Setelah menambahkan Futaba 18 di antara John dan Jane:" << endl;
    list.displayList();
    cout << endl;

    // Menambahkan Igor 20 di awal
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