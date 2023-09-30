#include <iostream>
using namespace std;

int arr[10], count =0;

void display(int a[], int start, int size)
{
    for (int i = start; i <=size; i++)
    {
        cout << a[i] << " ";
    }
}

void merge(int start, int end, int mid)
{

    int temp[10];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void mergesort(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);

    merge(start, end, mid);
}

int main()
{
    int size;
    cout << "enter the size of the array: ";
    cin >> size;

    cout << "enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << endl<< endl<< "entered array: ";
    for (int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }
    mergesort(0, size - 1);

    cout << endl<< endl<< "sorted array: ";
    for (int i = 0; i <size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
