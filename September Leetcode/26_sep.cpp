#include<bits/stdc++.h>
 
using namespace std ;

class MyCalendar {
public:
    vector<pair<int,int>>range ;
    MyCalendar() {
        
    }
    int startTime = 0 ;
    int endTime = 0 ;
    
    bool book(int start, int end) {
        for(auto &i : range){
            int startTime = i.first ;
            int endTime = i.second ;

            if(start < endTime && end > startTime){
                return false ;
            }
        }
        range.push_back({start , end}) ;
        return true ;
    }
};
 
int main(){

    vector<vector<int>>arr = {{10,20},{15,25},{20,30}};
 
    MyCalendar* obj = new MyCalendar();

    for(auto &it : arr){
        int start = it[0];
        int end = it[1] ;
        bool param_1 = obj->book(start,end);
        cout << param_1 << " ";
    }
    
    return 0;
}