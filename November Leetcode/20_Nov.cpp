#include<bits/stdc++.h>
 
using namespace std ;

// a a b a a a a c a a b c


int takeCharacters(string s, int k) {
    int n = s.length() ;
    int a = 0 , b = 0 , c = 0 ;
    int ans = 0 ;
    for(int i=0;i<n;i++){
        if(s[i] == 'a'){
            a++ ;
        }
        else if(s[i] == 'b'){
            b++ ;
        }
        else{
            c++ ;
        }
    }
    if(a<k || b < k || c < k) return -1 ;

    int i = 0 , j = 0 ;

    while(j < n){
        if(s[j] == 'a'){
            a-- ;
        }
        else if(s[j] == 'b'){
            b-- ;
        }
        else{
            c-- ;
        }

        while( i <= j && (a < k || b < k || c < k)){
            if(s[i] == 'a'){
                a++ ;
            }
            else if(s[i] == 'b'){
                b++ ;
            }
            else{
                c++ ;
            }
            i++ ;
        }

        ans = max(ans , j-i+1);
        j++ ;
    }

    return n-ans ;
}
 
int main(){
 
    string s = "aabaaaacaabc" ;
    int k = 2 ;
    cout << takeCharacters(s , k) ;
    return 0;
}

