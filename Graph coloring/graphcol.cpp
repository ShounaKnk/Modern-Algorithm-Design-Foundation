#include <iostream>
using namespace std;
#define MAX 20
int m,
n, j;
int vector[MAX];
int graph[MAX][MAX];
void assignColor(int vertex)
{
    while (true)
    {
        vector[vertex] = (vector[vertex] + 1) % (m + 1);
        if (vector[vertex] == 0)
        {
            return;
        }
        for (j = 0; j < n; j++)
        {
            if (graph[vertex][j] == 1 && vector[vertex] == vector[j])
            {
                break;
            }
        }
        if (j == n)
        {
            return;
        }
    }
}
void mColor(int vertex)
{
    while (true)
    {
        assignColor(vertex);
        if (vector[vertex] == 0)
        {
            return;
        }
        if (vertex == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << vector[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            mColor(vertex + 1);
        }
    }
}
int main()
{
    cout << "Enter the number of vertices in the graph : ";
    cin >> n;
    cout<<endl<<endl;
    for (int i = 0; i < n; i++)
    {
        vector[i] = {0};
    }
    cout << "Enter the number of colors to be used : ";
    cin >> m;
     cout<<endl<<endl;
    cout << "Enter the adjacency matrix :- " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout<<endl<<endl;
    cout << "The Solution Vectors are :-" << endl;
    mColor(0);
    return 0;
}
