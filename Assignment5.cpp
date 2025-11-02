#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;
using namespace std;

struct Path {
    int dest;
    double baseFare;
    double currFare;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numStages;
    cout << "Enter number of stages: " << flush;
    cin >> numStages;

    vector<int> nodesPerStage(numStages);
    long long totalNodes = 0;

    cout << "Enter number of nodes in each stage (" << numStages << " values): " << flush;
    for (int i = 0; i < numStages; ++i) {
        cin >> nodesPerStage[i];
        totalNodes += nodesPerStage[i];
    }

    vector<int> stageIndex(numStages);
    int currentIndex = 0;
    for (int i = 0; i < numStages; ++i) {
        stageIndex[i] = currentIndex;
        currentIndex += nodesPerStage[i];
    }

    int numPaths;
    cout << "Enter number of edges: " << flush;
    cin >> numPaths;

    vector<vector<Path>> graph(totalNodes);
    vector<vector<int>> reverseGraph(totalNodes);

    cout << "Enter each edge as: from to cost\n" << flush;
    for (int i = 0; i < numPaths; ++i) {
        int from, to;
        double fare;
        cin >> from >> to >> fare;
        if (from < 0 || from >= totalNodes || to < 0 || to >= totalNodes) {
            cerr << "Invalid node index\n";
            return 0;
        }
        Path p{to, fare, fare};
        graph[from].push_back(p);
        reverseGraph[to].push_back(from);
    }

    const double INF = 1e30;
    vector<double> minFare(totalNodes, INF);
    vector<int> nextStop(totalNodes, -1);

    int lastStage = numStages - 1;
    for (int i = 0; i < nodesPerStage[lastStage]; ++i) {
        int node = stageIndex[lastStage] + i;
        minFare[node] = 0.0;
    }

    for (int s = numStages - 2; s >= 0; --s) {
        for (int i = 0; i < nodesPerStage[s]; ++i) {
            int u = stageIndex[s] + i;
            double bestCost = INF;
            int bestNext = -1;

            for (auto &p : graph[u]) {
                int v = p.dest;
                if (minFare[v] + p.currFare < bestCost) {
                    bestCost = minFare[v] + p.currFare;
                    bestNext = v;
                }
            }
            minFare[u] = bestCost;
            nextStop[u] = bestNext;
        }
    }

    cout << fixed << setprecision(6);
    cout << "\nMinimum costs from Stage 0:\n";
    for (int i = 0; i < nodesPerStage[0]; ++i) {
        int node = stageIndex[0] + i;
        if (minFare[node] >= INF / 2)
            cout << "Node " << node << ": unreachable\n";
        else
            cout << "Node " << node << ": cost = " << minFare[node] << "\n";
    }

    cout << "\nEnter source node id (stage 0) to print path, or -1 to skip: " << flush;
    int source;
    cin >> source;

    if (source >= 0 && source < totalNodes) {
        if (minFare[source] >= INF / 2) {
            cout << "No path from " << source << "\n";
        } else {
            cout << "Path from " << source << ": ";
            int current = source;
            double total = 0.0;
            while (current != -1) {
                cout << current;
                int nxt = nextStop[current];
                if (nxt != -1) {
                    double cost = 0;
                    for (auto &p : graph[current])
                        if (p.dest == nxt) cost = p.currFare;
                    total += cost;
                    cout << " -> ";
                } else break;
                current = nxt;
            }
            cout << "\nTotal route cost: " << total << "\n";
        }
    }

    cout << "\nEnter number of updates (0 to skip): " << flush;
    int updates;
    cin >> updates;

    while (updates-- > 0) {
        int from, to;
        double multiplier;
        cout << "Enter edge update (from to multiplier): " << flush;
        cin >> from >> to >> multiplier;

        for (auto &p : graph[from])
            if (p.dest == to)
                p.currFare = p.baseFare * multiplier;

        auto updateFare = [&](int node) -> double {
            double best = INF;
            int next = -1;
            for (auto &p : graph[node]) {
                if (minFare[p.dest] >= INF / 2) continue;
                double temp = p.currFare + minFare[p.dest];
                if (temp < best) { best = temp; next = p.dest; }
            }
            nextStop[node] = next;
            return best;
        };

        queue<int> q;
        double newFare = updateFare(from);
        if (fabs(newFare - minFare[from]) > 1e-9) {
            minFare[from] = newFare;
            q.push(from);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int prev : reverseGraph[node]) {
                double newCost = updateFare(prev);
                if (fabs(newCost - minFare[prev]) > 1e-9) {
                    minFare[prev] = newCost;
                    q.push(prev);
                }
            }
        }
    }

    cout << "\nUpdated costs from Stage 0:\n";
    for (int i = 0; i < nodesPerStage[0]; ++i) {
        int node = stageIndex[0] + i;
        if (minFare[node] >= INF / 2)
            cout << "Node " << node << ": unreachable\n";
        else
            cout << "Node " << node << ": cost = " << minFare[node] << "\n";
    }

    return 0;
}
