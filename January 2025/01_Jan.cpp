#include<bits/stdc++.h>
 
using namespace std ;

// 0 0 1 1 1

int maxScore(string s) {
    int n = s.length() ;
    int ans = 0;
    vector<int>left(n,0);
    vector<int>right(n,0);
    if(s[0] == '0') left[0] = 1 ;
    if(s[n-1] == '1') right[n-1] = 1 ;

    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = left[i-1] ;
        }
    }

    for(int &i : left){
        cout<< i << " ";
    }
    cout<<endl;

    for(int i= n-2 ;i>=0 ; i--){
        if(s[i]=='1'){
            right[i] = right[i+1]+1 ;
        }
        else{
            right[i] = right[i+1] ;
        }
    }
    for(int &i : right){
        cout<< i << " ";
    }
    cout<<endl;
    if(s=="00"||s=="11") return 1 ;
    if(s=="01"||s=="10") return 2 ;
    for(int i=1;i<n-1;i++){
        ans = max(ans , left[i]+right[i]);
    }

    return ans ;
}

int maxScore2(string s) {
        int n = s.length() ;
        int ans = 0;
        int ones = count(s.begin() , s.end() ,'1') ; // treat whole string as right part so count 1 in right part
        int zeroes = 0 ; // at first left substring is 0 so number of 0 is 0

        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){ // as we iterate from left to right we find zeroes in left part hence increase number of 0
                zeroes++;
            }
            else{
                ones-- ; // from left to right if we find 1, but 1 only count in right part, but we are iterating as left part hence dec. it from ones 
            }

            ans = max(ans, ones+zeroes) ; // every time take max of ones and zeroes
        }
        return ans ;
    }
 
int main(){
    string s = "00" ;
    int ans = maxScore(s); 
    cout << ans ;
    return 0;
}