// first  reverse the string 
// convert bracket closing to openning
// int last again reverse the answer and we get prefix expresssion

#include"bits/stdc++.h"
using namespace std;

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

string infixToPrefix(string s){
    // first reverse thr given string
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
            res+=s[i];      // simple print oprand
        }
        else if(s[i]==')'){   //change (=>)
            st.push(s[i]);
        }
        else if(s[i]=='('){       //change )=>(
            while(!st.empty() and st.top()!=')'){     //change (=>)
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

    reverse(res.begin(),res.end());
    return res;
    
}

int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-i)")<<endl;
}