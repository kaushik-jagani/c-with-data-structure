#include "bits/stdc++.h"
using namespace std;
#define n 100

class stack
{
    int *arr;
    int top; // both are private

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "stack is overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack is underflow(no element to remove)" << endl;
            return;
        }
        top--;
    }

    int peep()
    {

        if (top == -1)
        {
            cout << "stack is empty(no element to remove)" << endl;
        }

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.top() << endl;
}