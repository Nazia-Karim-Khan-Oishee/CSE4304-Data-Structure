#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (b.second < a.second);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    vector<int> vect(100005,0);
    cin >> x;
    if (x > 0)
    {
        vect[x]++;
    }
    else
    {
        cout << "Invalid Input";
        return 0;
    }
    vector<pair<int, int>> vect2;
    while (x > 0)
    {
        cin >> x;
        vect[x]++;
    }
    for (int i = 1; i < 10000 ; i++)
    {
        vect2.push_back(make_pair(i, vect[i]));
    }
    sort(vect2.begin(), vect2.end(), sortbysec);
    for (int i = 0; vect2[i].second>0; i++)
    {
        cout<<vect2[i].first<<" occurred "<<vect2[i].second<<" times."<<endl;

    }
    return 0;
}

