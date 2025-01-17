#include<bits/stdc++.h>
 
using namespace std ;

long parse_int(string number) {
    map<string, int> numberMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
        {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
        {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
        {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000},{"million",1000000}
    };

    stringstream ss(number) ;
    string word  ; 
    long total = 0 ;
    int currentNumber = 0 ;

    while( ss >> word) {
        if(word.find('-') != string::npos){
            stringstream hyphenStream(word) ;
            string part;
            while(getline(hyphenStream,part,'-')){
                if(numberMap.find(part) != numberMap.end()){
                    currentNumber += numberMap[part] ;
                }
            }
        }
        else if(numberMap.find(word) != numberMap.end()){
            int val = numberMap[word] ;
            if(val == 100){
                currentNumber *= 100 ;
            }
            else if(val == 1000){
                total += currentNumber * val ;
                currentNumber = 0 ;
            }
            else if(val == 1000000){
                total += currentNumber * val ;
                currentNumber = 0 ;
            }
            else{
                currentNumber += val ;
            }
        }
        else if(word == "and"){
            continue ;
        }
    }
    return total + currentNumber ;
}
 
int main(){
 
    string number = "one million" ; // 246 
    long ans = parse_int(number) ;
    cout << ans ;
    return 0;
}