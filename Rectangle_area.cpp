#include<bits/stdc++.h>
 
using namespace std ;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area_1 = (ax2-ax1) * (ay2 - ay1)  ;
    int area_2 = (bx2 - bx1) * (by2 - by1) ;

    int intersection_width = max(0 ,(min(ax2 , bx2) - max(ax1 , bx1))) ;

    int intersection_length = max(0 ,(min(ay2 , by2) - max(ay1 , by1) ));

    int intersection_area = intersection_width *  intersection_length ;

    int ans = (area_1 + area_2) - intersection_area ;

    return ans ;
}
 
int main(){
 
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2 ;

    cout << computeArea(ax1, ay1, ax2, ay2, bx1,  by1, bx2,  by2) ;

    return 0;
}