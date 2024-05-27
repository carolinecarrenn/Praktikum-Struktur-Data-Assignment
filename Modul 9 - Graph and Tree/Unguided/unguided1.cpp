/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int caroline_2311102174;
int main() {
  int jumlah_simpul;
  cout << "Silakan masukan jumlah simpul : ";
  cin >> jumlah_simpul;

  vector<string> nama_simpul(jumlah_simpul);
  cout << "Silakan masukan nama simpul" << endl;
  for (int i = 0; i < jumlah_simpul; i++) {
    cout << "Simpul " << i + 1 << " ";
    cin >> nama_simpul[i];
  }

  vector<vector<int>> bobot_antar_simpul(jumlah_simpul, vector<int>(jumlah_simpul, 0));
  cout << "Silakan masukkan bobot antar simpul" << endl;
  for (int i = 0; i < jumlah_simpul; i++) {
    for (int j = 0; j < jumlah_simpul; j++) {
      cout << nama_simpul[i] << " --> " << nama_simpul[j] << " = ";
      cin >> bobot_antar_simpul[i][j];
    }
  }

  cout << "Simpul\t";
  for (int i = 0; i < jumlah_simpul; i++) {
    cout << nama_simpul[i] << "\t";
  }
  cout << endl;

  for (int i = 0; i < jumlah_simpul; i++) {
    cout << nama_simpul[i] << "\t";
    for (int j = 0; j < jumlah_simpul; j++) {
      cout << bobot_antar_simpul[i][j] << "\t";
    }
    cout << endl;
  }

  return 0;
}
