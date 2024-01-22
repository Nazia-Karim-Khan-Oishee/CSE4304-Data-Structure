#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int, int> map1;

    int key=1;
    int x,sum;
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
    cin>>sum;
    int found=0,c=0;

    for (auto z:map1)
    {
        if(z.second!=-3)
        {

            for(auto y:map1)
            {
                if(y.second!=-3)
                {

                    if((z.second + y.second) ==sum)
                    {
                        found=1;
                        c++;
                        //cout<<c;
                        cout<<(z.second)<<" "<<y.second<<endl;
                        y.second=-3;
                        z.second=-3;
                        break;
                    }
                }

            }
            /*if(c==(map1.size()/2))
            {
                break;
            }*/
        }

    }
    if(found==0)
    {
        cout <<"NO pairs found"<<endl;
    }
    return 0;
}

