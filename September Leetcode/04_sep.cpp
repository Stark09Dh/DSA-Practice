#include<bits/stdc++.h>
 
using namespace std ;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<string> st ;
    for(vector<int>&obs : obstacles){
        string key = to_string(obs[0]) + "_" + to_string(obs[1]) ;
        st.insert(key);

    }

    int x = 0 ;
    int y = 0 ;
    int maxD = 0 ;
    pair<int,int>dir = {0,1};

    for(int i=0;i<commands.size();i++){
        if(commands[i] == -2){ // 90 deg left
            dir = {-dir.second , dir.first};
        }
        else if(commands[i] == -1){ // 90 deg right
            dir = {dir.second , -dir.first};
        }
        else{
            for(int step = 0 ; step < commands[i] ; step++){
                int newX = x + dir.first ;
                int newY = y + dir.second ;

                string nextKey = to_string(newX) + "_" + to_string(newY) ;

                if(st.find(nextKey) != st.end()){
                    break; 
                }

                x = newX ;
                y = newY ;
            }
        }

        maxD = max(maxD , x*x + y*y);
    }
    return maxD ;
}
 
int main(){
 
    vector<int>commands = {4,-1,4,-2,4};
    vector<vector<int>>obstacles = {{2,4}};
    int ans = robotSim(commands,obstacles);
    cout <<ans ;
    return 0;
}