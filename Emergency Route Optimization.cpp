#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adj;

    void addEdge(const string &u, const string &v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since it's bi-directional
    }

    void removeEdge(const string &u, const string &v) {
        auto &neighborsU = adj[u];
        neighborsU.erase(remove_if(neighborsU.begin(), neighborsU.end(),
                                   [&](pair<string, int> p) { return p.first == v; }), neighborsU.end());

        auto &neighborsV = adj[v];
        neighborsV.erase(remove_if(neighborsV.begin(), neighborsV.end(),
                                   [&](pair<string, int> p) { return p.first == u; }), neighborsV.end());
    }

    void updateEdgeWeight(const string &u, const string &v, int newWeight) {
        for (auto &p : adj[u]) {
            if (p.first == v) {
                p.second = newWeight;
                break;
            }
        }
        for (auto &p : adj[v]) {
            if (p.first == u) {
                p.second = newWeight;
                break;
            }
        }
    }

    pair<int, vector<string>> dijkstra(const string &start, const string &end) {
        unordered_map<string, int> dist;
        unordered_map<string, string> prev;
        for (auto &node : adj)
            dist[node.first] = INT_MAX;
        dist[start] = 0;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (u == end) break;

            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<string> path;
        for (string at = end; !at.empty(); at = prev[at])
            path.push_back(at);
        reverse(path.begin(), path.end());
        return {dist[end], path};
    }

    void printPath(const string &start, const string &end) {
        auto [time, path] = dijkstra(start, end);
        if (time == INT_MAX) {
            cout << "No path found from " << start << " to " << end << endl;
            return;
        }
        cout << "Shortest path from " << start << " to " << end << ":\n";
        for (const string &node : path)
            cout << node << " ";
        cout << "\nTotal travel time: " << time << " mins\n\n";
    }
};

void buildBaseGraph(Graph &g) {
    g.addEdge("Mirpur 1", "Mirpur 10", 10);
    g.addEdge("Mirpur 10", "Mohakhali", 20);
    g.addEdge("Uttara Sector 3", "Mirpur 10", 20);
    g.addEdge("Uttara Sector 3", "Baridhara", 30);
    g.addEdge("Baridhara", "Mohakhali", 6);
    g.addEdge("Baridhara", "Farmgate", 7);
    g.addEdge("Mohakhali", "Farmgate", 10);
    g.addEdge("Mohakhali", "Shahbagh", 10);
    g.addEdge("Farmgate", "Shahbagh", 7);
    g.addEdge("Farmgate", "Motijheel", 5);
    g.addEdge("Shahbagh", "Motijheel", 5);
    g.addEdge("Shahbagh", "Lalbagh Fort", 9);
    g.addEdge("Lalbagh Fort", "Dhanmondi 32", 9);
    g.addEdge("Dhanmondi 32", "Farmgate", 9);
    g.addEdge("Dhanmondi 27", "Dhanmondi 32", 4);
    g.addEdge("Dhanmondi 27", "Sadarghat", 3);
    g.addEdge("Dhanmondi 27", "Mirpur 1", 10);
    g.addEdge("Sadarghat", "Lalbagh Fort", 20);
    g.addEdge("Motijheel", "Sadarghat", 20);
    g.addEdge("Dhanmondi 32", "Sadarghat", 25);
}

int main() {
    Graph g;
    buildBaseGraph(g);

    cout << "Q2: Normal Condition:\n";
    g.printPath("Farmgate", "Sadarghat");
    g.printPath("Mirpur 1", "Motijheel");

    cout << "Q3: Rush Hour Condition:\n";
    g.updateEdgeWeight("Farmgate", "Dhanmondi 32", 18);
    g.updateEdgeWeight("Dhanmondi 32", "Sadarghat", 50);
    g.updateEdgeWeight("Mirpur 1", "Mirpur 10", 20);
    g.printPath("Sadarghat", "Motijheel");
    g.printPath("Uttara Sector 3", "Dhanmondi 27");

    cout << "Q4: Road Block Scenario:\n";
    g.removeEdge("Farmgate", "Shahbagh");
    g.printPath("Sadarghat", "Shahbagh");

    cout << "Q5: Multi-Objective Route:\n";
    auto [time1, path1] = g.dijkstra("Mohakhali", "Dhanmondi 27");
    auto [time2, path2] = g.dijkstra("Dhanmondi 27", "Motijheel");

    cout << "Mohakhali → Dhanmondi 27:\n";
    for (auto &p : path1) cout << p << " ";
    cout << "\nTime: " << time1 << " mins\n";

    cout << "Dhanmondi 27 → Motijheel:\n";
    for (auto &p : path2) cout << p << " ";
    cout << "\nTime: " << time2 << " mins\n";

    cout << "Total Time: " << (time1 + time2) << " mins\n";

    return 0;
}
