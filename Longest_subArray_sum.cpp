// longest subArray sum whonse Sum is equals to k

#include<bits/stdc++.h>
 
using namespace std ;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    int ans = 0; // To store the maximum length
    int sum = 0; // To keep track of the current sum
    unordered_map<int, int> sumMap; // To store the first occurrence of each sum

    // Initialize the map with sum 0 at index -1 to handle the case where the sum equals k at some point
    sumMap[0] = -1;

    for (int r = 0; r < n; r++) {
        sum += a[r]; // Add the current element to the sum

        // Check if there is a subarray with the required sum
        if (sumMap.find(sum - k) != sumMap.end()) {
            // If found, calculate the length of the subarray
            ans = max(ans, r - sumMap[sum - k]);
        }

        // Only add the current sum to the map if it's not already there to maintain the earliest index
        if (sumMap.find(sum) == sumMap.end()) {
            sumMap[sum] = r; // Store the index of the first occurrence of this sum
        }
    }
    
    return ans; 

}
 
int main(){
 
    vector<int>nums = {1,2,3,1,1,1,1} ;
    int k = 3 ;
    cout << longestSubarrayWithSumK(nums , k);
    return 0;
}