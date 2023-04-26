#include <iostream>
#include <array>

using namespace std;

void insertionsort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int tem = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > tem) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tem;
    }
}

int main() {
    int arr[] = {5, 3, 2, 8, 7, 1, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionsort(arr, n);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}