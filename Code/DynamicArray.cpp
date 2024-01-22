#include <bits/stdc++.h>


#define endl "\n"

using namespace std;
class DynamicArray{
    public:
    int  *array;
    int count,size;

    DynamicArray()
    {
        count =0;
        size = 1;
        array = new int[size];
    }
    public : void push_back(int a)
    {
        if(count==size)
        {
            growsize();
        }
        array[count]=a;
        count++;
    }
    public : void growsize()
    {
        //int temp[NULL];     
        size = size*2;
        int *temp;
        temp = new int[size];
        int i=0;
            for(i; i<count; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array=temp;
       
    }
    public : void insert(int i, int a)

    {
        int *temp1;
        temp1 = new int[count+1];
        int j=0;
        for(j; j<i; j++)
        {
            temp1[j] = array[j];
        }
        temp1[j]=a;
        j++;
        for(j=i; j<count; j++)
        {
            temp1[j+1] = array[j];
        }
        count++;
        delete[] array;
        array=temp1;
    }
    public : void erase(int i)
    {
    int *temp;
    temp = new int[count];
    int j=0;
    for(j; j<i; j++)
    {
        temp[j] = array[j];
    }
    for(j=i+1; j<count; j++)
    {
        temp[j-1] = array[j];
    }
    count--;
    delete[] array;
    array=temp;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    DynamicArray da1;
    da1.push_back(1);
    da1.push_back(2);
    da1.push_back(3);
    da1.push_back(4);
    da1.push_back(4);
    da1.push_back(2);
    cout<<"Elements of the Array: ";
    for(int i=0; i<da1.count;i++)
    {
        cout<<da1.array[i]<<" ";
    }
    cout<<endl;
    da1.insert(2,9);
    for(int i=0; i<da1.count;i++)
    {
        cout<<da1.array[i]<<" ";
    }
    cout<<endl; 
    da1.erase(2);
    da1.erase(3);
    for(int i=0; i<da1.count;i++)
    {
        cout<<da1.array[i]<<" ";
    }

    cout<<endl;



    return 0;
}