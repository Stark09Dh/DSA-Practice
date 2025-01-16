#include<bits/stdc++.h>
 
using namespace std ;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size() ;
    vector<int>ans(n,0) ;
    if(k==0) return ans ;
    vector<int>temp ;
    temp.insert(temp.end() , code.begin() , code.end()) ;
    temp.insert(temp.end() , code.begin() , code.end()) ;

    if ( k > 0) {
        int i = 0 , j = 1 ;
        while(j <= k){
            ans[0] += temp[j] ;
            j++;
        }

        for(int a = 1 ; a < code.size() ; a++){
            int sum = 0;
            j = a+1 ;
            while(j <= a+k){
                sum += temp[j] ;
                j++;
            }
            ans[a] = sum ;
        }
    }
    if(k < 0){
        k = abs(k) ;
        int j = n-k ;
        while(j < n-k+k){
            ans[0] += temp[j] ;
            j++;
        }
        
        for(int a = 1 ; a < code.size() ; a++){
            int sum =  0;
            j = n-k+a ;
            while(j < n+a){
                sum += temp[j] ;
                j++;
            }
            ans[a] = sum ;
        }
    }

    return ans ;

}

//[22,26,22,28,29,22,19,22,18,21,28,19]
 
int main(){
 
    vector<int> code = {10,5,7,7,3,2,10,3,6,9,1,6} ;
    int k =  -4;
    vector<int>ans = decrypt(code , k );
    for(int &i : ans) {
        cout << i << " " ;
    }
    return 0;
}