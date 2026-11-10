#include <iostream>
using namespace std;

int main() {
    int nilai[3][5];

    cout << "Masukkan nilai matrix 3x5:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Nilai [" << i << "][" << j << "] = ";
            cin >> nilai[i][j];
        }
    }

    cout << "\nMatrix yang dimasukkan:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
