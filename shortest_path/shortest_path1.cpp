#include <iostream>
#include <string>
using namespace std;
#define Infinity 999
#define MAX 20
int no_of_vertices;

int minDistance(int distance[], bool visited[])
{
    int min = Infinity;
    int min_index;
    for (int i = 0; i < no_of_vertices; i++)
    {
        if (visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
void Dijkstra(int source, int cost[MAX][MAX])
{
    int distance[MAX]; 
    bool visited[MAX];
    string path[MAX];
    for (int i = 0; i < no_of_vertices; i++)
    {
        distance[i] = Infinity;
        visited[i] = false;
        path[i] = to_string(source + 1);
    }
    distance[source] = 0;
    for (int i = 0; i < no_of_vertices; i++)
    {
        int u = minDistance(distance, visited); 
        visited[u] = true;
        for (int j = 0; j < no_of_vertices; j++)
        {
            if (!visited[j]&& cost[u][j]&& distance[u] + cost[u][j] < distance[j])
                {
                    distance[j] = distance[u] + cost[u][j];
                    path[j] = path[u] + " -> " + to_string(j + 1);
                }
        }
    }
    cout << "Src" << "\t"<< "Destn" << "\t" << "MinCost" << "\t"<< "Path"<< "\t" << endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << source + 1 << "\t";
        cout << i + 1 << "\t";
        if (distance[i] == Infinity)
            cout << '-' << "\t" << '-' << endl;
        else
            cout << distance[i] << "\t" << path[i] << endl;
    }
}
int main()
{
    cout << "Enter the Number of Vertices : ";
    cin >> no_of_vertices;
    int cost[MAX][MAX];
    cout << "Enter the Cost Matrix :- " << endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = 0; j < no_of_vertices; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << endl;
    Dijkstra(0, cost);
    return 0;
}