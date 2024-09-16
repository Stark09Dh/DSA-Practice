#include<bits/stdc++.h>
 
using namespace std ;

int findMinDifference(vector<string>& timePoints) {

    vector<int>minutes ;
    
    for (int i = 0; i < timePoints.size(); ++i) {
        int h = stoi(timePoints[i].substr(0, 2));
        int m = stoi(timePoints[i].substr(3));
        minutes[i] = h * 60 + m;
    }

    sort(minutes.begin(),minutes.end());

    int minD = INT_MAX ;

    for(int i=0;i<minutes.size()-1;i++){
        minD = min(minD , minutes[i+1] - minutes[i]) ;
    }

    minD = min(minD , 24*60 - minutes.back() + minutes.front());

    return minD ;
}
 
int main(){
 
    vector<string> timePoints = {"23:59","00:00"} ;
    int ans = findMinDifference(timePoints);

    cout << ans ;
    return 0;
}