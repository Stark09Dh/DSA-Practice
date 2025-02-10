#include<bits/stdc++.h>
 
using namespace std ;

class NumberContainers {
public:
    unordered_map<int , set<int>>mp ;
    unordered_map<int , int>idxTonum ;
    NumberContainers() {
    
    }
    void change(int index, int number) {
        if(idxTonum.find(index) != idxTonum.end()){
            int num = idxTonum[index] ;
            mp[num].erase(index) ;
        }
        mp[number].insert(index) ;
        idxTonum[index] = number ;
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end()){
            return -1 ;
        }
        
        return *mp[number].begin(); ;
    }
};
 
int main(){
    NumberContainers nc =  NumberContainers();
    nc.change(2,10);
    nc.change(1,10);
    nc.change(3,10);
    nc.change(5,10);
    nc.change(1,20);
    cout << nc.find(10) ;
    
    return 0;
}