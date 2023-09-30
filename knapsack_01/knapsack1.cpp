#include <iostream>

using namespace std;
int max(int item1, int item2)
{
    return ((item1 > item2) ? item1 : item2);
}

void knapsackTable(int no_items, int capacity, int profit[], int weight[], int T[][10])
{
    cout << endl
         << "KnapSack (Profit)Table generated : " << endl;

    for (int i = 0; i <= no_items; i++)
    {

        for (int j = 0; j <= capacity; j++)
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
            } // if (weight[i] <= j)
        }
    }
    for (int i = 0; i <= no_items; i++)
    {

        for (int j = 0; j <= capacity; j++)
        {

            cout << T[i][j] << "\t";
        }

        cout << endl;
    }
}

void selectItem(int no_items, int capacity, int profit[], int weight[], int T[][10])
{

    int i = no_items;

    int j = capacity;

    bool optimal_solution[10];

    while ((i > 0) && (j > 0))
    {
        if (T[i][j] != T[i - 1][j])
        {
            optimal_solution[i] = true;
            cout << endl<< "-> Item '" << i << "' added to Knapsack...";
            j = j - weight[i];
            i = i - 1;
        }

        else
        {
            optimal_solution[i] = false;
            i = i - 1;
        }
    }
}

int main()

{

    int no_items = 4;

    int capacity = 5; 

    int weight[10] = {0, 2, 1, 3, 2}; 
    int profit[10] = {0, 12, 10, 20, 15}; 

    int T[10][10]; // Knapsack table...

    knapsackTable(no_items, capacity, profit, weight, T);

    selectItem(no_items, capacity, profit, weight, T);

    return (0);
}