#include <iostream>
using namespace std;

int T[10][10];

void tableprint(int n, int cap)
{
    cout << "PROFIT TABLE: " << endl<< endl;
    for(int i = 0; i<= cap; i++)
    {
        if(i == 0)
            cout<<"   |0\t";
        else
            cout<<i<<"\t";
    }
    cout<<endl;
    cout << "___|_________________________________________" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << i << "  |";
        for (int j = 0; j <= cap; j++)
        {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void knapsack(int n, int cap, int weight[], int profit[])
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if ((i == 0) || (j == 0))
            {
                T[i][j] = 0;
            }
            else if (weight[i] > j)
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                T[i][j] = max(T[i - 1][j], T[i - 1][j - weight[i]] + profit[i]);
            }
        }
    }
    tableprint(n, cap);
}

void itemselect(int n, int cap, int weight[], int profit[])
{
    int i = n;
    int j = cap;
    bool optimal_solution[10];
    int oparray[10], count = 0;
    int select[n], s=0;

    for(int i=0; i<n; i++)
    {
        select[i] = 0;
    }

    while ((i > 0) && (j > 0))
    {
        if (T[i][j] != T[i - 1][j])
        {
            optimal_solution[i] = true;
            cout << "==>Item " << i << " was selected" << endl;
            oparray[count] = n-s;
            select[s] =1;5

            count++;
            j = j - weight[i];
            i = i - 1;
        }
        else
        {
            optimal_solution[i] = false;
            i = i - 1;
        }
        s++;
    }

    cout << "\n\noptimal solution = { ";
    for (int c = 0; c < count; c++)
    {
        cout << "x" << oparray[c] << ", ";
    }
    cout << "}"<<endl;
    cout<<"included items = { ";
    for (int c = 0; c < n; c++)
    {
        cout << select[c]<<", ";
    }
    cout << "}"<<endl;
    cout<<"maximum profit:  "<<T[n][cap];
}

int main()
{

    int n, cap;
    cout<<"enter the number of objects: ";
    cin>>n;
    cout<<"enter the maximum capacity:";
    cin>>cap;
    int weight[n+1];
    int profit[n+1];
    cout<<endl<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<"enter the weight of object "<<i<<": ";
        cin>>weight[i];
    }
    cout<<endl<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<"enter the profit of object "<<i<<": ";
        cin>>profit[i];
    }
    knapsack(n, cap, weight, profit);
    cout << endl<< endl;
    itemselect(n, cap, weight, profit);
    cout << endl<< endl;
}
