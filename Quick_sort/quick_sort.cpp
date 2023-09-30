#include <iostream>
using namespace std;
int arr[10];

void display(int size)
{
    cout<<"array: ";
    for(int i =0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int lb, int ub)
{
    int temp;
    int start = lb;
    int pivot = start;
    int end = ub;

    while (start < end)
    {
        while (arr[start] <= arr[pivot] && start < end)
            start++;
        while (arr[end] > arr[pivot])
            end--;
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}

void quicksort(int lb, int ub)
{
    if (lb < ub)
    {
        int loc;
        loc = partition(lb, ub);
        quicksort(lb, loc - 1);
        quicksort(loc + 1, ub);
    }
    else
    {
        return;
    }
}

int main()
{
    int size;
    cout<<"enter the size of the array: ";
    cin>>size;
    cout<<"enter the size of the array: ";
    for(int i =0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"before sorting ";
    display(size);

    quicksort(0, size-1);

    cout<<endl<<"after sorting ";
    display(size);
}