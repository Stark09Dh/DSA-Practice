#include<bits/stdc++.h>
 
using namespace std ;

// TC : O(n*m) TLE
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int n = items.size();
    int m = queries.size() ;

    sort(items.begin() , items.end()) ;

    vector<int>ans(m,-1) ;

    for(int i=0;i<m;i++){
        int tempval = INT_MIN ;
        for(int j=0;j<n;j++){
            int price = items[j][0] ;
            int beauty = items[j][1] ;
            if(price <= queries[i]){
                tempval = max(tempval , beauty) ;
            }
        }
        ans[i] = (tempval == INT_MIN) ? 0 : tempval ;
    }

    return ans ;
}

// TC : O(n*log(n) + m*log(n))

vector<int> maximumBeauty2(vector<vector<int>>& items, vector<int>& queries) {
    int n = items.size();
    int m = queries.size() ;

    sort(items.begin() , items.end()) ;

    int maxBeauty = items[0][1] ;

    vector<int>ans(m,-1) ;

    for(int i=0;i<n;i++){
        maxBeauty = max(maxBeauty , items[i][1]);
        items[i][1] = maxBeauty ;
    }

    for(int i=0;i<m;i++){
        int q = queries[i] ;
        int low = 0 , high = n-1 ;
        int temp = 0  ;
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            int price = items[mid][0] ;
            int beauty = items[mid][1] ;
            

            if(price <= queries[i]){
                temp = max(temp , beauty) ;
                low = mid + 1 ;
            }
            else{
                high = mid - 1 ;
            }
        }
        ans[i] = temp ;
    }

    return ans ;
}

 
int main(){
 
    vector<vector<int>>  items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int>queries = {1,2,3,4,5,6} ;
    vector<int>ans = maximumBeauty2(items , queries) ;

    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}