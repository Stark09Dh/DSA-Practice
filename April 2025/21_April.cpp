#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    bool check(int first , int last , vector<int>&nums, int lower , int upper){
        int next = first ;
        for(int i = 0 ; i < nums.size() ; i++){
            // cout << "Next : "<<next << endl ;
            next += nums[i] ;
            if(next < lower || next > upper) return false ;
        }
        // cout << "Next : " << next << endl ;
        return next==last ;
    }

    // brute force
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int sum = accumulate(differences.begin() , differences.end() , 0);
        vector<pair<int,int>>possibles ;
        for(int i = lower ; i <= upper - sum ; i++){
            int first = i ;
            int last = i + sum ;
            possibles.push_back({first, last});
        }   
        int res = 0 ; 
        for(auto &it : possibles){
            // cout << "First : " << it.first << " second : " << it.second << endl;
            if(check(it.first , it.second , differences , lower , upper)){
                res++ ; 
            }
        }
        return res ;
    }

    // optimized 

    int numberOfArray(vector<int>&differences , int lower , int upper) {
        
        int minval = INT_MAX , maxval = INT_MIN , prefix = 0;

        for(int &d : differences){
            prefix += d ;
            minval = min(minval , prefix) ;
            maxval = max(maxval , prefix) ;
        }
        if( ((upper - maxval) - (lower - minval) + 1 ) <= 0) return 0 ;

        return (upper - maxval) - (lower - minval) + 1 ;
    }


 
};
int main(){
 
    Solution sol ;
    int lower = 3 , upper = 6 ;
    vector<int>differences = {4,-7,2} ;
    cout << sol.numberOfArray(differences , lower , upper) ;
    return 0;
}