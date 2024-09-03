#include <iostream>
#include <iomanip>

#define INF 1000000 // A large value to represent infinity
#define V 4         // Number of vertices in the graph

using namespace std;

// Function to print the solution matrix
void printSolution(int dist[V][V]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << setw(4) << "INF";
            else
                cout << setw(4) << dist[i][j];
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the input graph
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Compute shortest distances
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print the solution
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0,   3,  INF, 6},
        {9, 0,   4, INF},
        {5, INF, 0,   2},
        {1, INF, INF, 0}
    };

    cout << "Shortest distances between every pair of vertices:\n";
    floydWarshall(graph);

    return 0;
}
