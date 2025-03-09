#include<bits/stdc++.h>
 
using namespace std ;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size() ;
    int l = 0 ;
    int ans = 0 ;
    for(int r = 1 ; r < ( n + k - 1) ; r++){
        if(colors[r% n] == colors[(r-1) %n]){
            l = r ;
        }
        if(r-l+1 > k){
            l++ ;
        }
        if(r-l+1 == k){
            ans += 1 ;
        } 
    }
    return ans; 
    

}
 
int main(){
 
    vector<int> colors = {0,1,0,0,1,0,1};
    int k = 6 ;
    cout << numberOfAlternatingGroups(colors,k);

    return 0;
}