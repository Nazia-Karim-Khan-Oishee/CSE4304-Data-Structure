#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[5]={1,2,3,4,5};
    for(int i=0; i<5; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
///allocating memory
int n;
//printf("Add elements",)
scanf("%d", &n);
    int* ptr;
    ptr = (int*)malloc(n * sizeof(int));
int i;

for( i=0; i<5; i++)
    {
        ptr[i] = arr1[i];
    }
    //int * list = arr1;
    //delete[] list;
    int x;
    for(i; i<n+5; i++)
    {
        scanf("%d", &x);
        ptr[i] = x;
    }
    printf("The elements of the array are: ");
    int j=0;
		for (j;  j<n+5; ++j) {
			printf("%d ", ptr[j]);
		}
        return 0;
}
