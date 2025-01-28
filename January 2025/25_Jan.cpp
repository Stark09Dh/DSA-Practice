#include<bits/stdc++.h>
 
using namespace std ;
 
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size() ;
    for(int i=0;i<n;i++){
        while(true){
            int smallValue = nums[i] ;
            int idx = -1 ;

            for(int j = i+1 ; j < n; j++){
                if(abs(nums[j] - nums[i])){
                    if(nums[j] < smallValue){
                        smallValue = nums[j] ;
                        idx = j ;
                    }
                }
            }

            if(idx != -1){
                swap(nums[i] , nums[idx]) ;
            }
            else{
                break ;
            }
        }
    } 
    return nums ;
}

// Better Approach
vector<int> lexicographicallySmallestArray2(vector<int>& nums, int limit) {
    int n = nums.size() ;
    vector<int>vec = nums ;
    sort(vec.begin() , vec.end()) ;

    int groupNum = 0; 
    unordered_map<int , int>numToGroup ;
    numToGroup[vec[0]] = groupNum ;

    unordered_map<int,list<int>>groupToList;
    groupToList[groupNum].push_back(vec[0]) ;

    for(int i = 1 ; i < n ; i++){
        if(abs(vec[i] - vec[i-1] > limit)){
            groupNum +=1 ;
        }
        numToGroup[vec[i]] = groupNum ;
        groupToList[groupNum].push_back(vec[i]) ;
    }
    vector<int>res; 
    for(int i = 0 ; i < n;i++){
        int num = nums[i] ;
        int group = numToGroup[num] ;
        res[i] = *(groupToList[group].begin()) ;
        groupToList[group].pop_front() ;

    }
    return res ;

}



int main(){
 
    vector<int> nums = {1,5,3,9,8};
    int limit = 2 ;
    vector<int>ans = lexicographicallySmallestArray2(nums , limit) ;
    for(int i : ans ){
        cout << i << " " ;
    }
    return 0;
}