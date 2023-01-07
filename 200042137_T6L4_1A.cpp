#include <iostream>
#include <queue>
#include<vector>
using namespace std;



int main()
{
    int n,z,c,x;
    queue<int> q;
    cin>>n;
    c=n;
    int arr[n];
    while(n--)
    {
        cin>>x;
        q.push(x);
    }
    int k,i=0;
    while(c--)
    {
        cin>>k;
        arr[i]=k;
        i++;
    }

    int topOfSandwich = 0;
    int StudentsUnabletoEat = 0;
    while (q.size() && StudentsUnabletoEat < q.size())
    {
        if (arr[topOfSandwich] == q.front())
        {
            StudentsUnabletoEat = 0;

            ++topOfSandwich;
            q.pop();
        }
        else
        {
            ++StudentsUnabletoEat;

            q.push(q.front());
            q.pop();
        }
    }

    cout<<StudentsUnabletoEat;
    return 0;
}
