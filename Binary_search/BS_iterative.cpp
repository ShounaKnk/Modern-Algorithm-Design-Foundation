#include <iostream>
using namespace std;
int arr[10], key;

void sort(int arr[], int n)
{
    cout << "entered array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int search(int arr[], int key, int n)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (key < arr[mid])
        {
            high = mid - 1;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    cout << "enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, n);

    cout << endl;
    cout << "enter the element to search: ";
    cin >> key;

    int pos;
    pos = search(arr, key, n);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "key: " << key << endl;

    cout << endl;

    if (pos == -1)
    {
        cout << "element not found\n";
    }
    else
    {
        cout << key << " was found at position " << pos << endl;
    }
}