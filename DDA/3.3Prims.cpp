#include <iostream>
#include <cstring>
using namespace std;

#define INF 999
#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};

int main() {
    int no_edge = 0;  // number of edges in MST
    int selected[V];  // array to track selected vertices
    memset(selected, false, sizeof(selected));  // set all vertices as not selected initially

    selected[0] = true;  // start from vertex 0

    int total_steps = 0;  // initialize total steps counter

    cout << "Edge : Weight" << endl;

    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        // Find the minimum edge from selected vertices to non-selected vertices
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] && G[i][j] < min) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // Print the edge and weight
        cout << x << " - " << y << " : " << G[x][y] << endl;

        // Mark vertex y as selected
        selected[y] = true;

        // Increment edge count
        no_edge++;

        // Increment total steps count
        total_steps++;
    }

    cout << "Total number of steps: " << total_steps << endl;

    return 0;
}

