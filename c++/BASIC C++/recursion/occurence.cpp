//find the first and last occurence of a number in array
#include"bits/stdc++.h"
using namespace std;

int firstocu(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocu(arr,n,i+1,key);
}

int lastoc(int arr[],int n, int i, int key){
    if(i==n){
        return -1;
    }
    int restarray=lastoc(arr,n,i+1,key);
    if(restarray!=-1){
        return restarray;
    }
    if(arr[i]==key){
        return i;
    }

    return -1;
}
int main(){
    int arr[]={1,2,8,2,4,6};
    int key;
    // cin>>key;

    cout<<firstocu(arr,6,2,6)<<endl;
    cout<<lastoc(arr,6,0,2)<<endl;

}