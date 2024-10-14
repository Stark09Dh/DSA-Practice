#include<bits/stdc++.h>
 
using namespace std ;

class node{
    public:
    int data ;
    int row;
    int col ;

    node(int d , int r , int c ){
        data = d ;
        row = r ;
        col = c ;
    }
} ;

class compare {
    public:
    bool operator()(node &a , node &b){
        return a.data > b.data ;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    if(nums.empty()) return {} ;
    int k = nums.size();
    int n = nums[0].size() ;
    int mini = INT_MAX , maxi = INT_MIN ;
    priority_queue<node , vector<node> , compare>minheap ;
    for(int i=0;i<k;i++){
        if(!nums[i].empty()){
        int element = nums[i][0];
        mini = min(mini , element);

        maxi = max(maxi , element) ;
        
        minheap.push(node(element , i ,0));
            
        }
    }

    int start = mini , end = maxi ;

    while(!minheap.empty()){

        node temp  = minheap.top();
        minheap.pop();

        mini = temp.data ;

        if(maxi - mini < end - start){
            start  = mini ;
            end = maxi ;
        }

        if(temp.col + 1 < nums[temp.row].size()){
            maxi = max(maxi , nums[temp.row][temp.col+1]);
            minheap.push(node(nums[temp.row][temp.col+1], temp.row , temp.col+1));
        }
        else{
            break ;
        }

    }
    return {start ,end} ;
}
 
int main(){
 
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int>ans = smallestRange(nums) ;

    for(int &i : ans) {
        cout << i << " ";
    }
    return 0;
}