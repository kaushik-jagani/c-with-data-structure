#include"bits/stdc++.h"
using namespace std;

class stackk{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stackk(){
        N=0;
    }
    void push(int val){              //push costly
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){                 //pop costly
        // q1.pop();
        // N--;

        if(q1.empty()){
            return;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    int top(){
        // return q1.front();
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q2.push(val);

         queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return val;
    }
    int size(){
        return N;
    }
};

int main(){

    stackk st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();

    cout<<st.top()<<endl;


}