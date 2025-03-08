/* Program Name: prims algorithm
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: a given graph will output a MST using prims algorithm*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure to represent an edge, containing weight, vertex, and parent.
struct Edge {
    int weight, vertex, parent;

    // Define comparison operator for priority queue (min-heap based on edge weight)
    bool operator>(const Edge &other) const {
        return weight > other.weight; // Compare based on edge weight
    }
};

// Function to implement Prim's Minimum Spanning Tree (MST) algorithm
void primAlgo(int n, vector<vector<int>> &graph) {
  
    // Vector to keep track of selected vertices (in MST)
    vector<bool> selected(n, false);

    // Min-heap (priority queue) to get the edge with the smallest weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap; //https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

    // Start with vertex 0, with no parent (-1) and weight 0
    minHeap.push({0, 0, -1});

    int totalWeight = 0;
    vector<pair<int, int>> mstEdges; // To store edges in MST (parent, vertex)
  
    while (mstEdges.size() < n - 1) {
      
        Edge e = minHeap.top();
        minHeap.pop();
        
        int u = e.vertex, w = e.weight, parent = e.parent;

        // Skip if the vertex is already selected
        if (selected[u]) continue;
        
        // Mark the vertex as selected (added to MST)
        selected[u] = true;


        totalWeight += w;

        // If the vertex has a parent, add the edge (parent, vertex) to MST edges
        if (parent != -1) {
            mstEdges.push_back(make_pair(parent, u));
        }

        // Explore all adjacent vertices (neighbors of the current vertex)
        for (int v = 0; v < n; ++v) {
            // If the vertex is not selected and there's an edge between u and v
            if (!selected[v] && graph[u][v] != -1) {
                // Add the edge to the priority queue with the weight, vertex v and u as parent
                minHeap.push({graph[u][v], v, u});
            }
        }
    }
    
    // Output the total weight of the MST
    cout << totalWeight << "\n";
  
    vector<string> edges;
    for (size_t i = 0; i < mstEdges.size(); ++i) {
        // Convert vertex numbers to corresponding letters (A, B, C...)
        edges.push_back(string(1, 'A' + mstEdges[i].first) + string(1, 'A' + mstEdges[i].second));
    }

    sort(edges.begin(), edges.end());

    for (size_t i = 0; i < edges.size(); ++i) {
        cout << edges[i] << "\n";
    }

    cout << "\n";
}

int main() {
    int n;

    while (cin >> n) {
      
        // Create an adjacency matrix to store the graph
        vector<vector<int>> graph(n, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }

        primAlgo(n, graph);
    }

    return 0;
}

