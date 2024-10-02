#include<bits/stdc++.h>
 
using namespace std ;

vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    vector<int>ans(n);
    unordered_map<int ,int>mp ;
    vector<int>temp(arr.begin(), arr.end());

    sort(temp.begin(),temp.end());
    int rank = 1 ;
    for(int i = 0 ;i<n;i++){
        if(mp.find(temp[i]) == mp.end()){
            mp[temp[i]] = rank ;
            rank++;
        }
        
        
    }

    for(int i=0;i<n;i++){
        ans[i] = mp[arr[i]] ;
    }

    return ans ;
}
 
int main(){
    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    vector<int>ans = arrayRankTransform(arr);
    for(auto &it : ans){
        cout << it << " ";
    }
    return 0;
}