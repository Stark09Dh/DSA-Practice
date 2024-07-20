// Evaluate Reverse Polish Notation 

// stoi == string to int 

#include<bits/stdc++.h>
 

using namespace std ;

int sol(vector<string>&str){
    stack<int>st ;
    int n = str.size();
    for(string token : str){
        if(token == "+"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push(num2 + num1);
        }
        else if(token == "-"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push(num2 - num1);
        }
        else if(token == "*"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push(num2 * num1);
        }
        else if(token == "/"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push(num2 / num1);
        }
        else {
            st.push(stoi(token));
        }
    }
    return st.top() ;

}
 
int main(){
 
    vector<string> str = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = sol(str);
    cout << ans ;

    
    return 0;
}