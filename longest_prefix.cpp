#include<bits/stdc++.h>
 
using namespace std ;

string sol(vector<string>&strs){
    if (strs.empty()) return "";
    int n= strs.size();
    string ans = strs[0];
    int m = ans.length();
    for(int i=1;i<n;i++){
        string temp = strs[i];
        int y = temp.length();
        int l = m-1 , r = y-1 ;
        if(m != y){
            while(l>r){
                --l;
                ans.pop_back();
            }
            while(r>l){
                --r;
            }
        }
        while(l>=0 && r>=0){
            if(ans[l] == temp[r]){
                l--,r--;
            }
            else{
                l--,r--;
                ans.pop_back();
            }
        }
    }
    return ans ;
}

string sol2(vector<string>& strs) {
    if (strs.empty()) return ""; 
    
    string ans = strs[0]; 
    int n = strs.size();
    
    for (int i = 1; i < n; ++i) {
        string temp = strs[i];
        int m = ans.length(); 
        int y = temp.length(); 
        
        int l = 0, r = 0;
        while (l < m && r < y && ans[l] == temp[r]) {
            ++l;
            ++r;
        }
        ans = ans.substr(0, l); 
    }
    
    return ans;
}

 
int main(){
 
    vector<string>strs = {"flower","flow","flight"};
    string ans = sol2(strs);
    cout << ans << " ";

    return 0;
}