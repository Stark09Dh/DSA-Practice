/*
Codewars -> Observed Pin (4th kyu)
*/


#include<bits/stdc++.h>
 
using namespace std ;

unordered_map <char, vector<char>>adj_map = {
    {'1' ,{'1','2','4'}},{'2',{'1','2','3','5'}},
    {'3',{'2','3','6'}},{'4',{'1','4','5','7'}},
    {'5',{'2','4','5','6','8'}},{'6',{'3','5','6','9'}},
    {'7',{'4','7','8'}},{'8',{'0','5','7','8','9'}},
    {'9',{'6','8','9'}},{'0',{'0','8'}}
};

void generate_combo(int index ,vector<vector<char>>&adj_digit,string curr,vector<string>&ans){
    if(index == adj_digit.size()){
        ans.push_back(curr);
        return ;
    }

    for(char digit : adj_digit[index]){
        generate_combo(index+1,adj_digit,curr+digit,ans);
    }
}

vector<string> get_pins(string observed) {
    vector<vector<char>>adj_digit ;

    for(char digit : observed){
        adj_digit.push_back(adj_map[digit]);
    }

    vector<string>ans ;

    generate_combo(0,adj_digit,"",ans);

    return ans ;

}
 
int main(){
 
    string observed = "236" ;
    vector<string>ans = get_pins(observed) ;
    for(auto &i : ans){
        cout << i << " " ;
    }
    return 0;
}