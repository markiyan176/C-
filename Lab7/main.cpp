#include <iostream>
#include "array_utils.h"

using namespace std;

int main() {
    int N;
    cout << "Введіть кількість елементів масиву: ";
    cin >> N;

    if (N <= 0) {
        cout << "Розмір масиву має бути більшим за нуль.\n";
        return 1;
    }

    double* arr;
    CREATE_ARRAY(arr, N);

    cout << "Масив заповнений випадковими числами:\n";
    PRINT_ARRAY(arr, N);

    double minPositive;
    int minPositiveIndex, lastNegativeIndex;
    FIND_MIN_POSITIVE(arr, N, minPositive, minPositiveIndex);
    FIND_LAST_NEGATIVE(arr, N, lastNegativeIndex);

    if (minPositiveIndex == -1 || lastNegativeIndex == -1) {
        cout << "Мінімального додатнього або останнього від'ємного елемента не знайдено.\n";
        delete[] arr;
        return 0;
    }

    double sumBetween;
    int firstPositiveIndex;
    SUM_BETWEEN(arr, N, sumBetween, firstPositiveIndex, lastNegativeIndex);

    cout << "Мінімальний додатний елемент: " << minPositive << " (індекс " << minPositiveIndex << ")\n";
    cout << "Сума елементів між першим додатнім і останнім від'ємним: " << sumBetween << "\n";

    SWAP_ELEMENTS(arr, minPositiveIndex, lastNegativeIndex);

    cout << "Масив після перестановки:\n";
    PRINT_ARRAY(arr, N);

    delete[] arr;
    return 0;
}
