#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {

        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }
    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }
    void PushBack(int val)
    {
        if(Capacity==Size)
        {
            growsize();
        }
        arr[Size]=val;
        Size++;

    }
    void growsize()
    {

        Capacity = Capacity*2;
        int *temp;
        temp = new int[Capacity];
        int i=0;
        for(i; i<Size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr=temp;

    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    int Remove(int i)
    {
        int *temp;
        temp = new int[Capacity];
        int j=0;
        for(j; j<i; j++)
        {
            temp[j] = arr[j];
        }
        for(j=i+1; j<Size; j++)
        {
            temp[j-1] = arr[j];
        }
        Size--;
        delete[] arr;
        arr=temp;
    }

};



Dynamic_Array increment(Dynamic_Array d)
{
    int inc=1;
    int len = d.Get_Size();
    Dynamic_Array temp;
while(len!=0)
    {
        int c = d.Get(len-1);

        if(c+inc >9)
        {
           temp.PushBack(0);
            inc=1;
        }
        else
        {
            temp.PushBack(c+inc);
            inc=0;
        }
        //d.Remove(len-1);
len--;
    }
    if(inc>0)
    {
        temp.PushBack(inc);
    }

    int i=0;
    int j = temp.Get_Size() -1;
    while(i<=j)
    {
        if(i==j)
        {
            break;
        }
        swap(temp.arr[i],temp.arr[j]);
        i++;
        j--;
    }
    return temp;


}

int main()
{
    Dynamic_Array Arr;
    //int sz;
    //cin >> sz;
   // for(int i = 0; );
    Arr.PushBack(2);
    Arr.PushBack(9);
    Arr.PushBack(9);
    Arr.PushBack(9);
    Dynamic_Array Arr2;
    Arr2 = increment(Arr);
    for(int i=0; i<Arr2.Get_Size(); i++)
    {
        cout<<Arr2.arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

