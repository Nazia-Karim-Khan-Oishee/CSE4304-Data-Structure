#include<stdio.h>
int main()
{
int array[500]={0} , n;
printf("Input\n");
scanf("%d", &n);
array[n]++;
while(n>0)
{
 scanf("%d", &n); ;
 array[n]++;
}
printf("Output\n");
for(int i=1; i<500; i++)
    {
        if(array[i]>0)
        {
            printf("%d occurs %d times\n" , i, array[i]);
        }
    }
    return 0;
}
