#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>  
#include <ctime>     

using namespace std;


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}


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
    printMatrix(matrix);

   
    for (int i = 0; i < n; ++i) {
        int diag_elem = matrix[i][n - i - 1]; 

       
        if (diag_elem % 2 == 0) {
            sort(matrix[i].begin(), matrix[i].end());
        }
    }

   
    cout << "\nМатриця після сортування рядків з парними елементами на побічній діагоналі:" << endl;
    printMatrix(matrix);

    return 0;
}
