#include <iostream>
using namespace std;

bool isPossible(int cookRanks[], int n, int mid, int totalPratas){
    int pratasCooked = 0, pratasCount = 0, count = 1;
    for (int i=0; i<n;i++){
        int rank = cookRanks[i]; 
        bool valid = true;
        while(valid){
            int prata = rank * count;
            if(pratasCooked + prata <= mid){
                pratasCooked += prata;
                pratasCount++;
                count++;
            }else{
                pratasCooked =0;
                count = 1;
                valid = false;
            }
        }
        if(pratasCount == totalPratas){
            return true;
        }
    }
    return false;
}

int main(){
    int cookRanks[6] = {1,2,3,4,5,6};
    int totalPratas = 20;
    int start = totalPratas * (totalPratas - 1) / 2, end = 0;
    for (int i=0; i<6; i++){
        end = max(end, cookRanks[i]);
    }
    end *= start;

    int ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(isPossible(cookRanks, 6, mid, totalPratas)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    cout << ans<< " ";
    
}