#include <iostream>
#include <string>
using namespace std;
#define INF 99999
int src = 0;
int graph[6][6] =
    {{0, 50, 45, 10, INF, INF},
     {INF, 0, 10, 15, INF, INF},
     {INF, INF, 0, INF, 30, INF},
     {20, INF, INF, 0, 15, INF},
     {INF, 20, 35, INF, 0, INF},
     {INF, INF, INF, INF, 3, 0}};

int main()
{
    int V = 6;
    int dist[V];
    bool S[V];
    string path[6];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        S[i] = false;
    }
    dist[0] = 0;

    for (int i = 0; i < V; i++)
    {
        int min_index, min = INF;
        for (int v = 0; v < V; v++)
        {
            if (S[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
                path[i] = to_string(src + 1);
            }
        }
        S[min_index] = true;

        for (int v = 0; v < V; v++)
        { 
            if (!S[v] && graph[min_index][v] && dist[min_index] != INF && dist[min_index] + graph[min_index][v] < dist[v])
            {
                dist[v] = dist[min_index] + graph[min_index][v];
                path[v] = path[min_index] + " -> " + to_string(v + 1);
            }
        }
    }

    cout << "verteX\tpath\t\tdist from source" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << i<<"\t"<<path[i-1]<<"\t"<< "\t" << dist[i-1] << endl;
    }
    return 0;
}
