#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int N;
    cout << "Введіть кількість елементів масиву: ";
    cin >> N;

    srand(time(0));
    
    vector<double> arr(N);
    
    cout << "Масив заповнений випадковими числами:\n";
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 201 - 100) / 10.0; 
        cout << arr[i] << " ";
    }
    cout << endl;


    double minPositive = numeric_limits<double>::max();
    int minPositiveIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0 && arr[i] < minPositive) {
            minPositive = arr[i];
            minPositiveIndex = i;
        }
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }

    if (minPositiveIndex == -1 || lastNegativeIndex == -1) {
        cout << "Мінімального додатнього або останнього від'ємного елемента не знайдено.\n";
        return 0;
    }


    int firstPositiveIndex = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            firstPositiveIndex = i;
            break;
        }
    }

    double sumBetween = 0;
    if (firstPositiveIndex < lastNegativeIndex) {
        for (int i = firstPositiveIndex + 1; i < lastNegativeIndex; i++) {
            sumBetween += arr[i];
        }
    }

    
    cout << "Мінімальний додатний елемент: " << minPositive << " (індекс " << minPositiveIndex << ")\n";
    cout << "Сума елементів між першим додатнім і останнім від'ємним: " << sumBetween << "\n";


    swap(arr[minPositiveIndex], arr[lastNegativeIndex]);


    cout << "Масив після перестановки:\n";
    for (double element : arr) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
