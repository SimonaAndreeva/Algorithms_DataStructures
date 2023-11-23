#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>

using namespace std;

void selectionSort(int arr[], int n);

void bubbleSort(int arr[], int n);

void insertionSort(int arr[], int n);

int randInt();


int main() {

    time_t t0, t1;
    clock_t c0, c1;

    srand(time(NULL));
    int size = 10000;
    float TimeSelection, TimeBubble, TimeInsertion;

    for (size; size <= 100000; size = size + 10000) {
        cout << "Array with: " << size << endl;

        // Generate array
        int a[size];
        for (int i = 0; i < size; i++) {
            a[i] = randInt();
        }
        int selectionArray[size];
        int bubbleArray[size];
        int insertionArray[size];

        // Copy the original array to three separate arrays
        copy(a, a + size, selectionArray);
        copy(a, a + size, bubbleArray);
        copy(a, a + size, insertionArray);

        // Measure Bubble sort time
        t0 = time(NULL);
        c0 = clock();
        bubbleSort(bubbleArray, size);
        c1 = clock();
        t1 = time(NULL);
        TimeBubble = (float) (c1 - c0) / CLOCKS_PER_SEC;
        cout << "Bubble time: " << TimeBubble << endl;


        // Measure Selection sort time
        t0 = time(NULL);
        c0 = clock();
        selectionSort(selectionArray, size);
        c1 = clock();
        t1 = time(NULL);
        TimeSelection = (float) (c1 - c0) / CLOCKS_PER_SEC;
        cout << "Selection time: " << TimeSelection << endl;


        // Measure Insertion sort time
        t0 = time(NULL);
        c0 = clock();
        insertionSort(insertionArray, size);
        c1 = clock();
        t1 = time(NULL);
        TimeInsertion = (float) (c1 - c0) / CLOCKS_PER_SEC;
        cout << "Insertion time: " << TimeInsertion << endl;

        cout << endl;
    }

    return 0;
}


void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i) {
            int b = min_idx;
            min_idx = arr[i];
            arr[i] = b;
        }
    }
}


void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int randInt() {
    return rand() % 100;
}
