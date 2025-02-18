#include<bits/stdc++.h>
 
using namespace std ;

string smallestNumber(string pattern) {
    int n = pattern.length() ;

    string num = "" ;
    int counter = 1 ;
    stack<char>st ;

    for(int i = 0 ; i <=n ; i++){
        st.push(counter+'0') ;
        counter++ ;
        if( i == n || pattern[i] =='I'){
            while(!st.empty()){
                num+= st.top();
                st.pop() ;
            }
        }
    }
    return num ;
}

string smallestNumber2(string pattern){
    int n = pattern.length() ;
    string num = "" ;
    for(int i = 1 ; i <= n+1 ; i++){
        num += char(i +'0') ;
    }
    bool D_seen = false;
    int count_D = 0 ;
    int idx = -1 ;

    for(int i = 0 ; i <= n ; i++){
        if(pattern[i] == 'I' && D_seen){
            // cout << *(num.begin())<< " " <<idx  << " "<< endl ;
            reverse(num.begin()+idx , num.begin()+i+count_D);
            count_D = 0 ;
            D_seen = false ;
        }
        else if(pattern[i] =='D'){
            if(D_seen == false){
                idx = i ;
            }
            D_seen = true ;
            count_D++;
            
        }
        if(i == n && pattern[i-1] == 'D'){
            reverse(num.begin()+idx , num.end());
        }
    }
    return num ;
}
 
int main(){
 
    string pattern = "IIIDIDDD";
    string ans = smallestNumber(pattern) ;
    cout << ans  ;
    return 0;
}

// char - '0' -->char to int