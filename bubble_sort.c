// If at any Pass no Swapping is done, Then it is sure that array has already fully sorted.

#include<stdio.h>
#include<stdbool.h>

void print_array(int a[],int n)
{
    printf("[");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);

        if(i!=n-1)
        printf(" ");
    }

    printf("]");
}



int * bubble_sort(int a[],int n)
{
    bool mustContinue=true;

    int temp,i,j;

    for(i=0;i<n;i++)
    {
        if(!mustContinue)
        {
            if(i==1)
            printf("(The Array is Already Sorted)\n");
            break;
        }

        mustContinue=false;

        printf("The Array After %d Iteration(s) is:",i+1);
        print_array(a,n);
        printf("\n");

        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                mustContinue=true;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    return a;
}



int main()
{
    int arr[1000],n,*ptr;

    printf("Enter the Number of Elements:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter The %d-th Element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\n");

    printf("The Array Before Sorting:\n");
    print_array(arr,n);

    printf("\n\n");

    ptr=bubble_sort(arr,n);

    printf("\n\nThe Array After Sorting:\n");
    print_array(ptr,n);

    return 0;
}