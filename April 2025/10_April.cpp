#include<bits/stdc++.h>
 
using namespace std ;
typedef long long ll ;
class Solution{
    
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1) ;
        string finishStr = to_string(finish) ;

        return sol(finishStr,s,limit) - sol(startStr,s,limit) ;

    }
private:
    long long sol(string &str , string suffix,int limit){
        if(str.length() < suffix.length()) return 0 ;

        long long count =0 ; 
        string trailString = str.substr(str.length() - suffix.length());
        int remainigLen = str.length() - suffix.length() ;

        for(int i = 0; i < remainigLen ; i++){
            int digit = str[i] - '0' ;
            if(digit <= limit){
                count += digit * pow(limit+1 , remainigLen-i-1);

            }
            else{
                count += pow(limit + 1 , remainigLen-i) ;
                return count ;
            }
        }
        if(trailString >= suffix){
            count += 1 ;
        }

        return count ;

    }
};
int main(){
 
    Solution sol ;
    ll start = 125 ;
    ll finish = 125;
    int limit  = 9 ; // 1 <= limit <= 9
    string s = "25" ;
    cout << sol.numberOfPowerfulInt(start , finish , limit , s) ;
    

    return 0;
}