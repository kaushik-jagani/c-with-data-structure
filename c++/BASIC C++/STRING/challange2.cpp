#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str="1254863784469";
    sort(str.begin(),str.end(),greater<int>());
    cout<<str<<endl;
}