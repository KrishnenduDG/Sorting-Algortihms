#include<stdio.h>
#include<math.h>

void print_array(int a[],int size)
{
    for(int i=0;i<size;i++)
    printf("%d ",a[i]);

    printf("\n");
}


void merge(int a[],int low,int mid,int high)
{
    int l1[100],l2[100],count=0,i,index=low;

    // Making the two Lists

    // Right List
    for(i=low;i<=mid;i++)
    {
        l1[count]=a[i];
        count++;
    }

    // Left List
    count=0;
    for(i=mid+1;i<=high;i++)
    {
        l2[count]=a[i];
        count++;
    }

    int p1=0,p2=0;

    /* While there are elements to be considered in both the list,we do the following
     We Check among current elements of two lists and insert them in ascending order by using two pointers(one for each list)
    */
    while(p1!=(mid-low+1) && p2!=(high-mid))
    {
        if(l1[p1]>l2[p2])
        {
            a[index]=l2[p2];
            p2++;
        }

        else if(l1[p1]<l2[p2])
        {
            a[index]=l1[p1];
            p1++;
        }

        else
        {
            a[index]=l1[p1];
            p1++;
            p2++;
        }

        index++;
    }

    // if l2(second list) has been exhausted
    if(p1!=(mid-low+1))
    {
        // While first list is not exhausted, we insert the elements of the first list in the original array
        while(p1!=(mid-low+1))
        {
            a[index]=l1[p1];
            p1++;
            index++;
        }
    }

    // If l1(First List) has been exhausted
    if(p2!=(high-mid))
    {
        // While second list is not exhausted, we insert the elements of the second list in the original array
        while(p2!=(high-mid))
        {
            a[index]=l2[p2];
            p2++;
            index++;
        }
    }
}


void merge_sort(int a[],int low,int high)
{
    if(low>=high)
    return;

    // Getting the middle element from the required portion of the array
    int mid=(int)floor((high+low)/2);

    // Handling the First Half(Right Part)
    merge_sort(a,low,mid);

    // Handling the second Half(Left Part)
    merge_sort(a,mid+1,high);

    // Merging both the parts after they are individually sorted
    merge(a,low,mid,high);

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
    printf("\n\n");

    merge_sort(a,0,n-1);


    
    printf("Array After Sorting:\n");
    print_array(a,n);

    return 0;
}