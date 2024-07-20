#include<bits/stdc++.h>
 
using namespace std ;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0;
    int j = 0;
    vector<int>ans;
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i]>nums2[j]){
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<m){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        ans.push_back(nums2[j]);
        j++;
    }
    for(int i=0;i<m+n;i++){
        nums1[i] = ans [i];
    }
}
 
int main(){
    int n=3;
    int m = 3;
    vector<int>arr1 = {1,2,3};
    vector<int>arr2 = {2,5,6};
    merge(arr1,m,arr2,n);
    for(int i = 0 ;i<m+n;i++){
        cout << arr1[i] << " ";
    }
    
    return 0;
}