#include<bits/stdc++.h>
 
using namespace std ;

int maxPoints(vector<vector<int>>& points){
    int n= points.size();
    int ans = 0 ;
    for(int i=0;i<n-1;i++){
        unordered_map<double,int>mp ;

        for(int j=0;j<n;j++){
            if(j == i) continue ;
            auto dy = (points[j][1] - points[i][1]);
            auto dx = (points[j][0] - points[i][0]);

            auto theta = atan2(dy,dx);
            mp[theta]++ ;
        }
        for(auto &it : mp){
            ans = max(ans, it.second+1);
        }
    }
    return ans ;
}
 
int main(){
 
    vector<vector<int>>points = {{1,1},{2,2},{3,3}} ;
    int ans = maxPoints(points);
    cout << ans ;
    return 0;
}