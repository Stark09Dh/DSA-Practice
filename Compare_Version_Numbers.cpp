// Compare Version Numbers

#include<bits/stdc++.h>
 
using namespace std ;

// if version1 > version2 --> 1
// if version2 > version1 --> -1
// else --> 0

int compareVersion(string version1, string version2) {
    int n = version1.length() ;
    int m = version2.length() ;


    int i = 0 , j =0 ;

    while (i < n || j < m) {
        
        int num1 = 0;
        while (i < n && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        
        int num2 = 0;
        while (j < m && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        
        if (num1 < num2) {
            return -1;
        } else if (num1 > num2) {
            return 1;
        }

        
        if (i < n) i++;  
        if (j < m) j++;  
    }

    return 0;
}
 
int main(){
 
    string version1 = "1.001" ;
    string version2 = "1.20" ;

    cout << compareVersion(version1 , version2 ) ;

    return 0;
}