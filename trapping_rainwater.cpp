#include<bits/stdc++.h>
 
using namespace std ;


// using prefix and suffix max TC = O(3n) SC = 2O(n)
int sol(vector<int>&arr){
    int n= arr.size();
    int ans = 0 ;
    vector<int>prefix(n,0);
    vector<int>suffix(n,0);
    suffix[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],arr[i]);
    }
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = max(prefix[i-1],arr[i]);
    }
    for(int i=0;i<n;i++){
        int temp = min(prefix[i],suffix[i]) - arr[i];
        ans += temp; 
    }
    return ans ;
}
 
// using two pointer TC = O(N) SC = O(1);
int sol2(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0; // if there are less than 3 elements, no water can be trapped
    int ans = 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;

    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                ans += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                ans += rightMax - arr[right];
            }
            right--;
        }
    }
    return ans;
}


int main(){
 
    vector<int>arr = {4,2,0,3,2,5};
    int ans = sol(arr);
    cout << ans ;
    return 0;
}