#include <iostream>
#include <queue>
using namespace std;


queue<int> Q;

int ping(int t)
{
// YOUR CODE HERE
int time,f=0;
time =t;
//int req = abs(t-Q.front());
Q.push(t);
while(f==0)
{
int req = abs(Q.front()-t);
//cout<<Q.front();
if(req <= 3000)
{
    //cout<<req<<endl;
    f=1;
    //cout<<Q.size();
    return Q.size();

}
else
{
    //cout<<" v";
    Q.pop();
    continue;
    //req = abs(Q.front()-t);
}
f=0;
}
}
int main()
{
    cout << ping(1) <<'\n';
    cout << ping(2) <<'\n';
    cout << ping(3) <<'\n';
    cout << ping(4) <<'\n';
    cout << ping(3001) <<'\n';
    cout << ping(3002) <<'\n';
    cout << ping(3003) <<'\n';
    cout << ping(6003) <<'\n';
    cout << ping(10003) <<'\n';

    return 0;
}
