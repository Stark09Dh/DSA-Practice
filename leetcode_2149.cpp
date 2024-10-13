//  Rearrange Array Elements by Sign

#include<bits/stdc++.h>
 
using namespace std ;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();

    vector<int>ans(n,0);

    int even = 0  ;
    int odd = 1 ;

    for(int i=0;i<n;i++){
        if(nums[i] > 0 && even < n ){
            ans[even] = nums[i] ;
            even += 2 ;
        }
        else if(nums[i] < 0 && odd < n){
            ans[odd] = nums[i] ;
            odd += 2 ;
        }
    }
    return ans ;

}
 
int main(){
 
    vector<int> nums = {-1 ,1 } ;

    vector<int> ans = rearrangeArray(nums);

    for(auto &i : ans ){
        cout << i << " ";
    }
    return 0;
}