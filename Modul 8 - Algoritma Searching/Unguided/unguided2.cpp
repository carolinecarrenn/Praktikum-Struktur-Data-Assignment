/// Nama  : Caroline Carren A.R
/// Nim   : 2311102174
/// Kelas : S1 IF 11 E

#include <iostream>
#include <cstring> // Untuk fungsi strlen dan strcpy

using namespace std;

void countAndDisplayVowels(const char* sentence) {
    int vowelCount = 0;
    int length = strlen(sentence);
    cout << "Analisis kalimat:\n";
    for (int i = 0; i < length; i++) {
        char lowerCh = tolower(sentence[i]);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            vowelCount++;
            cout << sentence[i] << " adalah vokal\n";
        } else if (isalpha(lowerCh)) {
            cout << sentence[i] << " adalah konsonan\n";
        } else {
            cout << sentence[i] << " bukan huruf\n";
        }
    }
    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;
}

int main() {
    char sentence[1000];
    cout << "Masukkan sebuah kalimat: ";
    cin.getline(sentence, 1000);

    countAndDisplayVowels(sentence);

    return 0;
}

