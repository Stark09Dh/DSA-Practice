#include<bits/stdc++.h>
 
using namespace std ;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int>ans;

    
    
    for(auto &it : queries){
        int first = it[0];
        int second = it[1] ;
        int tempxor = 0 ;
        for(int i=first ;i <= second ; i++){
            tempxor = tempxor ^ arr[i] ;
        }
        ans.push_back(tempxor);
    }

    return ans ;

}
 
int main(){
 
    vector<int>arr = {1,3,4,8} ;
    vector<vector<int>>queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int>ans = xorQueries(arr,queries);

    for(auto &it : ans){
        cout << it << " ";
    }
    // cout << (3^4) ;
    return 0;
}