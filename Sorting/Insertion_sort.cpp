#include<bits/stdc++.h>
 
using namespace std ;

void insertionSort(vector<int>&a){
    int n = a.size();

    for(int i=0;i<n;i++){
        int j =i ;
        while(j>0  && a[j-1]>a[j]){
            swap(a[j-1],a[j]);
            j-- ;
        }
    }
}
 
int main(){
 
    vector<int> arr = {13,46,52,24,20,9};
    insertionSort(arr);
    for(int &i : arr){
        cout << i << " ";
    }
    return 0;
}