#include<bits/stdc++.h>
 
using namespace std ;


// Brute Force 
int smallestChair2(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();

    vector<int> chairs(n,-1);

    int arrival_time = times[targetFriend][0];

    sort(times.begin(),times.end());

    for(vector<int> &vec : times){
        int arrival = vec[0];
        int depart = vec[1] ;
        for(int i=0;i<n;i++){
            if(chairs[i] <= arrival){
                chairs[i]  = depart ;

                if(arrival == arrival_time){
                    return i ;

                }
                break ;
            }
        }
    }
    return -1 ;
}

// optimal Solution 
int smallestChair(vector<vector<int>>& times, int targetFriend) {
    
}


int main(){

    vector<vector<int>>times = {{1,4},{2,3},{4,6}} ;
    int targetFriend = 1 ;

    cout << smallestChair( times , targetFriend) ;
 
    return 0;
}