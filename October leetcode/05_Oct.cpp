#include<bits/stdc++.h>
 
using namespace std ;


// TC : O(mnlong(n)) SC: O(n);
bool checkInclusion(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int i = 0 ,j= i+n-1;
    sort(s1.begin(),s1.end());

    while(i < m && j < m){
        string temp = s2.substr(i,j-i+1);
        sort(temp.begin(),temp.end());
        if(temp == s1) return true ;
        else{
            i++ , j++ ;
        }
    }

    return false ;
}


// TC : O(m+n) SC : O(26);

bool checkInclusion2(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();

    if(n>m) return false ;

    vector<int>s1_freq(26,0);
    vector<int>s2_freq(26,0);

    for(char &ch : s1){
        s1_freq[ch-'a']++;
    }

    int  i= 0 , j= 0 ;

    while(j<m){
        s2_freq[s2[j]-'a']++;

        if(j-i+1 > n){
            s2_freq[s2[i] -'a']--;
            i++;
        }
        if(s1_freq == s2_freq) return true ;

        j++ ;


    }
    return false ;
}
 
int main(){
 
    string s2 = "eidboaoo";
    string s1 = "ab" ;

    cout << checkInclusion(s1,s2);

    return 0;
}