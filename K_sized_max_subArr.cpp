#include<bits/stdc++.h>
 
using namespace std ;

vector<int> max_of_subarrays(int k, vector<int> &arr) {
    vector<int>ans ;
    deque<int>dq ;
    
    for (int i = 0; i < arr.size(); i++) {

        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        
        dq.push_back(i);

        
        if (i >= k - 1) {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans ;
}
 
int main(){
 
    vector<int>arr ={1,2,3,1,4,5,2,3,6};
    int k = 3 ;
    vector<int>ans = max_of_subarrays(k,arr);

    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}