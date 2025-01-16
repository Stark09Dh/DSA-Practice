#include<bits/stdc++.h>
 
using namespace std ;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size() ;
    vector<int>ans ;
    unordered_map<int, int>mp ;
    for(int i = 0 ; i < n ; i++){
        int val  = 0 ;
        mp[A[i]]++  ;
        for(int  j =0 ; j<= i;j++){
            if(mp.find(B[j]) != mp.end()){
                val++ ;
            }
        }
        ans.push_back(val) ;
    }   
    return ans ;
}
 
int main(){
 
    vector<int> A = {2,1,3};
    vector<int> B = {3,1,2} ;
    
    vector<int>ans = findThePrefixCommonArray(A, B);
    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}