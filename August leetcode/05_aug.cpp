#include<bits/stdc++.h>
 
using namespace std ;

string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string,int>mp;

    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    string res = "";
    for(auto &it : mp){
        if(it.second == 1){
            res = it.first ;
            k--;
        }
    }

    return (k<=0) ? res : "";

}
 
int main(){
 
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2 ;
    string ans = kthDistinct(arr,k);
    cout << ans ;

    return 0;
}