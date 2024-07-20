#include<bits/stdc++.h>

using namespace std ;

// using Brute Forces TC : O(nlogn)
int sol(int n ,vector<int>&arr){
    sort(arr.begin(),arr.end());
    int largest = arr[n-1];
    int Slargest = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i]<largest && arr[i]>Slargest){
            Slargest = arr[i];
        }
    }
    return Slargest;
}

// Better TC : O(2n)
int sol2(int n, vector<int>&arr ){
    int largest = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    int Slargest = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i]<largest && arr[i]>Slargest){
            Slargest = arr[i];
        }
    }
    return Slargest;
}

//Optimized TC O(n)
int sol3(int n , vector<int>&arr){
    int largest = arr[0];
    int Slargest = -1 ;
    for(int i= 1;i<n;i++){
        if(arr[i]>largest){
            Slargest = largest;
            largest = arr[i];
            
        }
        else if(arr[i]<largest && arr[i]>Slargest){
            Slargest = arr[i];
        }
        
    }
    return Slargest;
}

// For Second Smallest 
int sol4(int n , vector<int>&arr){
    int smallest = arr[0];
    int Ssmallest = INT_MAX ;
    for(int i = 1;i<n;i++){
        if(arr[i]<smallest){
            Ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<Ssmallest){
            Ssmallest = arr[i];
        }
    }
    return Ssmallest;
}

int main(){
    int n = 6 ;
    vector<int>arr = {1,2,4,7,7,5};
    int Slargest = sol4(n,arr);
    cout << Slargest;
}