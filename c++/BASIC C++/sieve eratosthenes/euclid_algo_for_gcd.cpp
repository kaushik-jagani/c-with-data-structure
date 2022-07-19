#include"bits/stdc++.h"
using namespace std;
int gcd(int a, int b){
    while(b!=0){         //42%24=18
        int rem=a%b;      //24%18=6
        a=b;              //18%6=0
        b=rem;
    }
    return a;

}
int main(){
    int a,b;

    cin>>a>>b;

    cout<<gcd(a,b)<<endl;
}