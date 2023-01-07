#include <iostream>
using namespace std;


void SWAP(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right< N && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        SWAP(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}
void Build_Max_Heap(int arr[], int N)
{
    int a;
// Index of last non-leaf node
    int startIndex = (N / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    printf("Max Heap : ");

    for (int i = 0; i < N; ++i)
    {

        printf("%d ",arr[i]);
    }
    printf("\n");
    //void heapsort(int arr[],int N);

}
void heapSort(int arr[], int N)
{

    for(int i=N-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
        printf("Sorted : ");
    for (int i = 0; i < N; ++i)
    {

        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[10000];
    int x;
    int i=0;
    while(1)
    {
        cin>>x;
        if(x==-1)
        {
            break;
        }
        arr[i]=x;
        i++;
    }

    //int N = sizeof(arr) / sizeof(arr[0]);
    Build_Max_Heap(arr, i);
    heapSort(arr, i);

    return 0;
}
