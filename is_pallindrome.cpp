#include<bits/stdc++.h>
 
using namespace std ;


void removeSpecialCharacter(string &str)
{
    for (int i = 0; i < str.size(); i++) {
 
        // Finding the character whose
        // ASCII value fall under this
        // range
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a'
            || str[i] > 'z') {
            // erase function to erase
            // the character
            str.erase(i, 1);
            i--;
        }
    }
}

bool isPallindrome(string &str){

    for(auto &i:str){
        i = tolower(i);
    }
    int a = 0;
    int j = str.length()-1 ;
    while(a<=j){
        if(str[a] != str[j]) {
            return false ;
        }
        a++;
        j--;
    }
    return true ;
}
 
int main(){
 
    string str = "A man, a plan, a canal: Panama";
    removeSpecialCharacter(str);
    bool ans = isPallindrome(str);
    cout << ans << endl;
    cout << str ;
    return 0;
}