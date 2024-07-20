// Find the index of First occurence 

#include<bits/stdc++.h>
 
using namespace std ;

int sol(string &needle, string &haystack){
    int n = needle.length();
    int m = haystack.length();

    for (int i = 0; i <= m - n; i++) { // Loop through possible start positions
        int j;
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) { // If we reached end of needle, it means we found a match
            return i;
        }
    }

    return -1;
}

 
int main(){
 
    string needle = "a";
    string haystack = "a";
    int idx = sol(needle, haystack);
    cout << idx ;
    return 0;
}