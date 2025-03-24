#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    // Brute Force gives TLE 
    int countDays(int days , vector<vector<int>>&meetings){
        int n = meetings.size() ;
        sort(meetings.begin() , meetings.end());
        vector<bool>occupied(days+1,false) ;
        for(int i = 0 ; i < n ; i++){
            int x = meetings[i][0] ;
            int y = meetings[i][1] ;
            while(x <= y){
                occupied[x] = true ;
                x++ ;
            }
        }
        int ans = 0 ;
        for(int i = 1 ; i <= days ; i++){
            if(occupied [i] == false) ans++ ;
        }
        return ans ;
    }
    // Better approach
    int countDays_2(int days , vector<vector<int>>&meetings){
        int n  = meetings.size() ;
        sort(meetings.begin() , meetings.end()) ;
        vector<vector<int>> overlapped ;
        overlapped.push_back(meetings[0]);

        for(int i = 1 ; i < n ; i++){
            if(overlapped.back()[1] >= meetings[i][0]){
                overlapped.back()[1] = max(overlapped.back()[1] , meetings[i][1]) ;
            }
            else{
                overlapped.push_back(meetings[i]) ;
            }
        }
        int m = overlapped.size() ;
        
        int ans = 0 ;

        for(int i = 1 ; i < overlapped.size() ; i++){
            int diff =  overlapped[i][0] - overlapped[i-1][1] ;
            ans += diff-1 ; 
        }
        ans += days - overlapped[m-1][1] ; 
        
        return ans  ;

    }
 
};
int main(){



 
    Solution sol ;
    int days = 10 ;
    vector<vector<int>>meetings = {{5,7},{1,3},{9,10}} ;
    cout << sol.countDays_2(days ,meetings) ;
    return 0;
}