#include<bits/stdc++.h>
 
using namespace std ;

void solution(int n){
    int left = 1 ;
    int right = n * (n+1) ;
    int col = n*2 ;
    vector<vector<int>>ans(n,vector<int>(col , 0));

    for(int i=0;i<n;i++){
        for(int j=i ; j <= col - i -1 ; j++){
            if(j<n){
                ans[i][j] = left ;
                left++ ;
            }
            else if(j>= n){
                ans[i][j] = right - (col - 1 - j);
            }
        }
        right = right - ( n-i-1 );
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            if(ans[i][j] == 0){
                cout << " ";
            }
            else{
                cout << ans[i][j] ;
                if(j < ans[i].size()-1  && ans[i][j + 1] != 0){
                    cout << "*" ;
                }
            }
        }
        cout << endl ;
    }
}
 
int main(){
 
    int n ;
    cin >> n ;
    solution(n);

    return 0;
}