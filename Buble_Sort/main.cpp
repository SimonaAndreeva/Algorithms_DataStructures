#include <iostream>
using namespace std;

int main() {

    int size = 7;
    int array[7] = {1,0,8,4,2,7,3};


    bool isSwapped = true;
    int count = 0;

    while(isSwapped) {
        isSwapped = false;

        for(int i = 1; i < size; i++) {
            if(array[i]>array[i-1]) {
                swap(array[i], array[i-1]);
                isSwapped = true;
                count++;
            }
        }

        for (int i = 0; i < 7; i++) {
            cout << array[i] << " ";
        }
        cout<<endl;
        size--;
    }

    cout<<endl<<count;

    return 0;
}








