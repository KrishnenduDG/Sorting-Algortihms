#include<stdio.h>

void print_array(int a[],int size)
{
    for(int i=0;i<size;i++)
    printf("%d ",a[i]);

    printf("\n");
}

int partition(int list[],int low,int high)
{
    int down_ptr=low,up_ptr=high,pivot=low,temp;

    /* while (i<j), we loop and do the following thing

    1) Repeatedly increase the down_ptr until list[down_ptr]<=list[pivot]
    2) Repeatedly decrease the up_ptr until list[up_ptr]>=list[pivot]
    
    If (down_ptr < up_ptr),we swap the corresponding elements
    */

    while(down_ptr<up_ptr)
    {
        while (list[down_ptr] <= list[pivot] && down_ptr <= high)
            down_ptr++;

        while (list[up_ptr] > list[pivot] && up_ptr >= low)
            up_ptr--;

        if (down_ptr < up_ptr)
        {
            temp = list[down_ptr];
            list[down_ptr] = list[up_ptr];
            list[up_ptr] = temp;
        }
    }

        // Swapping list[pivot] and list[up_ptr]
        temp = list[up_ptr];
        list[up_ptr] = list[pivot];
        list[pivot] = temp;

        return up_ptr;
}

void quicksort(int list[], int low, int high)
{
    int pivot;

    // Array is already sorted
    if(low>high)
    return;

    // getting the pivot index
    pivot=partition(list,low,high);

    // Handling the Left sub-part of pivot
    quicksort(list,low,pivot-1);

    // Handling the Right sub-part of pivot
    quicksort(list,pivot+1,high);
}

int main()
{
    int a[100],n;

    // Taking the array as input and sorting using quicksort
    printf("Enter the Size of Array:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the %d-th element:",i+1);
        scanf("%d",&a[i]);
    }

    printf("Array before Sorting:\n");
    print_array(a,n);
    
    quicksort(a,0,n-1);

    
    printf("Array After Sorting:\n");
    print_array(a,n);

    return 0;
}