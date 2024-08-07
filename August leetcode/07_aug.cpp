#include<bits/stdc++.h>
 
using namespace std ;

const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string solve(int num){
    if(num<10){
        return ones[num];
    }
    if(num<20){
        return ones[num];
    }
    if(num<100){
        return tens[num/10] + (num % 10 != 0 ? " " + ones[num%10]:"");
    }

    if(num<1000){
        return solve(num/100)+" Hundred" + ((num%100 != 0) ? " " + solve(num%100):"");
    }

    if(num<1000000){
        return solve(num/1000)+" Thousand" + ((num%1000 != 0) ? " " + solve(num%1000):""); 
    }
    if(num<1000000000){
        return solve(num/1000000)+" Million" + ((num%1000000 != 0) ? " " + solve(num%1000000):"");
    }
    return solve(num/1000000000)+" Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000):"");
}




string numberToWords(int num){
    if(num == 0) return "Zero";

    return solve(num);
}
 
int main(){
 
    int num = 995543;
    string ans = numberToWords(num);
    cout << ans ;
    return 0;
}