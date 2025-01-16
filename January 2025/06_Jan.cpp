#include<bits/stdc++.h>
 
using namespace std ;

vector<int> minOperations(string boxes) {
    int n = boxes.length();
    vector<int>ans(n);
    int l = 0 ;
    int r = 1 ;
    for(int i = 0 ; i<n;i++){
        int temp_ans = 0;
        if(i > 0){
            l = i-1 ;
            r = i + 1 ;
        }
        while(l>=0){
            if(boxes[l]=='1'){
                temp_ans += i-l ;
            }
            l-- ;
        }
        while(r<n){
            if(boxes[r] == '1'){
                temp_ans += r-i ;
            }
            r++ ;
        }
        ans[i] = temp_ans ;
    }  
    return ans ; 
}
 
int main(){
 
    string s = "001011" ;
    vector<int>ans = minOperations(s) ;

    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}