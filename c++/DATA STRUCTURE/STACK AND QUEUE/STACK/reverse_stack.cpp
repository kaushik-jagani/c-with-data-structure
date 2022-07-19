#include"bits/stdc++.h"
using namespace std;

void insertAtBotoom(stack<int> &st,int elem){

    if(st.empty()){
        st.push(elem);
        return;
    }

    int topele=st.top();
    st.pop();
    insertAtBotoom(st,elem);

    st.push(topele);
}
void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }
    int elem=st.top();
    st.pop();
    reverse(st);
    insertAtBotoom(st,elem);
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    
    reverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}