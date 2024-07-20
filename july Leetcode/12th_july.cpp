#include<bits/stdc++.h>
 
using namespace std ;



int maximumGain(string s, int x, int y) {
    vector<char> v , v1 ;
    int score = 0 ; 
    bool flag = 0 ;
    if(x>y) flag = true ;
    for(auto a : s){
        if(!v.empty()){
            if(flag){
                if(v.back() == 'a' && a == 'b'){
                    score += x ;
                    v.pop_back();
                }
                else v.push_back(a);
            }
            else{
                if(v.back() == 'b' && a == 'a'){
                    score += y ;
                    v.pop_back();
                }
                else v.push_back(a);
            }
        }
        else v.push_back(a);
    }

    for(auto a : v){
        if(!v1.empty()){
            if(!flag){
                if(v1.back() == 'a' && a == 'b'){
                    score += x ;
                    v1.pop_back();
                }
                else v1.push_back(a);
            }
            else{
                if(v1.back() == 'b' && a == 'a'){
                    score += y ;
                    v1.pop_back();
                }
                else v1.push_back(a);
            }
        }
        else v1.push_back(a);
    }
    return score ;
}
 
int main(){
 
    string str = "cdbcbbaaabab";
    int x= 4 , y = 5 ;
    int ans = maximumGain(str,x,y);
    cout << ans ;
    return 0;
}