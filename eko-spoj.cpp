#include <iostream>
using namespace std;

bool isPossible(int trees[], int n, int mid, int m){
    int woodsCollected = 0;
    for (int i=0; i<n;i++){
        if(trees[i] <= mid){
            continue;
        }else{
            int wood = trees[i]-mid;
            if (woodsCollected+wood >= m){
                return true;
            }else{
                woodsCollected += wood;
            }
        }
    }
    return false;
}

int main(){
    int trees[4] = {20,15,10,17};
    int m = 7;
    int start = 0, end = 0;
    for (int i=0; i<4; i++){
        end = max(end, trees[i]);
    }

    int ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossible(trees, 4, mid, m)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    cout << ans<< " ";
    
}