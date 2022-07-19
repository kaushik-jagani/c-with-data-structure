#include"bits/stdc++.h"
using namespace std;

void gensub(string s,string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);

    gensub(ros,ans);
    gensub(ros,ans+ch);
    gensub(ros,ans+to_string(code));

}    

int main(){
    gensub("AB","");
}