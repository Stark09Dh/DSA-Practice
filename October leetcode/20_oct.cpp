#include<bits/stdc++.h>
 
using namespace std ;

char solve(vector<char>&values , char opt){
    if(opt == '!'){
        return (values[0] == 't') ? 'f' : 't' ;
    }
    if(opt == '&'){
        for(char &c : values){
            if(c == 'f'){
                return 'f' ;
            }
        }
        return 't' ;
    }
    if(opt == '|'){
        for(char &c : values){
            if(c == 't'){
                return 't' ;
            }
        }
        return 'f' ;
    }

    return 't' ;
}

bool parseBoolExpr(string expression) {
    int n = expression.length() ;

    stack<char>st ;

    for(int i=0;i<n;i++){
        if(expression[i] == ','){
            continue ;
        }
        if(expression[i] ==')'){
            vector<char>values ;

            while(st.top() != '('){
                values.push_back(st.top());
                st.pop();
            }
            st.pop();
            char oprt = st.top() ; // ! , & , |
            st.pop() ;

            st.push(solve(values ,oprt));
        }
        else{
            st.push(expression[i]);
        }
    }

    return (st.top() == 't') ? true : false ;
}
 
int main(){
    
    string expression = "&(|(f))" ;
    cout << (parseBoolExpr) ? "True" : "False" ;
    
    return 0;
}