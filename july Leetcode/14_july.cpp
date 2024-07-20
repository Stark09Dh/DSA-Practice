#include<bits/stdc++.h>
 
using namespace std ;

string countOfAtoms(string &formula){
    int n = formula.length();

    stack<unordered_map<string,int>>st;

    st.push(unordered_map<string,int>());

    int i=0 ;
    while(i<n){
        if(formula[i] == '('){
            st.push(unordered_map<string,int>());
            i++;
        }
        else if(formula[i] ==')'){
            unordered_map<string,int> curr = st.top();
            st.pop();
            i++;
            string mult ;
            while((i<n) && isdigit(formula[i])){
                mult.push_back(formula[i]);
                i++ ;
            }
            if(!mult.empty()){
                int multInt = stoi(mult);
                for( auto & it : curr){
                    string element = it.first ;
                    int count = it.second;

                    curr[element] = count * multInt ;
                }
            }
            // merging back to stack's top map
            for(auto &it : curr){
                string element = it.first;
                int count = it.second ;

                st.top()[element] += count ;
            }
        }
        else{
            string currEle;
            currEle.push_back(formula[i]);
            i++;
            while(i<n && isalpha(formula[i]) && islower(formula[i])){
                currEle.push_back(formula[i]);
                i++;
            }

            string currCount ;
            while(i<n && isdigit(formula[i])){
                currCount.push_back(formula[i]);
                i++;
            }

            int currCountInt = currCount.empty() ? 1 : stoi(currCount);
            st.top()[currEle] += currCountInt ;
        }
    }
    map<string,int>sortedMap(st.top().begin(),st.top().end()) ;

    string res ;

    for(auto &it : sortedMap){
        string element = it.first;
        res += element ;
        int count = it.second ;
        if(count > 1 ){
            res += to_string(count);
        }
    }
    return res ;

}

 
int main(){
 
    string formula = "K4(ON(SO3)2)2";
    string ans = countOfAtoms(formula);
    cout << ans ;
    return 0;
}