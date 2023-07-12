#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

     int n;
    cout << "Vuvedi broi elementi: ";
    cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int j = 1;
    for(int i = 1; i<n; i++) {

       if(array[i]<array[j]) {

       }
       j = i+1;
    }

    return 0;
}
