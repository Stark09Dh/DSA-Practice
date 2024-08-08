#include<bits/stdc++.h>
 
using namespace std ;

void BubbleSort(vector<int>&arr){
    int n = arr.size();

    for(int i=n-1;i>=0;i--){
        int swaps = 0 ;
        for(int j = 0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps=1;
            }
        }
        if(swaps==0) break ;
    }

}
 
int main(){
 
    vector<int> arr = {13,46,52,24,20,9};
    BubbleSort(arr);
    for(int &i : arr){
        cout << i << " ";
    }
    return 0;
}