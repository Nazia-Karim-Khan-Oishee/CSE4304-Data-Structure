#include<iostream>
#include <queue>
using namespace std;

int main() {

    int n,k;
    priority_queue<int> Q;
    int a;
    while(1)
    {
        cin>>a;
        if(a == -1)
        {
            break;
        }
        Q.push(a);
    }
    while(Q.size() > 1){
            int c = Q.top();
           //cout<<c;
            Q.pop();
            int b = Q.top();
           //cout<<c;
             Q.pop();
             if( c-b > 0)
            {
            Q.push(c - b);
            }
            /*else{
                Q.push(max(c,b));
            }*/
        }
    if(Q.empty())
    {
        cout <<0;
    }
    else
    {
        cout<<Q.top();
    }

    return 0;
}

