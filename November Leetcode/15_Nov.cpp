#include<bits/stdc++.h>
 
using namespace std ;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size() ;
    int j = n-1 ;
    while(j>0 && arr[j] >= arr[j-1]){
        j-- ;
    }

    int i = 0 ;
    int ans = j;

    while(i<j && ( i==0 ||arr[i] >= arr[i-1])){


        while(j<n && arr[i] > arr[j]){
            j++ ;
        }

        ans = min(ans , j-i-1);
        i++ ;
    }

    return ans ;

}
 
int main(){
 
    vector<int>nums = {1,2,3,10,4,2,3,5} ;
    cout << findLengthOfShortestSubarray(nums) ;
    return 0;
}