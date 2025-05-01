#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp ;
        for(auto &i : answers){
            mp[i]++ ;
        }

        int rabits = 0 ;

        
        for(auto &it : mp){
            int x = it.first ;
            int count = it.second ;

            int groupSize = x+1 ;
            int groups = ceil((double)count / groupSize) ;

            rabits += groups* groupSize ;
        }
        return rabits ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> nums = {1,1,2} ;
    cout << sol.numRabbits(nums) ;
    return 0;
}