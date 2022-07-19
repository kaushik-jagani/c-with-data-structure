#include"bits/stdc++.h"
using namespace std;

int factorial(int n){
    if(n==0){             //base condition it is neccesarry for recurrsion
        return 1;
    }

    int prevfact=factorial(n-1);

    return n*prevfact;
}

int main(){

    int n;
    cin>>n;

    cout<<factorial(n)<<endl;
}