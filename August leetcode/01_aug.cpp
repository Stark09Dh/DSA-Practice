// 2678. Number of Senior Citizens


#include<bits/stdc++.h>

 
using namespace std ;

int countSeniors(vector<string>& details) {
    int ans = 0 ;
    for(auto &it : details){
        string age = it.substr(11, 2);
        int ageN = stoi(age);
        if(ageN>60) ans++ ;
    }
    return ans ;
}

 
int main(){
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"} ;

    int ans = countSeniors(details);
    cout << ans ;
    
    return 0;
}