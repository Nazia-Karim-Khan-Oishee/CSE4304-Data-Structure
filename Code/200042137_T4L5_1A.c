#include<iostream>
#include <queue>
using namespace std;
int main() {

    int n,k;
    priority_queue<pair<int,int> vector<int>, greater<int>> Q;
    cin>>n;
    //cin>>k;
    int a,b;
    for (int i=0; i<n; i++) {
        cin>>a;
        cin>>b;
        Q.push({a,b});
    }
    int C=1;
    for(int i=0;i<n;i++)
    {
        bool diff=(Q[i].second<Q[i+1].first)
        if(diff)
        {
            C++;
        }
    }
    cout<<C;
    return 0;
}

