#include<bits/stdc++.h>
 
using namespace std ;

int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long long total = 0 ;
    for(int c : chalk){
        total += c ;
    }

    k = k % total ;

    for(int i=0;i<n;i++){
        if(k<chalk[i]){
            return i ;
        }
        k -= chalk[i]; 
    }
    return 0 ;
}

 
int main(){
 
    vector<int>chalk = {5,1,5};
    int k = 22 ;

    int ans = chalkReplacer(chalk,k);

    cout << ans ; 
    return 0;
}