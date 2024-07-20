#include<bits/stdc++.h>
 
using namespace std ;

double averageWaitingTime(vector<vector<int>>& customers){
    double size = customers.size();
    double sum = 0;
    int nt = customers[0][0];
    int i = 0 ;
    while(i<size){
        if(nt < customers[i][0]){
            nt = customers[i][0];
        }
        nt = nt + customers[i][1];
        double wt = nt - customers[i][0];
        sum += wt ;
        i++ ;
    }
    return sum / size ;

}
 
int main(){
 
    vector<vector<int>> customers = {{5,2},{5,4},{10,3},{20,1}};
    double ans = averageWaitingTime(customers);
    cout << ans ;
    return 0;
}