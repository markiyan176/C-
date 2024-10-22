#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>     

using namespace std;

int main() {
    srand(time(0));  

    int n;
    cout << "Введіть розмір матриці: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100 + 1; 
        }
    }


    cout << "Початкова матриця:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }


    for (int i = 0; i < n; ++i) {
        int diag_elem = matrix[i][n - i - 1];  

        if (diag_elem % 2 == 0) { 
            for (int j = 0; j < n - 1; ++j) {
                for (int k = 0; k < n - j - 1; ++k) {
                    if (matrix[i][k] > matrix[i][k + 1]) {
                        swap(matrix[i][k], matrix[i][k + 1]);
                    }
                }
            }
        }
    }

    cout << "\nМатриця після сортування рядків з парними елементами на побічній діагоналі:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }

    return 0;
}
