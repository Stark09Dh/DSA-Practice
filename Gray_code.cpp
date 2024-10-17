// leetcode 89 Gray Code 

#include<bits/stdc++.h>
 
using namespace std ;

vector<int> grayCode(int n) {
    vector<int>ans = {0, 1} ;
    
    for(int i=1 ;i<n;i++){
        auto temp = ans ;
        reverse(temp.begin() , temp.end());
        for(auto &v : temp) v += 1 << i ;
        ans.insert(ans.end() , temp.begin() , temp.end());
    }

    return ans ;
}
 
int main(){
 
    int num = 3 ;
    vector<int> ans = grayCode(num) ;

    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}