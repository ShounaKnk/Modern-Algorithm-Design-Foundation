#include<iostream>
using namespace std;
int arr[10], key;

void sort(int arr[], int n)
{
    cout<<"entered array: ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    int i, j, temp;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
}

int search(int arr[], int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low + high)/2;
        if(key == arr[mid])
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            return search(arr, low, mid-1, key);
        }
        else
        {
            return search(arr, mid +1, high, key);
        }
    }
    else
    {
        return -1;
    }

}



int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    cout<<"enter the elements of array: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, n);

    cout<<endl;
    cout<<"enter the element to search: ";
    cin>>key;

    int pos;
    pos = search(arr, 0, n-1, key);

    cout<<endl<<endl<<"sorted array: ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    cout<<"key: "<<key<<endl;

    cout<<endl;

    if(pos == -1)
    {
        cout<<"element not found\n";
    }
    else
    {
        cout<<key<<" was found at position "<<pos<<endl;
    }
}
