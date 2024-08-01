#include<bits/stdc++.h>
 
using namespace std ;
int WIDTH ;

int solve(int i ,vector<vector<int>>&books,int width ,int maxH){
    if( i >= books.size()) return maxH ;
    int bookH = books[i][1];
    int bookW = books[i][0];
    int keep = INT_MAX ;
    int skip = INT_MAX ;
    if(bookW <= width){
        keep = solve(i+1,books,width-bookW,max(maxH,bookH));
    }
    skip =  solve(i+1,books,WIDTH-bookW,bookH) + maxH ;



    return min(skip , keep);

}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    WIDTH = shelfWidth ;
    return solve(0,books,shelfWidth,0);   
     
}
 
int main(){
 
    vector<vector<int>>books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth = 4 ;
    int ans = minHeightShelves(books,shelfWidth);
    cout << ans ;
    return 0;
}