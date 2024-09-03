#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Find operation of union-find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union operation of union-find
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function to sort edges by weight
bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void KruskalMST(vector<Edge>& edges, int V, int& total_steps) {
    vector<Edge> result;
    vector<Subset> subsets(V);

    // Initialize subsets
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    int e = 0, i = 0;
    int total_cost = 0; // Initialize total cost

    while (e < V - 1 && i < edges.size()) {
        total_steps++; // Increment steps counter
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            total_cost += next_edge.weight; // Add weight to total cost
            Union(subsets, x, y);
            e++;
        }
    }

    // Print the MST
    cout << "Edge \tWeight" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].src << " - " << result[i].dest << "\t" << result[i].weight << endl;
    }

    // Print the total cost
    cout << "Total cost of MST: " << total_cost << 
	endl;
}

int main() {
    const int V = 8; // Number of vertices
    vector<Edge> edges;
    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 2, 1));
    edges.push_back(Edge(1, 4, 6));
    edges.push_back(Edge(1, 5, 3));
    edges.push_back(Edge(2, 4, 5));
    edges.push_back(Edge(3, 4, 7));
    edges.push_back(Edge(3, 6, 9));
    edges.push_back(Edge(3, 5, 2));
    edges.push_back(Edge(4, 6, 6));
//    edges.push_back(Edge(5, 7, 3));
//    edges.push_back(Edge(6, 7, 1));

    int total_steps = 0; // Initialize total steps counter

    KruskalMST(edges, V, total_steps);

    cout << "Total number of steps: " << total_steps << endl; // Print total steps

    return 0;
}
