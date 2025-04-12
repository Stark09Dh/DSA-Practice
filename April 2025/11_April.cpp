#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int countSymmetricIntegers(int low, int high) {
        if(low >= 100 && high <= 1000) return 0 ;
        int count = 0 ;
        
        for(int i = low ; i<= high ; i++){
            string s = to_string(i) ;
            int sum = 0 ;
            if(s.length() % 2 != 0) continue;
            else{
                if(check(s)) count++ ;
            }
        }
        return count ;
    }
private:
    bool check(string &s){
        int n = s.length();
        int sum1 = 0 ;
        int sum2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i < n/2) sum1 += s[i]-'0' ;
            else sum2 += s[i]-'0' ;
        }
        return sum1 == sum2 ;

    }
 
};
int main(){
 
    Solution sol ;
    int low = 1200 ;
    int high = 1230 ;
    cout << sol.countSymmetricIntegers(low , high) ;

    return 0;
}