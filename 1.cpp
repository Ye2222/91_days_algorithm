#include <iostream>
using namespace std;

void binarySearch(int a[], int target) {
    int size = 5;
    cout << size << endl;
    int left = 0, right = size - 1;
    int count = 0;
    while(left <= right) {
        count++;
        int mid = left + (right - left) / 2;
        cout << "mid "<<mid << endl;
        if(a[mid] < target) left = mid + 1;
        else if (a[mid] > target) right = mid - 1;
        else {
            cout << "find target" << endl;
            break;
        }
    }
    cout << count << endl;
    return;
}
int main() {
    int a[] = {1, 2, 3, 4, 5};
    binarySearch(a, 6);
    return 0;
}