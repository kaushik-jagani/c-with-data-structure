// two types of polymorephism 1)overloading(complie time)  2)overriding(run time)
// function overloading
#include"bits/stdc++.h"
using namespace std;

class loading{
    public:

    void fun(){
        cout<<" i am without argument"<<endl;
    }

    void fun(int n){
        cout<<"i am function with int type arguments"<<endl;
    }

    void fun( double n){
        cout<<"i am functionn with double type argument"<<endl;
    }
};

int32_t main(){
    loading obj;
    obj.fun();
    obj.fun(2);
    obj.fun(2.25);
}