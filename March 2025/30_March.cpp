#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    vector<int> partitionLabels(string s) {
        int n = s.length() ;
        vector<int>res ;
        vector<int>mp(26,-1) ;

        for(int i= 0 ; i < n ; i++){
            int idx = s[i] - 'a' ;
            mp[idx] = i ;
        }

        int i = 0 ;
        while(i < n ){
            int end = mp[s[i] - 'a' ];

            int j = i ;
            while( j < end){
                end = max(end , mp[s[j]-'a']) ;
                j++ ;
            }
            res.push_back(j - i + 1) ;
            i = j + 1 ;
        }
        return res ;

    }
 
};
int main(){
 
    Solution sol ;
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = sol.partitionLabels(s);
    for(auto &i : ans ){
        cout << i << " ";
    }
    
    return 0;
}