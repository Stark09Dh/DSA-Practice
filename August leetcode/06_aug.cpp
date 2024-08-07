#include<bits/stdc++.h>
 
using namespace std ;



int minimumPushes(string &word){
    int n = word.length();

    vector<int> mp(26,0) ;

    for(int i=0;i<n;i++){
        mp[word[i]-'a']++ ;
    }

    sort(mp.begin(),mp.end(),greater<int>()) ;

    int ans = 0 ;


    for (int i = 0; i < 26; ++i) {
        ans += (i / 8 + 1) * mp[i];
    }

    return ans ;

}
 
int main(){
 
    string word = "abcde";
    int ans = minimumPushes(word);
    cout << ans ;
    return 0;
}