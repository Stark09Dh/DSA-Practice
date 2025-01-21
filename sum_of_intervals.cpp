#include<bits/stdc++.h>
 
using namespace std ;

int sum_intervals(vector<pair<int, int>> intervals) {
    int ans = 0 ;
    sort(intervals.begin() , intervals.end());
    
    vector<vector<int>> temp ;
    // temp.push_back({intervals[0].first , intervals[0].second});
    for(int i = 1 ; i < intervals.size() ; i++){
        int first = intervals[i].first;
        int second = intervals[i].second ;

        if(temp.empty() || first > temp.back()[1]){
            temp.push_back({first,second}) ;
        }
        else{
            temp.back()[1] = max(temp.back()[1],second) ;
        }
    }
    for(vector<int> &vec:temp){
        for(int &i:vec){
            cout << i << " ";
        }
        cout << endl ;
    }

    for(auto &i: temp){
        ans += i[1] - i[0] ; 
    }


   return ans ; 
}
 
int main(){

    vector<pair<int,int>> intervals = {{1, 5},{10, 20},{1, 6},{16, 19},{5, 11}};
    
    int ans = sum_intervals(intervals) ;

    cout << ans ;

    
 
    
    return 0;
}