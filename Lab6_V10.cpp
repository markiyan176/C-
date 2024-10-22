#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <cmath> 

using namespace std;

int main() {
    const int SIZE = 10;
    int matrix[SIZE][SIZE];


    srand(time(0));


    cout << "Згенерована матриця 10x10:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 101 - 50; 
            cout << matrix[i][j] << "\t";    
        }
        cout << endl;
    }

    int localMinCount = 0;

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int current = matrix[i][j];
            if (current < matrix[i - 1][j] && current < matrix[i + 1][j] && 
                current < matrix[i][j - 1] && current < matrix[i][j + 1]) { 
                localMinCount++;
            }
        }
    }

    int sumAboveDiagonal = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            sumAboveDiagonal += abs(matrix[i][j]);
        }
    }

    // Виведення результатів
    cout << "Кількість локальних мінімумів: " << localMinCount << endl;
    cout << "Сума модулів елементів вище головної діагоналі: " << sumAboveDiagonal << endl;

    return 0;
}
