#include"bits/stdc++.h"
using namespace std;

int main(){
    int a=10;
    int *p=&a;
    cout<<p<<endl;
    int **q=&p;
    cout<<**q<<endl;
    cout<<*q<<endl;
    cout<<q<<endl;

}