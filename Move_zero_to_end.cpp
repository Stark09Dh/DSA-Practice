#include<bits/stdc++.h>

using namespace std ;


// TC = O(2n)
void soln(vector<int>&arr,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i] = temp[i];
    }
    for(int j=temp.size();j<n;j++){
        arr[j] = 0 ;
    }
}

void soln2(vector<int>&arr,int n){
    int j = -1 ;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i ;
            break;
        }
    }
    if(j != -1){
        for(int i = j+1 ; i < n ; i++){
            if(arr[i] != 0){
                swap(arr[j],arr[i]);
                j++;
            }
        }
    }
    

}

int main(){
    int n = 3 ;
    vector<int>arr = {8,6,9};
    // int j = -1 ;
    // for(int i=0;i<n;i++){
    //     if(arr[i] == 0){
    //         j = i ;
    //         break;
    //     }
    // }
    // cout << j ;
    soln2(arr,n);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;

}