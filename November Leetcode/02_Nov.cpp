#include<bits/stdc++.h>
 
using namespace std ;

bool isCircularSentence(string sentence) {
    vector<string>words ;
    stringstream ss(sentence) ;
    string temp ;
    while(ss >> temp){
        words.push_back(temp);
    }

    string start = "" ;
    string end = "" ;
    start.push_back(words[0][0]) ;
    int n = words[0].length() ;
    end.push_back(words[0][n-1]) ;

    for(int i=1;i<words.size() ; i++){
        int n = words[i].length() ;
        if(end.back() == words[i][0]){
            start.push_back(words[i][0]);
            end.push_back(words[i][n-1]);
        }
        else{
            return false ;
        }
    }

    return (end[end.length()-1] == start[0]) ? true : false ;


}
 
int main(){
 
    string word = "eetcode" ;
    cout << isCircularSentence(word) ;
    
    return 0;
}