#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    char array_b[14] = {0, 1, 3, 3, 8, 8, 'a', 'a', 'd', 'e', 'e', 'n', 'r', 'v'};
    int length = std::size(array_b);

    int n;
    cin >> n;


    int left, right = 0, middle;

    middle = length / 2;
    left = 0;
    right = length;
    bool isFounded = false;

    while (left <= right) {

        if (array_b[middle] == n) {
            isFounded = true;
            break;
        } else {
            if (n < array_b[middle]) {
                left = 0;
                right = middle - 1;
            } else {
                left = middle + 1;

            }

            middle = (right + left) / 2;
        }
    }

    if (isFounded) {
        cout << "Founded";
    } else {
        cout << "Not founded";
    }
    return 0;
}
