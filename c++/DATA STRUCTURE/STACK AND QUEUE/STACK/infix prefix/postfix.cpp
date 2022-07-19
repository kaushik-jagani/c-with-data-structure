// left to right perform
// postfix:- 4 6 +2 / 5 * 7 +
//infix :-((((4+6)/2)*5)+7)
//reverse polishnotation
//is anyonr string number and we subtract the ascii value of 0 we get intger value

#include"bits/stdc++.h"
using namespace std;

int postfix(string s){
    stack<int> st;

    for(int i=0;i<s.length();i++){    // because its perform left to right
        if(s[i]>='0' and s[i]<='9'){
          st.push(s[i]-'0');
        }
        else{
            int op2= st.top();
            st.pop();

            int op1=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;

                case '-':
                st.push(op1-op2);
                break;

                case '*':
                st.push(op1*op2);
                break;

                case '/':
                st.push(op1/op2);
                break;

                case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }

    }
    return st.top();
}


int main(){
    cout<<postfix("46+2/5*7+");
}