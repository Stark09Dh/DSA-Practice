#include<bits/stdc++.h>
 
using namespace std ;

class Solution{
    public:
        void remove_duplicate(vector<int>&nums){
            sort(nums.begin() , nums.end()) ;
            int j = 1 ;
            for(int i = 1 ;i< nums.size() ; i++){
                if(nums[i] != nums[i-1]){
                    nums[j++] = nums[i] ;
                }
            }
        }

        string remove_duplicate(string s){
            sort(s.begin() , s.end()) ;
            string res = "" ;
            res += s[0] ;
            for(int i = 1 ;i< s.length() ; i++){
                if(s[i] != s[i-1]){
                    res += s[i] ;
                }
            }
            return res ;
            
        }

        int remove_element(vector<int>&nums, int val){
            int j = 0;
            int n = nums.size();
            for(int i=0;i<n;i++){
                if(nums[i] != val){
                    nums[j++] = nums[i];
                }
            }
            return j ;
        }

};

 
int main(){

    vector<int> nums = {2,3,3,2};
    string s = "abcdefccd" ;
    int val = 3 ;
    cout << (new Solution) ->remove_duplicate(s) <<endl ;
    int res = (new Solution) -> remove_element(nums , val) ;
    for(int i=0;i<res;i++){
        cout << nums[i]<< " ";
    }
    
    
    return 0;
}