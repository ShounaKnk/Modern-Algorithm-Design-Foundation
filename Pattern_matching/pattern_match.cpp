#include<iostream>

using namespace std;


int search(char T[],char P[],int n,int m)
{
    int j,i;
    for ( i=0; i<= n-m; i++)
    {
        j=0;
        while (j<m && P[j] == T[i+j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }

    }
            return -1;
}
void display(char arr[],int n)
{

    cout<<endl<<"String:\t";
    for ( int i=0; i<n; i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    char arr1[10],arr2[10];
    int n,m,found=0;

    cout<<"Enter the size of array1:";
    cin>>n;

    cout<<endl<<"Enter the string in the array1: ";
    for ( int i=0; i<n; i++)
    {
        cin>>arr1[i];
    }

    cout<<endl<<"Enter the size of array2:\t";
    cin>>m;

    cout<<endl<<"Enter the string in the array2: ";
    for ( int i=0; i<m; i++)
    {
        cin>>arr2[i];
    }

    display(arr1,n);
    display(arr2,m);

    found=search(arr1,arr2,n,m);

    if (found == -1)
    {
        cout<<endl<<"\nPattern not found"<<endl;
    }
    else
    {
        cout<<endl<<"\nPattern found at index "<<found;
    }
    return 0;
}
