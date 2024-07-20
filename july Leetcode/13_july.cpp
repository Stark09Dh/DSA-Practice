#include<bits/stdc++.h>
 
using namespace std ;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions){
    int n = positions.size();
    vector<int>index(n) ;
    iota(begin(index),end(index),0);

    auto lambda = [&](int &i, int &j){
        return positions[i] < positions[j];
    } ;

    sort(index.begin(),index.end(),lambda);

    vector<int>result ;

    stack<int>st ;

    for(int currIdx : index){
        if(directions[currIdx] == 'R'){
            st.push(currIdx);
        }
        else{
            while(!st.empty() && healths[currIdx]>0){
                int top_idx = st.top();

                if(healths[top_idx] > healths[currIdx]){
                    healths[top_idx] -= 1 ;
                    healths[currIdx] = 0 ;
                    st.push(top_idx);
                } 
                else if(healths[top_idx] < healths[currIdx]){
                    healths[currIdx] -= 1 ;
                    healths[top_idx] = 0 ;
                }
                else{
                    healths[currIdx] = 0 ;
                    healths[top_idx] = 0 ;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(healths[i] > 0 ){
            result.push_back(healths[i]);
        }
    }

    return result ;



}
 
int main(){
 
    vector<int>positions = {1,2,5,6};
    vector<int>healths = {10,10,11,11};
    string direction = "RLRL" ;
    vector<int>ans = survivedRobotsHealths(positions,healths,direction);
    cout << "[" ;
    for(auto &i : ans){
        cout << i << " ";
    }
    cout << "]";
    return 0;
}