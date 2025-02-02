#include<bits/stdc++.h>
 
using namespace std ;
/*

{3 ,4 ,5 ,1 ,2} ---> 3,4,5,1,2, 3,4,5,1,2

*/

bool check(vector<int>& nums) {
    vector<int>temp = nums ;
    nums.insert(nums.end() ,temp.begin(),temp.end()) ; 
    sort(temp.begin() , temp.end()) ;
    bool ans = false ;
    auto it = search(nums.begin() , nums.end() , temp.begin() , temp.end()) ; // act as indexof in java , finds the temp in nums
    if(it != nums.end()){
        ans = true ;
    }
    return ans ;

}
 
int main(){
    vector<int>nums = {3,4,5,1,2} ;
    cout << (check(nums)) ? "True" : "false" ;
    
    return 0;
}