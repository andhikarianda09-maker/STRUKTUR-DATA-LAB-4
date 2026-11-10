#include <iostream>
using namespace std;

int main() {
    int nilai[2][3][4] = {
        {
            {0, 0, 0},
            {1, 1, 1,},
            {2, 2, 2,}

        },
        {
            {3, 3, 3},
            {4, 4, 4},
            {5, 5, 5}

        }
    };

 for (int i = 0; i < 2; i++){
    for (int j = 0; j < 3; j++){
        for (int k = 0; k < 4; k++){
            cout << nilai[i][j][k] << " ";
        }
        cout << endl;
    }
 }


}