// 1460. Make Two Arrays Equal by Reversing Subarrays

#include<bits/stdc++.h>
 
using namespace std ;

bool canBeEqual(vector<int>& target, vector<int>& arr){
    sort(arr.begin(),arr.end());
    sort(target.begin(),target.end());

    for(int i=0;i<arr.size();i++){
        if(arr[i] != target[i]){
            return false ;
        }
    }
    return true ;
}
 
bool canBeSum(vector<int>& target, vector<int>& arr){
    int sum1 = 0 , sum2 = 0,sqr1 = 1,sqr2 = 1;
    for(int i=0;i<arr.size();i++){
        sum1 += arr[i];
        sqr1 *= arr[i] ;
        sum2 += target[i] ;
        sqr2 *= target[i]; 
    }
    return (sum1 == sum2) && (sqr1==sqr2) ;
}


int main(){
 
    vector<int>arr = {1,2,3};
    vector<int>target = {2,2,2};
    bool ans = canBeSum(target,arr);
    cout << (ans==1) ? "True" : "False" ;
    return 0;
}