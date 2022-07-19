#include"bits/stdc++.h"
using namespace std;

bool isvalid(string s){
    stack<char> st;
    int n=s.size();
    bool ans=true;

    for(int i=0;i<n;i++){
        if(s[i]=='{' or s[i]=='(' or s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() and st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() and st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;

            }
        }
        else if(s[i]==']'){
            if(!st.empty() and st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
                
            }
        }
    }

    // cheack in brackt left in string because number of opening and closing bracket may be not same
    if(!st.empty()){
        return false;
    }

    return ans;

}

int main(){
    string s="[{(})}]";

    if(isvalid(s)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;

    }
}