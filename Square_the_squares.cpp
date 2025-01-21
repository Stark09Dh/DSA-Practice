/*
Given a positive integral number n, return a strictly increasing sequence 
(list/array/string depending on the language) of numbers, so 
that the sum of the squares is equal to n².
*/

#include<bits/stdc++.h>

using namespace std ;
vector<long long> result ;

bool findSquares(int target, int maxSquare) {
    if (target == 0) {
        return true; // Found a valid decomposition
    }
    for (int i = maxSquare-1; i > 0; --i) {
        int square = i * i;
        if (square <= target) {
            result.push_back(i); // Choose this square
            if (findSquares(target - square, i - 1)) {
                return true; // Continue searching
            }
            result.pop_back(); // Backtrack if not successful
        }
    }
    return false; // No valid decomposition found
}


vector<long long> decompose(long long n){
    
    if (findSquares(n * n, n)) {
        sort(result.begin(),result.end()) ; // Sort the result in ascending order
        return result ; // Return the result if found
    } else {
        return {}; // Return an empty vector if no valid decomposition exists
    }
}

int main(){
    long long n = 5 ;
    vector<long long> ans = decompose(n) ;

    for(auto i : ans){
        cout << i << " " ;
    }
    
    return 0;
}