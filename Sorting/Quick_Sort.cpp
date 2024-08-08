#include<bits/stdc++.h>
 
using namespace std ;

int partition_function(vector<int>&arr,int low , int high){
    int pivot = low , i = low , j = high ;
    while(i<j){
        while(i<high && arr[i]<= arr[pivot]){
            i++;
        }
        while(j>low && arr[j]>arr[pivot]){
            j-- ;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j ;
}

void quick_Sort(vector<int>&arr,int low , int high){
    if(low < high){
        int partition = partition_function(arr,low,high);
        quick_Sort(arr,low,partition-1);
        quick_Sort(arr,partition+1,high);
    }
}
 
int main(){
 
    vector<int>arr ={4,6,2,5,7,9,1,3};
    int n = arr.size();
    quick_Sort(arr,0,n-1);
    for(int &i : arr){
        cout << i << " ";
    }
    return 0;
}