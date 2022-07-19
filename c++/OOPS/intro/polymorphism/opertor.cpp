// operator overloading

#include"bits/stdc++.h"
using namespace std;

class complex{
    private:
    int real,img;
    public:
    complex(int r,int i){
        real=r;
        img=i;
    }
    complex operator + (complex const &obj){
        complex res;
        res.img=img+obj.img;
        res.real=real +obj.real;
        return res;
    }

    void display(){
        cout<<real<<" "<<img<<endl;
    }
};

int main(){
    complex c1(12,7);
    complex c2(6,7);
    complex c3=c1+c2;
    c3.dispaly();
    
}