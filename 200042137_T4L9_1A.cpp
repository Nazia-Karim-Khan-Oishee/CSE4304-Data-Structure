
#include <bits/stdc++.h>
using namespace std;

#define d 256


int main()
{
    string Haystack,needle;
    cin>>Haystack;
    cin>>needle;


    int q = 100000;

    int M = needle.size();
    int N = Haystack.size();
    int i, j;
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
        p = (d * p + needle[i]) % q;
        t = (d * t + Haystack[i]) % q;
    }
    int match=0;
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (Haystack[i + j] != needle[j])
                {
                    break;
                }
            }

            if (j == M)
            {
                match++;
                cout << needle<<" occured in " <<Haystack<<"at index"<< i<< endl;

            }
        }

        if (i < N - M)
        {
            t = (d * (t - Haystack[i] * h) + Haystack[i + M]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }

    if(match==0)
    {
        cout<<needle<<" did not occur in "<<Haystack;
    }
    return 0;
}

