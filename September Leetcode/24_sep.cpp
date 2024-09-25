#include<bits/stdc++.h>
 
using namespace std ;

// TC : O(n*m)  SC : O(n+m)
int longestCommonPrefix2(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>hash1 ;
        unordered_set<string>hash2 ;

        for(int i=0;i<arr1.size();i++){
            string temp = to_string(arr1[i]);
            for(int j=0;j<=temp.length();j++){
                hash1.insert(temp.substr(0,j));
            }
        }
        for(int i=0;i<arr2.size();i++){
            string temp = to_string(arr2[i]);
            for(int j=0;j<=temp.length();j++){
                hash2.insert(temp.substr(0,j));
            }
        }
        int ans = INT_MIN;
        for(auto &it : hash1){
            if(hash2.find(it) != hash2.end()){
                int len = it.length() ;
                ans = max(ans,len);
            }
        }

        return ans ;
    }


// TC : O(n*m)  SC : O(n)
int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int>hash1 ;
    int ans = 0 ;

    for(int i : arr1){
        while(!hash1.count(i) && i > 0){
            hash1.insert(i);
            i /= 10 ;
        }
    }

    for(int j: arr2){
        while(!hash1.count(j) && j > 0){
            j /= 10 ;
        }
        if(j > 0){
            ans = max(ans , static_cast<int>(log10(j)+1));
        }
    }

    return ans ;

}

int longestCommonPrefix3(vector<int>& arr1, vector<int>& arr2){
    
}


 
int main(){
 
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {4,4,4} ;
    int ans = longestCommonPrefix(arr1,arr2);
    cout << ans ;
    // to find length of any integer take : len = log10(number)+1
    return 0;
}