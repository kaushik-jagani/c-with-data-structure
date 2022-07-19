// check arrray is sorted or not
#include"bits/stdc++.h"
using namespace std;

bool sorted(int arr[],int n){
    if(n==1){
        return true;
    }
    bool restarray=sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restarray);
}
int main(){
    int arr[]={1,5,3,4,5,6};

    cout<<sorted(arr,5);

}