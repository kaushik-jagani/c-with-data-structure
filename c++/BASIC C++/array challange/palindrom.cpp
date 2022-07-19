#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool flag=0; //flag=1

    for(int i=0;i<n;i++){
        if(arr[i]==arr[n-1-i])//!=
        {
            flag=1; //flag=0;;
            // break;
        }
        else{
            flag=0;
        }
    }
    
    if(flag){
        cout<<"word is palindrom";
    }
    else{
        cout<<"word is not palindrom";
    }

}