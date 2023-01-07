#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cin>>k;

//int findTheWinner(int n, int k) {
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        q.push(i);
    }
    while(q.size()!=1)
    {
        int x=k;
        while(x>1)
        {
            int r=q.front();
            q.pop();
            q.push(r);
            x--;
        }
        q.pop();
    }
    cout<< q.front();

    return 0;
}
