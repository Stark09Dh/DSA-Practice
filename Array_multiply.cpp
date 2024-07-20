#include<bits/stdc++.h>
 
using namespace std ;


// Brute Force TC = O(N*N) SC = O(N)
vector<int>sol(vector<int>&arr){
    int n = arr.size();
    vector<int>res;
    for(int i=0;i<n;i++){
        int temp = 1;
        for(int j=0;j<n;j++){
            if(i != j){
                temp *= arr[j];
            }
        }
        res.push_back(temp);
    }
    return res ;
}


// TC = O(N) SC = (3N) 
vector<int> sol2(vector<int>&arr){
    int n = arr.size();
    vector<int>left_p(n,1);
    vector<int>right_p(n,1);
    vector<int>res(n,1);

    for(int i=1;i<n;i++){
        left_p[i] = left_p[i-1]*arr[i-1];
    }
    for(int i=n-2;i>=0;i--){
        right_p[i] = right_p[i+1]*arr[i+1];
    }

    for(int i=0;i<n;i++){
        res[i] = left_p[i]*right_p[i];
    }
    return res ;

}
 
int main(){
 
    vector<int> arr = {1,2,3,4};
    vector<int> ans = sol2(arr);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}