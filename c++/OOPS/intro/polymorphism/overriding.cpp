#include"bits/stdc++.h"
using namespace std;

// method overriding

class base{
    public:
    virtual void print(){
        cout<<"this is the base class print"<<endl;
    }
    void display(){
        cout<<" this is the base class display"<<endl;
    }
};

class derived:public base{
    public:
      void print(){
        cout<<"this is the derived class print"<<endl;
    }
    void display(){
        cout<<" this is the derived class display"<<endl;
    }
};
int main(){

    base *baseptr;
    derived d;
    baseptr=&d;

    baseptr -> print();
    baseptr ->display();
}