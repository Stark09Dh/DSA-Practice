#include<bits/stdc++.h>
 
using namespace std ;

string range_extraction(vector<int> args) {
    int n = args.size() ;
    string ans = "" ;

    int l = 0  ;
    while(l < n){
        int r = l+1;
        while(args[r-1]+1 == args[r]){
            r++;
        }

        if(r-l-1 >= 2){
            ans += to_string(args[l])+"-"+to_string(args[r-1]) ;
            l = r-1 ;
        }
        else{
            ans += to_string(args[l]) ;
        }
        
        l++;
        if(l < n){
            ans += "," ;
        }

    }
    return ans ;
}
 
int main(){
 
    vector<int> args = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20} ;
    // return "-6,-3-1,3-5,7-11,14,15,17-20" 
    string ans = range_extraction(args) ;

    cout << ans << endl;
    

    return 0;
}