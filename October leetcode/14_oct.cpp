#include<bits/stdc++.h>
 
using namespace std ;

long long maxKelements(vector<int>& nums, int k) {
    int n = nums.size() ;
    priority_queue<int> pq ;   

    long long score = 0 ;

    for(int &i: nums){
        pq.push(i);
    }

    while(k > 0){
        int val = pq.top();
        cout<< val << endl ;
        pq.pop() ;
        score += val ;
        int temp = val + 3 -1 ;
        pq.push(ceil(temp/3)) ;
        k-- ;
    }

    return score ;

}
 
int main(){
 
    vector<int>nums = {1,10,3,3,3} ;

    int k  = 3 ;
    cout << maxKelements(nums, k) ;

    return 0;
}