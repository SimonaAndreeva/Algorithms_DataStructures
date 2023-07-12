#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {

    const int size = 6;
    int array[size] = {6, 8, 3, 7, 4, 9};

    int num, index;
    int sustoqnie = 0, obhozdane = 1, sravnenie = 0;

    for (int i = 0; i < size; i++) {

        cout << "Sustoqnie " << sustoqnie << ": ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        sustoqnie++;

        num = array[i];
        index = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < num) {
                num = array[j];
                index = j;

            }
            sravnenie++;
        }

        array[index] = array[i];
        array[i] = num;

        cout << endl << "Obhozdane " << obhozdane << endl;
        cout << "Sravnenie " << sravnenie << endl;
        cout << endl;
        obhozdane++;
        sravnenie = 0;
    }

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }


    return 0;
}
