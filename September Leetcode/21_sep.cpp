#include<bits/stdc++.h>
 
using namespace std ;

void solve(int start , int n ,vector<int>&res){
    if(start>n) return ;

    res.push_back(start);

    for(int curr = 0 ; curr <= 9 ; curr++){
        int newNum = (start*10) + curr ;
        if(newNum > n) return ;
        
        solve(newNum ,n ,res);
        
    }
}

vector<int> lexicalOrder(int n) {
    vector<int>res ;

    for(int start = 1 ;start<=9; start++){
        solve(start,n,res);
    }


    return res ; 
}
 
int main(){
 
    int n = 13 ;
    vector<int>ans = lexicalOrder(n);
    for(auto &i : ans){
        cout << i << " ";
    }
    return 0;
}