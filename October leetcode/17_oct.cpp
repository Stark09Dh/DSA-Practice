#include<bits/stdc++.h>
 
using namespace std ;

int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.length() ;

    vector<int>maxRight(n) ;

    maxRight[n-1] = n-1 ;

    for(int i = n-2 ;i >= 0 ;i-- ){
        int rightMax_idx = maxRight[i+1] ;
        int rightMax_element = s[rightMax_idx] ;

        maxRight[i] = (s[i] > rightMax_element) ? i : rightMax_idx ;
    }

    for(int i=0;i<n;i++){
        int maxRight_idx = maxRight[i];
        int maxRight_element = s[maxRight_idx] ;
        if(s[i] < maxRight_element) {
            swap(s[i] , s[maxRight_idx]);
            return stoi(s) ;
        }
    }

    return num ;
}
 
int main(){
 
    int num = 9973 ;
    cout << maximumSwap(num) ;
    // vector<int>ans = maximumSwap(num);

    // for(int &i : ans){
    //     cout << i << " ";
    // }

    
    return 0;
}