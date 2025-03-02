#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>>temp ;
    for(auto i : nums1){
        temp.push_back(i);
    }
    for(auto i : nums2){
        temp.push_back(i);
    }
    sort(temp.begin() , temp.end()) ;
    vector<vector<int>>ans ;
    ans.push_back(temp[0]) ;

    for(int i = 1 ; i < temp.size() ; i++){
        if(ans.back()[0] == temp[i][0]){
            ans.back()[1] = ans.back()[1] + temp[i][1] ;
        }
        else{
            ans.push_back(temp[i]) ;
        }
    }

    return ans ;

}
 
int main(){

    vector<vector<int>>nums1 = {{2,4},{3,6},{5,5}};
    vector<vector<int>>nums2 = {{1,3},{4,3}} ;
    vector<vector<int>>ans = mergeArrays(nums1 , nums2) ;

    for(vector<int> &vec : ans){
        for(int i : vec) {
            cout << i << " " ;
        }
        cout << endl;
    }
    return 0;
}