#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <climits>

using namespace std;

// Class to represent the Graph
class Graph {
public:
    int V; // Number of courses (vertices)
    vector<vector<int>> adjList; // Adjacency list for graph
    vector<int> coloring; // Stores the color assigned to each course (exam slot)
    
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        coloring.resize(V, -1); // Initialize all courses with no color
    }

    // Add an edge between two courses (indicating conflict)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Check if a color can be assigned to a vertex
    bool isSafeToColor(int vertex, int color) {
        for (int neighbor : adjList[vertex]) {
            if (coloring[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    // Graph Coloring using Greedy Algorithm
    void greedyColoring() {
        // Assign the first color to the first vertex
        coloring[0] = 0;

        // Assign colors to the remaining vertices
        for (int u = 1; u < V; u++) {
            // Find the first available color
            bool colorFound = false;
            for (int c = 0; c < V; c++) {
                if (isSafeToColor(u, c)) {
                    coloring[u] = c;
                    colorFound = true;
                    break;
                }
            }
            if (!colorFound) {
                cout << "No valid coloring found for vertex " << u << endl;
                return;
            }
        }

        // Print the colors assigned
        for (int i = 0; i < V; i++) {
            cout << "Course " << i + 1 << " -> Time Slot " << coloring[i] + 1 << endl;
        }
    }
};

