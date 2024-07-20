#include<bits/stdc++.h>
 
using namespace std ;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

int RomantoDecimal(string &str){
    int n = str.length();
    int res = 0 ;
    for(int i=0;i<n;i++){
        int temp = value(str[i]);
        if(i+1<=n){
            int temp2 = value(str[i+1]);
            if(temp < temp2){
                res -=  temp;
            }
            else{
                res += temp ;
            }
        }
    }
    return res ;
}
 
int main(){
 
    
    string str = "III";
    int ans = RomantoDecimal(str);
    cout << ans ;
    

    return 0;
}