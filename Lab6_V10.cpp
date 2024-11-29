#include <iostream>
#include <fstream> // Для роботи з файлами
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    const int SIZE = 10;
    int matrix[SIZE][SIZE];

    srand(time(0));

    // Відкриття файлу для запису результатів
    ofstream outputFile("result.txt"); // Назва файлу, куди будуть записані результати

    if (!outputFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    outputFile << "Результат роботи програми\n";
    outputFile << "Згенерована матриця 10x10:\n";

    cout << "Згенерована матриця 10x10:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 101 - 50; 
            cout << matrix[i][j] << "\t";    
            outputFile << matrix[i][j] << "\t"; // Запис у файл
        }
        cout << endl;
        outputFile << endl;
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

    outputFile << "\nКількість локальних мінімумів: " << localMinCount << endl;
    outputFile << "Сума модулів елементів вище головної діагоналі: " << sumAboveDiagonal << endl;

    outputFile.close(); // Закриття файлу

    cout << "Результати записані у файл 'result.txt'." << endl;

    return 0;
}
