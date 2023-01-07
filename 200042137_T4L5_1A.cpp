#include<iostream>
#include <queue>
using namespace std;
int main() {

    int n,k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    cin>>n;
    //cin>>k;
    int a,b;
    for (int i=0; i<n; i++) {
        cin>>a;
        cin>>b;
        Q.push({a,b});
    }
    int C=0;
    for(int i=0;i<n;i++)
    {
       // bool diff=(Q[i].second<Q[i+1].first)
       int first = Q.top().second;
       Q.pop();
        if(first > Q.top().first)
        {
            C++;
            //first = Q.top.second;
        }
    }
    cout<<C;
    return 0;
}

