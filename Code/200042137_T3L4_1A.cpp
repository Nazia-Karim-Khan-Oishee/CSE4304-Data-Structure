#include <iostream>
#include <queue>
//#include<bool>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;
public:
    void push_s(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop_s()
    {
        if (q1.empty())
        {

            return;
        }
        q1.pop();
    }

    int top_s()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }

    bool empty_s()
    {
        if(q1.empty())
        {
            return true;
        }
        //cout<<"The Stack is empty."<<endl;
        return false;

    }
};

int main()
{
    Stack s;
    s.push_s(10);
    cout <<s.top_s()<<endl;
    s.push_s(20);
    cout <<s.top_s() <<endl;
    s.pop_s();
    cout<<s.top_s() <<endl;
    s.push_s(100);
    cout <<s.top_s() <<endl;
    cout <<s.empty_s() <<endl;
    s.pop_s();
    s.pop_s();
    cout <<s.empty_s() <<endl;
    return 0;
}


