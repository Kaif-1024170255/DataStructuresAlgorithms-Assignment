#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag=true;
            }
        }
        if(flag==false)
            return;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
