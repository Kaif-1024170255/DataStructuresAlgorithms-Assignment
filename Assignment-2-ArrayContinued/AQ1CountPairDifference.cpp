#include <iostream>
#include <cmath>
using namespace std;
int countPairsWithDiffK(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k)
                count++;
        }
    }
    return count;
}
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Count of pairs with difference " << k << " = "
         << countPairsWithDiffK(arr, n, k);
    return 0;
}
