#include"bits/stdc++.h"
using namespace std;

int main(){

    int a=10;
    int *ptr=&a;

    cout<<*ptr<<endl;
    *ptr=24;
    cout<<a<<endl;

}

// pointer is variable that stors address of another variable