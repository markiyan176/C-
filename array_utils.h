#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Макрос для створення та заповнення масиву
#define CREATE_ARRAY(arr, N)                     \
    do {                                         \
        srand(time(0));                          \
        arr = new double[N];                     \
        for (int i = 0; i < N; i++) {            \
            arr[i] = (rand() % 201 - 100) / 10.0;\
        }                                        \
    } while (0)

// Макрос для виводу масиву
#define PRINT_ARRAY(arr, N)                      \
    do {                                         \
        for (int i = 0; i < N; i++) {            \
            cout << arr[i] << " ";               \
        }                                        \
        cout << endl;                            \
    } while (0)

// Макрос для пошуку мінімального додатного елемента
#define FIND_MIN_POSITIVE(arr, N, minPositive, minPositiveIndex) \
    do {                                                        \
        minPositive = numeric_limits<double>::max();            \
        minPositiveIndex = -1;                                  \
        for (int i = 0; i < N; i++) {                           \
            if (arr[i] > 0 && arr[i] < minPositive) {           \
                minPositive = arr[i];                           \
                minPositiveIndex = i;                           \
            }                                                   \
        }                                                       \
    } while (0)

// Макрос для пошуку індексу останнього від’ємного елемента
#define FIND_LAST_NEGATIVE(arr, N, lastNegativeIndex) \
    do {                                              \
        lastNegativeIndex = -1;                       \
        for (int i = 0; i < N; i++) {                 \
            if (arr[i] < 0) {                         \
                lastNegativeIndex = i;                \
            }                                         \
        }                                             \
    } while (0)

// Макрос для обчислення суми між першим додатним і останнім від’ємним
#define SUM_BETWEEN(arr, N, sumBetween, firstPositiveIndex, lastNegativeIndex) \
    do {                                                                       \
        sumBetween = 0;                                                        \
        firstPositiveIndex = -1;                                               \
        for (int i = 0; i < N; i++) {                                          \
            if (arr[i] > 0) {                                                  \
                firstPositiveIndex = i;                                        \
                break;                                                         \
            }                                                                  \
        }                                                                      \
        if (firstPositiveIndex < lastNegativeIndex) {                          \
            for (int i = firstPositiveIndex + 1; i < lastNegativeIndex; i++) { \
                sumBetween += arr[i];                                          \
            }                                                                  \
        }                                                                      \
    } while (0)

// Макрос для перестановки елементів
#define SWAP_ELEMENTS(arr, i, j) \
    do {                         \
        double temp = arr[i];    \
        arr[i] = arr[j];         \
        arr[j] = temp;           \
    } while (0)

#endif // ARRAY_UTILS_H
