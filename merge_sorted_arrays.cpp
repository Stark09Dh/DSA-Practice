#include<bits/stdc++.h>

using namespace std ;
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n = a.size();
    int m = b.size();
    int i = 0,j=0;
    vector<int>ans ;
    while(i<n && j < m){
        if(a[i] <= b[j]){
            if(ans.size()==0 || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back() != b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    } 
    while(i<n){
        if(ans.size()==0 || ans.back() != a[i]){
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j<m){
        if(ans.size()==0 || ans.back() != b[j]){
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans ;
}


int main(){
    vector<int>a = {1,2,3,3};
    vector<int>b = {2,2,4};
    vector<int>res = sortedArray(a,b);
    for(int i : res){
        cout << i << " ";
    }
}