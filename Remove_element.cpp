#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr,int val){
    int j = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] != val){
            arr[j++] = arr[i];
        }
    }
    return j ;
}

 
int main(){

    vector<int> nums = {2,3,3,2};
    int val = 3 ;
    int res  = sol(nums,val);
    for(int i=0;i<res;i++){
        cout << nums[i]<< " ";
    }
    
    return 0;
}