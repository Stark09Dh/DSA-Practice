#include<bits/stdc++.h>
 
using namespace std ;

int maxCount(vector<int>& banned, int n, int maxSum) {
    int ans = 0 ;
    int sum = 0 ;
    set<int>st(banned.begin() , banned.end()) ;

    for(int i = 1 ; i<=n ; i++){
        if(!st.count(i)){
            if(sum+ i <= maxSum){
                sum += i ;
                ans += 1;  
            }  
            else{
                break ;
            }
        }
    }
    return ans ;
        
}
 
int main(){
 
    vector<int> banned = {1,2,3,4,5,6,7} ;
    int n = 8 ;
    int maxSum = 1 ;

    cout << maxCount(banned , n , maxSum) ;
    return 0;
}