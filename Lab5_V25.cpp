#include <iostream>
using namespace std;


int findMaxIndex(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


void bubbleSortUpToMax(int arr[], int size) {

    int maxIndex = findMaxIndex(arr, size);

    for (int i = 0; i < maxIndex - 1; i++) {
        for (int j = 0; j < maxIndex - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 5, 3, 8, 1, 9, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);


    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSortUpToMax(arr, size);

    cout << "Масив після сортування до максимального елемента: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
