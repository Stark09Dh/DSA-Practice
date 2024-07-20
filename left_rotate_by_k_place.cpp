#include<bits/stdc++.h>

using namespace std;

void soln(vector<int>&arr,int n,int k){
    for(int a = 0; a < k ; a++){
        int i=0;
        int j = 1;
        while(j<n){
            int temp  = arr[i];
            arr[i] = arr[j];
            arr[j] = temp ;
            i++,j++;
        }
    }
}

void reverse(vector<int>&arr,int start,int end){
    
    while(start<=end){
        swap(arr[start],arr[end]);
        start++,end--;
    }
}


int main(){
    int n = 6 ;
    vector<int>arr = {1,2,3,4,5,6,7};
    
    /*
    For Rotating the array by 1 place 
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp ;
    */

    int k = 3 ; 
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    for(int i:arr){
        cout << i << " ";
    }



    
    return 0 ;

}