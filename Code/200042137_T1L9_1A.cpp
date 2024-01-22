#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int, int> map1;
    map<int, int> map2;

    int key=1,key2=1;
    int x,y;
    cin>>x;
    if(x!=-1)
    {
        map1.insert({key,x});
        key++;
    }
    while(1)
    {
        cin>>x;
        if(x==-1)
        {
            break;
        }
        map1.insert({key,x});
        key++;
    }


    cin>>y;
    if(y!=-1)
    {
        map2.insert({key2,y});
        key2++;
    }
    while(1)
    {
        cin>>y;
        if(y==-1)
        {
            break;
        }
        map2.insert({key2,y});
        key2++;
    }

    int not_subset=0;

    for (auto z:map2)
    {
        if(map1.find(z.second)== map1.end())
        {
            not_subset=1;;
        }
    }
    if(not_subset==1)
    {
        cout <<"NO"<<endl;
        return 0;
    }
    cout <<"YES"<<endl;
    return 0;
}
