// find which charcter arree in string more than 1 time;
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str="kaushik";
    int freq[26];

    for(int i=0;i<26;i++)
    freq[i]=0;

    for(int i=0;i<str.size();i++)
    freq[str[i]-'a']++;

    char ans='a';
    int max=0;
    for(int i=0;i<26;i++){
        if(freq[i]>max){
            max=freq[i];
            ans=i+'a';

        }
    }
     cout<<max<<" "<<ans<<endl;
}