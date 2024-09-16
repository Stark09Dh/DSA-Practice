#include<bits/stdc++.h>
 
using namespace std ;
vector<pair<int,int>>vec ;
int maxMeetings(int n, int start[], int end[]) {
    // Your code here
    int res = 0; // n <= s.size();
    
    for(int i=0;i<n;i++){
        vec.push_back({end[i],start[i]});
    }

    sort(vec.begin(),vec.end());

    int endtime = -1 ;

    for(auto &it : vec){
        if(it.first > endtime && it.second > endtime){
            endtime = it.first ;
            res++ ;
        }
    }

    return res;

}
 
int main(){
    
    int n = 3 ;
    int start[n] = {10,12,20};

    int end[n] = {20,25,30};

    int ans = maxMeetings(n,start,end);

    cout << ans ; 
    
    return 0;
}