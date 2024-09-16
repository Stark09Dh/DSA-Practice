#include<bits/stdc++.h>
 
using namespace std ;
// stol and to_string

long helper(long firstHalf , bool isEven){
    long resNum = firstHalf;

    if(isEven == false){
        firstHalf /= 10 ;
    }

    while(firstHalf > 0){
        int digit = firstHalf % 10 ;
        resNum = (resNum * 10) + digit ;
        firstHalf /= 10 ;
    }

    return resNum ;
}




string nearestPalindromic(string n) {
    int l = n.length();
    
    int mid = l/2 ; // half of the string n

    int firstHalfLength = (l%2==0) ? mid : (mid+1) ;

    long firstHalf = stol(n.substr(0,firstHalfLength));

    vector<long> res ;

    res.push_back(helper(firstHalf ,l%2==0));
    res.push_back(helper(firstHalf+1 ,l%2==0));
    res.push_back(helper(firstHalf-1 ,l%2==0));
    

    res.push_back((long)pow(10,l-1) -1);
    res.push_back((long)pow(10,l) + 1);

    long diff = LONG_MAX ;
    long ans = INT_MAX ;
    long original = stol(n);

    for(long num : res){
        if(num == original){
            continue;
        }
        if(abs(num - original) < diff){
            diff = abs(num - original);
            ans = num ;
        }
        else if(abs(num - original) == diff){
            ans = min(ans,num);
        }
    }
    return to_string(ans);

}
 
int main(){
 
    string n = "99";
    
    string ans = nearestPalindromic(n);
    cout << ans ;
    return 0;
}