#include<bits/stdc++.h>
 
using namespace std ;
 

//Brute Force approach TC : O(n^3)
int numTeams1(vector<int>& rating) {
    
    int n= rating.size();
    if(n<3) return 0 ;
    int ans = 0 ;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i < j && j < k && ((rating[i]<rating[j] && rating[j]<rating[k])||(rating[i]>rating[j] && rating[j]>rating[k]))){
                    ans+=1 ;
                }
            }
        }
    }
    return ans ;
}


// Better Solution Tc : O(n^2)

int numTeams2(vector<int>&rating){
    int n= rating.size();
    int ans = 0 ;
    
    for(int i=1;i<n-1;i++){

        int left[2] = {0} , right[2] = {0};

        for(int j =0 ;j<i;j++){
            if(rating[j] < rating[i]){
                left[0]++;
            }
            else{
                left[1]++;
            }

        }

        for(int k= i+1;k<n;k++){
            if(rating[k] > rating[i]){
                right[1]++;
            }
            else{
                right[0]++ ;
            }
        }
        ans += left[0]*right[1] + left[1]*right[0];
    }
    
    return ans ;
}



int main(){
 
    vector<int>rating = {2,5,3,4,1};
    int ans = numTeams2(rating);
    cout << ans ;
    return 0;
}