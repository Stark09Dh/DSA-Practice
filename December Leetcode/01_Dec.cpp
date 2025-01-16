#include<bits/stdc++.h>
 
using namespace std ;
bool checkIfExist(vector<int>& arr) {
    int n = arr.size() ;
    sort(arr.begin() , arr.end()) ;
    for(int i= 0 ;i < n ; i++){
        int target = 2 * arr[i] ;
        int l = 0 , r = n-1 ;

        while(l <= r) {
            int mid = (l+r)/2 ;
            if(arr[mid] == target && i != mid){
                return true ;
            }
            else if(arr[mid] > target){
                r = mid - 1 ;
            }
            else{
                l = mid+1 ;
            }
        }
    }
    return false ;
     
}
 
int main(){
 
    vector<int> arr = {2,5,3,0} ;
    cout << checkIfExist(arr) ;
    return 0;
}