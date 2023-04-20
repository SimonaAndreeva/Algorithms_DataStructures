
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

int main() {
    char n[6];
    for(int i = 0; i < 6; i++) {
        cin>>n[i];
    }

    char array_b[14] = {'0', '1', '3', '3', '8', '8', 'a', 'a', 'd', 'e', 'e', 'n', 'r', 'v'};
    int length = std::size(array_b);
    int left, right , middle, counter;

    for(int i = 0; i<6; i++) {
        counter = 0;
        middle = length / 2;
        left = 0;
        right = length;
        bool isFounded = false;

        while (left <= right) {
            counter++;

            if (array_b[middle] == n[i]) {
                isFounded = true;
                break;
            } else {
                if (n[i] < array_b[middle]) {
                    left = 0;
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
                middle = (right + left) / 2;
            }
            cout<<"Left: "<<left<<"; ";
            cout<<"Right: "<<right<<"; ";
            cout<<"Middle: "<<middle<<endl;
        }
        cout<<"The number of times n was checked: "<<counter<<endl;
        if (isFounded) {
            cout << "Founded"<<endl;
        } else {
            cout << "Not founded"<<endl;
        }
    }
}








