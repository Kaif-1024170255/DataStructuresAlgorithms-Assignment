#include <iostream>
using namespace std;

void duplicateZeros(int arr[], int n) {
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            zeros++;
    }
    int i = n - 1;          
    int j = n + zeros - 1;  
    while (i >= 0 && j >= 0) {
        if (arr[i] != 0) {
            if (j < n)
                arr[j] = arr[i];
        } else {
            if (j < n)
                arr[j] = 0;
            j--;
            if (j < n)
                arr[j] = 0;
        }
        i--;
        j--;
    }
}
int main() {
    int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    duplicateZeros(arr, n);
    cout << "Array after duplicating zeros: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
