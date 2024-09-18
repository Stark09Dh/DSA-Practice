#include<bits/stdc++.h>
 
using namespace std ;



string largestNumber(vector<int>& nums) {
    vector<string>str ;

    for(int &i : nums){
        str.push_back(to_string(i));
    }

    sort(str.begin(), str.end(), [](const string& a, const string& b) {
        return a + b > b + a; 
    });

    if (str[0] == "0") {
        return {"0"};
    }

    string ans ="";
    for(auto &s : str){
        ans+=s;
    }

    return ans ;
}
 
int main(){
 
    vector<int>nums = {0,0,0};
    string ans = largestNumber(nums);
    cout << ans ;
    // string s1 = "210" ;
    // string s2 = "102" ;
    // cout << (s1 < s2) ;
    return 0;
}