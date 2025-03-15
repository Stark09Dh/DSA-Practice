#include<bits/stdc++.h>
 
using namespace std ;

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int m = queries.size();
    int n = nums.size() ;
    int sum = accumulate(nums.begin() , nums.end() , 0) ;

    for(int i = 0 ; i <  m ; i++){
        int l = queries[i][0];
        int r =  queries[i][1] ;
        int val = queries[i][2] ;
        for(int j = l ; j <= r ; j++){
            if(nums[j] - val >= 0){
                nums[j] = nums[j] - val ;
                sum -= val ;
            }
            else{  
                sum -= nums[j] ;
                nums[j] = 0 ;
            }

            if(sum == 0) return i + 1;
        }
    }
    return -1 ;
}
 
int main(){
 
    vector<int> nums = {2,0,2};
    vector<vector<int>>queries = {{0,2,1},{0,2,1},{1,1,3}} ;
    cout << minZeroArray(nums, queries) ;
    return 0;
}