#include<bits/stdc++.h>
using namespace std;

//ex:- 0 1 1 2 3 5 8 13 .....
//fib(n)=fin(n-1)+fib(n-2)
int fibonnaci(int n){
    if(n==0 || n==1)           //base condition
    {
        return n;
    }
   
   return fibonnaci(n-1)+fibonnaci(n-2);

}
int main(){

    int n;
    cin>>n;

    cout<<fibonnaci(n)<<endl;
}