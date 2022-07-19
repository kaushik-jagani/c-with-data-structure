#include"bits/stdc++.h"
#include<stack>
using namespace std;

void reverseString(string s){
    stack<string> st;

    for(int i=0;i<s.length();i++){
        string word="";

        while(s[i]!=' ' and i<s.length()){
            word+=s[i];
            i++;
        }st.push(word);
    }

    while(!st.empty()){                // ->jya sudhi stack khali nahi hoi tya sudhi loop chalse
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main(){
    string s="hey, how are you doing?";

    reverseString(s);

}