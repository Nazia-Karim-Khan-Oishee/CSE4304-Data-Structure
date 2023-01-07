#include<iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int current = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l<N && arr[l] < arr[current])
    {
        current = l;
    }

    if (r<N && arr[r] < arr[current])
    {
        current = r;
    }

    if (current!=i)
    {
        swap(arr[i], arr[current]);
        heapify(arr, N, current);
    }
}
void BuildHeap(int arr[], int N)
{
    int st=N-1;
    for (int i=st; i>= 0; i--)
    {
        heapify(arr, N, i);
    }
    for (int i=0; i<N; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int Heap_Minimum(int heap[], int N)
{
    cout<<"Min Heap: "<<endl;
    for (int i = 0; i <N; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
    return heap[0];
}
void Extract_min(int heap[], int n)
{
    heap[0] = heap[n- 1];
    n--;
    heapify(heap,n,0);
}

void insertNode(int heap[], int N, int val)
{

    N++;

    heap[N-1] = val;

    BuildHeap(heap,N);
}

int main()
{
    int arr[10000];
    int x;
    int i = 0;
    int I=0;
    while (1)
    {
        cin >> x;
        if(x==-1)
        {
            break;
        }
        arr[i] = x;
        i++;
    }
    int Count=i;
    BuildHeap(arr, i);
    int c=5;
    while(c--)
    {
        cin >> x;
        if (x == 1)
        {
            cout << Heap_Minimum(arr,i)<<endl;;
        }
        else if (x == 2)
        {
            cout<<arr[0]<<endl;
            Extract_min(arr,i);
            cout << "Min Heap: ";
            for (int i = 0; i <Count; i++)
            {
                cout << arr[i] << " ";
            }
            cout<<endl;
        }
        else
        {
            insertNode(arr,i, x);
            cout<<endl;

        }
    }
    return 0;
}
