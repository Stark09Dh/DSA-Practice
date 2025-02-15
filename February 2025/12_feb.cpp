#include<bits/stdc++.h>
 
using namespace std ;

int getSum(int num){
    int sum = 0 ;
    while(num > 0){
        int digit = num % 10 ;
        sum += digit ;
        num = num / 10 ;
    }
    return sum ;
}

int maximumSum(vector<int>& nums) {
    int n = nums.size() ;
    int ans = 0 ;
    unordered_map<int,int>mp ;
    for(int i = 0 ; i < n ; i++){
        int tempSum = 0 ;
        int digitSum = getSum(nums[i]) ;
        if(mp.find(digitSum) != mp.end()){
            tempSum = nums[i] + mp[digitSum] ;
            ans = max(ans , tempSum) ;
            mp[digitSum] = (nums[i] > mp[digitSum]) ? nums[i] : mp[digitSum] ;
        }
        else{
            mp[digitSum] = nums[i] ;
        }
        
    }
    return ans==0?-1:ans ;
    

    
}

int main(){

    
    vector<int>nums = {368,369,307,304,384,138,90,279,35,396,114,328,251,364,300,191,438,467,183};
    cout << maximumSum(nums) ;
    
    return 0;
}

