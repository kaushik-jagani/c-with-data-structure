#include"bits/stdc++.h"
using namespace std;

int main(){

   int arr[]={10,11,12};
   cout<<*arr<<endl;

    int *ptr=arr;
    for(int i=0;i<3;i++)
    {
        cout<<*ptr<<endl;
        ptr++;
    }
    
     for(int i=0;i<3;i++)
    {
        cout<<*(arr+i)<<endl;
        // ptr++;
    }
}

// pointer is variable that stors address of another variable