#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int> > >& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Function to run Prim's algorithm to find the Minimum Spanning Tree (MST)
void primMST(const vector<vector<pair<int, int> > >& graph, int V, int& total_steps, int& total_cost) {
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int src = 0; // Start from vertex 0

    key[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        total_steps++; // Increment steps for selecting vertex u

        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print MST edges and their weights
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
            total_cost += key[i]; // Add the weight of the edge to the total cost
        }
    }
}

int main() {
    const int V = 8;
    vector<vector<pair<int, int> > > graph(V);
   
    // Adding edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 5, 5);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 4, 8);
    addEdge(graph, 3, 6, 7);
    addEdge(graph, 3, 5, 9);
    addEdge(graph, 4, 6, 1);
//    addEdge(graph, 5, 7, 1);
//    addEdge(graph, 6, 7, 3);

    int total_steps = 0; // Initialize total steps counter
    int total_cost = 0; // Initialize total cost counter

    primMST(graph, V, total_steps, total_cost);

    cout << "Total number of steps: " << total_steps << endl; // Print total steps
    cout << "Total cost of MST: " << total_cost << endl; // Print total cost

    return 0;
}
