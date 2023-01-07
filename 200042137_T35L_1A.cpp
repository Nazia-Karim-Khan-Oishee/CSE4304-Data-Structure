#include<iostream>
#include <queue>
using namespace std;

int main() {

    int n,k;
    priority_queue<int, vector<int>, greater<int>> Q;
    cin>>n;
    cin>>k;
    int a;
    for (int i=0; i<n; i++) {
        cin>>a;
        Q.push(a);
    }
    int Count = 0;
    while (Q.top()<k) {
        if (Q.size()==1) {
            cout << "-1"<<endl;
        }
        else
        {int s = Q.top();
        Q.pop();
        int s2 = Q.top();
        Q.pop();
        Q.push(s + 2*s2);
        Count++;
        }
    }
    cout << Count << endl;
    return 0;
}
