#include<bits/stdc++.h>
 
using namespace std ;

int n ;

int solve(int i ,int j ,vector<vector<int>>&triangle){
    //base case
    if(i==n-1) return triangle[i][j];  


    int down = triangle[i][j] + solve(i+1,j,triangle);
    int daigonal = triangle[i][j] + solve(i+1,j+1,triangle);

    return min(down,daigonal);
}

int minimumTotal(vector<vector<int>>&triangle){
    n = triangle.size();

    return solve(0,0,triangle);

}
 
int main(){
 
    vector<vector<int>>triangle = {{-10}} ;
    int ans = minimumTotal(triangle);
    cout << ans ;
    return 0;
}