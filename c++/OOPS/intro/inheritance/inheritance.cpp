// derived class borrow properties of base class 
/* it means base claas is parent or deerived is child class
-> private part never be inherite only public & protected part can be.
*/
#include "bits/stdc++.h"
using namespace std;

class A{
    public:
    void func(){
        cout<<"inherited";
    }
};

class B:public A{

};

int main(){
    B b; //objects class of B
    b.func();
}