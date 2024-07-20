#include<bits/stdc++.h>
 
using namespace std ;

string IntToRoman(int n){
    string ans = "";
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;    
    while(n>0)
    {
      int div = n/num[i];
      n = n%num[i];
      while(div--)
      {
        ans += sym[i];
      }
      i--;
    }
    return ans ;
}
 
int main(){
 
    string res = IntToRoman(58);
    cout << res ;
    return 0;
}