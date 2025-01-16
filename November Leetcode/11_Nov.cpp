#include<bits/stdc++.h>
 
using namespace std ;

bool isPrime(int num ){
    int limit = sqrt(num) + 1;

    for(int i=2;i<limit;i++){
        if(num % i == 0){
            return false ;
        }
    }
    return true ;
}

bool primeSubOperation(vector<int>& nums) {
    int n = nums.size();
    int prev = 0 ;

    for(int i = 0;i<n;i++){
        int upper_bound = nums[i] - prev ;

        int largest_num = 0 ;

        for(int i=upper_bound-1 ; i>=2 ; i--){
            if(isPrime(i)){
                largest_num = i ;
                break ;
            }
        }
        if(nums[i] - largest_num <= prev) return false ;

        prev = nums[i] - largest_num ;
    }

    return true ;
        
}
 
int main(){
 
    vector<int>nums = {4,9,6,10} ;

    cout << primeSubOperation(nums) ;

    return 0;
}