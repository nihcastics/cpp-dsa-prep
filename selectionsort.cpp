#include <iostream>
#include <climits>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int sortedIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[sortedIndex]){
                sortedIndex = j;
            }
        }
        swap(arr[sortedIndex], arr[i]);
    }
}


void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        bool sorted = true;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1] && (j+1) <= n-i-1){
                swap(arr[j], arr[j+1]);
                sorted = false;
            }
        }
        if(sorted){
            break;
        }
    }
}

int main(){
    int n = 10;
    int arr[n] = {5, 7, 9, 2, 1, 4, 6, 8, 10, 3};
    selectionSort(arr, n);
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}