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

void kMaxSums(int a[], int b[], int n, int k) {
    int total = n * n;                 
    int sums[total];               
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sums[idx++] = a[i] + b[j];
        }
    }

    selectionSort(sums,total,'d');

    for (int i = 0; i < k; i++) {
        cout << sums[i] << " ";
    }
}

int main() {
    int a[] = {1, 4, 2, 3};
    int b[] = {2, 5, 1, 6};
    int n = 4, k = 3;

    kMaxSums(a, b, n, k);

    return 0;
}
