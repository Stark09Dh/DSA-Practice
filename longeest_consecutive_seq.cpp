#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&nums){
    int ans = 1 ;
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int>st ;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1 ;
                int x = it ;
                while(st.find(x+1) != st.end()){
                    x = x+1 ;
                    cnt+=1;
                }
                ans = max(ans,cnt);
            }
            
        }

    return ans ;

}
 
int main(){
 
    vector<int>nums = {0,3,7,2,5,8,4,6,0,1};
    int ans = sol(nums);
    cout << ans ;
    return 0;
}