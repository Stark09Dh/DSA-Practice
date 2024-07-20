#include<bits/stdc++.h>

using namespace std ;

// Using map 
vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_map<int, int> freqMap;

    // Step 1: Store the frequency of elements in arr1
    for (int num : arr1) {
        freqMap[num]++;
    }

    vector<int> result;

    // Step 2: Traverse arr2 and check if each element exists in freqMap
    for (int num : arr2) {
        // If the element exists in freqMap and its frequency is greater than 0
        if (freqMap.find(num) != freqMap.end() && freqMap[num] > 0) {
            // Add the element to the result
            result.push_back(num);
            // Decrement the frequency in freqMap
            freqMap[num]--;
            // If the frequency becomes zero, remove the element from freqMap
            if (freqMap[num] == 0) {
                freqMap.erase(num);
            }
        }
    }

    return result;
}

// Using Two Pointer 

vector<int> soln(vector<int>&a,vector<int>&b){
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<int>res;
    while(i<n && j<m){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    return res;
}

int main(){

    vector<int>a = {1,2,2,2,3,4};
    vector<int>b = {2,2,3,3};
    vector<int>ans = soln(a,b);
    for(int i : ans){
        cout << i << " ";
    }
    // map<int,int>amap;
    // map<int,int>bmap;
    // for(int num : a){
    //     amap[num]++;
    // }
    // for(int num : b){
    //     bmap[num]++;
    // }
    // for (const auto& pair : amap) {
    //     cout << pair.first << ":" << pair.second << endl;
    // }
    
}