#include <iostream>
using namespace std;
void sort012(int arr[], int n) {
    int low = 0;       // position for 0
    int mid = 0;       // current element
    int high = n - 1;  // position for 2
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                {
                    int temp = arr[low];
                    arr[low] = arr[mid];
                    arr[mid] = temp;
                }
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                {
                    int temp = arr[mid];
                    arr[mid] = arr[high];
                    arr[high] = temp;
                }
                high--;
                break;
        }
    }
}
int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
