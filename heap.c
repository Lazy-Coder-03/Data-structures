
#include <stdio.h>
#include <stdlib.h>

int arr1[] = {40,10,30,50,60,15};
int arr2[] = {80,14,60,10,100,78,50,30,15};

void swap(int arr[],int i, int j)
{
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

void printarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Maxheapify(int a[], int n, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int t;
    while (left <= n && a[left] > a[largest])
    {
        largest = left;
    }
    while (right <= n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a,i,largest);
        Maxheapify(a, n, largest);
    }
}

void build_heap(int a[], int n)
{
    int i;
    for(i=n/2;i>=0;i--)
    {
        Maxheapify(a,n,i);
    }
}

void heapSort(int a[], int n)
{
    int i;
    build_heap(a,n);
    for(i=n-1;i>0;i--)
    {
        swap(a,0,i);
        build_heap(a,i-1);
        printarr(a,n);
        //Maxheapify(a,i-1,0);
    }
    //build_heap(a,n);
}

int main()
{
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    /*printarr(arr1, n1);
    heapSort(arr1, n1);
    printarr(arr1, n1);*/
    printarr(arr2, n2);
    heapSort(arr2, n2);
    printarr(arr2, n2);
}