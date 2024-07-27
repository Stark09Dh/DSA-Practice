#include<bits/stdc++.h>
 
using namespace std ;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital){
    vector<pair<int,int>>temp ;
    int n = profits.size();
    for(int i=0;i<n;i++){
        temp.push_back({capital[i],profits[i]});
    }
    sort(temp.begin(),temp.end());
    priority_queue<int>pq ;

    int i=0;
    while(k--){
        while(i<n && temp[i].first <= w){
            pq.push(temp[i].second);
            i++ ;
        }

        w += pq.top();
        pq.pop();
    }
    return w ;

}
 
int main(){
 
    int w = 0 ;
    int k = 2 ;
    vector<int>profits = {1,2,3};
    vector<int>capitals = {0,1,1};
    int maxProfit =  findMaximizedCapital(k,w,profits,capitals);
    // vector<vector<int>>arr  =  findMaximizedCapital(k,w,profits,capitals);
    cout << maxProfit ;
    // for(auto &it : arr){
    //     cout << it[0]<< " "<<it[1] <<endl;
    // }
    return 0;
}