#include<bits/stdc++.h>
 
using namespace std ;

int countPalindromicSubsequence(string s) {
    int n = s.length(); 
    unordered_set<char> letters ;
    for(char &i : s){
        letters.insert(i);
    }

    int ans = 0 ;

    for(auto &letter : letters){
        int left_idx = -1 ;
        int right_idx = -1 ;

        for(int i = 0 ;i<n ; i++){
            if(s[i] == letter){
                if(left_idx == -1){
                    left_idx = i ;
                }
                right_idx = i ;

            }
            
        }

        unordered_set<char>middleChar ;

        for(int j = left_idx+1 ; j < right_idx ; j++){
            middleChar.insert(s[j]);
        }

        ans += middleChar.size() ;

    
    }
    return ans ;
}
 
int main(){
 
    string s = "bbcbaba" ;
    int ans = countPalindromicSubsequence(s) ;
    cout << ans ;
    return 0;
}