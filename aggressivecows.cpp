#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int mid, int cowCount){
    int totalCows = 1;
    int lastDistance = arr[0];
    for (int i=1; i<n;i++){
        int distanceDifference = arr[i]-lastDistance;
        
        if (distanceDifference >= mid){
            totalCows++;
            if(totalCows == cowCount){
                return true;
            }
            lastDistance = arr[i];
        }
    }
    return false;
}
int main(){
    int arr[5] = {1,2,3,4,6};
    int cowCount = 2;
    int start = 0, end = 0;
    for (int i=0; i<5; i++){
        start = min(start, arr[i]);
        end = max(end, arr[i]);
    }
    end = end - start;
    int ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossible(arr, 5, mid, cowCount)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    cout << ans<< " ";
    
}