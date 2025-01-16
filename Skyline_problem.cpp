#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int,int>>Pair ;

    for(int i=0;i<buildings.size();i++){
        int sp = buildings[i][0];
        int ep = buildings[i][1];
        int ht = buildings[i][2];

        Pair.push_back({sp,-ht});
        Pair.push_back({ep,ht});
    }

    sort(Pair.begin(),Pair.end());

    vector<vector<int>>ans ;

    multiset<int> wallHeight  = {0} ;

    int currHeight = 0 ;

    for( auto p : Pair){
        if(p.second < 0){
            wallHeight.insert(-p.second) ;
        }
        else{
            wallHeight.erase(wallHeight.find(p.second));
        }

        if(*wallHeight.rbegin() != currHeight){
            ans.push_back({p.first , currHeight = *wallHeight.rbegin()}) ;
        }

    }
    return ans ;

}

 
int main(){
 
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}} ;

    vector<vector<int>>ans = getSkyline(buildings) ;

    for(vector<int> vec : ans){
        for(int s : vec){
            cout << s << " ";   
        }
        cout << endl;
    }
    return 0;
}