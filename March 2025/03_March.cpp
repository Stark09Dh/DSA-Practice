#include<bits/stdc++.h>
 
using namespace std ;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size() ;
    vector<int>ans;
    for(int &i : nums){
        if(i < pivot){
            ans.push_back(i) ;
        }
    }
    for(int &i : nums){
        if(i == pivot) {
            ans.push_back(i) ;
        }
    }
    for(int &i : nums){
        if(i > pivot) {
            ans.push_back(i) ;
        }
    }
    return ans ;
}
 
int main(){
 
    vector<int> nums = {9,12,5,10,14,3,10} ;
    int pivot = 10 ;
    vector<int> ans =  pivotArray(nums , pivot) ;

    for(int i : ans) {
        cout << i << " " ;
    }
    return 0;
}