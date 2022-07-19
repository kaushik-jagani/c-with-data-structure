#include"bits/stdc++.h"
#include<iostream>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;

    // constructor
    student(string s, int a,int  g){
        name=s;
        age=a;
        gender=g;
    }

    student(){
        cout<<"default constructor";
    }                        //default constructor

    student(student &a){
        cout<<"copy constructor";
        name=a.name;
        age=a.age;
        gender=a.gender;
    }                      //copy constructor

    ~student(){
        cout<<"destructor called"<<endl;
    }
    void print(){
        cout<<"name is:";
        cout<<name<<endl;
        cout<<"age :";
        cout<<age<<endl;
        cout<<"gender :";
        cout<<gender<<endl;
    }

    bool opreator == (student &a){
        if(name==a.name and age==a.age and gender==a.gender){
            return true;
        }
        return false;
    }
};

int main(){

    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cout<<"enter a name :";
    //     cin>>arr[i].name;
    //     cout<<"enter a age :";
    //     cin>>arr[i].age;
    //     cout<<"enter a gender :";
    //     cin>>arr[i].gender;
    // }
    
    // for(int i=0;i<3;i++){
    //     arr[i].print();
    // }

    student a("kaushik",19,1);
    // a.print();
    student b;
    student c=a;

    if(c==a){
        cout<<"same "<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}