#include<bits/stdc++.h>
 
using namespace std ;

vector < int> josephus(vector < int > items, int k) {
    vector<int>ans ;
    int i = 0 ;
    while(!items.empty()){
        i = (i+k-1)% items.size() ;
        ans.push_back(items[i]) ;
        items.erase(items.begin()+i) ;
    }
    return ans ;
}
 
int main(){
 
    vector<int> items = {1,2,3,4,5,6,7} ;
    int k = 3 ;
    vector<int>ans = josephus(items , k ) ;
    for(int &i : ans ){
        cout << i << " ";
    }
    
    return 0;
}