#include <iostream>
#include <algorithm>
using namespace std;

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];
int total_steps = 0; // Step counter

int find(int i)
{
    total_steps++; // Increment step count for while loop check
    while (visited[i])
    {
        total_steps++; // Increment step count for visited check
        i = visited[i];
    }
    return i;
}

int uni(int i, int j)
{
    total_steps++; // Increment step count for function call
    if (i != j)
    {
        visited[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    cout << endl;
    while (ne < n)
    {
        int min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                total_steps++; // Increment step count for nested loop iteration
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            cout << "Edge " << ne << ": (" << a << " " << b << ") cost: " << min << endl;
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;

    cout << "\nTotal number of steps: " << total_steps << endl;

    return 0;
}

