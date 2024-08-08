// 452. Minimum Number of Arrows to Burst Balloons

#include<bits/stdc++.h>
 
using namespace std ;

int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(),points.end());

    vector<vector<int>>res ;

    for(int i=0;i<n;i++){
        if(res.empty() || res.back()[1]<points[i][0]){
            res.push_back(points[i]);
        }
        else{
            res.back()[0] = max(res.back()[0],points[i][0]);
            res.back()[1] = min(res.back()[1],points[i][1]);
        }
    }

    return res.size();
    
}
 
int main(){
 
    vector<vector<int>>points = {{1,2},{3,4},{5,6},{7,8}};
    int ans = findMinArrowShots(points);
    cout << ans ;
    return 0;
}