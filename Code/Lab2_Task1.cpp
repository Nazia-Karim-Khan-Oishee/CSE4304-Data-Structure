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
    void Remove(int i)
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

int main()
{
    Dynamic_Array arr;
    for(int i =0;i<16;i++)
    {
        arr.PushBack(100 + i);
        cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;
    }

}
