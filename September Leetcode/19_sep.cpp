#include<bits/stdc++.h>
 
using namespace std ;

int cal(int a , int b , char syb){
    if(syb == '+') return a+b;
    if(syb == '-') return a-b ;
    return a*b ;
}

vector<int> diffWaysToCompute(string exp) {
    vector<int>ans ;
    bool isNum = true ;

    for(int i=0;i<exp.size();i++){
        if(!isdigit(exp[i])){
            isNum = false;

            vector<int>L =diffWaysToCompute(exp.substr(0,i));
            vector<int>R =diffWaysToCompute(exp.substr(i+1));


            for(int x : L){
                for(int y : R){
                    ans.push_back(cal(x,y,exp[i]));
                }
            }
        }
    }
    if(isNum) ans.push_back(stoi(exp));
    return ans ;
}
 
int main(){
 
    string s ="2*3-4*5";
    vector<int>ans = diffWaysToCompute(s);
    for(auto &it : ans){
        cout << it << " ";
    }
    return 0;
}