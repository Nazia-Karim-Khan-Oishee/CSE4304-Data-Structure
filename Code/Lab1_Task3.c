#include<stdio.h>

/*int binarySearch(int array[], int first, int last, int x)
{
    while(first<=last)
    {
        int middle = first + (last-first)/2;
        if (array[middle] == x)
           {
            return middle;
           }
        if (array[middle] > x)

           {
                last = middle- 1;
           }
           if (array[middle] < x)

           {
                first = middle + 1;
           }
    }
    }
        return -1;
}

*/
int binarySearch(int array[], int first, int last, int x)
{
    if (last>=first) {
        int middle = first + (last-first)/2;
        if (array[middle] == x)
           {
            return middle;
           }
        if (array[middle] > x)

           {
               return binarySearch(array, first, middle-1, x);
           }
        return binarySearch(array, middle + 1, last, x);
    }
   else
   {
       return -1;
   }
}

int main()
{
    int n;
scanf("%d", &n);
     int arr[100000]={0} ,i=0;
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    arr[i]=n;
    while(n!=-1)
    {
        i++;
        scanf("%d", &n);
        arr[i]=n;
    }
    int a;
scanf("%d", &a);
    int s=binarySearch(arr, 0, i, a);
    if(s==-1)
    {
        printf("-1");
    }
    else
    {
        printf("%d" , s);
    }
    return 0;

}

