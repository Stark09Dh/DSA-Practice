#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int calculateSum(int x){
        string s = to_string(x) ;
        int sum = 0 ;
        for(auto &it : s){
            sum += it-'0' ;
        }
        return sum ;
    }

    int countLargestGroup(int n) {

        unordered_map<int,int>mp;
        int maxSize = 1 ;
        for(int i = 1 ; i <= n ; i++){
            int sum = calculateSum(i) ;
            mp[sum]++ ;
            maxSize = max(maxSize , mp[sum]) ;
        }
        int ans = 0 ;

        for(auto &it : mp){
            if(it.second == maxSize){
                ans++ ;
            }
        }
        return ans ; 
        
    }
 
};
int main(){
 
    Solution sol ;
    int n = 2 ;
    cout << sol.countLargestGroup(n);

    return 0;
}