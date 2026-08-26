#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int mid, int studCount){
    int totalStudents = 1;
    int totalPages = 0;

    for (int i=0; i<n;i++){
        if(arr[i] > mid){
            return false;
        }
        if (totalPages + arr[i] > mid){
            totalStudents++;
            if(totalStudents > studCount){
                return false;
            }
            totalPages= arr[i];
        }else{
            totalPages += arr[i];
        }
    }
    return true;
}
int main(){
    int arr[6] = {10,20,30,40,50,60};
    int studCount = 3;
    int start = 0, end = 0;
    for (int i=0; i<6; i++){
        end += arr[i];
    }
    int ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossible(arr, 6, mid, studCount)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    cout << ans<< " ";
    
}