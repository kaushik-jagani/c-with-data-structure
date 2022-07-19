#include"bits/stdc++.h"
#include"iostream"
using namespace std;
//dequeue using 2 stack

class queuee{
    stack<int> s1;
    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty()){
            cout<<"queue is empty";
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;     //stack contain only 1 element so that after pop stack empty above line show
        }
        int item=pop();
        s1.push(x);
        return item;
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    queuee q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;


}