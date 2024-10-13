#include<bits/stdc++.h>
 
using namespace std ;

int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());

    priority_queue<int, vector<int>, greater<int>>pq;

    for(vector<int> interval : intervals){
        int start = interval[0];
        int end = interval[1];

        if(!pq.empty() && start > pq.top()){
            pq.pop();
        }

        pq.push(end);
    }  
    return pq.size() ;
}

 
int main(){
 
    vector<vector<int>>intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}} ;
    cout << minGroups(intervals);
    return 0;
}