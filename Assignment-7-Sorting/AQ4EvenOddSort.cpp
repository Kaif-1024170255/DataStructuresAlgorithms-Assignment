#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n,char ad) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            bool choice=(ad=='a')?(arr[j] < arr[minIndex]):(arr[j] > arr[minIndex]);
            if(choice)
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
void sortEvenOdd(int arr[], int n) {
    int oddCount  = n / 2;         
    int evenCount = (n + 1) / 2;   
    int even[evenCount], odd[oddCount];

    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even[e++] = arr[i];
        else
            odd[o++] = arr[i];
    }
    selectionSort(even,evenCount,'a');
    selectionSort(odd,oddCount,'d');

    int idx = 0;
    for (int i = 0; i < evenCount; i++)
        arr[idx++] = even[i];

    for (int i = 0; i < oddCount; i++)
        arr[idx++] = odd[i];
}

int main() {
    int arr[] = {1, 3, 2, 7, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortEvenOdd(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
