#include<bits/stdc++.h>
 
using namespace std ;

int largestCombination(vector<int>& nums) {
    int n = nums.size(); 
    int score = 0 ;
    for(int i=0;i<24;i++){
        int temp =0 ;
        for(int num : nums){
            if(num & (1<<i)) temp++ ;
        }
        score = max(score , temp) ;
    }
    return score ;
}
 
int main(){
 
    vector<int>nums = {16,17,71,62,12,24,14} ;
    cout << largestCombination(nums) ;

    return 0;
}