#include<bits/stdc++.h>
 
using namespace std ;

int nthUglyNumber(int n){
    vector<int>ans(n+1);
    int i2,i3,i5;
    i2 = i3 = i5 =1 ;

    ans[1] =1 ;

    for(int i=2;i<=n;i++){
        int i_2 = ans[i2]*2;
        int i_3 = ans[i3]*3;
        int i_5 = ans[i5]*5;

        int mini = min({i_2, i_3,i_5});

        ans[i] = mini;

        if(mini == i_2){
            i2++ ;
        }
        if(mini == i_3){
            i3++ ;
        }
        if(mini == i_5){
            i5++ ;
        }
    }

    return ans[n];
}
 
int main(){
 
    int n = 10 ;
    int ans = nthUglyNumber(n);
    cout << ans ;
    return 0;
}