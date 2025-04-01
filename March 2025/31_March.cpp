#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size() ;
        if (n == 1 || k == 1) return 0;
        vector<long long>splits ;

        for(int i = 0 ; i < n-1 ; i++ ){
            splits.push_back(weights[i] + weights[i+1]) ;
        }

        sort(splits.begin() , splits.end()) ;
        long long m = splits.size() ;
        if(m < k -1 ) return 0 ;
        
        int i = k-1 ;

        long long max_score =  accumulate(splits.end() - i, splits.end(), 0LL);
        long long min_score =  accumulate(splits.begin() , splits.begin()+i,0LL);

        return max_score - min_score ;   
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> weights = {1,3,5,1};
    int k = 2 ;
    cout << sol.putMarbles(weights,k);
    
    return 0;
}