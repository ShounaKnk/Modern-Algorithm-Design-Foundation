#include <iostream>
#include <string>
using namespace std;
#define MAX 20
int n, m;
int set[MAX];

void sumOfSubset(int sum, int item, int remainingCapacity, string vector)
{
    if (sum == m && remainingCapacity == 0)
    {
        cout << vector << endl;
    }
    if (sum > m || remainingCapacity == 0)
    { 
        return;
    }
    sumOfSubset(sum + set[item], item + 1, remainingCapacity - set[item], vector + "1 ");
    sumOfSubset(sum, item + 1, remainingCapacity - set[item], vector + "0 ");
}
int main()
{
    int totalSum = 0;
    string vector = "";
    cout << "Enter the Number of Elements in the Set : ";
    cin >> n;
    cout<<endl<<endl;
    cout << "Enter the Elements in the set : ";
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
        totalSum += set[i];
    }
    cout<<endl<<endl;
    cout << "Enter the Integer : ";
    cin >> m;
    cout<<endl<<endl;
    cout << "The Solution Vectors are :- " << endl;
    sumOfSubset(0, 0, totalSum, vector);
    return 0;
}