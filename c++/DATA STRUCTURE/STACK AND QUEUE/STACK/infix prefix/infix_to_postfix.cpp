#include"bits/stdc++.h"
using namespace std;
//left to right perform
/*
-->precedence
1 $$ or ^^
2 *,/
3 +,-
4 ( ) brackets
*/
// only opertar are stay in stack
// ex:-(a-b/c)*(a/k-i)  ans=abc/-ak/i-*

int prec(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*' or c=='/'){
        return 2;
    }
    else if(c=='+' or c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
            res+=s[i];      // simple print oprand
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() and st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // empty stack after perform all opertion ( stack ni ander vadhela badh operator ne pop karva)
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    return res;
}
int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-i)")<<endl;
}