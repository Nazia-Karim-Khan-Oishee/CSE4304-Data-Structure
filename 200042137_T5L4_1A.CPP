#include <iostream>
#include <queue>
#include<vector>
using namespace std;


//queue<int> Q;
int main()
{
    queue<int> q;
    int arr[1000];
    // vector<int> v(1000);
    int x;
    int i=0;
    while(1)
    {
        cin>>x;
        if((x)!=-1)
        {

            q.push(x);
            //v.push_back(x);
            arr[i]=x;
            i++;
            //cin>>x;
            // cout<<"d"<<endl;
        }
        else
        {
            break;
        }
    }
    //cin>>x;
    int n,ans=0;
    cin>>n;
   // cout<<n;
    //n=n-1;
    int j=0;
    int k = arr[n];
    //cout<<arr[k]<<endl;
    while(q.size()!=0)
    {
        if(q.front()>=k)
        {
            if(j<=n)
            {
                ans = ans + k;
                q.pop();
                j++;
            }
            else
            {
                ans = ans + k -1;
                j++;
                q.pop();
            }
        }
        else
        {
            ans =ans + q.front();
            q.pop();
            j++;
        }

    }
cout<<ans;
    return 0;
}
