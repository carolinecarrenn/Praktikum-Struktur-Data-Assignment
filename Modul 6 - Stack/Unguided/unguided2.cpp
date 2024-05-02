/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk melakukan pembalikan kalimat menggunakan stack
string balikKalimat(string kalimat) {
    stack<char> tumpukan; // Menggunakan stack dari library <stack>

    // Memasukkan karakter kalimat ke dalam tumpukan
    for (char c : kalimat) {
        tumpukan.push(c);
    }

    string terbalik = ""; // Variabel untuk menyimpan kalimat yang sudah dibalik

    // Mengambil karakter dari tumpukan dan membentuk kalimat yang sudah dibalik
    while (!tumpukan.empty()) {
        terbalik += tumpukan.top();
        tumpukan.pop();
    }

    return terbalik; // Mengembalikan kalimat yang sudah dibalik
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat); // Meminta pengguna untuk memasukkan kalimat

    string terbalik = balikKalimat(kalimat); // Memanggil fungsi untuk melakukan pembalikan kalimat
    cout << "Kalimat yang sudah dibalik: " << terbalik << endl;

    return 0;
}
