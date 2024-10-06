#include<bits/stdc++.h>
 
using namespace std ;

// TC : O(m+n)  SC : O(m+n)

bool areSentencesSimilar(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();


    if(n < m) {
        swap(s1,s2);
    }

    vector<string>vec1,vec2;

    stringstream ss1(s1);
    string temp ;
    while(ss1 >> temp){
        vec1.push_back(temp);
    }

    stringstream ss2(s2);
    while(ss1 >> temp){
        vec2.push_back(temp);
    }

    int i=0 , j = vec1.size()-1;
    int k =0 , l = vec2.size()-1;

    while(k<vec2.size() && i< vec1.size() && vec2[k]==vec1[i]){
        i++ , k++;
    }

    while(l >= k && vec2[l] == vec1[j]){
        j-- , l-- ;
    }

    return (l < k) ;

}
 
int main(){
 
    string sentence1 = "My name is Haley" ;
    string sentence2 = "My Haley" ;

    cout << areSentencesSimilar(sentence1,sentence2);
    return 0;
}