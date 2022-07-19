#include"bits/stdc++.h"
using namespace std;

void gensub(string s,string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);

    gensub(ros,ans);
    gensub(ros,ans+ch);
}

int main(){
    gensub("ABC","");
}