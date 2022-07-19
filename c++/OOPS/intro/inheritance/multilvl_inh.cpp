// derived class borrow properties of base class 
/* it means base claas is parent or deerived is child class
-> private part never be inherite only public & protected part can be.
*/
#include "bits/stdc++.h"
using namespace std;

class A{
    public:
    void Afunc(){
        cout<<"inherited"<<endl;
    }
};

class B{
    public:
    void Bfunc(){
        cout<<"inherited B"<<endl;
    }
};

class C : public A,public B{
    public:
};

int main(){
    C c; //objects class of B
    c.Afunc();
    c.Bfunc();
}