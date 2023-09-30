#include <iostream>
using namespace std;
#define MAX 20
#define INFINITY 999

int n;
int IPIndex = 0; 
int W[MAX][MAX]; 
int C[MAX][MAX]; 
int R[MAX][MAX]; 
int P[MAX];      
int Q[MAX];      
int IP[MAX];     


void Print_Matrix(int M[MAX][MAX])
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void Optimal_Binary_Search()
{
    int min, min_preorderIndex;
    for (int i = 0; i <= n; i++)
    {
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            W[j][j + i] = P[j + i - 1] + Q[j + i] + W[j][j + i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            min = INFINITY;
            for (int k = j + 1; k <= j + i; k++)
            {
                if (C[j][k - 1] + C[k][j + i] < min)
                {
                    min = C[j][k - 1] + C[k][j + i];
                    min_preorderIndex = k;
                }
            }
            C[j][j + i] = min + W[j][j + i];
            R[j][j + i] = min_preorderIndex;
        }
    }
    cout << "Weight Matrix :-" << endl;
    Print_Matrix(W);
    cout << "Cost Matrix :-" << endl;
    Print_Matrix(C);
    cout << "Root Matrix :-" << endl;
    Print_Matrix(R);
}

int main()
{
    cout << "Enter the total number of nodes in the Binary Tree : ";
    cin >> n;
    cout << "Enter the Probabilities of Successful Search : ";
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    cout << "Enter the Probabilities of Unsuccessful Search : ";
    for (int i = 0; i <= n; i++)
    {
        cin >> Q[i];
    }
    Optimal_Binary_Search();
    return 0;
}