#include<bits/stdc++.h>
 
using namespace std ;
void decode_message(string& encoded) {
    /*
    Write your logic here to decode the encoded message.
    Parameters:
        encoded (std::string): The encoded message as a string
    Returns:
        None
    */
    unordered_map<string , string>cypher = {
        {"a", "n"} ,{"b", "m"} , {"c", "l"} ,{"d", "k"},{"e", "j"},{"f", "i"},{"g", "h"},
        {"h", "g"},{"i", "f"},{"j", "e"},{"k", "d"},{"l", "c"},{"m", "b"},{"n", "a"},
        {"o#", "z"},{"z#", "o"},{"p#", "y"},{"y#", "p"},{"q#", "x"},{"x#", "q"},{"r#", "w"},{"w#", "r"},
        {"s#", "v"},{"v#", "s"},{"t#", "u"},{"u#", "t"}
    };
    string ans = "" ;

    for(int i = 0 ; i < encoded.length() ; i++){
        string temp ;
        if((int)encoded[i] > 110){
            temp = encoded.substr(i,2) ;
        }
        else{
            temp = encoded.substr(i,1) ;
        }
        encoded.replace(i, temp.length(), cypher[temp]);
    }
    
}
 
int main(){
 
    string s = "mjt#av#u#z#y#y#nmcj" ;
    decode_message(s) ;
    cout << s ;
    return 0;
}