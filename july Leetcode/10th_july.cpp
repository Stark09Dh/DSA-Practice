#include<bits/stdc++.h>
 
using namespace std ;

int minOperations(vector<string>&logs){
    int l = 0, r = 0 , size = logs.size();
    
    while(r < size){
        if(logs[r] == "../"){
            l = max(0,l-1);
        }
        else if(logs[r] == "./"){
            l = max(0,l) ;
        }
        else{
            l = max(0,l+1) ;
        }
        r++;
    }
    return l ;
}
 
int main(){
 
    vector<string>logs = {"d1/","d2/","../","d21/","./"};
    int ans = minOperations(logs);
    cout << ans ;
    return 0;
}