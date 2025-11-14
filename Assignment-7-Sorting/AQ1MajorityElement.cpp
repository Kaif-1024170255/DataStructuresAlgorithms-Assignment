#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
int majorityElement(int arr[], int n) {
    selectionSort(arr,n);     // sort the array
    return arr[n / 2];       // majority element must be at middle
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Majority Element: " << majorityElement(arr, n);
    return 0;
}
