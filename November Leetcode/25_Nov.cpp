#include<bits/stdc++.h>
 
using namespace std ;

int slidingPuzzle(vector<vector<int>>& board) {
    string s = "";
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ;  j < 3 ; j++){
            s += to_string(board[i][j]) ;
        }
    }

    string target = "123450" ;

    queue<string> q ;
    q.push(s) ;
    unordered_map<int , vector<int>> mp ;

    mp[0] = {1, 3} ;
    mp[1] = {0 ,2, 4};
    mp[2] = {1,5};
    mp[3] = {0,4} ;
    mp[4] = {1,3,5} ;
    mp[5] = {2 ,4} ;

    unordered_set<string>visited ;

    visited.insert(s) ;

    int level = 0 ;

    while(!q.empty()){
        int n = q.size();
        while(n--){

        
            string curr = q.front() ;
            q.pop() ;
            if(curr == target){
                return level ;
            }
            int indexOfZero = curr.find('0') ;
            for(int swapIdx : mp[indexOfZero]){
                string newState = curr ;
                swap(newState[indexOfZero] , newState[swapIdx]);
                if(visited.find(newState) == visited.end()){
                    q.push(newState) ;
                    visited.insert(newState) ;

                }
            }
        }
        level++ ;
    }

    return -1 ;
}
 
int main(){
 
    vector<vector<int>> board = {{1,2,3},{5,4,0}} ;

    cout << slidingPuzzle(board) ;

    return 0;
}