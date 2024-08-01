#include<bits/stdc++.h>
 
using namespace std ;

vector<int> plusOne(vector<int>& digits){
    // {1 ,3,5,7,9};
    reverse(digits.begin(),digits.end());
    int n = digits.size();
    int carry = 1 ;

    for(int i=0 ;i<n;i++){
        if(carry && digits[i] == 9){
            digits[i] = 0 ;
        }
        else{
            digits[i] += carry ;
            carry = 0 ;
        }
    }
    if(carry) {
        digits.push_back(1);
    }
    reverse(digits.begin(),digits.end());
    return digits ;
    
    
}
// 
 
int main(){
 
    vector<int>digits = {9,8,7,6,5,4,3,2,1,0};
    vector<int>ans = plusOne(digits);

    for(int &num : ans){
        cout << num << " ";
    }

    return 0;
}