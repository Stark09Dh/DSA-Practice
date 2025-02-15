#include<bits/stdc++.h>
 
using namespace std ;

class ProductOfNumbers {
public:
    vector<int> number ;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        number.push_back(num) ;
    }
    
    int getProduct(int k) {
        int ans = 1 ;
        int n = number.size() ;
        for(int i = 1 ; i <= k ; i++){
            ans *= number[n-i];
        }
        return ans ;
    }
};
 
int main(){
    ProductOfNumbers p = ProductOfNumbers() ;
    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);
    cout << p.getProduct(2)<<endl;
    cout << p.getProduct(3)<<endl;
    cout << p.getProduct(4)<<endl;
    p.add(8);
    cout << p.getProduct(2)<<endl;
    
    return 0;
}