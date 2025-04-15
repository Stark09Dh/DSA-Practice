#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(abs(arr[i]-arr[j])<= a){

                    for(int k = j+1 ; k < n ; k++){
                        if ( abs(arr[j]-arr[k] <= b) && abs(arr[i]-arr[k]) <= c){
                            ans++;
                        }
                    }
                }   
            }
        }
        return ans ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> arr = {3,0,1,1,9,7} ;
    int a = 7 , b = 2 , c = 3  ;
    cout << sol.countGoodTriplets(arr , a , b , c);
    return 0;
}