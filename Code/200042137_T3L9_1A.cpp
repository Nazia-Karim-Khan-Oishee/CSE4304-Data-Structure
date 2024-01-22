#include <bits/stdc++.h>
using namespace std;

#define d 256

int main()
{
	string str1 ="sadbutsad";
	string str2="sad";

	int q = 100000;
   int M = str2.size();
    int N = str1.size();
    int i ,j;
    int p = 0;
    int t = 0;
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
    {

        h = (h * d) % q;

    }
    //Calculate the hash value
    for (i = 0; i < M; i++)
    {
        p = (d * p + str2[i]) % q;
    }
    cout<<p<<endl;
    for (i = 0; i < N; i++)
    {

    t = (d * t + str1[i]) % q;

    }
    cout<<t;
	return 0;
}

