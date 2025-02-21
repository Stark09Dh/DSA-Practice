#include<bits/stdc++.h>
using namespace std ;

// Brute Force TC = O(2^n)
// Better approach would be Cantor's Diagonalization Method 


set<string>st ;

string decToBinary(int x, int n){
    string res = "" ;
    string s(n,'0' ) ;
    if(x == 0) return s;
    while(x >= 1){
        int rem = x % 2 ;
        x = x / 2 ;
        res.push_back(rem  + '0') ;
    }
    reverse(res.begin() , res.end()) ;
    if (res.size() < n) {
        res = string(n - res.size(), '0') + res; // Left-pad with '0'
    }
    return res ;
}


void check(int n , string &ans){
    int maxNum = pow(2,n) ;
    for(int i = 0 ; i < maxNum ; i++){
        string temp = decToBinary(i,n) ;
        if(st.find(temp) == st.end()){
            ans = temp ;
            
        }
    }
}


string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size() ; // size of Binary string and nums
    for(auto i : nums){
        st.insert(i) ;
    }
    string ans ;
    check(n , ans) ; 
    return ans ;
}

// using Cantor's Diagonalization Method --> For each index i in nums, take the i-th character of the i-th string and flip it ('0' → '1', '1' → '0').

string sol(vector<string>&nums){
    string ans = "";
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        
        ans += (nums[i][i] == '0') ? '1' : '0';
    }
    return ans;
}
 
int main(){
 
    vector<string>nums = {"10" , "11"} ;
    // string ans = findDifferentBinaryString(nums) ;
    string ans = sol(nums) ;
    cout << ans ;
    return 0;
}