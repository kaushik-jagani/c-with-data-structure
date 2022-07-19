// subarray and sub sequance
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
    number of subarray in array is continuous part of array
    nC2 +n=n*(n+1)/2;

    subsequences
    not continuose manner but sequance are not change=2^n
    */

    // problrm:-1 sum of every subarray

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            cout << curr << endl;
        }
    }
}