#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::size;

void searchAlgFirstTAsk(int *n, int *array, int length,int counter);

void searchAlgSecondKotva(int *n, int *array, int length,int counter);

void searchAlgDihotomichno(int *n, int *arrayOrdered, int length,int counter);


int main() {

    srand(time(NULL));


    int array[400001];
    for(int i = 0; i< size(array); i++) {
        array[i] = rand() % 400000;
    }

    int n[5];
    for(int i = 0; i< size(n); i++) {
        cin>>n[i];
    }

    int arrayOrdered[200000];
    arrayOrdered[0] = 1;
    for(int i = 1; i< size(arrayOrdered); i++) {
        arrayOrdered[i] = arrayOrdered[i-1] + 1;
    }


//time of the first algorithm
    auto start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j<=10; j++) {
        for (int i = 0; i < size(n); i++) {
            searchAlgFirstTAsk(n, array, size(array)-1, i);
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout<<"Time: "<<duration.count()<<endl;

//time of the second algorithm
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int j = 0; j<=10; j++) {
        for (int i = 0; i < size(n); i++) {
            searchAlgSecondKotva(n, array, size(array)-1, i);
        }
    }

    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    cout<<"Time: "<<duration2.count()<<endl;

//time of the third algorithm
    auto start3 = std::chrono::high_resolution_clock::now();
    for(int j = 0; j<=10; j++) {
        for (int i = 0; i < size(n); i++) {
            searchAlgDihotomichno(n, arrayOrdered, size(arrayOrdered)-1, i);
        }
    }

    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);

    cout<<"Time: "<<duration3.count()<<endl;
}

void searchAlgFirstTAsk(int *n, int *array, int length, int counter) {

    for(int i = 0; i<length; i++) {
            if(array[i] == n[counter]) {
            }
    }
}

void searchAlgSecondKotva(int *n, int *array, int length,int counter) {
    array[length-1] = n[counter];

    int br = 0;
    while(n[counter]!=array[br]) {
        br++;
    }
    if(br<length-1) {
    }
    else {
    }
}

void searchAlgDihotomichno(int *n, int *arrayOrdered, int length,int counter) {
    int left, right = 0, middle;

    middle = length / 2;
    left = 0;
    right = length;
    bool isFounded = false;

    while (left <= right) {
        if (arrayOrdered[middle] == n[counter]) {
            isFounded = true;
            break;
        } else {
            if (n[counter] < arrayOrdered[middle]) {
                left = 0;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            middle = (right + left) / 2;
        }
    }
}
