#include<bits/stdc++.h>
 
using namespace std ;

int isPrefixOfWord(string sentence, string searchWord) {
    int word = 1 ;
    int i = 0 ;
    while(i < sentence.length()){
        int j = 0;
        
        if (i == 0 || sentence[i - 1] == ' ') {
            while(i < sentence.length() && sentence[i] == searchWord[j]) {
                i++, j++;
                if(j >= searchWord.length()) {
                    return word;
                }
            }
        }
        
        if (i < sentence.length() && sentence[i] == ' ') {
            word++;
            i++;  
        } else {
            i++;  
        }
    } 
    return -1 ;   

}
 
int main(){
 
    string sentence = "hellohello hellohellohello", searchWord = "ell" ;

    cout << isPrefixOfWord(sentence , searchWord) ;

    return 0;
}