#include<bits/stdc++.h>
 
using namespace std ;

void helper(string &ans) {
    // Reverse the string 'ans' using a stack
    stack<char> tempStack;
    for (char c : ans) {
        tempStack.push(c);
    }
    ans = "";
    while (!tempStack.empty()) {
        ans += tempStack.top();
        tempStack.pop();
    }
}

string reverseParentheses(string &s) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            string temp = "";
            while (!st.empty() && st.top() != '(') {
                temp = st.top() + temp;
                st.pop();
            }
            st.pop(); // Pop the '('

            helper(temp); // Reverse 'temp' and push it back onto 'st'

            for (char c : temp) {
                st.push(c);
            }
        } else {
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
 
int main(){
 
    string s = "(ed(et(oc))el)";
    string ans = reverseParentheses(s);
    for(auto i : ans ){
        cout << i ;
    }
    return 0;
}