#include<bits/stdc++.h>
 
using namespace std ;

// Brute Force TC : O(n^2)  SC : O(1)
int maxWidthRamp2(vector<int>& nums) {
    int n = nums.size();
    int ans = 0 ;

    for(int i= 0; i<n ; i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] <= nums[j]){
                int tempVal = j - i ;
                ans = max(ans , tempVal);
            }
        }
    }
    return ans ;
}

// Using Monotonic(descreasing order) behaviour of stack
// TC : O(n)  SC : O(n) 

int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    int ans = 0 ;
    stack<int>st ;


    for(int i=0;i<n;i++){
        if(st.empty() || nums[st.top()] > nums[i]){
            st.push(i);
        }
    }

    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && nums[i] >= nums[st.top()]){
            ans = max(ans , i - st.top());
            st.pop();
        }
    }

    return ans ;
}


 
int main(){
 
    vector<int>nums = {9,8,1,0,1,9,4,0,4,1};
    cout << maxWidthRamp(nums) ;
    return 0;
}