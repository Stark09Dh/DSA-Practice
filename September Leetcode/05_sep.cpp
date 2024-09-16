#include<bits/stdc++.h>
 
using namespace std ;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = accumulate(rolls.begin(),rolls.end(),0);
    vector<int>ans ;
    int sumToFill = (mean * (n+m)) - sum ;

    if(sumToFill < n*1 || sumToFill > n*6){
        return {};
    }
    
    while(n){
        int num = min(6,sumToFill-n+1);
        ans.push_back(num);

        sumToFill -= num ;
        n--;
    }
    
    return ans ;
}
 
int main(){
 
    vector<int>rolls = {1,2,3,4};
    int  mean = 6, n = 4 ;
    vector<int>ans = missingRolls(rolls,mean,n);
    for(int i : ans ){
        cout << i << " ";
    }
    return 0;
}