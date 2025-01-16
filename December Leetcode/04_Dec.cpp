#include<bits/stdc++.h>
 
using namespace std ;

bool canMakeSubsequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length(); 
    int i = 0 , j = 0 ;

    while(i < n && j < m){
        if(str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i]-25 == str2[j]){
            j++ ;
        }
        i++;
    }
    return j == str2.length() ;

}
 
int main(){
 
    string str1 = "abc", str2 = "ad" ;

    cout << canMakeSubsequence(str1 , str2) ;
    
    return 0;
}